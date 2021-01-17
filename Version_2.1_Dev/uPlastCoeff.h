//---------------------------------------------------------------------------

#ifndef uPlastCoeffH
#define uPlastCoeffH

#include <map>
#include "uWord_Automation.h"

enum class PlastCoeff{
	Omega,
	Eta_uf,
	Eta_lf,
	Omega_3_uf,
    Omega_3_lf,
	Omega_4,
};

class PlastCoeffList{
public:
   PlastCoeffList(std::map<PlastCoeff const, double const> const &);
   void print(TWord_Automation &)const;
private:
	std::map<PlastCoeff const, double const> const pl_coeff_;
};
//---------------------------------------------------------------------------
#endif
