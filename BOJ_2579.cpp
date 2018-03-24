#include <iostream>
#include <algorithm>

using namespace std;
int DP[301], stair[301];

int main()
{
	int n;

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> stair[i];
	}

	for (int i = 1; i <= n; i++)
	{
		if (i != 3) DP[i] = DP[i - 1] + stair[i];
		else // 3번째 계단일 경우
			DP[i] = max(DP[i - 2] + stair[i], stair[i-1] + stair[i]);

		if (i >= 4) // 4번째 이상 계단일 경우
			DP[i] = max(stair[i] + DP[i - 2], stair[i] + stair[i - 1] + DP[i - 3]); // 현재 계단만 밟을 경우와 현재,이전 계단 밟을 경우 비교

	}

	cout << DP[n];

	return 0;
}
