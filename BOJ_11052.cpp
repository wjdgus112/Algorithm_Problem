#include <iostream>
#include <algorithm>

using namespace std;

int N;
int D[1001], P[1001];

int main()
{
	cin.sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> P[i];
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			D[i] = max(D[i], D[i - j] + P[j]);
		}
	}

	cout << D[N];

	return 0;
}