//---------------------------------------------------------------------------


#pragma hdrstop

#include "String_doubleUnit.h"
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

static  String text, header;

//---------------------------------------------------------------------------
// Чтение из поля string0 произвольного числа double *number. Поле field содержит название поля string0
// вовращаемое значение 0 либо 1 (ошибка)
int String_double(AnsiString field, AnsiString string0, double *number) {
  char *endptr;
  AnsiString  string;
  int i, j, rc;

  string = string0;
  for (i=0, j=0; i < string.Length(); i++) {
     if (string.c_str()[i]==',')
         string.c_str()[i]='.';
     if  (string.c_str()[i]!=' ') {
         string.c_str()[j]=string.c_str()[i];
         //str[j]=string.c_str()[i];
         j++;
     }
  }
  if (j<string.Length())
     string.c_str()[j]='\0';

  *number=str_exp(string.c_str(), &rc);
  //*number=strtod(string.c_str(), &endptr);
  //if (*endptr!=NULL && endptr[0]!=' ' ) {
  if (rc!=0) {
       text="Строка (" +string + ") не может быть преобразована в число";
       header="Недопустимое числовое значение в поле \"" + field + "\"";

	   i=Application->MessageBox(text.c_str(),
                  header.c_str(),
                  MB_OK | MB_ICONERROR);

       return 1;
  }

  return 0;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
// Чтение из поля string0 числа > 0. Поле field содержит название поля string0
// вовращаемое значение 0 либо 1 (ошибка)
int String_double_plus(AnsiString field, AnsiString string, double *number) {
  char *endptr;
  int i,rc;
  //AnsiString dubl_string;

  //dubl_string = string;

  rc=String_double(field, string, number);
  if (rc>0) return rc;
  if (*number<=1e-6 ) {
       text="Заданное значение (" +string + ") выходит за рамки допустимого диапазона (+1e-6 : +1e16)";
       header="Недопустимое числовое значение в поле \"" + field + "\"";

       i=Application->MessageBox(text.c_str(),
                  header.c_str(),
                  MB_OK | MB_ICONERROR);
       //string = dubl_string;

      // ErrorMessage("Заданное значение (" +string + ") выходит за рамки допустимого диапазона (+1e-6 : +1e16)");
      return 1;
  }

  return 0;
}
//---------------------------------------------------------------------------
// Чтение из поля string0 числа >1e-6 и <=value. Поле field содержит название поля string0
// вовращаемое значение 0 либо 1 (ошибка)
int String_double_plus_low(AnsiString field, AnsiString string, double value, double *number) {
  char *endptr;
  int i,rc;
  //AnsiString dubl_string;

  //dubl_string = string;

  rc=String_double(field, string, number);
  if (rc>0) return rc;
  if (*number<=1e-6 || *number>value) {
       text="Заданное значение (" +string + ") выходит за рамки допустимого диапазона (+1e-6 : "+FloatToStrF(value,ffFixed,15,2)+")";
       header="Недопустимое числовое значение в поле \"" + field + "\"";

       i=Application->MessageBox(text.c_str(),
                  header.c_str(),
                  MB_OK | MB_ICONERROR);
       //string = dubl_string;

      return 1;
  }

  return 0;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
// Чтение из поля string0 целого числа >0 и <=value. Поле field содержит название поля string0
// вовращаемое значение 0 либо 1 (ошибка)
int StringInt_plus_low(AnsiString field, AnsiString string, int value, int *number) {

  char *num_str[MAX_NUM];
  char *str_end[MAX_NUM];
  char str_p[MAX_NUM];
  char *str_q;
  double p_, q_;
  char  stroka[256];
  int i, j, k, n, pp, rc;

  strcpy(stroka, string.c_str());
  k = wordsn(stroka, ",",  num_str);

  j = 0;
  for (i=0; i<k; i++) {
    strcpy(str_p, num_str[i]);
    n = wordsn(num_str[i], "-",  str_end);
    if (n>2) {
       text="Неправильное выражение " +AnsiString(str_p);
       header=" ";
       i=Application->MessageBox(text.c_str(),
                  header.c_str(),
                  MB_OK | MB_ICONERROR);
       return 1;
    }
    rc = String_double_plus_low(field, AnsiString(str_end[0]), double(value), &p_);
    if (rc>0) return rc;
    q_ = p_;
    if (n==2) {
      rc = String_double_plus_low(field, AnsiString(str_end[1]), double(value), &q_);
      if (rc>0) return rc;
    }
    if (p_ > q_) {
       pp = p_;
       p_ = q_;
       q_ = pp;

    }
    for ( ;p_<=q_ ; p_++) {
       if (j >= MAX_NUM-2) {
		 i=Application->MessageBox(String("Количество заданных значений превышает допустимое ("+IntToStr(MAX_NUM-1)+")").c_str(),
				  L"", MB_OK | MB_ICONERROR);
         return 1;
       }
       number[j]=p_;
       j++;
    }
  }
  number[j] = -1;
  return 0;
}
//---------------------------------------------------------------------------
// Чтение из поля string0 числа >=0 и <=value. Поле field содержит название поля string0
// вовращаемое значение 0 либо 1 (ошибка)
//---------------------------------------------------------------------------
int String_double_zero_plus_low(AnsiString field, AnsiString string, double value, double *number) {
  char *endptr;
  int i,rc;
  //AnsiString dubl_string;

  //dubl_string = string;

  rc=String_double(field, string, number);
  if (rc>0) return rc;
  if (*number<0 || *number>value) {
       text="Заданное значение (" +string + ") выходит за рамки допустимого диапазона (0 : "+FloatToStrF(value,ffFixed,15,2)+")";
       header="Недопустимое числовое значение в поле \"" + field + "\"";

       i=Application->MessageBox(text.c_str(),
                  header.c_str(),
                  MB_OK | MB_ICONERROR);
       //string = dubl_string;

      return 1;
  }

  return 0;
}
//---------------------------------------------------------------------------
// Чтение из поля string0 числа >=0. Поле field содержит название поля string0
// вовращаемое значение 0 либо 1 (ошибка)
int String_double_zero_plus(AnsiString field, AnsiString string, double *number) {
  char *endptr;
  int rc;

  rc=String_double(field, string, number);
  if (rc>0) return rc;
  if (*number<0 ) {
       text="Заданное значение (" +string + ") выходит за рамки допустимого диапазона (0 : +1e16)";
       header="Недопустимое числовое значение в поле \"" + field + "\"";

       rc=Application->MessageBox(text.c_str(),
                  header.c_str(),
                  MB_OK | MB_ICONERROR);

       // ErrorMessage("Заданное значение (" +string + ") выходит за рамки допустимого диапазона (0 : +1e16)");
       return 1;
  }

  return 0;
}
//-------------------------------------------------------------------------------------
//  чтение выражения
double str_exp(char *str, int *rc) {
  int len, i, j, n;
  bool mult, exp;
  char *endptr;
  int i_left;
  char str_left[48];
  double member_0[N_MEMBER];
  char operand_0[N_MEMBER];
  double member_1[N_MEMBER];
  char operand_1[N_MEMBER];
  int n_memb;

  len=strlen(str);

  n_memb=0;
  exp=false;
  i_left=0;
  operand_0[0]=opNULL;
  for (i=0; i<len; i++) {
     if (i_left==N_MEMBER) {
       text="Выражение (" +AnsiString(str) + ") слишком длинное ";
       header=" ";
       i=Application->MessageBox(text.c_str(),
                  header.c_str(),
                  MB_OK | MB_ICONERROR);
       return 1;
     }
        switch (str[i]) {
          case ' ':
          break;
          case '0': case '1': case '2': case '3': case '4':
          case '5': case '6': case '7': case '8': case '9':
          case 'E': case 'e': case '.':
            str_left[i_left] = str[i];
            if (str[i]=='E' || str[i]=='e') exp=true;
            i_left++;
          break;
          case '-': case '+':
          case '*': case '/':
          if (exp) {
            str_left[i_left] = str[i];
            exp=false;
            i_left++;
          }
          else {
             str_left[i_left]='\0';
             member_0[n_memb]=strtod(str_left, &endptr);
             if (*endptr!=NULL && endptr[0]!=' ') {
                *rc=1;
                return 0.0;
             }
             i_left=0;
             operand_0[n_memb]=str[i];
             n_memb++;
          }
          break;
          default:
            *rc=1;
            return 0.0;
        }
  }

  str_left[i_left]='\0';
  member_0[n_memb]=strtod(str_left, &endptr);
  if (*endptr!=NULL && endptr[0]!=' ') {
       *rc=1;
       return 0.0;
  }
  n_memb++;
  mult=false;  // флаг мультипликативной операции

  for (i=0,j=0; i<n_memb-1; i++) {
    switch (operand_0[i]) {
     case opMULT:
       if (!mult)
         member_1[j] = member_0[i]*member_0[i+1];
       else
         member_1[j] = member_1[j]*member_0[i+1];
       mult=true;
       break;
     case opDIVIDE:
       if (member_0[i+1]==0.0) {
          *rc=1;
          return 0.0;
       }
       if (!mult)
         member_1[j] = member_0[i]/member_0[i+1];
       else
         member_1[j] = member_1[j]/member_0[i+1];
       mult=true;
       break;
     case opNULL:
     case opPLUS:
     case opMINUS:
        if (mult) {
          operand_1[j]=operand_0[i];
          mult=false;
        }
        else {
          member_1[j]=member_0[i];
          operand_1[j]=operand_0[i];
        }
        j++;
    }
  }
  if (!mult) {
    member_1[j]=member_0[n_memb-1];
  }
  j++;
  n_memb=j;
  for (i=0; i<n_memb-1; i++) {
    switch (operand_1[i]) {
     case opPLUS:
       member_1[0] += member_1[i+1];
       break;
     case opMINUS:
       member_1[0] -= member_1[i+1];
     case opNULL:
     ;
    }
  }
  *rc=0;
  return member_1[0];
}
//---------------------------------------------------------------------------
int String_double_minus(AnsiString field, AnsiString string, double *number) {
  char *endptr;
  int i,rc;

  rc=String_double(field, string, number);
  if (rc>0) return rc;
  if (*number >= -1e-6 ) {
       text="Заданное значение (" +string + ") выходит за рамки допустимого диапазона (-1e16 : -1e-6)";
       header="Недопустимое числовое значение в поле \"" + field + "\"";

	   i=Application->MessageBox(text.c_str(),
                  header.c_str(),
                  MB_OK | MB_ICONERROR);
	  return 1;
  }

  return 0;
}
//------------------------------------------------------------------------
//  определение числа слов в строке,
//  определение адресов начала слов,
//  при этом разделители в исходной строке заменяются на \0
int wordsn(char *s1, char* s2, char **ad)
//  char *s1;     /*   строка , в которой выделяются слова и заменяются разде*/
//  char *s2;     /*   строка, содержащая разделители       */
//  char **ad;    /*   адреса начала слов                     */
  {
     int n;
	n=0;
	ad[0]=strtok(s1,s2);
	while (ad[n]!= NULL) {
             if (n == 100) break;
	     ad[++n]=strtok(NULL,s2);
        }
	     //   строка s1  при этом нарезается \0
	return(n);
  }  /* wordsn*/


