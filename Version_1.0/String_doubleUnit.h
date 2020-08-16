//---------------------------------------------------------------------------

#ifndef String_doubleUnitH
#define String_doubleUnitH
#include <vcl.h>

#define opNULL              ' '
#define opPLUS              '+'
#define opMINUS             '-'
#define opMULT              '*'
#define opDIVIDE            '/'
#define N_MEMBER  100  // число членов в выражении
#define MAX_NUM 1000

int String_double(AnsiString field,AnsiString string, double * number);
int String_double_plus(AnsiString field, AnsiString string, double * number);
int String_double_zero_plus(AnsiString field, AnsiString string, double * number);
int String_double_plus_low(AnsiString field, AnsiString string, double value, double * number);
int String_double_zero_plus_low(AnsiString field, AnsiString string, double value, double * number);
int StringInt_plus_low(AnsiString field, AnsiString string, int value, int *number);
int String_double_minus(AnsiString field, AnsiString string, double *number);

double str_exp(char *string, int *rc);
int wordsn(char *s1, char *s2, char **ad);


//---------------------------------------------------------------------------
#endif
