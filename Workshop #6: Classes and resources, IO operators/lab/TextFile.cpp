/**********************************************************
 * Name: Xuewei Sheng
 * Student ID: 061745121
 * Seneca email: xsheng3@myseneca.ca
 * Section: NFF
 **********************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include "TextFile.h"
#include "cstring.h"
using namespace std;
namespace sdds {
   Line::operator const char* () const {
      return (const char*)m_value;
   };

   Line& Line::operator=(const char* lineValue) {
      delete[] m_value;
      m_value = new char[strLen(lineValue) + 1];
      strCpy(m_value, lineValue);
      return *this;
   }
   Line::~Line() {
      delete[] m_value;
   }


   //deletes the m_textLines dynamic array and sets it to nullptr, deletes the m_filename dynamic Cstring and sets is to nullptr, sets m_noOfLines attribute to zero.
   void TextFile::setEmpty() {   
       delete[] m_textLines;
       m_textLines = nullptr;      
       delete[] m_filename;
       m_filename = nullptr;
       m_noOfLines = 0;
   }


   //If the isCopy argument is false, dynamically allocates a Cstring in m_filename and copies the content of the fname argument into it. If the isCopy argument is true, dynamically allocates a Cstring in m_filename and copies the content of the fname argument with a prefix of "C_" attached to it.
   void TextFile::setFilename(const char* fname, bool isCopy) {
       if (!isCopy)
       {           
           delete[] m_filename;
           int len = strLen(fname);
           m_filename = new char[len + 1];
           strCpy(m_filename, fname);
       }
       else
       {
           delete[] m_filename;
           int len = strLen(fname);
           m_filename = new char[len + 3];
           strCpy(m_filename, "C_");
           strCat(m_filename, fname);
       }
   }

   //Counts the number of lines in the file :
   //Creates a local ifstream object to open the file with the name held in m_filename.Then it will read the file,
   //character by character, and accumulates the number of newlines in the m_noOfLines attribute.
   //In the end, it will increase m_noOfLines by one, just in case, the last line does not have a new line at the end.
   //If the number of lines is zero, it will delete the m_filenameand set it to nullptr. (Setting the TextFile to a safe empty state)
   void TextFile::setNoOfLines() {
       ifstream f(m_filename);
       while (f)
       {
           if(f.get() == '\n')
           m_noOfLines ++;
       }
       if (m_noOfLines == 0)
       {
           delete[] m_filename;
           m_filename = nullptr;
       }
       else
       {
           m_noOfLines++;
       }
   }

  // Loads the text file m_filename into the dynamic array of Lines pointed by m_textLines :
  //If the m_filename is null, this function does nothing.
  //If the m_filename is not null(TextFile is not in a safe empty state), 
   //loadText() will dynamically allocate an array of Lines pointed by m_textLines with the size kept in m_noOfLines.
   // Make sure m_textLine is deleted before this to prevent memory leak.
       //Create a local instance of ifstream using the file name m_filename to read the lines of the text file.
       //Since the length of each line is unknown, read the line using a local C++ string objectand the getline helper function. 
       //(note: this is the HELPER getline function and not a method of istream).
       //In a loop reads each line into the string objectand then sets the m_textLines array elements to the values returned by the c_str() method of the string object until the reading fails(end of file reached).
       //After all the lines are read, make sure to update the value of m_noOfline to the actual number of lines read(This covers the possibility of one extra empty line at the end of the file)
   void TextFile::loadText() {
       if (m_filename)
       {
           ifstream f(m_filename);
           delete [] m_textLines;
           m_textLines = new Line[m_noOfLines];
           
           if (f.is_open())
           {
               int i = 0;
               string line;
               while (getline(f, line))
               {
                   m_textLines[i] = line.c_str();
                   i++;
               }
               m_noOfLines = i;
           }
       }
   }

