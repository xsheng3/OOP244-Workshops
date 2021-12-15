/**********************************************************
* Name: Xuewei Sheng
* Student ID: 061745121
* Seneca email: xsheng3@myseneca.ca
* Section: NFF
**********************************************************/
#include "LabelMaker.h"
using namespace std;
namespace sdds {

	void LabelMaker::setEmpty(){
		m_noOfLabels = 0;
		m_labels = nullptr;
	}	
	
	//creates a dynamic array of Labels to the size of noOfLabels
	LabelMaker::LabelMaker(int noOfLabels) {
		setEmpty();
		if (noOfLabels)
		{
			m_noOfLabels = noOfLabels;
		}

		if (nullptr != m_labels)
		{
			delete[] m_labels;
			m_labels = nullptr;
		}
		m_labels = new Label[noOfLabels];
	}

	//Gets the contents of the Labels as demonstrated in the Execution sample
	void LabelMaker::readLabels()
	{
		cout << "Enter " << m_noOfLabels << " labels:" << endl;
		if (m_noOfLabels) {			
			for (int i = 0; i < m_noOfLabels; i++)
			{
				cout << "Enter label number " << i+1 << endl;
				cout << "> ";
				m_labels[i].readLabel();
			}
		}
		
	}

	//Prints the Labels as demonstrated in the Execution sample
	void LabelMaker::printLabels()
	{
		if (m_noOfLabels) {
			for (int i = 0; i < m_noOfLabels; i++)
			{
				m_labels[i].printLabel();
				cout << endl;
			}
		}
	}

	//Deallocates the memory when LabelMaker goes out of scope.
	LabelMaker::~LabelMaker()
	{
		if (m_labels != nullptr)
		{
			delete[] m_labels;
			m_labels = nullptr;
		}
	}

}