#include <iostream>
#include "Header.hpp"

int main()
{
	std::vector <std::vector <int>> vec;
	vec = an::LettersSort(an::NumberOfLetters());
	int* maxLet;
	maxLet = an::MaxLet(vec);
	an::ChangeText(maxLet);
	/*for (int i = 0; i < 5; i++) {						// 5 most common letters
		std::cout << char(maxLet[i]) << std::endl;
	}*/
	/*std::cout << std::endl;								//to check how many of each letter there is
	for (int i = 25; i >= 0; i--) {
		std::cout << vec[i][0] << " " << (char)vec[i][1] << std::endl;
	}*/
}