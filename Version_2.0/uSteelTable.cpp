//---------------------------------------------------------------------------

#pragma hdrstop

#include "uSteelTable.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
SteelTableRow::SteelTableRow(std::u16string grade, std::map<std::pair<double,double>, SteelData> ranges):
								grade_(grade),
								ranges_(ranges){}
SteelData const & SteelTableRow::operator()(double thick)const
{
	auto iter = std::find_if(ranges_.cbegin(), ranges_.cend(),
		[thick](auto const & range){return thick > range.first.first &&  thick <= range.first.second;});

	if (iter == ranges_.end())
		throw std::u16string {u"Для заданной толщины стали свойства в стандарте не определены!"};
	return iter -> second;
}
std::u16string const & SteelTableRow::grade() const
{
	return grade_;
}
std::map<std::pair<double,double>, SteelData> const & SteelTableRow::ranges()const
{
	return ranges_;
}
//---------------------------------------------------------------------------
SteelTable::SteelTable(std::vector<SteelTableRow> const rows):
	rows_(rows){}
SteelTableRow const & SteelTable::operator[](int index)const
{
	return rows_[index];
}
SteelTableRow const & SteelTable::row(std::u16string const & grade)const
{
	return rows_[index(grade)];
}
std::vector<std::u16string> SteelTable::grades()const
{
	std::vector<std::u16string> grades;
	for(auto const & row:rows_)
		grades.emplace_back(row.grade());
	return grades;
}
int SteelTable::index(std::u16string const & grade)const
{
	std::vector<std::u16string> grades_lst = grades();

	auto iter = std::find(grades_lst.cbegin(), grades_lst.cend(), grade);

	if (iter == grades_lst.cend())
		throw std::u16string {u"Заданная марка стали в стандарте не определена! Обратите внимание, буквы в марке стали должны вводиться кириллицей!"};
	return std::distance(grades_lst.cbegin(), iter);
}
