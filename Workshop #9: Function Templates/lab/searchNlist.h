/**********************************************************
 * Name: Xuewei Sheng
 * Student ID: 061745121
 * Seneca email: xsheng3@myseneca.ca
 * Section: NFF
 **********************************************************/
#define CRT_SECURE_NO_WARNINGS
#ifndef SDDS_SEARCHNLIST_H_
#define SDDS_SEARCHNLIST_H_
#include"Collection.h"
#include<cstring>
using namespace std;
namespace sdds {
		template <typename T1, typename T2>
		bool search(Collection<T1>&	C, T1 c[], int size, T2 key)
		{
			bool result = false;
			for (int i = 0; i < size; i++)
			{
				if (c[i] == key)
				{
					C.add(c[i]);
					result = true;
				}
			}
			return result;
		}
		
		template <typename T>
		void listArrayElements(const char* title, const T a[], int size)
		{
			cout << title << endl;
			for (int i = 0; i < size; i++) 
			{
				cout << i + 1 << ": " << a[i] << endl;
			}
		}
}
#endif