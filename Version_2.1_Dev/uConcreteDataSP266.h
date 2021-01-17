//---------------------------------------------------------------------------
#ifndef uConcreteDataSP266H
#define uConcreteDataSP266H

#include <string>
#include <vector>
#include <map>

namespace ConcreteDataSP266{
	std::vector<std::string> grades();
	std::string description(unsigned int index);
	std::map<std::string, double> properties(unsigned int index);
}
//---------------------------------------------------------------------------
#endif
