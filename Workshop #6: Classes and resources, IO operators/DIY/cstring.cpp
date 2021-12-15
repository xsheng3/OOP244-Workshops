/**********************************************************
 * Name: Xuewei Sheng
 * Student ID: 061745121
 * Seneca email: xsheng3@myseneca.ca
 * Section: NFF
 **********************************************************/

#include <iostream>
#include "cstring.h"
namespace sdds {
	// Copies the srouce character string into the destination
	void strCpy(char* des, const char* src)
	{
		int i = 0;
		while (src[i] != '\0')
		{
			des[i] = src[i];
			i++;
		}
		des[i] = 0;

	}


	// Copies the source character string into the destination upto "len"
	// characters. The destination will be null terminated only if the number
	// of the characters copied is less than "len"
	void strnCpy(char* des, const char* src, int len)
	{
		int i;
		for (i = 0; i < len; i++)
		{
			des[i] = src[i];
		}
		des[i] = 0;
	}


	// Compares two C-strings 
	// returns 0 if they are the same
	// return > 0 if s1 > s2
	// return < 0 if s1 < s2
	int strCmp(const char* s1, const char* s2)
	{
		int i = 0;
		int result = 0;
		bool match = true;
		while ((s1[i] != '\0' || s2[i] != '\0') && match == true)
		{
			if (s1[i] == s2[i])
			{
				result = 0;
				i++;
			}
			else if (s1[i] > s2[i])
			{
				result = 1;
				match = false;
			}
			else if (s1[i] < s2[i])
			{
				result = -1;
				match = false;
			}
		}
		return result;
	}

	// returns 0 if they are the same
	// return > 0 if s1 > s2
	// return < 0 if s1 < s2
	int strnCmp(const char* s1, const char* s2, int len)
	{
		int result = 0;
		bool match = true;
		for (int i = 0; i < len && match == true; i++)
		{
			if (s1[i] > s2[i])
			{
				result = 1;
				match = false;
			}
			else if (s1[i] < s2[i])
			{
				result = -1;
				match = false;
			}
			else
			{
				result = 0;
			}
		}
		return result;
	}


	// returns the lenght of the C-string in characters
	int strLen(const char* s)
	{
		int len = 0;
		while (s[len] != '\0')
		{
			len++;
		}
		return len;
	}

	// returns the address of first occurance of "str2" in "str1"
	// returns nullptr if no match is found
	const char* strStr(const char* str1, const char* str2)
	{
		int i = 0;
		bool found = false;
		const char* result = nullptr;

		while (str1[i] != '\0' && found != true)
		{
			if (str2[0] == str1[i])
			{
				found = true;
				int j = 0;
				int k = i;
				while (str2[j] != '\0' && found == true)
				{
					if (str2[j] != str1[k + j])
					{
						i++;
						found = false;
						break;
					}
					else
					{
						j++;
					}
				}
			}
			else
			{
				i++;
			}
		}

		if (found == true)
		{
			result = &str1[i];
		}

		return result;
	}
	// Concantinates "src" C-string to the end of "des"
	void strCat(char* des, const char* src)
	{
		int i = 0, j = 0;
		while (des[i] != '\0')
		{
			i++;
		}
		while (src[j] != '\0')
		{
			des[i + j] = src[j];
			j++;
		}
		des[i + j] = '\0';
	}

}