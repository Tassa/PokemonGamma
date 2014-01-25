#ifndef GENERAL_USEFULL_H
#define GENERAL_USEFULL_H

#include <string>

namespace stdUse
{
    const char numbersChars[10]={'0','1','2','3','4','5','6','7','8','9'};

	int sumOfIntArray(int* array, int size);

	std::string Uint_to_string(const unsigned int & n);

	std::string int_to_string(int n);

};

#endif
