#include <iostream>
#include <cmath>

using namespace std;

int N;

void solve(int n, int x, int y)
{
	if (n == 0) return;

	solve(n - 1, x, 6 -x-y); // 6-x-y) : 2번째 장대
	cout << x << " " << y << "\n";
	solve(n - 1, 6 - x - y, y);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	cout << (1<<N)-1 << "\n";

	solve(N, 1, 3);

	return 0;
}