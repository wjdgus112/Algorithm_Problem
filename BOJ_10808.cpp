#include <iostream>
#include <string>

int alpha[26];
int main()
{
	std::string S;

	std::cin >> S;

	for (int i = 0; i < S.length(); i++)
	{
		for (int j = 'a'; j <= 'z'; j++)
		{
			if (S[i] == j)
				alpha[j - 97]++;
		}
	}

	for (int i = 0; i < 26; i++)
	{
		std::cout << alpha[i];
		if (i != 25) std::cout << " ";
	}

	return 0;
}