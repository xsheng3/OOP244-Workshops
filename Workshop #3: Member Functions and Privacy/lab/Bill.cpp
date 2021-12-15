/**********************************************************
 * Name: Xuewei Sheng
 * Student ID: 061745121
 * Seneca email: xsheng3@myseneca.ca
 * Section: NFF
 **********************************************************/

#include <iostream>
#include "cstring.h"
#include "Bill.h"
using namespace std;
namespace sdds {
    //calculate total tax, using the object tax() from Item class,
    //return total tax amout in double type
    double Bill::totalTax()const {
        double taxTotal = 0;
        for (int i = 0; i < m_noOfItems; i++)
        {
            taxTotal += m_items[i].tax();
        }
        return taxTotal;
    }

    //calculate total price, using the object price() from Item class,
    //return total price amout in double type
    double Bill::totalPrice()const {
        double priceTotal = 0;
        for (int i = 0; i < m_noOfItems; i++)
        {
            priceTotal += m_items[i].price();
        }
        return priceTotal;
    }
      
    //print the bill title in required format
    void Bill::Title()const {
        cout << "+--------------------------------------+" << endl;
        if (isValid())
        {
            cout << "| ";
            cout.width(36);
            cout.fill(' ');
            cout.setf(ios::left);
            cout << m_title;
            cout << " |" << endl;
        }
        else
        {
            cout << "| Invalid Bill                         |" << endl;
        }
        cout << "+----------------------+---------+-----+" << endl
             << "| Item Name            | Price   + Tax |" << endl
            << "+----------------------+---------+-----+" << endl;
    }

    // print bill footer in required format
    void Bill::footer()const {
        cout << "+----------------------+---------+-----+" << endl;
        if (isValid())
        {
            cout << "|                Total Tax: ";
            cout.setf(ios::right);
            cout.width(10);
            cout.fill(' ');
            cout.setf(ios::fixed);
            cout.precision(2);
            cout << totalTax();
            cout << " |" << endl;
            cout.unsetf(ios::right);

            cout << "|              Total Price: ";
            cout.width(10);
            cout << totalPrice();
            cout << " |" << endl;

            cout << "|          Total After Tax: ";
            cout.width(10);
            cout << totalTax() + totalPrice();
            cout << " |" << endl;
        }
        else
        {
            cout << "| Invalid Bill                         |" << endl;
        }
        cout << "+--------------------------------------+" << endl;
    }

    //set m_title and  m_items to a safe empty state
    void Bill::setEmpty(){
        m_title[0] = '\0';
        m_items = nullptr;
    }

    //validate the m_title is not empty and m_items is not null
    //use a for loop to validate all the items inthe m_items array are valid, using isValid() from Ietm class
    bool Bill::isValid()const {
        bool valid = m_items != nullptr && m_title[0] != '\0';
        for (int i = 0; valid && i < m_noOfItems; i++)
        {
            valid = m_items[i].isValid();
        }
        return valid;
    }

    //initialize the m_item to a safe empty state
    void Bill::init(const char* title, int noOfItems) {
        if (title != nullptr && noOfItems > 0)
        {
            m_noOfItems = noOfItems;
            m_itemsAdded = 0;
            strnCpy(m_title, title, 36);
            m_title[36] = '\0';
            m_items = new Item[noOfItems];
            for (int i = 0; i < noOfItems; i++)
            {
                m_items[i].setEmpty();
            }
        }
        else
        {
            setEmpty();
        }
    }

    //add one item data into m_item, using the set object from Item class
    //if add successfully, returen ture; else return false
    bool Bill::add(const char* item_name, double price, bool taxed) {
        bool added = true;
        if (m_itemsAdded < m_noOfItems)
        {
            m_items[m_itemsAdded++].set(item_name, price, taxed);
        }
        else
        {
            added = false;
        }
        return added;
    }

    //dispay title, and then use a for loop to print all the item detail of a bill
    void Bill::display() const {
        Title();
        
        for (int i = 0; i < m_noOfItems; i++)
        {
            m_items[i].display();
        }

        footer();
    }

    //deallocate the dynamic memory of the array of m_item; 
    void Bill::deallocate() {
        delete[] m_items;
        m_items = nullptr;
    }

}