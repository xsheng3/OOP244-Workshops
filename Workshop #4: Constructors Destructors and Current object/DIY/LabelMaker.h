
/**********************************************************
* Name: Xuewei Sheng
* Student ID: 061745121
* Seneca email: xsheng3@myseneca.ca
* Section: NFF
**********************************************************/

#ifndef SDDS_LABELMAKER_H
#define SDDS_LABELMAKER_H
#include <iostream>
#include"Label.h"

namespace sdds {
	class LabelMaker {		
		int m_noOfLabels;
		Label* m_labels;
		void setEmpty();
	public:
	    LabelMaker(int noOfLabels);	
		void readLabels();
		void printLabels();
		~LabelMaker();
	};
}
#endif