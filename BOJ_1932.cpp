#include <iostream>
#include <algorithm>
using namespace std;

int n,ans;
int DP[501][501];

int main()
{
	cin.sync_with_stdio(false);

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> DP[i][j];
			if (j == 1) DP[i][j] = DP[i - 1][j] + DP[i][j]; // 항상 맨 왼쪽 칸은 언제나 오른쪽 값과 더해진다.
			else if (j == i) DP[i][j] = DP[i - 1][j - 1] + DP[i][j]; // 각 층의 마지막 값은 항상 왼쪽 값과 더해진다.
			else DP[i][j] = max(DP[i - 1][j - 1], DP[i - 1][j]) + DP[i][j]; // 왼쪽, 오른쪽 둘 중에 큰 값과 더한다.

			if (ans < DP[i][j]) ans = DP[i][j];
		}
	}

	cout << ans;

	return 0;
}