#include <iostream>
#include <queue>

using namespace std;

#define MAX 1000

int N, M;

int map[MAX][MAX];
int tomato[MAX][MAX];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

int main()
{
	ios::sync_with_stdio(false);

	cin >> M >> N;

	queue<pair<int, int>> q;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			tomato[i][j] = -1;
			if (map[i][j] == 1)
			{
				q.push(make_pair(i, j));
				tomato[i][j] = 0;
			}
		}
	}


	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int k = 0; k < 4; k++)
		{
			// 상하좌우로 이동
			int nx = x + dx[k]; int ny = y + dy[k];

			if (0 <= nx && nx < N && 0 <= ny && ny < M)
			{
				// 상하좌우로 이동해서 토마토가 익지 않은 경우 방문
				if ( map[nx][ny] == 0 && tomato[nx][ny] == -1)
				{
					tomato[nx][ny] = tomato[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}

	int ans = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (ans < tomato[i][j])
			{
				ans = tomato[i][j];
			}
		}
	}

	// 토마토가 모두 익지 못한 경우 판단
	for (int i = 0; i<N; i++) {
		for (int j = 0; j<M; j++) {
			if (map[i][j] == 0 && tomato[i][j] == -1) {
				ans = -1;
			}
		}
	}

	cout << ans << "\n";

	return 0;
}