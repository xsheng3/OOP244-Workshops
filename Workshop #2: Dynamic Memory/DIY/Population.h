/**********************************************************
 * Name: Xuewei Sheng
 * Seneca email: xsheng3@myseneca.ca
 * Section: NFF
 **********************************************************/
#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_

namespace sdds {
    struct Population {
        char m_postCode[4];
        int m_popSize;
    };
    //sorts the array of populations based on the size of the population.
    void sort();
    // loads a population structue with its values from the file
    bool load(Population& pop);
    // loads all the file recoreds into the array
    bool load(const char* FILEname);

   
    // displays a population record on the screen:
    int display(const Population& pop);

   
    // first sorts the population records then displays all the population recoreds on the screen
    void display();

    // deallocates the population array 
    void deallocateMemory();


}
#endif // SDDS_POPULATION_H_
