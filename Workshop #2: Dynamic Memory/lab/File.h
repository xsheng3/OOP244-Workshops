
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
   // TODO: Declare read prototypes
   bool read(char* name);
   bool read(int& empNo);
   bool read(double& salary);

 

}
#endif // !SDDS_FILE_H_
