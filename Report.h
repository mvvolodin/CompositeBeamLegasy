//---------------------------------------------------------------------------

#ifndef ReportH
#define ReportH
#include <cstdio>
//---------------------------------------------------------------------------
class Report{
private:
	bool debug_;
	const char* file_name_;
   //	char placeholder_;

	FILE* report_;
public:
	Report(const char* file_name, bool debug);
	void print_title(const char* title);
	void print_subtitle(const char* subtitle);
	void print_double(const char* description, double value);
	void open();

};
#endif
