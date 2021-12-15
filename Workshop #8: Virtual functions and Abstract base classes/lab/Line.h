/**********************************************************
 * Name: Xuewei Sheng
 * Student ID: 061745121
 * Seneca email: xsheng3@myseneca.ca
 * Section: NFF
 **********************************************************/
#ifndef SDDS_LINE_H__
#define SDDS_LINE_H__
#include<iostream>
#include"LblShape.h"
namespace sdds {
	class Line : public LblShape {
		int m_length;
	public:
		Line();
		Line(const char* line, int length);
		void getSpecs(std::istream& is);
		void draw(std::ostream& os)const;

	};
}
#endif