   //Saves the content of the TextFile under a new name.
   //Use a local ofstream object to open a new file using the name kept in the argument filename.
   //Then loop through the elements of the m_textLines arrayand write them in the opened file adding a new line to the end of each line.
   void TextFile::saveAs(const char* fileName)const {
       ofstream f(fileName);
       if (f.is_open())
       {
           for (unsigned i = 0; i < m_noOfLines; i++)// i should be unsigned
           {
               f << m_textLines[i] << endl;
           }
       }
   }

   //Creates an empty TextFile and initializes the m_pageSize attribute using the pageSize argument.
   TextFile::TextFile(unsigned pageSize) : m_pageSize{ pageSize } {
       /*m_filename = nullptr;
       m_textLines = nullptr;
       m_noOfLines = 0;
       m_pageSize = pageSize;*/
       //do this in the member initialization
   }

   //Initializes the m_pageSize attribute using the pageSize argument and all the other attributes to nullptr and zero. Then if the filename is not null, it will set the filename, set the number of Lines and load the Text (using the corresponding private methods.)
   TextFile::TextFile(const char* filename, unsigned pageSize): m_pageSize { pageSize }
   {
       if (filename)
       {
           setFilename(filename);
           setNoOfLines();
           loadText();
       }
   }


   //Initializes the m_pageSize attribute using the m_pageSize of the incoming TextFile objectand
   //all the other attributes to nullptrand zero.
   //If the incoming Text object is in a valid State, performs the following tasks to copy the textfileand the content safely :
       //Sets the file - name to the name of the incoming TextFile object(isCopy set to true) See setFilename()
       // Saves the content of the incoming TextFile under the file name of the current TextFile
       //set the number of lines
       //loads the Text
   TextFile::TextFile(const TextFile& src) : m_pageSize{ src.m_pageSize } {
       if (src)
       {
           setFilename(src.m_filename, true);
           src.saveAs(m_filename);
           setNoOfLines();
           loadText();
       }
   }

   TextFile& TextFile::operator=(const TextFile& src) {
       if (*this && src && this != &src)
       {
           delete[] m_textLines;
           m_textLines = nullptr;
           src.saveAs(m_filename);
           setNoOfLines();
           loadText();
       }
       return *this;
   }

   TextFile::~TextFile() {
       delete[] m_textLines;
       m_textLines = nullptr;
       delete[] m_filename;
       m_filename = nullptr;
   }

   std::ostream& TextFile::view(std::ostream& ostr)const {
       if (m_noOfLines > 0)
       {
           int len = strLen(m_filename);
           ostr << m_filename << endl;
           ostr.width(len);
           ostr.fill('=');
           ostr << '=' << endl;
           for (unsigned i = 0; i < m_noOfLines; i++)
           {
               ostr << m_textLines[i] << endl;
               if ((i+1) % m_pageSize == 0)
               {
                   ostr << "Hit ENTER to continue...";
                   cin.ignore(1000, '\n');                          
               }               
           }
       }            
       return ostr;
   }

   std::istream& TextFile::getFile(std::istream& istr) {
       std::string fname;
       istr >> fname; 
       cin.ignore(1000, '\n');
       setFilename(fname.c_str());
       setNoOfLines();
       loadText();
       return istr;
   }
   TextFile::operator bool()const {
       return (m_filename != nullptr && m_textLines != nullptr && m_noOfLines > 0);
   }

   unsigned TextFile::lines()const {
       return m_noOfLines;
   }

   const char* TextFile::name()const {
       return m_filename;
   }

   const char* TextFile::operator[](unsigned index)const {
       const char* line = nullptr;
       if (*this)
       {
           line = m_textLines[index % m_noOfLines];
       }
       return line;
   }


   std::ostream& operator<<(std::ostream& ostr, const TextFile& text) {
       text.view(ostr);
       return ostr;
   }
   std::istream& operator>>(std::istream& istr, TextFile& text) {
       text.getFile(istr);
       return istr;
   }

}