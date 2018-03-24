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
		else // 3��° ����� ���
			DP[i] = max(DP[i - 2] + stair[i], stair[i-1] + stair[i]);

		if (i >= 4) // 4��° �̻� ����� ���
			DP[i] = max(stair[i] + DP[i - 2], stair[i] + stair[i - 1] + DP[i - 3]); // ���� ��ܸ� ���� ���� ����,���� ��� ���� ��� ��

	}

	cout << DP[n];

	return 0;
}
