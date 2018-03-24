#include <iostream>

int student[100],apple[100];

int main()
{
	int N,result=0;

	std::cin >> N;

	for (int i = 0; i < N; i++)
	{
		std::cin >> student[i] >> apple[i];
		result += apple[i] % student[i];
	}

	std::cout << result;

	return 0;
}