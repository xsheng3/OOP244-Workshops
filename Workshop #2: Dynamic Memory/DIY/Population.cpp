/**********************************************************
 * Name: Xuewei Sheng
 * Seneca email: xsheng3@myseneca.ca
 * Section: NFF
 **********************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Population.h"
#include "File.h"
#include <cstring>

using namespace std;

namespace sdds {
    int noOfPostCode;
    Population* population;

    //sort by pupulation size of each postal code
    void sort() {
        int i, j;
        Population temp;
        for (i = noOfPostCode - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (population[j].m_popSize > population[j + 1].m_popSize) {
                    temp = population[j];
                    population[j] = population[j + 1];
                    population[j + 1] = temp;
                }
            }
        }
    }

    // reads one population record from the file and loads it into the population reference
    // argument
    bool load(Population& pop) {
        bool ok = false;
        char Post[4];

        /* if reading of postal code, populatio size are successful, 
              copy the postal code into the the pop.m_postCode 
              set "ok" flag to true
           end if
        */
        if (read(Post) && read(pop.m_popSize))
        {
            strcpy(pop.m_postCode, Post);
            ok = true;
        }

        return ok;
    }
    
    bool load(const char* FILEname) {
        bool ok = false;

        if (openFile(FILEname))
        {
            /*Set the noOfpostCode to the number of recoreds in the file.
              dyanamically allocated an array of population into the global
              Population pointer; "population" to the size of the noOfPostCode.
            */
            noOfPostCode = noOfRecords();
            population = new Population[noOfPostCode];

            /*
            In a loop load the population records from the file into
             the dynamic array.

             If the number of the records does not match the number of reads
                print the message
               "Error: incorrect number of records read; the data is possibly corrupted"
             Otherwise
                set the ok flag to true
             End if
            */
            int i;
            bool exitloop = false;
            for (i = 0; i < noOfPostCode && !exitloop;)
            {
                if (!load(population[i]))
                {
                    exitloop = true;
                }

                else
                {
                    i++;
                }
            }
            if (i != noOfPostCode)
            {
                cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
            }
            else
            {
                ok = true;
            }

            //close the file
            closeFile();
            
        }
        else {
            cout << "Could not open data file: " << FILEname << endl;
        }
        return ok;
    }

    //display one record of popultion 
    int display(const Population& pop)
    {
        cout << pop.m_postCode << ":  " << pop.m_popSize << endl;
        return pop.m_popSize;
    }

    //display all the record in the given file.
    void display()
    {
        int count = 0;
        cout << "Postal Code: population" << endl
            << "-------------------------" << endl;
        sort();
        for (int i = 0; i < noOfPostCode; i++)
        {
            cout << i + 1 << "- ";
            count += display(population[i]);
        }
        cout << "-------------------------" << endl
            << "Population of Canada: " << count << endl;
    }

    //dellocate the dynamic memory for the array of population.
    void deallocateMemory()
    {
        delete[] population;
        population = nullptr;
    }




}
