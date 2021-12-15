/**********************************************************
 * Name: Xuewei Sheng
 * Seneca email: xsheng3@myseneca.ca
 * Section: NFF
 **********************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cstring.h"  // implemented in workshop 1 part 2 (DIY)
#include "Employee.h"
#include "File.h"
using namespace std;

namespace sdds {

   int noOfEmployees;
   Employee* employees;


   void sort() {
      int i, j;
      Employee temp;
      for (i = noOfEmployees - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (employees[j].m_empNo > employees[j + 1].m_empNo) {
               temp = employees[j];
               employees[j] = employees[j + 1];
               employees[j + 1] = temp;
            }
         }
      }
   }

   // TODO: Finish the implementation of the 1 arg load function which
   // reads one employee record from the file and loads it into the employee reference
   // argument
   bool load(Employee& em) {
      bool ok = false;
      char name[128];
      /* if reading of employee number, salay and name are successful
              allocate memory to the size of the name + 1
              and keep its address in the name of the Employee Reference

              copy the name into the newly allocated memroy

              make sure the "ok" flag is set to true
         end if
      */  
     
      if (read(em.m_empNo) && read(em.m_salary) && read(name)) 
      {
          
          int len = strLen(name);
          em.m_name = new char[len+1];
          strCpy(em.m_name, name);
          ok = true;
      }

      return ok;
   }
   // TODO: Finish the implementation of the 0 arg load function 
   bool load() {
      bool ok = false;
      
      if (openFile(DATAFILE)) 
      {
          noOfEmployees = noOfRecords();
          employees = new Employee[noOfEmployees];

          int i;
          bool exitloop = false;
          for (i = 0; i < noOfEmployees && !exitloop;)
          {
              if (!load(employees[i])) 
              {
                  exitloop = true;
              }
                  
              else
              {
                  i++;
              }                  
          }
          if (i != noOfEmployees)
          {
              cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
          }
          else
          {
              ok = true;
          }

          closeFile();
         /* 
          Set the noOfEmployees to the number of recoreds in the file.
          dyanamically allocated an array of employees into the global
          Employee pointer; "employees" to the size of the noOfEmployees.

          In a loop load the employee records from the file into 
          the dynamic array.

          If the number of the records does not match the number of reads
             print the message
            "Error: incorrect number of records read; the data is possibly corrupted"
          Otherwise
             set the ok flag to true
          End if

          close the file
          */
      }
      else {
         cout << "Could not open data file: " << DATAFILE<< endl;
      }
      return ok;
   }

   // TODO: Implementation for the display functions go here
   void display (const Employee& em)
   {
       cout << em.m_empNo << ": "<< em.m_name<< ", " << em.m_salary << endl;
   }
   
   void display()
   {
       cout << "Employee Salary report, sorted by employee number" << endl 
           << "no- Empno, Name, Salary" << endl 
           << "------------------------------------------------" << endl;
       sort();
       for (int i = 0; i < noOfEmployees; i++)
       {
           cout << i + 1 << "- ";
           display(employees[i]);
       }

   }

   // TODO: Implementation for the deallocateMemory function goes here
   void deallocateMemory()
   {
       for (int i = 0; i < noOfEmployees; i++)
       {
           delete [] employees[i].m_name;
           employees[i].m_name = nullptr;
       }
       delete [] employees;
       employees = nullptr;
   }


}
