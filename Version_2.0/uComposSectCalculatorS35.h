////---------------------------------------------------------------------------
//
//#ifndef uComposSectCalculatorS35H
//#define uComposSectCalculatorS35H
//
//#include <vector>
//#include <string>
//
//#include "uComposSectGeomSP35.h"
//#include "uWorkingConditionsFactors.h"
//#include "uComposSectOutputSP35.h"
//#include "uComBeamOutputSP35.h"
//#include "uIntForcesCalculator.h"
//#include "uGlobGeom.h"
//#include "uPlastCoeff.h"
//
//#include "uComBeamInputSP35.h"
//
//#include "uFrmLogger.h"
//
////---------------------------------------------------------------------------
//enum class DesignCase{
//	Case_A,
//	Case_B,
//	Case_C,
//	Case_F // случай, когда в бетоне растяжение
//};
////---------------------------------------------------------------------------
//enum class Flange{
//	upper,
//	lower,
//};
//
//enum class ShrinkStressIn{
//	concrete,
//	rebar,
//};
////---------------------------------------------------------------------------
//enum class CreepStressIn{
//	concrete,
//	rebar,
//};
////---------------------------------------------------------------------------
//class ComposSectCalculatorSP35{
//
//public:
//	ComposSectCalculatorSP35(ComBeamInputSP35 const & input);
//	ComBeamOutputSP35 calculate(std::vector<Node> const & nodes_lst);
//
//private:
//
//	IntForcesCalculator const intr_frcs_calculator_;
//	WorkingConditionsFactors const work_cond_factors_;
//	ComposSectGeomSP35 const com_sect_;
//	ComposSectGeomSP35 const com_sect_shr_;
//	ComposSectGeomSP35 const com_sect_kr_;
//
//	DesignCase design_case(double sigma_b, double sigma_r);
//	ComposSectOutputSP35 calculate(Node const node);
//	double creep_stress(double const M, CreepStressIn const cr_str_in)const;
//	double shrink_stress(ShrinkStressIn const shr_str_in) const;
//	double shrink_stress(double const E, double const R, double const nu)const;
//};
//
////---------------------------------------------------------------------------
//#endif
