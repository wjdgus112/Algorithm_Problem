#include <iostream>

using namespace std;

#define MAX_N 10001

int n, m;
int a[MAX_N];
int ans;

void solution()
{
	int left = 0, right = 0,now_Sum=a[0];

	while (left <= right && right < n)
	{
		// ���� ������ ���� m�� ���� ��� 
		// right += 1
		if (now_Sum == m)
		{
			ans += 1;
			right += 1;
			now_Sum += a[right];
		}
		// ���� ������ ���� m���� Ŭ ���
		else if (now_Sum > m)
		{
			now_Sum -= a[left];
			left += 1;

			// left�� right���� Ŀ�� ��� �ٲ��ش�
			if (left > right && left < n)
			{
				right = left;
				now_Sum = a[left];
			}
		}
		// ���� ������ ���� m���� ���� ���
		else if (now_Sum < m)
		{
			right += 1;
			now_Sum += a[right];
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	solution();

	cout << ans << "\n";

	return 0;
}