//---------------------------------------------------------------------------

#pragma hdrstop

#include <algorithm>
#include "uCompositeBeam.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


CompositeBeam::CompositeBeam()
{
}
void CompositeBeam::initialize_section_list(double L, int temporary_supports_number)
{
	int num_temp_spans = temporary_supports_number + 1;
	/* TODO -oMV : Добавить определение max_elem_length_ через GUI */
	double max_elem_length = 500;

	int num_elements = 0.;

	num_elements = L / (num_temp_spans * max_elem_length) + 1;

	if(num_elements % 2 != 0) ++num_elements;

	num_elements = num_temp_spans * num_elements;

	std::vector<Section> sections_list;

	for (int n = 0; n <= num_elements; ++n)
		section_list_.push_back(Section{n, L / num_elements * n});

	initialize_support_list(L, temporary_supports_number);
}
void CompositeBeam::initialize_support_list(double L, int temporary_supports_number)
{
	int num_tmp_span = temporary_supports_number + 1;

	for(int n = 0; n <= num_tmp_span; ++n)
		support_list_.push_back(n * L / num_tmp_span);
}
void CompositeBeam::set_intr_frcs_calculator(InternalForcesCalculator& intr_frcs_calculator)
{
	intr_frcs_calculator_ = intr_frcs_calculator;
}
void CompositeBeam::set_composite_section(CompositeSectionGeometry& com_sect)
{
	com_sect_ = com_sect;
}
void CompositeBeam::set_working_conditions_factors(WorkingConditionsFactors& working_conditions_factors)
{
	working_conditions_factors_ = working_conditions_factors;
}
void CompositeBeam::calculate()
{
	for (auto& section:section_list_)
		section.calculate(intr_frcs_calculator_, working_conditions_factors_, com_sect_);
}

std::vector<double> CompositeBeam::get_M_Ia_design_list(LoadUnit load_unit, LengthUnit length_unit)const
{
	std::vector<double> M_Ia_design_list{};

	for (auto section:section_list_)
		M_Ia_design_list.push_back(section.get_M_Ia_design() / (static_cast<int>(load_unit)*static_cast<int>(length_unit)));

	M_Ia_design_list.shrink_to_fit();

	return M_Ia_design_list;
}
std::vector<double> CompositeBeam::get_M_Ib_design_list(LoadUnit load_unit, LengthUnit length_unit)const
{
	std::vector<double> M_Ib_design_list{};

	for (auto section:section_list_)
		M_Ib_design_list.push_back(section.get_M_Ib_design() / (static_cast<int>(load_unit)*static_cast<int>(length_unit)));

	M_Ib_design_list.shrink_to_fit();

	return M_Ib_design_list;
}
std::vector<double> CompositeBeam::get_M_IIa_design_list(LoadUnit load_unit, LengthUnit length_unit)const
{
	std::vector<double> M_IIa_design_list{};

	for (auto section:section_list_)
		M_IIa_design_list.push_back(section.get_M_IIa_design() / (static_cast<int>(load_unit)*static_cast<int>(length_unit)));

	M_IIa_design_list.shrink_to_fit();

	return M_IIa_design_list;
}
std::vector<double> CompositeBeam::get_M_IIb_design_list(LoadUnit load_unit, LengthUnit length_unit)const
{
	std::vector<double> M_IIb_design_list{};

	for (auto section:section_list_)
		M_IIb_design_list.push_back(section.get_M_IIb_design() / (static_cast<int>(load_unit)*static_cast<int>(length_unit)));

	M_IIb_design_list.shrink_to_fit();

	return M_IIb_design_list;
}
std::vector<double> CompositeBeam::get_M_total_design_list(LoadUnit load_unit, LengthUnit length_unit)const
{
	std::vector<double> M_total_design_list{};

	for (auto section:section_list_)
		M_total_design_list.push_back(section.get_M_total_design() / (static_cast<int>(load_unit)*static_cast<int>(length_unit)));

	M_total_design_list.shrink_to_fit();

	return M_total_design_list;
}
std::vector<double> CompositeBeam::get_Q_Ia_design_list(LoadUnit load_unit)const
{
	std::vector<double> Q_Ia_design_list{};

	for (auto section:section_list_)
		Q_Ia_design_list.push_back(section.get_Q_Ia_design() / (static_cast<int>(load_unit)));

	Q_Ia_design_list.shrink_to_fit();

	return Q_Ia_design_list;
}
std::vector<double> CompositeBeam::get_Q_Ib_design_list(LoadUnit load_unit)const
{
	std::vector<double> Q_Ib_design_list{};

	for (auto section:section_list_)
		Q_Ib_design_list.push_back(section.get_Q_Ib_design() / (static_cast<int>(load_unit)));

	Q_Ib_design_list.shrink_to_fit();

	return Q_Ib_design_list;
}
std::vector<double> CompositeBeam::get_Q_IIa_design_list(LoadUnit load_unit)const
{
	std::vector<double> Q_II_design_list{};

	for (auto section:section_list_)
		Q_II_design_list.push_back(section.get_Q_IIa_design() / static_cast<int>(load_unit));

	Q_II_design_list.shrink_to_fit();

	return Q_II_design_list;
}
std::vector<double> CompositeBeam::get_Q_IIb_design_list(LoadUnit load_unit)const
{
	std::vector<double> Q_II_design_list{};

	for (auto section:section_list_)
		Q_II_design_list.push_back(section.get_Q_IIb_design() / static_cast<int>(load_unit));

	Q_II_design_list.shrink_to_fit();

	return Q_II_design_list;
}
std::vector<double> CompositeBeam::get_Q_total_design_list(LoadUnit load_unit)const
{
	std::vector<double> Q_total_design_list{};

	for (auto section:section_list_)
		Q_total_design_list.push_back(section.get_Q_total_design() / static_cast<int>(load_unit));

	Q_total_design_list.shrink_to_fit();

	return Q_total_design_list;
}
const Section& CompositeBeam::get_max_direct_stress_ratio_section()const
{
	auto it_max_ratio_section = std::max_element(section_list_.begin(), section_list_.end(),
		[](const Section& sect1, const Section& sect2)
		{return sect1.get_max_direct_stress_ratio() < sect2.get_max_direct_stress_ratio();});

	return *it_max_ratio_section;
}
const Section& CompositeBeam::get_max_shear_stress_ratio_section()const
{
	auto it_max_ratio_section = std::max_element(section_list_.begin(), section_list_.end(),
		[](const Section& sect1, const Section& sect2)
		{return sect1.get_shear_ratio() < sect2.get_shear_ratio();});

	return *it_max_ratio_section;
}
const Section& CompositeBeam::get_max_rigid_plastic_ratio_section()const
{
	auto it_max_ratio_section = std::max_element(section_list_.begin(), section_list_.end(),
		[](const Section& sect1, const Section& sect2)
		{return sect1.get_rigid_plastic_ratio() < sect2.get_rigid_plastic_ratio();});

	return *it_max_ratio_section;
}
std::vector<double> CompositeBeam::get_x_list()const
{
	std::vector<double> x_list;

	for (auto section:section_list_)
		x_list.push_back(section.get_x());

    return x_list;
}

