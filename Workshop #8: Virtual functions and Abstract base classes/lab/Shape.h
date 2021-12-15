/**********************************************************
 * Name: Xuewei Sheng
 * Student ID: 061745121
 * Seneca email: xsheng3@myseneca.ca
 * Section: NFF
 **********************************************************/
#ifndef SDDS_SHAPE_H__
#define SDDS_SHAPE_H__
#include<iostream>
namespace sdds {
	class Shape {
	public:
		virtual void draw(std::ostream& os)const = 0;
		virtual void getSpecs(std::istream& is) = 0;
		virtual ~Shape() {};
	};
	std::ostream& operator<<(std::ostream& ostr, const Shape& shape);
	std::istream& operator>>(std::istream& istr, Shape& shape);
}
#endif

