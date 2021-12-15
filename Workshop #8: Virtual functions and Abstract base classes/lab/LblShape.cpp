/**********************************************************
 * Name: Xuewei Sheng
 * Student ID: 061745121
 * Seneca email: xsheng3@myseneca.ca
 * Section: NFF
 **********************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include"LblShape.h"
#include<cstring>
using namespace std;

namespace sdds {
	const char* LblShape::label()const {
		return m_label;
	}

	void LblShape::setLabel(const char* label) {
		if (label)
		{
			delete[] m_label;
			int len = strlen(label);
			m_label = new char[len + 1];
			strcpy(m_label, label);
		}
	}

	LblShape::LblShape(const char* label) {
		setLabel(label);
	}

	LblShape::~LblShape() {
		delete[] m_label;
		m_label = nullptr;
	}

	void LblShape::getSpecs(std::istream& is) {
		string label;
		getline(is, label, ',');
		setLabel(label.c_str());	
	}


}
