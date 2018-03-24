#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int alpha[27];

int main()
{
	string str;
	int center = -1;
	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		alpha[str[i] - 'A']++;
	}

	for (int i = 0; i < 27; i++)
	{
		// 알파벳의 개수가 홀수개이면
		if (alpha[i] % 2)
		{
			// 그 알파벳이 중앙에 위치해야한다.
			if (center == -1)	center = i;
			// 홀수개인게 여러개이면 팰린드롬을 만들지 못한다.
			else
			{
				cout << "I'm Sorry Hansoo";
				return 0;
			}
		}
	}

	for (int i = 0; i < 27; i++)
	{

		if (alpha[i]) // 알파벳이 존재하면
		{
			for(int j=0;j<alpha[i]/2;j++) // 알파벳의 개수의 반을 출력한다.
				cout << (char)(i + 'A');
		}
	}
	
	// 중앙에 위치할 알파벳이 존재하면 출력한다. (문자열의 크기가 홀수란 의미)
	if (center != -1)
		cout << (char)(center + 'A');	

	for (int i = 26; i >= 0; i--)
	{
		// 팰린드롬은 중앙을 기준으로 반대로 출력해야한다.
		if (alpha[i])
		{
			for (int j = 0; j<alpha[i]/2; j++)
				cout << (char)(i + 'A');
		}
	}

	return 0;
}