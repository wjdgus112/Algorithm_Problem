#include <iostream>
#include <algorithm>

using namespace std;
int DP[10001], wine[10001];

int main()
{
	int n;

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> wine[i];
	}

	for (int i = 1; i <= n; i++)
	{
		int ans = 0;
		if (i <= 2) DP[i] = wine[i] + wine[i - 1]; // DP[1] , DP[2] 초기화
		ans = max(DP[i - 1], // 현재 포도주를 마시지 않는 경우
				max(wine[i] + DP[i - 2],  // 현재 포도주를 마시고 이전 포도주를 마시지 않는 경우
					DP[i - 3] + wine[i] + wine[i - 1])); // 현재 포도주와 이전 포도주를 마시는 경우
		DP[i] = ans;
	}

	cout << DP[n];

	return 0;
}