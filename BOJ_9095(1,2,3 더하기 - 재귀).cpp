#include <iostream>

using namespace std;

int go(int cnt, int sum, int goal)
{
	if (sum > goal) return 0;
	if (sum == goal) return 1;

	int now = 0;
	for (int i = 1; i <= 3; i++)
	{
		now += go(cnt + 1, sum + i, goal);
	}

	return now;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int T;

	cin >> T;

	for (int test_case = 0; test_case < T; test_case++)
	{
		int n;
		cin >> n;

		int ans = go(0, 0, n);
		cout << ans << "\n";
	}

	return 0;
}