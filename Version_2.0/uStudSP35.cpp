//---------------------------------------------------------------------------

#pragma hdrstop
#include <algorithm>
#include "uStudSP35.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

StudSP35::StudSP35(std::u16string const & name, double d_1, double l_1, double R_y,
	double R_b, double m):
		name_(name), d_1_(d_1), l_1_(l_1), R_y_(R_y)
{
	if ((2.5 < l_1_ / d_1_) && (l_1_ /d_1_ <= 4.2)) //�������� �� �������, ����� ��������� l_/d_1_ ������ 2.5. ���� �� ������� ����������?
		P_Rd_ = 0.24 * l_1_ /10 * d_1_/10 * std::pow(10 * R_b , 0.5) * 1000; //1000 ������� � �, ��� ��� � �� ��
	else
		P_Rd_ = d_1_/10 * d_1_/10 * std::pow(10 * R_b, 0.5) * 1000;

   P_Rd_ = std::min(P_Rd_, 0.063 * d_1_/10 * d_1_/10 * m * R_y_ *1000);
}

