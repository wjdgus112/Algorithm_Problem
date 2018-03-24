#include <cstdio>
#include <iostream>
#define MAX_SIZE 31

int dp[MAX_SIZE];

int main()
{
	int n;
	
	std::cin >> n;

	dp[0] = 1;
	dp[1] = 0;
	dp[2] = 3;
	for (int i = 3; i <= n; i++) {
		dp[i] += dp[i - 2] * 3;

		for (int j = 4; j <= i; j += 2) dp[i] += dp[i - j] * 2;
	}

	printf("%d\n", dp[n]);

	return 0;
}