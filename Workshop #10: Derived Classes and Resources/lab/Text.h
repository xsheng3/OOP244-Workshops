/**********************************************************
 * Name: Xuewei Sheng
 * Student ID: 061745121
 * Seneca email: xsheng3@myseneca.ca
 * Section: NFF
 **********************************************************/
#ifndef SDDS_TEXT_H__
#define SDDS_TEXT_H__
#include <iostream>

using namespace std;
namespace sdds {
   class Text {
      char* m_filename ;
      char* m_content ;
      int getFileLength()const;
      void setName(const char* filename);
   protected:
      const char& operator[](int index)const;
   public:
      Text(const char* filename=nullptr);
      Text(const Text&);
      Text& operator=(const Text&);

      ~Text();

      void read();
      virtual void write(std::ostream& os)const;
   };
   std::ostream& operator<<(std::ostream& ostr, const Text& text);
   //std::istream& operator>>(std::ostream& istr, Text& text);
}
#endif // !SDDS_PERSON_H__

