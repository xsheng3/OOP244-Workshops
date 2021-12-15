/**********************************************************
 * Name: Xuewei Sheng
 * Student ID: 061745121
 * Seneca email: xsheng3@myseneca.ca
 * Section: NFF
 **********************************************************/

#include <iostream>
#include "cstring.h"
#include "CalorieList.h"
using namespace std;
namespace sdds {
    //calculate total calories, using the object calories() from Food class,
    //return total tax amout in double type
    int CalorieList::totalCalories()const {
        int caloriesTotal = 0;
        for (int i = 0; i < m_noOfFood; i++)
        {
            caloriesTotal += m_food[i].calories();
        }
        return caloriesTotal;
    }

    //print the CalorieList title in required format
    void CalorieList::Title()const {
        cout << "+----------------------------------------------------+" << endl;
        if (isValid())
        {
            cout << "|  Daily Calorie Consumption                         |" << endl;
        }
        else
        {
            cout << "| Invalid Calorie Consumption list                   |" << endl;
        }  
        cout << "+--------------------------------+------+------------+" << endl
            << "| Food name                      | Cals | When       |" << endl
            << "+--------------------------------+------+------------+" << endl;
    }

    // print CalorieList footer in required format
    void CalorieList::footer()const {
        cout << "+--------------------------------+------+------------+" << endl;
        if (isValid())
        {
            cout << "|    Total Calories for today: ";
            cout.setf(ios::right);
            cout.width(8);
            cout.fill(' ');      
            cout << totalCalories();
            cout << " |            |" << endl;
            cout.unsetf(ios::right);

        }
        else
        {
            cout << "|    Invalid Calorie Consumption list                |" << endl;
        }
        cout << "+----------------------------------------------------+" << endl;
    }

    //set m_items to a safe empty state
    void CalorieList::setEmpty() {
        m_food = nullptr;
    }

    //validate the m_items is not null
    //use a for loop to validate all the items inthe m_items array are valid, using isValid() from Ietm class
    bool CalorieList::isValid()const {
        bool valid = m_food != nullptr;
        for (int i = 0; valid && i < m_noOfFood; i++)
        {
            valid = m_food[i].isValid();
        }
        return valid;
    }

    //initialize the m_item to a safe empty state
    void CalorieList::init(int noOfFood) {
        if (noOfFood > 0)
        {
            m_noOfFood = noOfFood;
            m_foodAdded = 0;
            m_food = new Food[noOfFood];
            for (int i = 0; i < noOfFood; i++)
            {
                m_food[i].setEmpty();
            }
        }
        else
        {
            setEmpty();
        }
    }

    //add one item data into m_item, using the set object from Item class
    //if add successfully, returen ture; else return false
    bool CalorieList::add(const char* foodName, int calories, int timeCode) {
        bool added = true;
        if (m_foodAdded < m_noOfFood)
        {
            m_food[m_foodAdded++].set(foodName, calories, timeCode);
        }
        else
        {
            added = false;
        }
        return added;
    }

    //dispay title, and then use a for loop to print all the item detail of a CalorieList
    void CalorieList::display() const {
        Title();

        for (int i = 0; i < m_noOfFood; i++)
        {
            m_food[i].display();
        }

        footer();
    }

    //deallocate the dynamic memory of the array of m_item; 
    void CalorieList::deallocate() {
        delete[] m_food;
        m_food = nullptr;
    }

}