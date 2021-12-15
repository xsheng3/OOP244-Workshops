/**********************************************************
 * Name: Xuewei Sheng
 * Seneca email: xsheng3@myseneca.ca
 * Section: NFF
 **********************************************************/
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();
   bool read(char* postCode);
   bool read(int& popSize);

}
#endif // !SDDS_FILE_H_
