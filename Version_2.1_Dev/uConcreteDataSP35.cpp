//---------------------------------------------------------------------------

#pragma hdrstop

#include "uConcreteDataSP35.h"
#include <sstream>
//---------------------------------------------------------------------------
#pragma package(smart_init)

namespace{
		 //Марка, E_b, R_b, R_bt, c_n
	std::vector<std::string> descs{
		"B20   27000 15.0 1.35 115e-6",
		"B22.5 28500 15.0 1.35 107e-6",
		"B25   30000 18.5 1.55 100e-6",
		"B27.5 31500 18.5 1.55 92e-6",
		"B30   32500 22.1 1.75 84e-6",
		"B35   34500 25.5 1.95 75e-6",
		"B40   36000 29.0 2.10 67e-6",
		"B45   37500 32.0 2.25 55e-6",
		"B50   39000 36.0 2.45 50e-6",
		"B55   39500 36.0 2.60 41e-6",
		"B60   40000 39.5 2.75 39e-6"};
}
namespace ConcreteDataSP35{
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

		std::istringstream iss {ConcreteDataSP35::description(index)};

		iss >> bin >> prop["E_b"] >> prop["R_b"] >> prop["R_bt"] >> prop["c_n"];

		return prop;
	}
}

