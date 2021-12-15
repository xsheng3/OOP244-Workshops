/**********************************************************
 * Name: Xuewei Sheng
 * Student ID: 061745121
 * Seneca email: xsheng3@myseneca.ca
 * Section: NFF
 **********************************************************/

#include <iostream>
#include "cstring.h"
#include "Food.h"
using namespace std;
namespace sdds {
    //set the FoodName member Cstring variable to the Cstring in the 
    //"name" argument up to 30 characters
    void Food::setName(const char* name)
    {
        strnCpy(m_foodName, name, 30);
        m_foodName[30] = '\0';
    }

    //set the Food to a safe empty state
    void Food::setEmpty() {
        m_foodName[0] = '\0';
        m_calories = 0;
        m_timeCode = 0;
    }

    //if the input is valid, set the value to the class variables 
    void Food::set(const char* name, int calories, int timeCode) {
        if (name != nullptr && calories > 0)
        {
            setName(name);
            m_calories = calories;
            m_timeCode = timeCode;
        }
    }

    //display one valid or invalid Food in a required format
    void Food::display()const {
        if (isValid())
        {
            cout << "| ";
            cout.fill('.');
            cout.width(30);
            cout.setf(ios::left);
            cout << m_foodName;
            cout.unsetf(ios::left);


            cout << " | ";
            cout.setf(ios::right);
            cout.fill(' ');
            cout.width(4);
            cout << m_calories;
            cout.unsetf(ios::right);

            cout << " | ";
            cout.fill(' ');
            cout.width(10);
            cout.setf(ios::left);
            if (m_timeCode == 1)
            {
                cout << "Breakfast" << " |" << endl;
            }
            else if (m_timeCode == 2)
            {
                cout << "Lunch" << " |" << endl;
            }
            else if (m_timeCode == 3)
            {
                cout << "Dinner" << " |" << endl;
            }
            else if (m_timeCode == 4)
            {
                cout << "Snack" << " |" << endl;
            }
            cout.unsetf(ios::left);
        }
        else
        {
            cout << "| ";
            cout.fill('x');
            cout.width(33);
            cout << " | ";
            cout.width(7);
            cout << " | ";
            cout.width(12);
            cout << " |" << endl;
        }
    }

    //valid one Food
    bool Food::isValid()const {
        bool valid = false;
        if (m_foodName[0] != '\0' && m_timeCode <= 4 && m_timeCode >=1)
        {
            valid = true;
        }
        return valid;
    }

    //return the m_calories attibute
    int Food::calories()const {
        return m_calories;
    }

}