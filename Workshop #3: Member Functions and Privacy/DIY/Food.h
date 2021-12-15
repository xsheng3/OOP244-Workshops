/**********************************************************
 * Name: Xuewei Sheng
 * Student ID: 061745121
 * Seneca email: xsheng3@myseneca.ca
 * Section: NFF
 **********************************************************/

#ifndef SDDS_FOOD_H_
#define SDDS_FOOD_H_
namespace sdds {
    class Food {
        char m_foodName[31];
        int m_calories;
        int m_timeCode;
        void setName(const char* name);
    public:
        void setEmpty();
        void set(const char* name, int calories, int timeCode);
        void display()const;
        bool isValid()const;
        int calories()const;
    };
}

#endif 