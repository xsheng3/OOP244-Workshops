/**********************************************************
 * Name: Xuewei Sheng
 * Student ID: 061745121
 * Seneca email: xsheng3@myseneca.ca
 * Section: NFF
 **********************************************************/
#include <fstream>
#include"Text.h"
#include"cstring.h"
#include<string>

using namespace std;
namespace sdds {
   int Text::getFileLength() const {
      int len = 0;
      ifstream fin(m_filename);
      while (fin) {
         fin.get();
         len += !!fin;
      }
      return len;
   }


   void Text::setName(const char*filename) {
       if (m_filename != nullptr)
       {
           delete[] m_filename;
           m_filename = nullptr;
       }
       if (filename && filename[0] != '\0')
       {
           int len = strLen(filename);
           m_filename = new char[len + 1];
           strCpy(m_filename, filename);
       }
       else m_filename = nullptr;
   }


   const char& Text::operator[](int index)const {
       return m_content[index];
   }


   Text::Text(const char* filename) :m_filename(nullptr), m_content (nullptr) {
           setName(filename);
           if(filename)
           {
                int len = getFileLength();
                if (len > 0)
                {
                    m_content = new char[len + 1];
                    ifstream fin(m_filename);
                    string content;
                    getline(fin, content, '\0');
                    strCpy(m_content, content.c_str());
                }
           }
   }

   Text::Text(const Text& src) {
       m_filename = nullptr;
       m_content = nullptr;
       *this = src;
   }
   Text& Text::operator=(const Text& src) {
       if (this != &src)
       {
           setName(src.m_filename);
           int len = getFileLength();
           if (m_content)
           {
               delete[] m_content;
               m_content = nullptr;
           }
           m_content = new char[len + 1];
           strCpy(m_content, src.m_content);
       }
       return *this;
   }

   Text::~Text() {
       delete[] m_content;
       m_content = nullptr;
       delete[] m_filename;
       m_filename = nullptr;
   }

   void Text::read() {
       if (m_filename)
       {
           if (m_content)
           {
               delete[] m_content;
               m_content = nullptr;
           }

           int len = getFileLength();
           m_content = new char[len + 1];
           ifstream fin(m_filename);
           string content;
           getline(fin, content, '\0');
           strCpy(m_content, content.c_str());
       }       

   }

   void Text::write(std::ostream& os)const {
       if (m_content)
       {
           for (int i = 0; i < strLen(m_content); i++)
           {
               os << m_content[i];
           }
       }
   }

   std::ostream& operator<<(std::ostream& ostr, const Text& text) {
       text.write(ostr);
       return ostr;
   }

}