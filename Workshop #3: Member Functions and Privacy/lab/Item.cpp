/**********************************************************
 * Name: Xuewei Sheng
 * Student ID: 061745121
 * Seneca email: xsheng3@myseneca.ca
 * Section: NFF
 **********************************************************/

#include <iostream>
#include "cstring.h"
#include "Item.h"
using namespace std;
namespace sdds {
    //set the itemName member Cstring variable to the Cstring in the 
    //"name" argument up to 20 characters
    void Item::setName(const char* name)
    {
        strnCpy(m_itemName, name, 20);
        m_itemName[20] = '\0';
    }

    //set the Item to a safe empty state
    void Item::setEmpty() {
        m_itemName[0] = '\0';
        m_price = 0.0;
        m_taxed = true;
    }

    //if the input is valid, set the value to the class variables 
    void Item::set(const char* name, double price, bool taxed) {
        if (name != nullptr && price > 0.0)
        {
            setName(name);
            m_price = price;
            m_taxed = taxed;
        }
    }
    
    //display one valid or invalid item in a required format
    void Item::display()const {
        if (isValid())
        {
            cout << "| ";
            cout.fill('.');
            cout.width(20);
            cout.setf(ios::left);
            cout << m_itemName;
            cout.unsetf(ios::left);
            

            cout << " | ";
            cout.setf(ios::fixed);
            cout.setf(ios::right);
            cout.fill(' ');
            cout.precision(2);
            cout.width(7);
            cout << m_price;
            cout.unsetf(ios::right);

            cout << " | ";
            if (m_taxed)
            {
                cout << "Yes" << " |" << endl;
            }
            else
            {
                cout << "No " << " |" << endl;
            }
        }
        else
        {
            cout << "| ";
            cout.fill('x');
            cout.width(23);
            cout << " | ";
            cout.width(10);
            cout << " | ";
            cout.width(5);
            cout << " |" << endl;
        }
    }

    //valid one item
    bool Item::isValid()const {
        return m_itemName[0] != '\0';
    }
    
    //return the m_price attibute
    double Item::price()const {
        return m_price;
    }

    //returen the tax amount;
    double Item::tax()const {
        const double c_tax = 0.13;
        double tax = 0.0;
        if (m_taxed == true)
        {
            tax = price() * c_tax;
        }
        return tax;
    }
}