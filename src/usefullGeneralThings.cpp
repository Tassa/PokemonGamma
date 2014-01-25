#include "usefullGeneralThings.h"

	int stdUse::sumOfIntArray(int* array, int size)
	{
		int n=0;
		for(int i=0;i<size;i++)
		{
			n+= array[i];
		}

		return n;
	}

	std::string stdUse::Uint_to_string(const unsigned int & n)
	{
		if(n<=0){return "";}

		std::string nb = stdUse::Uint_to_string(n/10);
		nb.push_back(stdUse::numbersChars[n%10]);
		return nb;
	}

	std::string stdUse::int_to_string(int n)
	{
		if(n==0){return "0";}
		std::string nb = "";
		if(n<0){nb.push_back('-');n=-n;}
		nb += stdUse::Uint_to_string(n);
		return nb;
	}