std::vector<double> CompositeBeam::get_R_Ia_design_list(LoadUnit load_unit)const
{
	std::map<double, double> R_Ia_design_named_list = intr_frcs_calculator_.R_Ia_design();

	std::vector<double> R_Ia_design_list = make_R_list(R_Ia_design_named_list);

	std::transform(R_Ia_design_list.begin(), R_Ia_design_list.end(), R_Ia_design_list.begin(),[load_unit](double R) { return R / static_cast<int>(load_unit);});

	return R_Ia_design_list;
}
std::vector<double> CompositeBeam::get_R_Ib_design_list(LoadUnit load_unit)const
{
	std::map<double, double> R_Ib_design_named_list = intr_frcs_calculator_.R_Ib_design();

	std::vector<double> R_Ib_design_list = make_R_list(R_Ib_design_named_list);

	std::transform(R_Ib_design_list.begin(), R_Ib_design_list.end(), R_Ib_design_list.begin(),[load_unit](double R) { return R / static_cast<int>(load_unit);});

	return R_Ib_design_list;
}
std::vector<double> CompositeBeam::get_R_IIa_design_list(LoadUnit load_unit)const
{
	std::map<double, double> R_IIa_design_named_list = intr_frcs_calculator_.R_IIa_design();

	std::vector<double> R_IIa_design_list = make_R_list(R_IIa_design_named_list);

	std::transform(R_IIa_design_list.begin(), R_IIa_design_list.end(), R_IIa_design_list.begin(),[load_unit](double R) { return R / static_cast<int>(load_unit);});

	return R_IIa_design_list;
}
std::vector<double> CompositeBeam::get_R_IIb_design_list(LoadUnit load_unit)const
{
	std::map<double, double> R_IIb_design_named_list = intr_frcs_calculator_.R_IIb_design();

	std::vector<double> R_IIb_design_list = make_R_list(R_IIb_design_named_list);

	std::transform(R_IIb_design_list.begin(), R_IIb_design_list.end(), R_IIb_design_list.begin(),[load_unit](double R) { return R / static_cast<int>(load_unit);});

	return R_IIb_design_list;
}
std::vector<double> CompositeBeam::get_R_total_design_list(LoadUnit load_unit)const
{
	std::map<double, double> R_total_design_named_list = intr_frcs_calculator_.R_total_design();

	std::vector<double> R_total_design_list = make_R_list(R_total_design_named_list);

	std::transform(R_total_design_list.begin(), R_total_design_list.end(), R_total_design_list.begin(),[load_unit](double R) { return R / static_cast<int>(load_unit);});

	return R_total_design_list;
}
std::vector<double> CompositeBeam::get_P_IIa_design_list(LoadUnit load_unit)const
{
	std::map<double, double> PX_named_list = intr_frcs_calculator_.R_Ib_design();

	double L = section_list_.back().get_x();

	PX_named_list.at(0) = 0;
	PX_named_list.at(L) = 0;

	std::vector<double> PX_list = make_R_list(PX_named_list);

	std::transform(PX_list.begin(), PX_list.end(), PX_list.begin(),[load_unit](double R) { return -1 * R / static_cast<int>(load_unit);});

	return PX_list;
}

