#pragma once
#include <string>
#include <vector>

namespace an {
	std::vector<std::vector<int>> NumberOfLetters();
	void swap(int& a, int& b);
	std::vector<std::vector<int>> LettersSort(std::vector<std::vector<int>> a);
	int* MaxLet(std::vector<std::vector<int>> a);
	bool Atleast4(std::string s, int n[5]);
	void ChangeText(int n[5]);
}