#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_SIZE 501
#define MIN_INF -987654321
#define MAX_INF 987654321

int ans = MIN_INF;
int n, m;
int paper[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

bool IsRange(int x, int y)
{
	return 0 <= x && x < n && 0 <= y && y < m;
}

void Dfs(int x, int y,int curr_cnt, int curr_sum)
{
	// 4개의 칸으로 완성되면 종료
	if (curr_cnt == 4)
	{
		ans = max(ans, curr_sum);
		return;
	}

	visited[x][y] = true;

	for (int k = 0; k < 4; k++)
	{
		int next_x = x + dx[k], next_y = y + dy[k];

		if (!IsRange(next_x, next_y)) continue;

		if (visited[next_x][next_y] == false)
		{
			Dfs(next_x, next_y, curr_cnt + 1, curr_sum + paper[x][y]);
		}
	}

	visited[x][y] = false;
}

// ㅗ 모양 체크
void CheckException(int x, int y)
{
	int min = MAX_INF;
	int sum = paper[x][y];
	int cnt = 0;

	for (int k = 0; k < 4; k++)
	{
		int next_x = x + dx[k], next_y = y + dy[k];

		if (!IsRange(next_x,next_y)) continue;

		cnt++;
		sum += paper[next_x][next_y];
		if (min > paper[next_x][next_y])
			min = paper[next_x][next_y];
	}

	if (cnt == 4)
		sum -= min;

	ans = max(ans, sum);

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> paper[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			Dfs(i, j, 0, 0);
			CheckException(i, j);
		}
	}

	cout << ans << "\n";

	return 0;
}