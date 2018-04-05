#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

#define MAX 500002

int N, H;
int total_Bottom[MAX];
int total_Top[MAX];
int total[MAX];
int Top[MAX];
int Bottom[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> H;

	int min = INT_MAX;
	int ans_cnt = 1;

	for (int i = 0; i < N / 2; i++)
	{
		// 석순, 종유석s
		int val1, val2;

		cin >> val1 >> val2;

		Bottom[val1]++;
		Top[val2]++;
	}

	//Prefix sum
	for (int i = H; i >= 1; i--)
	{
		total_Bottom[i] = Bottom[i] + total_Bottom[i + 1];
		total_Top[i] = Top[i] + total_Top[i + 1];
	}

	for (int i = 1; i <= H; i++)
	{
		total[i] = total_Bottom[i] + total_Top[H-i+1];

		if (total[i] <= min)
			total[i] == min ? ans_cnt++ : ans_cnt = 1, min = total[i];
	}

	cout << min << " " << ans_cnt << "\n";

	return 0;
}