//---------------------------------------------------------------------------

#pragma hdrstop

#include "InternalForces.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
InternalForces::InternalForces()
{
}
InternalForces::InternalForces(double p, CS_Coordinates cs_coordinates, int temporary_supports_number)
{
   //	cs_number_=cs_coordinates.size();
	switch (temporary_supports_number) //как-то некрасиво!!!!!
	{
		case 0:
			R_calc_simple_beam(p, cs_coordinates.back());
			M_calc_simple_beam(p, cs_coordinates, temporary_supports_number);
			Q_calc_simple_beam(p, cs_coordinates, temporary_supports_number);
			break;
		case 1:
			R_calc_two_span_beam(p, cs_coordinates.back());
			M_calc_two_span_beam(p, cs_coordinates, temporary_supports_number);
			Q_calc_two_span_beam(p, cs_coordinates, temporary_supports_number);
			break ;
	}
}
void InternalForces::R_calc_simple_beam(double p, double l)
{
	R_.push_back(p*(l/2));
	R_.push_back(p*(l/2));
}
void InternalForces::R_calc_two_span_beam(double p, double l)
{
	R_.push_back(0.375*p*(l/2));
	R_.push_back(1.25*p*(l/2));
	R_.push_back(0.375*p*(l/2));
}
void InternalForces::M_calc_simple_beam(double p, CS_Coordinates cs_coordinates, int temporary_supports_number)
{
	double temp_M=0.0;
	double l=cs_coordinates.back();

	double A=0.5*p*l;

	for (int n = 0; n < cs_coordinates.size(); ++n)
	{
		double temp_l=cs_coordinates[n];
		temp_M=A*cs_coordinates[n]-p*temp_l*temp_l/2;
		M_.push_back(temp_M);
	}
}
void InternalForces::Q_calc_simple_beam(double p, CS_Coordinates cs_coordinates, int temporary_supports_number)
{
	double temp_Q=0.0;
	double l=cs_coordinates.back();

	double A=0.5*p*l;

	for (int n = 0; n < cs_coordinates.size(); ++n)
	{
		double temp_l=cs_coordinates[n];
		temp_Q=A-p*temp_l;
		Q_.push_back(temp_Q);
	}
}
void InternalForces::M_calc_two_span_beam(double p, CS_Coordinates cs_coordinates, int temporary_supports_number)//балки равнопролётные
{
	// Расчёт реакций Уманский I том глава 8.1.7
	double temp_M=0.0;
	double l=cs_coordinates.back();

	double A=0.375*p*l/2.0;
	double B=1.25*p*l/2.0;

	for (int n = 0; n< cs_coordinates.size(); ++n)
	{
		double temp_l=cs_coordinates[n];

		if (cs_coordinates[n]<=l/2)
		{ //здесь двойка это количество пролётов. Необходимо применить enum

			temp_M=A*temp_l-p*temp_l*temp_l/2;
		}
		else
		{
			temp_M=A*temp_l-p*temp_l*temp_l/2+B*(temp_l-l/2);
		}
		M_.push_back(temp_M);
	}
}
void InternalForces::Q_calc_two_span_beam(double p, CS_Coordinates cs_coordinates, int temporary_supports_number)//балки равнопролётные
{
	// Расчёт реакций Уманский I том глава 8.1.7
	double temp_Q=0.0;
	double l=cs_coordinates.back();

	double A=0.375*p*l/2.0;
	double B=1.25*p*l/2.0;

	for (int n = 0; n <= cs_coordinates.size(); ++n)
	{ //определение поперечных сил
		double temp_l=cs_coordinates[n];

		if (cs_coordinates[n]<=l/2)
			{  //здесь двойка это количество пролётов. Необходимо применить enum
				temp_Q=A-p*temp_l;
			}
		else
			{
				temp_Q=A-p*temp_l;
			}
		Q_.push_back(temp_Q);
	}
}
