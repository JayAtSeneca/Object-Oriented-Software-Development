#include <iostream>
#include <fstream>
#include "ProteinDatabase.h"

namespace sdds {

	ProteinDatabase::ProteinDatabase() {}
	ProteinDatabase::ProteinDatabase(const char* fileName) {
		readFile(fileName);
	}

	unsigned int ProteinDatabase::size()const {
		return m_size;
	}

	std::string ProteinDatabase::operator[](unsigned int index)const {
		std::string str = (index < m_size) ? m_proteinArr[index] : "";
		return str;
	}


	void ProteinDatabase::readFile(const char* fileName) {
		std::ifstream ifstr(fileName);
		std::string temp;
		if (ifstr) {
			while (getline(ifstr, temp, '\n')) {
				if (temp[0] == '>') 
					m_size++;
			}

			if (m_size > 0) {
				ifstr.clear();
				ifstr.seekg(0);
				m_proteinArr = new std::string[m_size];
				
				int index = -1;
				while (getline(ifstr, temp, '\n')) {
					if (temp[0] == '>') {
						index++;
					}
					else {
						m_proteinArr[index] += temp;
					}
				}
			}
		}
	}

	void ProteinDatabase::safeEmpty() {
		delete[] m_proteinArr;
		m_proteinArr = nullptr;
		m_size = 0;
	}

	ProteinDatabase::ProteinDatabase(const ProteinDatabase& src) {
		*this = src;
	}

	ProteinDatabase& ProteinDatabase::operator=(const ProteinDatabase& src) {
		if (this != &src) {
			safeEmpty();
			m_size = src.m_size;
			m_proteinArr = new std::string[m_size];
			for (unsigned int i = 0u; i < m_size; i++) {
				m_proteinArr[i] = src.m_proteinArr[i];
			}
		}
		return *this;
	}

	ProteinDatabase::ProteinDatabase(ProteinDatabase&& src) {
		*this = std::move(src);
	}

	ProteinDatabase& ProteinDatabase::operator=(ProteinDatabase&& src) {
		if (this != &src) {
			safeEmpty();
			m_size = src.m_size;
			m_proteinArr = src.m_proteinArr;
			src.m_proteinArr = nullptr;
			src.m_size = 0;
		}
		return *this;
	}

	ProteinDatabase:: ~ProteinDatabase() {
		delete[] m_proteinArr;
	}
}