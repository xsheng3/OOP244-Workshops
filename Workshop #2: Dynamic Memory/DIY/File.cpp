/**********************************************************
 * Name: Xuewei Sheng
 * Student ID: 061745121
 * Seneca email: xsheng3@myseneca.ca
 * Section: NFF
 **********************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds {
   FILE* fptr;
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }
   void closeFile() {
      if (fptr) fclose(fptr);
   }

   //read the postal code in the file, if read 3 charaters seccesfully, return the value of ture;
   bool read(char* postCode) {
       return fscanf(fptr, "%3s,", postCode) == 1;
   }

   //read the population size in the file, if read seccesfully, return the value of true;
   bool read(int& popSize) {
       return fscanf(fptr, "%d,", &popSize) == 1;
   }

}