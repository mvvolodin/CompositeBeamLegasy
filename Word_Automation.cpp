//---------------------------------------------------------------------------
#include <vcl.h>
#include <utilcls.h>
#include <Clipbrd.hpp>

#pragma hdrstop
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "Word_Automation.h"

#define  wdAutoFitFixed     0
#define  wdAutoFitContent   1
#define  wdAutoFitWindow    2

#define EMBRAC



//---------------------------------------------------------------------------
#pragma package(smart_init)

TWord_Automation Word_Automation;
void  StringRemoveSpace(char* string, char c_del, int *count);


//---------------------------------------------------------------------------
// открыть объект Word
void TWord_Automation::GetActiveWord()
{

     try {
          my_word = Variant::GetActiveObject("word.application");
     }
     catch (...) {
          // -- не удается отыскать активный объект Word
          // -- сформировать новый объект
          try {
              my_word = Variant::CreateObject("word.application");
		  }
		  catch (...) {
			// -- не удается создать новый объект Word
			#ifdef EMBRAC
			Application->MessageBox(L"Unable",L"Error:",MB_OK|MB_ICONERROR);
			#else
			Application->MessageBox("Unable","Error:",MB_OK|MB_ICONERROR);
			#endif
          }
     }
     my_word.OlePropertySet("Visible",(Variant)True);
}
//---------------------------------------------------------------------------
// Создать документ на основе шаблона Pattern
int TWord_Automation::CreateDocument(AnsiString Pattern)
{
    long doc_count;
    AnsiString filename;
    FILE *file_doc;
    int rc;

	my_docs = my_word.OlePropertyGet("Documents");

    // Function AddDocument("Add");
    if (Pattern=="") {  // пустой документ
        this_doc = my_docs.OleFunction("Add");
    }
    else {  // документ на основе шаблона
       filename = ExtractFileDir(Application->ExeName)+"\\" + Pattern;
       if ((file_doc = fopen(filename.c_str(),"r")) == NULL) {
		 fclose(file_doc);
		#ifdef EMBRAC
		   rc = Application->MessageBox((L"Шаблон с именем "+filename+L" не найден").c_str(), L"Ошибка при создании документа",
								MB_OK | MB_ICONERROR);
		 #else
		   rc = Application->MessageBox(("Шаблон с именем "+filename+" не найден").c_str(), "Ошибка при создании документа",
								MB_OK | MB_ICONERROR);
		 #endif
	   }
       else {
		 fclose(file_doc);
       }
       this_doc = my_docs.OleFunction("Add",StringToOleStr(filename));
    }
    doc_count = my_docs.OlePropertyGet("Count");
    //ShowMessage((AnsiString)"Открыто " + doc_count + " документов");
    return 0;

}
//---------------------------------------------------------------------------
// Вставка текста в конец текущего Range
void TWord_Automation::PasteCur(TRichEdit *RichEditOut)
{

    RichEditOut->SelectAll();
    RichEditOut->CutToClipboard();

    my_range.OleProcedure("Collapse",(Variant)0);
    my_range.OleProcedure("Paste");

}
//---------------------------------------------------------------------------
// Вставка текста в конец текущего Range c преобразованием таблиц
void TWord_Automation::PasteCurTable(TRichEdit *RichEditOut)
{
    int i;
    bool flag_table;
	char string[800];
	AnsiString Astring;
	Variant my_tables;
    Variant my_table;

    my_range.OleProcedure("Collapse",(Variant)0);
    flag_table=false;
    for (i=0; i<RichEditOut->Lines->Count; i++) {
		//if (strncmp(RichEditOut->Lines->Strings[i].c_str(),"*-",2)==0) {
		if (RichEditOut->Lines->Strings[i].SubString(0, 2)=="*-") {
		   if (flag_table) {
		   // конец таблицы
			 #ifdef EMBRAC
			   Astring = "|";
			   my_range.OleProcedure("ConvertToTable",StringToOleStr(Astring));
			 #else
			   my_range.OleProcedure("ConvertToTable",StringToOleStr("|"));
			 #endif

               my_tables=my_range.OlePropertyGet("Tables");
               my_table=my_tables.OleFunction("Item", 1);
               my_table.OleFunction("AutoFitBehavior", wdAutoFitContent);
             //  my_table.OleFunction("AutoFitBehavior", wdAutoFitWindow);
			   flag_table=false;
           }
           else {
           // начало таблицы
               my_range.OleProcedure("Collapse",(Variant)0);
               flag_table=true;
		   }
        }
		else {
		  int count;
		  #ifdef EMBRAC
		  Astring = RichEditOut->Lines->Strings[i];
   		  if (flag_table) { // убрать пробелы слева и справа в каждом поле таблицы
			StringRemoveSpace(Astring.c_str(),'|', &count);
		  }
		  else {
			 my_range.OleProcedure("Collapse",(Variant)0);
		  }
		  my_range.OleProcedure("InsertAfter", StringToOleStr(Astring.SubString(0, count)));
		  #else
		  strcpy(string, RichEditOut->Lines->Strings[i].c_str());
		  if (flag_table) { // убрать пробелы слева и справа в каждом поле таблицы
			 StringRemoveSpace(string,'|');
		  }
		  else {
			 my_range.OleProcedure("Collapse",(Variant)0);
		  }
		  my_range.OleProcedure("InsertAfter", StringToOleStr(string));
		  #endif
          my_range.OleProcedure("InsertParagraphAfter");
		}
    }
    RichEditOut->Clear();
}
//---------------------------------------------------------------------------
// Вставка текста в конец текущего Range
void TWord_Automation::InsertCur(AnsiString text)
{

    my_range.OleProcedure("InsertAfter", StringToOleStr(text));

}
//---------------------------------------------------------------------------
// Вставка текста в конец документа
void TWord_Automation::PasteEnd(TRichEdit *RichEditOut)
{

    RichEditOut->SelectAll();
    RichEditOut->CutToClipboard();

    my_range = this_doc.OleFunction("Range");
    my_range.OleProcedure("Collapse",(Variant)0);
    my_range.OleProcedure("Paste");

}
//---------------------------------------------------------------------------
// Вставка текста по шаблону
void TWord_Automation::Paste(TRichEdit *RichEditOut, AnsiString Pattern)
{

	RichEditOut->SelectAll();
    RichEditOut->CutToClipboard();

    my_range = this_doc.OleFunction("Range");
    my_range.OlePropertyGet("Find").OleProcedure("Execute", StringToOleStr(Pattern));
    my_range.OleProcedure("Paste");

}
//---------------------------------------------------------------------------
// Вставка строки текста по шаблону
void TWord_Automation::PasteTextPattern(AnsiString Text, AnsiString Pattern)
{

	my_selection.OlePropertySet("Start", (Variant)0);
	my_selection.OlePropertySet("End", (Variant)0);
 repeat:
	my_selection.OlePropertyGet("Find").OleProcedure("Execute", StringToOleStr(Pattern));
	if (my_selection.OlePropertyGet("Start") != my_selection.OlePropertyGet("End")) {
	  my_selection.OleProcedure("TypeText", StringToOleStr(Text));   // Это работает
	  //my_selection.Exec(Function("TypeText") << Text );
	  goto repeat;
	}

}
//---------------------------------------------------------------------------
// Вставка файла Word по шаблону
int TWord_Automation::PasteFilePattern(AnsiString FileName, AnsiString Pattern)
{
    AnsiString filename;
    FILE* file_doc;
    int rc;


	filename = ExtractFileDir(Application->ExeName)+"\\" + FileName;
	if ((file_doc = fopen(filename.c_str(),"r")) == NULL) {
		 fclose(file_doc);
		 #ifdef EMBRAC
		 rc = Application->MessageBox((L"Файл Word с именем "+filename+L" не найден").c_str(), L"Ошибка при создании документа",
								MB_OK | MB_ICONERROR);
		 #else
		 rc = Application->MessageBox((L"Файл Word с именем "+filename+L" не найден").c_str(), L"Ошибка при создании документа",
								MB_OK | MB_ICONERROR);
		 #endif
	}
	else {
		 fclose(file_doc);
	}
	my_selection.OlePropertySet("Start", (Variant)0);
	my_selection.OlePropertySet("End", (Variant)0);
 repeat:
	my_selection.OlePropertyGet("Find").OleProcedure("Execute", StringToOleStr(Pattern));
	if (my_selection.OlePropertyGet("Start") != my_selection.OlePropertyGet("End")) {
	  my_selection.OleProcedure("InsertFile", StringToOleStr(filename));
	  //my_selection.Exec(Function("InsertFile") << filename );
	  goto repeat;
	}

	return 0;
}
//---------------------------------------------------------------------------
// Вставка текста с преобразованием таблиц по шаблону
void TWord_Automation::PasteTable(TRichEdit *RichEditOut, AnsiString Pattern)
{
    my_range = this_doc.OleFunction("Range");
    my_range.OlePropertyGet("Find").OleProcedure("Execute", StringToOleStr(Pattern));
    my_range.OleProcedure("Delete");

    PasteCurTable(RichEditOut);
}
//------------------------------------------------------------
//  Убрать пробелы слева в каждом поле таблицы
void  StringRemoveSpace(char* string, char c_del, int *count) {
   bool flag_move;
   int i, j, k;

   flag_move=false;
   for (i=0, k=0; i< strlen(string); i++) {
	 if (string[i]==c_del) {
		 for (j=k-1; j>=0; j--)
			if (string[j]!=' ') break;
		 k = j+1;
		 string[k] = string[i];
		 flag_move=false;
		 k++;
		 continue;
	 }
	 if (string[i]!=' ' || flag_move) {
		 string[k] = string[i];
		 flag_move=true;
		 k++;
		 continue;
	 }
   }
   string[k]='\0';
   *count = k;
}
//-------------------------------------------------------------------------
// Вставка изображения из TImage по шаблону
void TWord_Automation::PasteImagePicturePattern(TImage *Image, AnsiString Pattern)
{
  TMetafile * GrapMeta = NULL;
  TMetafileCanvas *pCanvas;

  GrapMeta = new TMetafile;
  GrapMeta->Height = Image->Height;
  GrapMeta->Width = Image->Width;
  pCanvas = new TMetafileCanvas(GrapMeta, 0);
   // Вставить в буфер, потом взять из буфера для преобразования TBitmap в TGraphics
  Clipboard()->Assign(Image->Picture);
  Graphics::TBitmap*  gBitmap = new Graphics::TBitmap;

  gBitmap->Assign(Clipboard());
  // Рисуем на канве загружаемое изображение
  pCanvas->Draw(0, 0, gBitmap);
  delete  pCanvas;   // Должен быть уничтожен перед вставкой GrapMeta
  Word_Automation.PastePictures(GrapMeta, Pattern);
  delete  gBitmap;
  delete GrapMeta;

}
//-------------------------------------------------------------------------
// Вставка рисунка по шаблону
void TWord_Automation::PastePictures(TMetafile *GrapMeta, AnsiString Pattern)
{

    Clipboard()->Assign(GrapMeta);

    my_range = this_doc.OleFunction("Range");
    my_range.OlePropertyGet("Find").OleProcedure("Execute", StringToOleStr(Pattern));
    my_range.OleProcedure("Paste");
    my_range.OleProcedure("Collapse",(Variant)0);
    my_range.OleProcedure("InsertAfter", "\n");

}
//---------------------------------------------------------------------------
// Вставка рисунка в текущую строку
void TWord_Automation::PastePicturesCur(TMetafile *GrapMeta)
{

    Clipboard()->Assign(GrapMeta);

    my_range.OleProcedure("Collapse",(Variant)0);
    my_range.OleProcedure("Paste");
    my_range.OleProcedure("Collapse",(Variant)0);
    my_range.OleProcedure("InsertAfter", "\n");


}
//---------------------------------------------------------------------------
// Вставка рисунка в конец документа
void TWord_Automation::PastePicturesEnd(TMetafile *GrapMeta)
{

    Clipboard()->Assign(GrapMeta);

    my_range = this_doc.OleFunction("Range");
    my_range.OleProcedure("Collapse",(Variant)0);
    my_range.OleProcedure("Paste");
    my_range.OleProcedure("Collapse",(Variant)0);
    my_range.OleProcedure("InsertAfter", "\n");

}
//---------------------------------------------------------------------------
void TWord_Automation::QuickSave(AnsiString Name_file)
{

     //this_doc = my_word.OlePropertyGet("ActiveDocument");
     this_doc.OleProcedure("SaveAs",StringToOleStr(Name_file));
}
//---------------------------------------------------------------------------
void TWord_Automation::Close()
{
     this_doc.OleProcedure("Close");
}
//---------------------------------------------------------------------------
void TWord_Automation::QuickOpen(AnsiString Name_file)
{

    my_docs = my_word.OlePropertyGet("Documents");
    this_doc = my_docs.OleFunction("Open", StringToOleStr(Name_file));


}
//---------------------------------------------------------------------------
