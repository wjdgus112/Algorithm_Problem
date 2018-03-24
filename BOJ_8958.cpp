#include <iostream>
#include <cstring>
using namespace std;
#define SIZE 80
int main()
{
	int N,num=1;
	char str[SIZE];
	cin >> N;

	int *score = new int[N] {0, };

	for (int i = 0; i < N; i++)
	{
		cin >> str;

		for (int j = 0; j < strlen(str); j++)
		{
			if (str[j] == 'O')
			{
				score[i] += num++;
			}
			if (str[j] == 'X') num = 1;
		}
		num = 1;
	}

	
	for (int i = 0; i < N; i++)
	{
		cout << score[i] << endl;
	}

	delete[] score;
	score = NULL;

	return 0;
}