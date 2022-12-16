#include "Header.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

// Capital letters: 65-90
// Small letters: 97-122
namespace an {
	std::vector<std::vector<int>> NumberOfLetters() {
		std::ifstream in("input.txt", std::ios::in);
		std::ofstream out("output.txt", std::ios::out);
		std::string str;
		int n = 26;
		int m = 2;
		std::vector<std::vector<int>> letters(n, std::vector<int>(m, 0));
		int num = 65;	// int('A')
		for (int i = 0; i < 26; i++) {		//fill second column of array with int(of letters)
			letters[i][1] = num;
			num++;
		}
		while (!in.eof())
		{
			in >> str;
			for (int i = 0; i < str.length(); i++)
			{
				if (unsigned char(str[i]) >= 65 && unsigned char(str[i]) <= 90)
				{
					letters[int(unsigned char(str[i] - 'A'))][0] += 1;
				}
				else if (unsigned char(str[i]) >= 97 && unsigned char(str[i]) <= 122)
				{
					letters[int(unsigned char(str[i] - 'a'))][0] += 1;
				}
			}
		}
		return letters;
		in.close();
		out.close();
	}
	void swap(int& a, int& b)
	{
		int tmp = a;
		a = b;
		b = tmp;
	}
	std::vector<std::vector<int>> LettersSort(std::vector<std::vector<int>> a) {
		for (int i = 0; i < a.size(); i++) {
			for (int j = i; j < a.size(); j++) {
				if (a[i][0] > a[j][0]) {
					swap(a[i][0], a[j][0]);
					swap(a[i][1], a[j][1]);
				}
			}
		}
		return a;
	}

	int* MaxLet(std::vector<std::vector<int>> a) {
		static int maxLet[5] = { 0 };
		int c = 0;
		for (int i = a.size() - 1; i > (a.size() - 6); i--) {
			maxLet[c] = a[i][1];
			c++;
		}
		return maxLet;
	}

	bool Atleast4(std::string s, int n[5]) {
		bool flag = false;
		int c = 0;
		for (int i = 0; i < s.length() - 1; i++) {
			for (int k = 0; k < 5; k++) {
				if (s[i] == (char)n[k] || s[i] == (char)(n[k] + 32)) {
					c++;
					break;
				}
			}
			if (c >= 4) {
				flag = true;
				return flag;
			}
		}
		return flag;
	}
	void ChangeText(int n[5]) {
		std::ifstream in("input.txt", std::ios::in);
		std::ofstream out("output.txt", std::ios::out);
		std::string str;
		while (!in.eof())
		{
			in >> str;
			if (Atleast4(str, n) == true) {
				bool flag = false;
				int foundLetters[10] = { 0 };
				int m = 0;
				for (int i = 0; i < str.length(); i++) {
					for (int k = 0; k < 5; k++) {
						if (str[i] == (char)(n[k] + 32)) {
							foundLetters[m] = (int)str[i];
							m++;
							out << (char)(n[k]);
							flag = true;
							break;
						}
						else if (str[i] == (char)n[k]) {
							foundLetters[m] = (int)str[i];
							m++;
							out << (char)(n[k]);
							flag = true;
							break;
						}
					}
					if (i == str.length() - 1) {
						if (str[i] < 'A' || str[i] > 'Z' && str[i] < 'a' || str[i] > 'z') {
							out << '(';
							for (int v = 0; v < str.length(); v++) {
								for (int j = 0; j < 10; j++) {
									if (str[v] == (char)foundLetters[j]) {
										out << str[v];
									}
								}
							}
							out << ')' << str[i];
							continue;
						}
						else {
							out << str[i] << '(';
							for (int v = 0; v < str.length(); v++) {
								for (int j = 0; j < 10; j++) {
									if (str[v] == (char)foundLetters[j]) {
										out << str[v];
									}
								}
							}
							out << ')';
							continue;
						}
					}

					if (!flag)
						out << str[i];
					flag = false;
				}
				out << " ";
			}
			else {
				out << str << " ";
			}
		}
		in.close();
		out.close();
	}
}
