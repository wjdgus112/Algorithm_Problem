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
			if (j == 1) DP[i][j] = DP[i - 1][j] + DP[i][j]; // �׻� �� ���� ĭ�� ������ ������ ���� ��������.
			else if (j == i) DP[i][j] = DP[i - 1][j - 1] + DP[i][j]; // �� ���� ������ ���� �׻� ���� ���� ��������.
			else DP[i][j] = max(DP[i - 1][j - 1], DP[i - 1][j]) + DP[i][j]; // ����, ������ �� �߿� ū ���� ���Ѵ�.

			if (ans < DP[i][j]) ans = DP[i][j];
		}
	}

	cout << ans;

	return 0;
}