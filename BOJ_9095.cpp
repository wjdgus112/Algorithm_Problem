#include <iostream>

using namespace std;

int DP[11];

int main()
{
	int T,n;

	cin >> T;

	DP[1] = 1; DP[2] = 2; DP[3] = 4;

	for (int i = 4; i <= 10; i++)
	{
		DP[i] = DP[i - 1] + DP[i - 2] + DP[i - 3];
	}

	while (T--)
	{
		cin >> n;
		cout << DP[n] << endl;
	}

	return 0;
}