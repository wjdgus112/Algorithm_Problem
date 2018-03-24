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
		if (i <= 2) DP[i] = wine[i] + wine[i - 1]; // DP[1] , DP[2] �ʱ�ȭ
		ans = max(DP[i - 1], // ���� �����ָ� ������ �ʴ� ���
				max(wine[i] + DP[i - 2],  // ���� �����ָ� ���ð� ���� �����ָ� ������ �ʴ� ���
					DP[i - 3] + wine[i] + wine[i - 1])); // ���� �����ֿ� ���� �����ָ� ���ô� ���
		DP[i] = ans;
	}

	cout << DP[n];

	return 0;
}