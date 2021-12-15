/**********************************************************
 * Name: Xuewei Sheng
 * Student ID: 061745121
 * Seneca email: xsheng3@myseneca.ca
 * Section: NFF
 **********************************************************/

#ifndef SDDS_CALORILIST_H_
#define SDDS_CALORILIST_H_
#include "Food.h"
namespace sdds {
    class CalorieList {
        Food* m_food;
        int m_noOfFood;
        int m_foodAdded;

        int totalCalories()const;
        void Title()const;
        void footer()const;
        void setEmpty();
        bool isValid()const;
    public:
        void init(int noOfFood);
        bool add(const char* foodName, int calories, int timeCode);
        void display()const;
        void deallocate();
    };
}
#endif