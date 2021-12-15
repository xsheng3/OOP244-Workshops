/**********************************************************
 * Name: Xuewei Sheng
 * Student ID: 061745121
 * Seneca email: xsheng3@myseneca.ca
 * Section: NFF
 **********************************************************/
#ifndef SDDS_HTMLTEXT_H__
#define SDDS_HTMLTEXT_H__
#include "Text.h"
namespace sdds {
   class HtmlText :  public Text {
      char* m_title;
      void setTitle(const char* title);
   public:
      HtmlText(const char* filename=nullptr, const char* title = nullptr);
      HtmlText(const HtmlText&);
      HtmlText& operator=(const HtmlText&);
      ~HtmlText();
      void write(std::ostream& os)const;
   };
}
#endif // !SDDS_HTMLTEXT_H__
 