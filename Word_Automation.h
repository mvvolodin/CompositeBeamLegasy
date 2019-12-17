//---------------------------------------------------------------------------
#include <vcl.h>
#ifndef Word_AutomationH
#define Word_AutomationH
//---------------------------------------------------------------------------
class TWord_Automation
{
public:		// User declarations
		void GetActiveWord();
		int  CreateDocument(AnsiString Pattern);
        void QuickSave(AnsiString Name_file);
		void Close();
		void QuickOpen(AnsiString Name_file);
        void Paste(TRichEdit *RichEditOut, AnsiString Pattern);
		void PasteTable(TRichEdit *RichEditOut, AnsiString Pattern);
        void PasteCur(TRichEdit *RichEditOut);
        void PasteCurTable(TRichEdit *RichEditOut);
        void PasteEnd(TRichEdit *RichEditOut);
        void PastePictures(TMetafile *GrapMeta, AnsiString Pattern);
        void PastePicturesCur(TMetafile *GrapMeta);
        void PastePicturesEnd(TMetafile *GrapMeta);
        void InsertCur(AnsiString text);
        void PasteTextPattern(AnsiString Text, AnsiString Pattern);
		int PasteFilePattern(AnsiString FileName, AnsiString Pattern);
		// ¬ставка изображени€ из TImage по шаблону
		void PasteImagePicturePattern(TImage *Image, AnsiString Pattern);

		Variant my_word;
		Variant my_docs;
		Variant this_doc;
		Variant my_range;
		Variant my_selection;


};
extern PACKAGE TWord_Automation Word_Automation; //ƒл€ чего здесь требуетс€ extern PACKAGE???
//ƒл€ того, чтобы когда полключаю заголовочный файл "Word_Automation.h" был объект класса?
//присутствие в заголовочном файле объ€влени€ объекта была бы проблема перекомпил€ции всех файлов
//в который был бы включен заголовочный файл с объ€воением?
//---------------------------------------------------------------------------
#endif