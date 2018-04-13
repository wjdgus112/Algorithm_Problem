#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX_N 21
#define MIN_INF -987654321

int N, M;
int city[MAX_N][MAX_N];
int memo[MAX_N + 1];


int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1, 1, 0, 0 };

int ans;

void InitailzeMemo()
{
	for (int i = 1; i <= MAX_N; i++)
		memo[i] = i*i + (i - 1)*(i - 1);
}

bool IsRange(int x, int y)
{
	return 0 <= x && x < N && 0 <= y && y < N;
}

void Bfs(int start_x, int start_y)
{
	queue<pair<int, int>> q;
	bool visited[MAX_N][MAX_N] = {};

	visited[start_x][start_y] = true;
	q.push(make_pair(start_x, start_y));

	int q_size;
	int depth = 1;
	int house_cnt = city[start_x][start_y] == 1 ? 1 : 0;

	while (!q.empty())
	{
		q_size = q.size();

		// 수익이 운영 비용보다 많을 경우
		if (house_cnt*M >= memo[depth])
		{
			ans = max(ans, house_cnt);
		}

		if (depth == N + 1) return;

		while (q_size--)
		{
			int x = q.front().first, y = q.front().second;
			q.pop();

			for (int k = 0; k < 4; k++)
			{
				int nx = x + dx[k], ny = y + dy[k];

				// 범위를 벗어나거나 방문한 곳은 가지 않는다
				if (!IsRange(nx, ny) || visited[nx][ny]) continue;

				visited[nx][ny] = true;
				if (city[nx][ny] == 1)
					house_cnt++;
				q.push(make_pair(nx, ny));
			}
		}

		depth += 1;
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	InitailzeMemo();

	int T;

	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{

		cin >> N >> M;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> city[i][j];
			}
		}

		ans = MIN_INF;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				Bfs(i, j);
			}
		}

		cout << "#" << tc << " " << ans << "\n";
	}

	return 0;
}