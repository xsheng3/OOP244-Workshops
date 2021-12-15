#define _CRT_SECURE_NO_WARNINGS
#include<string>
#include<iostream>
#include"Rectangle.h"
#include<cstring>

using namespace std;

namespace sdds {
	Rectangle::Rectangle() :m_width{ 0 }, m_height{ 0 }{}
	Rectangle::Rectangle(const char* label, int width, int height): LblShape(label) {
		int len = strlen(label) + 2;
		if (width < len || height < 3)
		{
			m_width = 0;
			m_height = 0;
		}
		else
		{
			m_width = width;
			m_height = height;
		}
	}
	void Rectangle::getSpecs(std::istream& is) {
		LblShape::getSpecs(is);
		is >> m_width;
		is.ignore(1000, ',');
		is >> m_height;
		is.ignore(1000, '\n');

	}
	void Rectangle::draw(std::ostream& os)const {
		if (m_width && m_height)
		{
			os << '+';
			os.width(m_width-2);
			os.fill('-');
			os << '-';
			os << '+' << endl;

			os << '|';
			os.width(m_width-2);
			os.fill(' ');
			os.setf(ios::left);
			os << label();
			os << '|' << endl;

			for (int i = 0; i < m_height - 3; i++)
			{
				os << '|';
				os.width(m_width - 2);
				os.fill(' ');
				os << ' ';
				os << '|' << endl;
			}

			os << '+';
			os.width(m_width - 2);
			os.fill('-');
			os << '-';
			os << '+';
		}
	}

}