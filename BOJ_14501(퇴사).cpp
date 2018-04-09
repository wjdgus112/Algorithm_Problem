#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX_SIZE 16

int n;
int ans;
vector<pair<int, int>> vec_tp(MAX_SIZE, make_pair(0, 0));

void Recur(int curr_day, int curr_sum)
{
	// 끝나는 경우
	if (curr_day == n )
	{
		ans = max(ans, curr_sum);
		return;
	}

	int next_day = curr_day + vec_tp[curr_day].first;
	
	// 오늘 상담 하는 경우
	if (next_day <= n)
		Recur(next_day, curr_sum + vec_tp[curr_day].second);
	// 오늘 상담 안하는 경우
	if (curr_day + 1 <= n) 
		Recur(curr_day + 1, curr_sum);

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> vec_tp[i].first >> vec_tp[i].second;
	}

	Recur(0, 0);

	cout << ans << "\n";

	return 0;
}