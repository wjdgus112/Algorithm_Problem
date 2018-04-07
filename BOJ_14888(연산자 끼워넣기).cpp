#include <iostream>
#include <algorithm>

using namespace std;

#define INF 987654321

int n;
bool visited[10];
int numbers[11];
int op[10];
long long min_ans = INF, max_ans=-INF;
int plus_cnt, minus_cnt, multi_cnt, divide_cnt;


void Dfs(long long curr_result, int num_idx, int plus,int minus,int multi,int divide)
{
	// 연산자가 n-1개면 종료
	if (num_idx == n)
	{
		min_ans = min(min_ans, curr_result );
		max_ans = max(max_ans, curr_result);
		return;
	}

	if (plus < plus_cnt) Dfs(curr_result + numbers[num_idx], num_idx + 1, plus + 1, minus, multi, divide);
	if (minus < minus_cnt) Dfs(curr_result - numbers[num_idx], num_idx + 1, plus, minus + 1, multi, divide);
	if (multi < multi_cnt) Dfs(curr_result * numbers[num_idx], num_idx + 1, plus, minus, multi + 1, divide);
	if (divide < divide_cnt) Dfs(curr_result / numbers[num_idx], num_idx + 1, plus, minus, multi , divide + 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) cin >> numbers[i];

	int idx = 0;
	
	cin >> plus_cnt >> minus_cnt >> multi_cnt >> divide_cnt;

	Dfs(numbers[0],1,0,0,0,0);

	cout << max_ans << "\n" << min_ans << "\n";

	return 0;
}