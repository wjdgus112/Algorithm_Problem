#include <iostream>
#include <string>

std::string s;

int main()
{
	std::getline(std::cin, s);

	int len = s.length();

	for (int i = 0; i < len; i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z') // �빮��
		{
			if (s[i] + 13 > 90)	s[i] -= 13 ;
			else s[i] += 13;
		}
		else if (s[i] >= 'a' && s[i] <= 'z') // �ҹ���
		{
			if (s[i] + 13 > 122) s[i] -= 13;
			else s[i] += 13;
		}
	}

	std::cout << s;

	return 0;
}