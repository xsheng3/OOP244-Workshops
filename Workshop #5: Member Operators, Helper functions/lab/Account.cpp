/**********************************************************
 * Name: Xuewei Sheng
 * Student ID: 061745121
 * Seneca email: xsheng3@myseneca.ca
 * Section: NFF
 **********************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds {
   void Account::setEmpty() {
      m_number = -1;
      m_balance = 0.0;
   }

   // New account
   Account::Account() {  
      m_number = 0;
      m_balance = 0.0;
   }
   Account::Account(int number, double balance ) {
      setEmpty();
      if (number >= 10000 && number <= 99999
         && balance >= 0) {
         m_number = number;
         m_balance = balance;
      }
   }

   Account::operator bool() const{
        
       return (m_number >= 10000 && m_number <= 99999
           && m_balance >= 0);
          
   }
   Account::operator int() const {
       return m_number;
   }
   Account::operator double() const {
       return m_balance;
   }
   bool Account:: operator ~()const {
       return m_number == 0;
   }
   Account& Account::operator = (const int number) {
       if (~*this)
       {
           m_number = -1;
           if (number >= 10000 && number <= 99999)
           {
               m_number = number;
           }
       }
       return *this;
   }

   Account& Account::operator = (Account& ro) {
       if (~*this && ro)
       {
           m_number = ro.m_number;
           m_balance = ro.m_balance;
           ro.m_number = 0;
           ro.m_balance = 0.00;
       }      
       return *this;
   }
   Account& Account::operator += (double deposit) {
       if (*this && deposit > 0)
       {
           m_balance += deposit;
       }
       return *this;
   }
   Account& Account::operator -= (double withdraw) {
       if (*this && withdraw > 0 && m_balance >= withdraw)
       {
           m_balance -= withdraw;
       }
       return *this;
   }

   Account& Account::operator << (Account& ro) {
       if (*this && this != &ro && ro)
       {
           m_balance += ro.m_balance;
           ro.m_balance = 0.0;
       }
       return *this;
   }

   Account& Account::operator >> (Account& ro) {
       if (*this && this != &ro && ro)
       {
           ro.m_balance += m_balance;
           m_balance = 0.0;
       }
       return *this;
   }

   std::ostream& Account::display() const{
      if (*this) {  
         cout << " ";
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else if(~*this) {
         cout << "  NEW  |         0.00 ";
      }
      else {
         cout << "  BAD  |    ACCOUNT   ";
      }
      return cout;
   }

   double operator + (const Account& lo, const Account& ro) {
       double sum = 0.0;
       if (lo && ro)
       {
           sum = double(lo) + double(ro);
       }
       return sum;
   }
   double operator += (double &balance, const Account& ro) {       
   
       return balance += double(ro);       
    
   }
}