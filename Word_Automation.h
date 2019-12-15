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
        // Вставка изображения из TImage по шаблону
        void PasteImagePicturePattern(TImage *Image, AnsiString Pattern);

        Variant my_word;
        Variant my_docs;
        Variant this_doc;
        Variant my_range;
        Variant my_selection;


};
extern PACKAGE TWord_Automation Word_Automation;
//---------------------------------------------------------------------------
#endif