/**********************************************************
 * Name: Xuewei Sheng
 * Student ID: 061745121
 * Seneca email: xsheng3@myseneca.ca
 * Section: NFF
 **********************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include<string>
#include<iostream>
#include"Line.h"

using namespace std;

namespace sdds {
	Line::Line() :m_length{ 0 } {}
	Line::Line(const char* label, int length) : LblShape(label) {
		m_length = length;
	}
	void Line::getSpecs(std::istream& is) {
		LblShape::getSpecs(is);
		is >> m_length;
		is.ignore(1000, '\n');
	}
	void Line::draw(std::ostream& os)const {
		if (m_length > 0 && LblShape::label())
		{
			os << label() << endl;
			os.width(m_length);
			os.fill('=');
			os << '=';
		}
	}

}