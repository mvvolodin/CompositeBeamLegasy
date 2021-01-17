//---------------------------------------------------------------------------
#ifndef uSteelTableH
#define uSteelTableH
//---------------------------------------------------------------------------
#include <map>
#include <vector>
#include <string>
#include <algorithm>
//---------------------------------------------------------------------------
struct SteelData{
	double R_yn_;
	double R_un_;
};
//---------------------------------------------------------------------------
class SteelTableRow{
public:
   SteelTableRow(std::u16string grade, std::map<std::pair<double,double>, SteelData> ranges);
   SteelData const & operator()(double thick)const;
   std::u16string const & grade() const;
   std::map<std::pair<double,double>, SteelData> const & ranges()const;
private:
	std::u16string const grade_;
	std::map<std::pair<double,double>, SteelData> const ranges_;
};
//---------------------------------------------------------------------------
class SteelTable{
public:
	SteelTable(std::u16string const & title, std::vector<SteelTableRow> const & rows);
	SteelTableRow const & operator[](int index)const;
	SteelTableRow const & row(std::u16string const & grade)const;
	std::vector<std::u16string> grades()const;
    std::u16string const & title() const;
private:
	std::u16string const title_;
	std::vector<SteelTableRow> const rows_;
	int index(std::u16string const & grade)const;
};
//---------------------------------------------------------------------------
#endif
