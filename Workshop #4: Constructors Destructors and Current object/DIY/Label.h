/**********************************************************
 * Name: Xuewei Sheng
 * Student ID: 061745121
 * Seneca email: xsheng3@myseneca.ca
 * Section: NFF
 **********************************************************/

#ifndef SDDS_LABEL_H
#define SDDS_LABEL_H
#include <iostream>
#include"cstring.h"

namespace sdds {    
   class Label {
      char* m_labelName;
      char m_frameString[9];
      void setDefault();
      void setName(const char* Cstr);

   public:
      Label();
      Label(const char* frameArg);
      Label(const char* frameArg, const char* content);
      ~Label();
      void readLabel();
      std::ostream & printLabel()const;      
   };
}

#endif // !SDDS_LABEL_H
