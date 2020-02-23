//---------------------------------------------------------------------------

#ifndef CompositeBeamBuilderH
#define CompositeBeamBuilderH
#include "String_doubleUnit.h"
#include "GeometryUnit.h"
#include "LoadsUnit.h"
#include "SteelPart.h"
#include "ConcretePartUnit.h"
#include "CompositeSection.h"
//---------------------------------------------------------------------------
//Класс ответственный за создание отдельных объектов из которых формируется
//объект композитная балка
//---------------------------------------------------------------------------
class CompositeBeamBuilder{
private:
   //	TGeometry* geometry_;
   //	Loads loads_;
   //	SteelPart steel_part_;
	//ConcretePart concrete_part_;
public:
	TGeometry BuildGeometry(bool end_beam, String span_cptn, String span_txt,
						String trib_width_left_cptn, String trib_width_left_txt,
						 String trib_width_right_cptn, String trib_width_right_txt,
						 String number_propping_supports)
	{
	double span=0.0;
	double trib_width_left=0.0;
	double trib_width_right=0.0;
	int rc=0; //rc- return code -код ошибки
	//rc=String_double_plus(span_cptn, span_txt, &span);
	//if (rc>0) return 0;
	rc=String_double_plus(trib_width_left_cptn, trib_width_left_txt, &trib_width_left);
	//if (rc>0) return 0;
	rc=String_double_plus(trib_width_right_cptn, trib_width_right_txt, &trib_width_right);
	//if (rc>0) return 0;//какое значение возвращает return без следующего за ним значения
	return TGeometry();//TGeometry(end_beam, span, trib_width_left, trib_width_right,2);
	}
	TLoads BuildLoads(String dead_load_first_stage_cpt, String dead_load_first_stage_txt,
					 String dead_load_second_stage_cpt, String dead_load_second_stage_txt,
					 String live_load_cpt, String live_load_txt,
					 String gamma_f_DL_I_cpt, String gamma_f_DL_I_txt,
					 String gamma_f_DL_II_cpt, String gamma_f_DL_II_txt,
					 String gamma_f_LL_cpt, String gamma_f_LL_txt)
	{
//	int rc=0; //rc- return code -код ошибки
//	double SW=1.0;//необходимо получать по типу профиля
//	double DL_I=0.0;
//	double DL_II=0.0;
//	double LL=0.0;
//	double gamma_f_SW=1.0;//необходимо предусмотреть поле для ввода
//	double gamma_f_DL_I=0.0;
//	double gamma_f_DL_II=0.0;
//	double gamma_f_LL=0.0;
//
//	rc=String_double_plus(dead_load_first_stage_cpt, dead_load_first_stage_txt, &DL_I);
//	//if (rc>0) return;
//	rc=String_double_plus(dead_load_second_stage_cpt, dead_load_second_stage_txt, &DL_II);
//	//if (rc>0) return;
//	rc=String_double_plus(live_load_cpt, live_load_txt, &LL);
//	//if (rc>0) return;
//	rc=String_double_plus(gamma_f_DL_I_cpt, gamma_f_DL_I_txt, &gamma_f_DL_I);
//	//if (rc>0) return;
//	rc=String_double_plus(gamma_f_DL_II_cpt, gamma_f_DL_II_txt, &gamma_f_DL_II);
//	//if (rc>0) return;
//	rc=String_double_plus(gamma_f_LL_cpt, gamma_f_LL_txt, &gamma_f_LL);
//	//if (rc>0) return;
//
//	return TLoads (SW, DL_I, DL_II, LL, gamma_f_SW, gamma_f_DL_I, gamma_f_DL_II, gamma_f_LL);
	}

	CompositeSection BuildCompositeSection(SteelPart    steel_part,
										   TConcretePart* concrete_part)//Почему компилятор требует указатель для абстрактного типа?
	{                                                                   //Разве для параметров необходимо создать объекты?

	}


};
#endif
