#include <iostream>
#pragma warning(disable:4996)

int children[201], DP[201];

int main()
{
	int N,max=0;

	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &children[i]);
	}

	for (int i = 1; i <= N; i++)
	{
		DP[i] = 1;
		for (int j = 1; j < i; j++)
		{
			if (children[j] < children[i] && DP[i] < DP[j] + 1)
				DP[i]++;
			if (max < DP[i]) max = DP[i];
		}
	}

	printf("%d", N-max);

	return 0;
}