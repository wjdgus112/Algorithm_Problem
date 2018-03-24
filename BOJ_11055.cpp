#include <iostream>

int A[1001],DP[1001];

int main()
{
	int N,max=0;

	std::cin >> N;

	for (int i = 1; i <= N; i++) std::cin >> A[i];

	for (int i = 1; i <= N; i++)
	{
		DP[i] = A[i];
		for (int j = 1; j < i; j++)
		{
			if (A[j] < A[i] && DP[i] < DP[j] + A[i])
				DP[i] = DP[j] + A[i];
		}
		if (max < DP[i]) max = DP[i];
	}

	std::cout << max;

	return 0;
}