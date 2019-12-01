//---------------------------------------------------------------------------

#pragma hdrstop

#include "Report.h"
#include "Windows.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
Report::Report(const char* file_name, bool debug)
	:debug_(debug),file_name_(file_name)
{
	report_=fopen(file_name, "w"); //открываем поток
}
void Report::print_title(const char* title)
{
	fprintf(report_, "------------------------------------------");
	fprintf(report_, "---------- ќћѕќ«»“Ќќ≈ —≈„≈Ќ»я-------------");
	fprintf(report_, "------------------------------------------");
}
void Report::print_subtitle(const char* subtitile)
{



}


void Report::open()
{

 fclose(report_); //закрываем поток

  STARTUPINFOA startInfo={0};
  PROCESS_INFORMATION processInfo={0};

  char* app="\\notepad.exe";
  char* windir_variable=(char*)malloc(50*sizeof(char));
  char* path=(char*)malloc(strlen(windir_variable)+strlen(app)+1);
  GetEnvironmentVariableA("windir",windir_variable,100);
  strcpy(path,windir_variable);
  strcat(path,app);

	CreateProcessA(path,   // Name of program to execute
	NULL,                  // Command line
	NULL,                      // Process handle not inheritable
	NULL,                      // Thread handle not inheritable
	FALSE,                     // Set handle inheritance to FALSE
	NULL,                         // No creation flags
    NULL,                      // Use parent's environment block
	NULL,                      // Use parent's starting directory
	&startInfo,                       // Pointer to STARTUPINFO structure
	&processInfo);
}

char* str_center(char str[], unsigned int new_length, char placeholder)
{
    size_t str_length = strlen(str);

    // if a new length is less or equal length of the original string, returns the original string
    if (new_length <= str_length)
        return str;

    char *buffer;
    unsigned int i, total_rest_length;

	buffer =(char*) malloc(sizeof(char) * new_length);

    // length of a wrapper of the original string
    total_rest_length = new_length - str_length;

    // write a prefix to buffer
    i = 0;
    while (i < (total_rest_length / 2)) {
        buffer[i] = placeholder;
        ++i;
    }
    buffer[i + 1] = '\0';

    // write the original string
    strcat(buffer, str);

    // write a postfix to the buffer
   i += str_length;
    while (i < new_length) {
        buffer[i] = placeholder;
        ++i;
    }
    buffer[i + 1] = '\0';

    return buffer;
}


