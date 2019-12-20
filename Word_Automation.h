//---------------------------------------------------------------------------
#include <vcl.h>
#ifndef Word_AutomationH
#define Word_AutomationH
//---------------------------------------------------------------------------
//Ќадо над классом поработать
class TWord_Automation
{
private:
		Variant my_word;
		Variant my_docs;
		Variant this_doc;
		Variant my_range;  //необходимо добавить инициализацию в конструктор!
		Variant my_selection; //необходимо добавить инициализацию в конструк

		void GetActiveWord();
		int CreateDocument(AnsiString Pattern);
		void  StringRemoveSpace(char* string, char c_del, int *count);

public:
 //		TWord_Automation();
		TWord_Automation(AnsiString Pattern);
		// User declarations
		inline Variant get_my_word() const{return my_word;}
	 //	inline Variant get_my_selection() const{return my_selection;}

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

};

//---------------------------------------------------------------------------
#endif