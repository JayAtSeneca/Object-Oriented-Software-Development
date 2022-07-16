#include <iostream>
#include <iomanip>
#include "Station.h"
#include "Utilities.h"
using namespace std;
namespace sdds {
	size_t Station::m_widthField{ 0 };
	size_t Station::id_generator{ 0 };
	Station::Station(const std::string& record)
	{
		Utilities ut;
		if (record != "") {
			size_t next_pos = 0u;
			bool more = true;
			m_id = ++id_generator;
			m_name = ut.extractToken(record, next_pos, more);
			m_serialNum = std::stoi(ut.extractToken(record, next_pos, more));
			m_stockNum = std::stoi(ut.extractToken(record, next_pos, more));
			if (m_widthField < ut.getFieldWidth()) {
				m_widthField = ut.getFieldWidth();
			}
			m_description = ut.extractToken(record,next_pos,more);
		}
	}
	const std::string& Station::getItemName() const
	{
		return m_name;
	}
	size_t Station::getNextSerialNumber()
	{
		return m_serialNum++;
	}
	size_t Station::getQuantity() const
	{
		return m_stockNum;
	}
	void Station::updateQuantity()
	{
		if (m_stockNum > 0) {
			m_stockNum--;
		}
	}
	void Station::display(std::ostream& os, bool full) const
	{
		os << std::setw(3) << std::setfill('0') << std::right << m_id << " | ";
		os << std::setw(m_widthField + 1) << std::setfill(' ') << std::left << m_name << " | ";
		os << std::setw(6) << std::setfill('0') << std::right << m_serialNum << " | ";

		if (full)
		{
			os << std::setfill(' ') << std::right << std::setw(4) << m_stockNum << " | ";
			os << m_description;
		}
		os << std::endl;
	}
}