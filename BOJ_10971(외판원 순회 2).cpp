#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;


int w[10][10];
int d[10];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;

	cin >> n;


	for (int i = 0; i < n; i++)
	{
		// d[[i] -> ��� ���ø� Ž���ϱ� ���� ���ù�ȣ�� ����. ���߿� ������ �����.
		d[i] = i;
		// w�迭 �Է�
		for (int j = 0; j < n; j++)
		{
			cin >> w[i][j];
		}
	}

	int ans = 2147483647;

	do
	{
		// ��ΰ� �����ϴ°��� ����
		bool ok = true;
		int sum = 0;
		for (int i = 0; i < n-1; i++)
		{
			// �� �� ���ٸ� false 
			if (w[d[i]][d[i + 1]] == 0) ok = false;
			// �� �� ������ ����� �����ش�.
			else sum += w[d[i]][d[i + 1]];
		}

		// ���ƿ��� ��α��� �����Ѵٸ� ���ƿ��� ����� �����ش�.
		if (ok && w[d[n - 1]][d[0]] != 0)
		{
			sum += w[d[n - 1]][d[0]];
			ans = ans > sum ? sum : ans;
		}
	} while (next_permutation(d, d+n));

	cout << ans << "\n";

	return 0;

}