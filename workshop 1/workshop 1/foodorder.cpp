#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include "FoodOrder.h"
#include <string>
using namespace std;
double g_taxrate = 0.0;
double g_dailydiscount = 0.0;
namespace sdds
{
	FoodOrder::FoodOrder(const FoodOrder& F)
	{
		operator=(F);
	}
	FoodOrder& FoodOrder::operator=(const FoodOrder& F)
	{
		if (this != &F)
		{
			strcpy(m_name, F.m_name);
			delete[] m_description;
			m_description = alcpy(F.m_description);
			m_price = F.m_price;
			m_special = F.m_special;
		}
		return *this;
	}
	FoodOrder::~FoodOrder()
	{
		delete[] m_description;
	}
	std::istream& FoodOrder::read(std::istream& istr)
    {
		if (istr.good()) {
			string des;
			istr.getline(m_name,10, ',');
			getline(istr, des, ',');
			delete[] m_description;
			m_description = alcpy(des.c_str());
			istr >> m_price;
			istr.ignore();
			if (istr.peek() == 'Y')
			{
				m_special = true;
			}
			else
			{
				m_special = false;
			}
			istr.ignore(1000, '\n');
		}
		return istr;
    }
    std::ostream& FoodOrder::display(std::ostream& ostr)const
    {
		static int counter = 0;
		if (this->m_name) {
			
			ostr.setf(ios::fixed);
			ostr.width(2);
			ostr << left <<++counter << ". ";
			ostr.unsetf(ios::fixed);
			ostr.setf(ios::fixed);
			ostr.width(10);
			ostr << left << m_name << "|";
			ostr.unsetf(ios::fixed);
			ostr.setf(ios::fixed);
			ostr.width(25);
			ostr << left << m_description << "|";
			ostr.unsetf(ios::fixed);
			ostr.setf(ios::fixed);
			ostr.width(12);
			ostr.precision(2);
			ostr << left << (m_price * (1.0 + g_taxrate)) << '|';
			ostr.unsetf(ios::fixed);
			if (m_special)
			{
				ostr.setf(ios::fixed);
				ostr.precision(2);
				ostr << (m_price * (1.0 + g_taxrate) - g_dailydiscount);
				ostr.unsetf(ios::fixed);
			}
			ostr << endl;
		}
		else {
			ostr.setf(ios::left);
			ostr.width(2);
			ostr << ++counter << ". " << "No Order" << endl;
			ostr.unsetf(ios::left);
		}
		return ostr;
    }

	/*used this function from our previous semester OOP244 notes provided by my professor : https://github.com/Seneca-244200/Fardad-s-Notes-Archive/blob/master/2221/NAA/18-Mar30/Utils.cpp */ 
	char* alcpy(const char* cstr)
	{
		char* newStr{};
		if (cstr) {
			newStr = new char[strlen(cstr) + 1];
			strcpy(newStr, cstr);
		}
		return newStr;
	}
}