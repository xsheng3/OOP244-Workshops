/**********************************************************
 * Name: Xuewei Sheng
 * Student ID: 061745121
 * Seneca email: xsheng3@myseneca.ca
 * Section: NFF
 **********************************************************/
#include<iostream>
#include"Shape.h"

using namespace std;
namespace sdds {
	std::ostream& operator<<(std::ostream& ostr, const Shape& shape) {
		shape.draw(ostr);
		return ostr;
	}

	std::istream& operator>>(std::istream& istr, Shape& shape) {
		shape.getSpecs(istr);
		return istr;
	}


}