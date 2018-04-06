#include <iostream>

using namespace std;

#define MAX_N 21

int n, sum;
int num[MAX_N];
int ans;

void sub(int i, int prev_Sum)
{
	// index�� ������ ������ ����
	if (i == n)
	{
		// sum�� ������ ans++
		if (prev_Sum == sum)
			ans++;
		return;
	}

	// ���ڸ� ����ϴ� ���
	sub(i + 1, prev_Sum + num[i]);
	// ������� �ʴ� ���
	sub(i + 1, prev_Sum);

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> sum;

	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}

	sub(0, 0);

	if (sum == 0) ans -= 1;

	cout << ans << "\n";

	return 0;
}