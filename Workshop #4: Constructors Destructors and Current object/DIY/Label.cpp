 /**********************************************************
 * Name: Xuewei Sheng
 * Student ID: 061745121
 * Seneca email: xsheng3@myseneca.ca
 * Section: NFF
 **********************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include "cstring.h" 
#include "Label.h"
#define  MAX_NAME_SIZE 70

using namespace std;
namespace sdds {
    void Label::setDefault() {
        m_labelName = nullptr;
        strCpy(m_frameString, "+-+|+-+|");
    }

    void Label::setName(const char* Cstr) {
        if (Cstr)
        {
            if (nullptr != m_labelName)
            {
                delete[] m_labelName;
                m_labelName = nullptr;
            }
            int len = strLen(Cstr);
            len = len < MAX_NAME_SIZE ? len :  MAX_NAME_SIZE;
            m_labelName = new char[len + 1];
            strCpy(m_labelName, Cstr);
        }
    }



    //Creates an empty labeland defaults the frame to "+-+|+-+|"
    Label::Label() {
        setDefault();
    }

    // Creates an empty label and sets the frame to the frameArg argument.
    Label::Label(const char* frameArg) {
        if (frameArg) 
        {
            m_labelName = nullptr;
            strnCpy(m_frameString, frameArg, 8);
        }
        else
        {
            setDefault();
        }
    }

        //Creates a Label with the frame set to frameArg and the content of the Label 
        //set to the corresponding argument.Note that you must keep the content dynamically 
        //even though it should never be more than 70 characters.
    Label::Label(const char* frameArg, const char* content) {
        if (frameArg)
        {
            m_labelName = nullptr;
            strnCpy(m_frameString, frameArg, 8);
        }
        else
        {
            setDefault();
        }
        if (content)
        {
            setName(content);
        }
    }


        //destructor
        //Makes sure there is no memory leak when the label goes out of scope.
    Label::~Label() {
            delete[] m_labelName;
            m_labelName = nullptr;  
    }

        //Reads the label from console up to 70 characters and stores it in the Label as 
        //shown in the Execution sample
    void Label::readLabel() {
        char temp[71];
        cin.getline(temp, 71);
        if (cin.fail())
        {
            cin.ignore(1000, '\n');
        }
        setName(temp);
    }

    //  Prints the label by drawing the frame around the content ad shown in the Execution 
    //sample.Note that no newline is printed after the last lineand cout is returned at the end.
    std::ostream& Label::printLabel()const {
        if (m_labelName) {
            int len = strLen(m_labelName);
            cout << m_frameString[0];
            for (int i = 0; i < len + 2; i++)
            {
                cout << m_frameString[1];
            }
            cout << m_frameString[2] << endl;
            cout << m_frameString[7];
            cout.width((std::streamsize)len + 3);
            cout << m_frameString[3] << endl;
            cout << m_frameString[7] << " " << m_labelName << " " << m_frameString[3] << endl;
            cout << m_frameString[7];
            cout.width((std::streamsize)len + 3);
            cout << m_frameString[3] << endl;
            cout << m_frameString[6];
            for (int i = 0; i < len + 2; i++)
            {
                cout << m_frameString[5];
            }
            cout << m_frameString[4];
        }

        return cout;
    }
}
