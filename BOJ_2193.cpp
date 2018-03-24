#include <iostream>

using namespace std;

int N;
long long D[91][2], ans;

int main()
{
	cin.sync_with_stdio(false);

	cin >> N;

	D[1][0] = 0; D[1][1] = 1;

	for (int i = 2; i <= N; i++)
	{
		D[i][0] = D[i - 1][0] + D[i - 1][1];
		D[i][1] = D[i - 1][0];
	}

	ans = D[N][0] + D[N][1];

	cout << ans << "\n";

	return 0;
}