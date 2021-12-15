#include <iostream>
#include <fstream>
#include <string>
#include "Stats.h"
#include "cstring.h"
using namespace std;
namespace sdds {
	void Stats::setFilename(const char* filename, bool isCopy) {
		if (!isCopy)
		{
			delete[] m_filename;
			int len = strLen(filename);
			m_filename = new char[len + 1];
			strCpy(m_filename, filename);
		}
		else
		{
			delete[] m_filename;
			int len = strLen(filename);
			m_filename = new char[len + 3];
			strCpy(m_filename, "C_");
			strCat(m_filename, filename);
		}
	}

	void Stats::setNoOfNumbers() {
		ifstream f(m_filename);
		while (f)
		{
			if (f.get() == ',')
				m_noOfNumbers++;
		}
		if (m_noOfNumbers == 0)
		{
			delete[] m_filename;
			m_filename = nullptr;
		}
		else
		{
			m_noOfNumbers++;
		}
	}

	void Stats:: loadNumbers() {
		if (m_filename)
		{
			ifstream f(m_filename);
			delete [] m_numbers;
			m_numbers = new double[m_noOfNumbers];

			if (f.is_open())
			{
				double number;
				unsigned i = 0;
				while (f >> number && i < m_noOfNumbers)//read one number form file succesfully
				{
					m_numbers[i] = number;
					i++;
					//same as: m_numbers[i++] = val;
					f.ignore(1000, ',');
					//discard the following ','
				}
				m_noOfNumbers = i;
			}
		}
	}

 	void Stats::saveAs(const char* filename)const {
		
		ofstream file(filename); //destination file
		ifstream infile(m_filename);//source file

		char ch;
		while (infile.get(ch)) //read ch one by one from source file and write into destination file, no need to use class member variables 
			file << ch;
	}

	Stats::Stats(unsigned columnWidth, unsigned noOfColumns, unsigned precision) {
		m_columnWidth = columnWidth;
		m_noOfColumns = noOfColumns;
		m_precision = precision;
	}

	Stats::Stats(const char* filename, unsigned columnWidth, unsigned noOfColumns, unsigned precision) :m_columnWidth{ columnWidth }, m_noOfColumns{ noOfColumns }, m_precision{ precision }{

		if (filename)
		{
			//m_columnWidth = columnWidth;
			//m_noOfColumns = noOfColumns;
			//m_precision = precision;
			setFilename(filename);
			setNoOfNumbers();
			loadNumbers();
		}	
	}

	Stats::Stats(const Stats& src){
		if(src)
		{
			m_columnWidth = src.m_columnWidth;
			m_noOfColumns = src.m_noOfColumns;
			m_precision = src.m_precision;
			setFilename(src.m_filename, true);
			src.saveAs(m_filename);
			setNoOfNumbers();
			loadNumbers();
		}
	}

	Stats& Stats::operator=(const Stats& src) {
		if (*this && src && this != &src)
		{
			delete[] m_numbers;
			m_numbers = nullptr;
			src.saveAs(m_filename);
			setNoOfNumbers();
			m_columnWidth = src.m_columnWidth;
			m_precision = src.m_precision;
			m_noOfColumns = src.m_noOfColumns;
			loadNumbers();
		}
		return *this;
	}

	Stats::~Stats() {
		delete[] m_numbers;
		m_numbers = nullptr;
		delete[] m_filename;
		m_filename = nullptr;

	}

	std::ostream& Stats::display(std::ostream& ostr)const {
		if (m_noOfNumbers > 0)
		{
			int len = strLen(m_filename);
			ostr << m_filename << endl;
			ostr.width(len);
			ostr.fill('=');
			ostr << '=' << endl;

			for (unsigned i = 0; i < m_noOfNumbers; i++)
			{
				if ((i + m_noOfColumns) % m_noOfColumns == 0)
					ostr << endl;
				ostr.width(m_columnWidth);
				ostr.fill(' ');
				ostr.setf(ios::fixed);
				ostr.precision(m_precision);
				ostr << m_numbers[i];
				
			}
			ostr << endl << "Total of " << m_noOfNumbers << " listed!" << endl;
		}
		return ostr;
	}

	std::istream& Stats::getNumber(std::istream& istr) {
		std::string filename;
		istr >> filename;
		cin.ignore(1000, '\n');
		setFilename(filename.c_str());
		setNoOfNumbers();
		loadNumbers();
		return istr;
	}

	double& Stats::operator[](unsigned idx) {
		double* temp;
		if (*this) 
		{
			if (m_noOfNumbers != 0)
			{
				idx = idx % m_noOfNumbers;
			}
			temp = &m_numbers[idx];
		}
		else 
		{
			temp = &m_numberDum;
		}
		return *temp;
	}

	double Stats::operator[](unsigned idx) const {
		double temp = 0.00;
		if (*this)
		{
			if (m_noOfNumbers != 0) idx = idx % m_noOfNumbers;
			temp = m_numbers[idx];
		}

		return temp;
	}

	Stats::operator bool()const {
		return (m_filename != nullptr && m_noOfNumbers > 0);
	}

	void Stats::sort(bool ascending) {
		double temp = 0.0;
		unsigned i = 0, j = 0;
		if (*this) {
			if (ascending)
			{
			for (j = 0; j < (m_noOfNumbers - 1); j++)
			{
				for (i = 0; i < (m_noOfNumbers - 1 - j); i++)
				{
					if (m_numbers[i] > m_numbers[i + 1])
					{
						temp = m_numbers[i];
						m_numbers[i] = m_numbers[i + 1];
						m_numbers[i + 1] = temp;
					}
				}
			}
		    }
		else
		{
			for (j = 0; j < (m_noOfNumbers - 1); j++)
			{
				for (i = 0; i < (m_noOfNumbers - 1 - j); i++)
				{
					if (m_numbers[i] < m_numbers[i + 1])
					{
						temp = m_numbers[i];
						m_numbers[i] = m_numbers[i + 1];
						m_numbers[i + 1] = temp;
					}
				}
			}
		}
		}
		

	}

	unsigned Stats::size()const {
		return m_noOfNumbers;
	}

	const char* Stats::name()const {
		return m_filename;
	}

	unsigned Stats::occurrence(double min, double max, std::ostream& ostr ) {
		unsigned counter = 0;
		if (*this)
		{
			ostr << endl;
			for (unsigned i = 0; i < m_noOfNumbers; i++)
			{
				if (m_numbers[i] >= min && m_numbers[i] <= max)
				{
					ostr.width(m_columnWidth);
					ostr.fill(' ');
					ostr.setf(ios::fixed);
					ostr.precision(m_precision);
					ostr << m_numbers[i];
					counter++;
					if (counter % m_noOfColumns == 0)
						ostr << endl;
				}

			}
				ostr << endl << "Total of " << counter << " numbers are between " << min << " and " << max << endl;
		}


		return counter;

	}

	std::ostream& operator<<(std::ostream& ostr, const Stats& stats) {
		stats.display(ostr);
		return ostr;
	}

	std::istream& operator>>(std::istream& istr, Stats& stats) {
		stats.getNumber(istr);
		return istr;
	}
}