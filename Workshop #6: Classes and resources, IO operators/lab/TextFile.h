/**********************************************************
 * Name: Xuewei Sheng
 * Student ID: 061745121
 * Seneca email: xsheng3@myseneca.ca
 * Section: NFF
 **********************************************************/
#ifndef SDDS_TEXTFILE_H__
#define SDDS_TEXTFILE_H__
#include <iostream>
namespace sdds {
   class TextFile;
   class Line {
       char* m_value{ nullptr };
      operator const char* ()const;
      
      //use Line(){}; then you don`t need to implement the constructor
      Line() {};

      Line& operator=(const char*);

      ~Line();
      friend class TextFile;

      // copy and copy assignment prevention goes here
            //Make sure Line can not be copied or assigned to another Line.
      Line(const Line&) = delete;
      void operator=(const Line&) = delete;
   };

   class TextFile {//initialize the members here
       Line* m_textLines{ nullptr };
       char* m_filename{};
       unsigned m_noOfLines{ 0 };
      unsigned m_pageSize;
      void setFilename(const char* fname, bool isCopy = false);
      void setNoOfLines();
      void loadText();
      void saveAs(const char *fileName)const;
      void setEmpty();
   public:
      TextFile(unsigned pageSize = 15);
      TextFile(const char* filename, unsigned pageSize = 15);
      TextFile(const TextFile&);
      TextFile& operator=(const TextFile&);
      ~TextFile();
      std::ostream& view(std::ostream& ostr)const;
      std::istream& getFile(std::istream& istr);
      operator bool()const;
      unsigned lines()const;
      const char* name()const;
      const char* operator[](unsigned index)const;
   };
   std::ostream& operator<<(std::ostream& ostr, const TextFile& text);
   std::istream& operator>>(std::istream& istr, TextFile& text);

}
#endif // !SDDS_TEXTFILE_H__
