/**********************************************************
 * Name: Xuewei Sheng
 * Student ID: 061745121
 * Seneca email: xsheng3@myseneca.ca
 * Section: NFF
 **********************************************************/
#ifndef SDDS_RECTANGLE_H__
#define SDDS_RECTANGLE_H__
#include<iostream>
#include"LblShape.h"
namespace sdds {
	class Rectangle : public LblShape {
		int m_width;
		int m_height;
	public:
		Rectangle();
		Rectangle(const char* label, int width, int height);
		void draw(std::ostream& os)const;
		void getSpecs(std::istream& is);
	};

}
#endif

