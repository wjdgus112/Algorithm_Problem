#include <iostream>

using namespace std;

#define MAX_N 100001

int n, m;
int a[MAX_N];

int solution()
{
	int left = 0, right = 0, now_Sum = a[0];

	int ans = n + 1;

	while (left <= right && right < n)
	{
		if (now_Sum < m)
		{
			right += 1;
			now_Sum += a[right];
		}
		else if (now_Sum == m)
		{
			if (ans > right - left + 1)
				ans = right - left + 1;

			right += 1;
			now_Sum += a[right];
		}
		else if (now_Sum > m)
		{
			if (ans > right - left + 1)
				ans = right - left + 1;

			now_Sum -= a[left];
			left++;
			// left가 right보다 커진 경우 바꿔준다
			if (left > right && left < n)
			{
				right = left;
				now_Sum = a[left];
			}
		}
	}

	if (ans > n) return 0;
	else return ans;
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

	int left = 0, right = 0, now_Sum = a[0];

	int ans = n + 1;

	while (left <= right && right < n)
	{
		if (now_Sum < m)
		{
			right += 1;
			now_Sum += a[right];
		}
		else if (now_Sum == m)
		{
			if (ans > right - left + 1)
				ans = right - left + 1;

			right += 1;
			now_Sum += a[right];
		}
		else if (now_Sum > m)
		{
			if (ans > right - left + 1)
				ans = right - left + 1;

			now_Sum -= a[left];
			left++;
			// left가 right보다 커진 경우 바꿔준다
			if (left > right && left < n)
			{
				right = left;
				now_Sum = a[left];
			}
		}
	}

	cout << solution() << "\n";

	return 0;
}