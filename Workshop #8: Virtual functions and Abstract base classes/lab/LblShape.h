/**********************************************************
 * Name: Xuewei Sheng
 * Student ID: 061745121
 * Seneca email: xsheng3@myseneca.ca
 * Section: NFF
 **********************************************************/
#ifndef SDDS_LBLSHAPE_H__
#define SDDS_LBLSHAPE_H__
#include<iostream>
#include"Shape.h"
namespace sdds {
	class LblShape :public Shape {
		char* m_label{ nullptr };
		void setLabel(const char* label);
	protected:
		const char* label()const;
	public:
		LblShape() {};
		LblShape(const char* label);

		void getSpecs(std::istream& is);
		~LblShape();
	};
}
#endif