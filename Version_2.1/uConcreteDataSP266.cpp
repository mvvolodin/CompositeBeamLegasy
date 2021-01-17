//---------------------------------------------------------------------------

#pragma hdrstop

#include "uConcreteDataSP266.h"
#include <sstream>
//---------------------------------------------------------------------------
#pragma package(smart_init)

namespace{
		//Марка, E_b, R_bn, R_btn
	std::vector<std::string> descs{
		"B10   19000 7.5  0.85",
		"B12.5 21500 9.5  1   ",
		"B15   24000 11   1.1 ",
		"B20   27500 15   1.35",
		"B25   30000 18.5 1.55",
		"B30   32500 22   1.75",
		"B35   34500 25.5 1.95",
		"B40   36000 29   2.1 ",
		"B45   37000 32   2.25",
		"B50   38000 36   2.45",
		"B55   39000 36   2.6 ",
		"B60   39500 39.5 2.75"};
}
namespace ConcreteDataSP266{
	std::vector<std::string> grades()
	{
		std::vector<std::string> res;

		for(auto const & d:descs){
			auto const found = d.find_first_of(' ');
			res.emplace_back(d.c_str(), found);
		}

		return res;
	}
	std::string description(unsigned int index)
	{
		return descs[index];
	}
	std::map<std::string, double> properties(unsigned int index)
	{
		std::string bin;
		std::map<std::string, double> prop;

		std::istringstream iss {ConcreteDataSP266::description(index)};

		iss >> bin >> prop["E_b"] >> prop["R_bn"] >> prop["R_btn"];

		return prop;
	}
}

