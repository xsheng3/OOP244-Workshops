/**********************************************************
 * Name: Xuewei Sheng
 * Student ID: 061745121
 * Seneca email: xsheng3@myseneca.ca
 * Section: NFF
 **********************************************************/
#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds {
    class Account {
        int m_number;
        double m_balance;
        void setEmpty();
    public:
        Account();
        Account(int number, double balance);
        std::ostream& display()const;
        operator bool()const;
        operator int()const;
        operator double()const;
        bool operator ~()const;
        Account& operator = (const int number);
        Account& operator = (Account& ro);
        Account& operator += (double deposit);
        Account& operator -= (double withdraw);
        Account& operator << (Account& ro);
        Account& operator >> (Account& ro);

    };

    double operator + (const Account& lo, const Account& ro);
    double operator += (double &balance, const Account& ro);

   
   
}
#endif // SDDS_ACCOUNT_H_