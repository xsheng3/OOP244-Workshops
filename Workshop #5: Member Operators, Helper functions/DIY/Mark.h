/**********************************************************
 * Name: Xuewei Sheng
 * Student ID: 061745121
 * Seneca email: xsheng3@myseneca.ca
 * Section: NFF
 **********************************************************/
#ifndef SDDS_MARK_H_
#define SDDS_MARK_H_
#include <iostream>

namespace sdds {
    class Mark {
        int m_mark;
        bool isValid();
        void setEmpty();
    public:
        Mark();
        Mark(int number);

        operator bool()const;
        operator int()const;
        operator double()const;
        operator char()const;
        //bool operator ~()const;
        Mark& operator += (const int number);
        Mark& operator = (const int number);
        //Mark& operator = (Mark& ro);

        //Mark& operator -= (double withdraw);
        //Mark& operator << (Mark& ro);
        //Mark& operator >> (Mark& ro);
        //std::ostream& display()const;
    };

    //double operator + (const Account& lo, const Account& ro);
    int operator += (int& number, const Mark& ro);
}
#endif