#include <iostream>

using namespace std;

int N;
long long D[101][101];
long long mod = 1000000000;

int main()
{
	cin.sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= 9; i++) D[1][i] = 1;

	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			D[i][j] = 0;

			if (j-1 >= 0) D[i][j] += D[i - 1][j - 1];
			if (j + 1 <= 9) D[i][j] += D[i - 1][j + 1];

			D[i][j] %= mod;
		}
	}

	long long ans = 0;
	
	for (int i = 0; i <= 9; i++)
	{
		ans += D[N][i];
	}

	ans %= mod;

	cout << ans;

	return 0;
}