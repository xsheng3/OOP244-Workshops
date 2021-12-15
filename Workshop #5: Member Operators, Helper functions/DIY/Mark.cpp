/**********************************************************
* Name: Xuewei Sheng
* Student ID : 061745121
* Seneca email : xsheng3@myseneca.ca
* Section: NFF
* *********************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Mark.h"

using namespace std;
namespace sdds {
    bool Mark::isValid() {
        return (m_mark <= 100 && m_mark >= 0);
    }

    void Mark::setEmpty() {
            m_mark = -1;
    }

    Mark::Mark() {
        m_mark = 0;
    } 

    Mark::Mark(int number) {
        setEmpty();
        if (number >= 0 && number <= 100)
        {
            m_mark = number;
        }       
    }
        
    Mark::operator bool()const {
        return (m_mark >= 0 && m_mark <= 100);
    }

    Mark::operator int()const {
        int result = 0;
        if (m_mark <= 100 && m_mark >= 0)
            result = m_mark;
        return result;
    }
    Mark::operator double()const {
        double gpa = 0.0;
        if (m_mark >= 50 && m_mark < 60)
        {
            gpa = 1.0;
        }
        else if (m_mark >= 60 && m_mark < 70)
        {
            gpa = 2.0;
        }
        else if (m_mark >= 70 && m_mark < 80)
        {
            gpa = 3.0;
        }
        else if (m_mark >= 80 && m_mark <= 100)
        {
            gpa = 4.0;
        }
        return gpa;
    }

    Mark::operator char()const {
        char grade = 'X';
        if (m_mark >= 0 && m_mark < 50)
        {
            grade = 'F';
        }
        else if (m_mark >= 50 && m_mark < 60)
        {
            grade = 'D';
        }
        else if (m_mark >= 60 && m_mark < 70)
        {
            grade = 'C';
        }
        else if (m_mark >= 70 && m_mark < 80)
        {
            grade = 'B';
        }
        else if (m_mark >= 80 && m_mark <= 100)
        {
            grade = 'A';
        }
        return grade;
   }
    Mark& Mark::operator += (const int number) {
        if (*this)
        {
            m_mark += number;
        }
        return *this;
    }

    Mark& Mark::operator = (const int number) {
        if (number <= 100 && number >= 0)
        {
            m_mark = number;
        }
        else
        {
            m_mark = -1;
        }
        return *this;
    }

    int operator += (int& number, const Mark& ro) {
        
        if (ro)
        {
            number += int(ro);            
        }
        return number;
    }
};