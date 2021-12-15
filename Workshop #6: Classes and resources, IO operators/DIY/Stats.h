/**********************************************************
 * Name: Xuewei Sheng
 * Student ID: 061745121
 * Seneca email: xsheng3@myseneca.ca
 * Section: NFF
 **********************************************************/
#ifndef SDDS_STATS_H__
#define SDDS_STATS_H__
#include <iostream>
namespace sdds {
   class Stats {	   
	   char* m_filename{};
	   double* m_numbers{ nullptr };
	   unsigned m_columnWidth;
	   unsigned m_noOfColumns;	   
	   unsigned m_precision;
	   unsigned m_noOfNumbers{ 0 };
	   double m_numberDum = { 0.0 };
	   void setFilename(const char* filename, bool isCopy = false);
	   void setNoOfNumbers();
	   void loadNumbers();
	   void saveAs(const char* filename)const;

   public:
	   Stats(unsigned columnWidth = 15, unsigned noOfColumns = 4, unsigned precision = 2);
	   Stats(const char* filename, unsigned columnWidth = 15, unsigned noOfColumns = 4, unsigned precision = 2);
	   Stats(const Stats&);
	   Stats& operator=(const Stats&);
	   ~Stats();
	   std::ostream& display(std::ostream& ostr)const;
	   std::istream& getNumber(std::istream& istr);
	   double& operator[](unsigned idx);
	   double operator[](unsigned idx) const;
	   operator bool()const;
	   void sort(bool ascending);
	   unsigned size()const;
	   const char* name()const;
	   unsigned occurrence(double min, double max, std::ostream& ostr = std::cout);
   };
   std::ostream& operator<<(std::ostream& ostr, const Stats& stats);
   std::istream& operator>>(std::istream& istr, Stats& stats);
}
#endif // !SDDS_STATS_H__
