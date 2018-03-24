#include <cstdio>
#include <queue>

#pragma warning(disable:4996)

#define MAX 100

using namespace std;

int map[MAX][MAX];
int ans[MAX][MAX];
bool chk[MAX][MAX];
int N, M;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0;i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}

	queue<pair<int, int>> q;

	q.push(make_pair(0, 0));
	chk[0][0] = true;
	ans[0][0] = 1;

	while (!q.empty())
	{
		int x = q.front().first; int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k]; int ny = y + dy[k];
			if (0 <= nx && nx < N && 0 <= ny && ny < M)
			{
				if (map[nx][ny] == 1 && chk[nx][ny] == false)
				{
					q.push(make_pair(nx, ny));
					ans[nx][ny] = ans[x][y] + 1;
					chk[nx][ny] = true;
				}
			}
		}
	}

	printf("%d\n", ans[N - 1][M - 1]);

	return 0;
}