std::vector<double> CompositeBeam::make_R_list(std::map<double, double> R_LCC_list)const
{
	std::map<double, double> R_x_list{};

	for (auto section:section_list_)
		R_x_list.insert({section.get_x(), 0.});

	R_LCC_list.insert(R_x_list.begin(),R_x_list.end());

	std::vector<double> R_list{};

	for (auto R_Ia_design_x:R_LCC_list)
		R_list.push_back(R_Ia_design_x.second);

	return R_list;
}
std::vector<double> CompositeBeam::get_support_x_list()const
{
	return support_list_;
}
std::vector<double> CompositeBeam::get_f_Ia_design_list(LengthUnit length_unit)const
{
	std::vector<double> f_Ia_design_list{};

	double E_st_I_s = com_sect_.get_E_st_I_st();

	for (auto section:section_list_)
		f_Ia_design_list.push_back(section.get_f_Ia_design() / E_st_I_s / static_cast<int>(length_unit));

	f_Ia_design_list.shrink_to_fit();

	return f_Ia_design_list;
}
std::vector<double> CompositeBeam::get_f_Ib_design_list(LengthUnit length_unit)const
{
	std::vector<double> f_Ib_design_list{};

	double E_st_I_s = com_sect_.get_E_st_I_st();

	for (auto section:section_list_)
		f_Ib_design_list.push_back(section.get_f_Ib_design() / E_st_I_s / static_cast<int>(length_unit));

	f_Ib_design_list.shrink_to_fit();

	return f_Ib_design_list;
}
std::vector<double> CompositeBeam::get_f_IIa_design_list(LengthUnit length_unit)const
{
	std::vector<double> f_IIa_design_list{};

	double E_st_I_red = com_sect_.get_E_st_I_red();

	for (auto section:section_list_)
		f_IIa_design_list.push_back(section.get_f_IIa_design() / E_st_I_red / static_cast<int>(length_unit));

	f_IIa_design_list.shrink_to_fit();

	return f_IIa_design_list;
}

std::vector<double> CompositeBeam::get_f_IIb_design_list(LengthUnit length_unit)const
{
	std::vector<double> f_IIb_design_list{};

	double E_st_I_red = com_sect_.get_E_st_I_red();

	for (auto section:section_list_)
		f_IIb_design_list.push_back(section.get_f_IIb_design() / E_st_I_red / static_cast<int>(length_unit));

	f_IIb_design_list.shrink_to_fit();

	return f_IIb_design_list;
}
std::vector<double> CompositeBeam::get_f_total_design_list(LengthUnit length_unit)const
{
	std::vector<double> f_total_design_list{};

	double E_st_I_s = com_sect_.get_E_st_I_st();
	double E_st_I_red = com_sect_.get_E_st_I_red();

	for (auto section:section_list_)
		f_total_design_list.push_back(section.get_f_Ib_design() / E_st_I_s / static_cast<int>(length_unit) +
			section.get_f_IIa_design() / E_st_I_red / static_cast<int>(length_unit) +
			section.get_f_IIb_design() / E_st_I_red / static_cast<int>(length_unit));

	f_total_design_list.shrink_to_fit();

	return f_total_design_list;
}
