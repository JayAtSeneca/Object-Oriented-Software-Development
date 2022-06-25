//MagicScroll.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <stdexcept>
#include "MagicScroll.h"
using namespace std;
namespace sdds {
	int MagicScroll::oldElfCount = 0;
	MagicScroll::MagicScroll(){}
	MagicScroll::MagicScroll(Language scroll, const char* words) {
		if (words == nullptr) {
			
			throw std::invalid_argument("invalid");
		}
		else {
			m_length = strlen(words);
			m_incantation = new char[strlen(words) + 1];
			strcpy(m_incantation, words);
			if (scroll == Language::None) {
				m_spell = Language::ModernHuman;
			}
			else {
				m_spell = scroll;
			}
			if (m_spell == Language::OldElf) {
				oldElfCount++;
			}
		}
	}

	int MagicScroll::getPower() {
		int power = 0;
		if (m_spell == Language::ModernHuman) {
			char vowels[5]{ 'a','e','i','o','u' };
			for (int i = 0; i < m_length; i++) {
				for (int j = 0; j < 5; i++) {
					if (m_incantation[i] == vowels[j]) {
						power++;
					}
				}
			}
			power += 1;
		}
		else if (m_spell == Language::Gibberish) {
			power = 0;
		}
		else if (m_spell == Language::OldElf) {
			char ch = ' ';
			for (int i = 0; i < m_length; i++) {
				if (m_incantation[i] == ch) {
					power++;
				}
			}
			power+=2;
		}
		else {
			throw "Exception";
		}

		if (m_spell == Language::OldElf && power >= 1000) {
			std::exit(10);
		}
		return power;
	}
	MagicScroll::MagicScroll(const MagicScroll& m)
	{
		*this = m;
	}
	MagicScroll::MagicScroll(MagicScroll&& m)
	{
		*this = std::move(m);
	}
	MagicScroll& MagicScroll::operator=(const MagicScroll& m)
	{
		if (this != &m) {
			if (m.m_incantation) {
				if (m_incantation != nullptr) {
					delete[] m_incantation;
				}
				m_length = m.m_length;
				m_incantation = new char[m.m_length + 1];
				strcpy(m_incantation, m.m_incantation);
				m_spell = m.m_spell;
				if (m_spell == Language::OldElf) {
					oldElfCount++;
				}
			}
		}
		return *this;
	}
	MagicScroll& MagicScroll::operator=(MagicScroll&& m)
	{
		if (this != &m) {
			if (m.m_incantation != nullptr) {
				if (m_incantation != nullptr) {
					delete[] m_incantation;
				}
				m_length = m.m_length;
				m.m_length = 0u;
				m_incantation = m.m_incantation;
				m.m_incantation = nullptr;
				m_spell = m.m_spell;
				m.m_spell = Language::None;
				if (m_spell == Language::OldElf) {
					oldElfCount++;
				}
			}
		}
		return *this;
	}
	MagicScroll::~MagicScroll()
	{
		delete[] m_incantation;
		oldElfCount--;
	}
}