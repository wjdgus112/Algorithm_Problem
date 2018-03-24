#include <iostream>
#include <queue>

using namespace std;

#define MAX 100

int a[MAX][MAX];
int g[MAX][MAX];
int grup_dis[MAX][MAX];
int group_max;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int N;

bool chk(int x, int y)
{
	return 0 <= x && x < N && 0 <= y && y < N;
}

void BFS()
{
	int ans = -1;
	// 모든 그룹들을 따로따로 BFS로 탐색해서 거리를 계산한다.
	for (int gpnum = 1; gpnum <= group_max; gpnum++)
	{
		queue<pair <int, int>> q;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				grup_dis[i][j] = -1;

				// 현재 그룹에 해당하는 좌표만 방문할 정점으로 큐에 삽입한다.
				if (g[i][j] == gpnum)
				{
					q.push(make_pair(i, j));
					// 해당 그룹의 해당하는 좌표의 거리값을 0으로 초기화 한다.
					grup_dis[i][j] = 0;
				}
			}
		}
		// BFS로 현재 그룹에서 다른 그룹까지 거리를 계산하는 과정.
		while (!q.empty())	
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			// 상하좌우로 이동하며 탐색
			for (int k = 0; k < 4; k++)
			{
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (chk(nx, ny))
				{
					// 이동한 곳이 해당하는 그룹의 좌표가 아니고 거리값이 없으면
					if (grup_dis[nx][ny] == -1)
					{
						grup_dis[nx][ny] = grup_dis[x][y] + 1;
						q.push(make_pair(nx, ny));	
					}
				}
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				// 현재 그룹의 섬이 아닌 다른 섬을 방문할 경우
				if (a[i][j] == 1 && g[i][j] != gpnum)
				{
					// 현재 그룹의 섬부터 현재 좌표의 섬까지의 거리를 계산해 최소값을 ans에 저장한다.
					if (ans == -1 || grup_dis[i][j] - 1 < ans)
					{
						ans = grup_dis[i][j] - 1;
					}
				}
			}
		}
	}

	cout << ans;
}

void DFS(int x, int y, int cnt)
{
	g[x][y] = cnt;
	
	for (int k = 0; k < 4; k++)
	{
		int nx = x + dx[k];
		int ny = y + dy[k];

		if (chk(nx, ny))
		{
			if (a[nx][ny] == 1 && g[nx][ny] == 0)
			{
				DFS(nx, ny, cnt);
			}
		}
	}
}

void Input()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> a[i][j];
		}
	}
}

void divide_group()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (a[i][j] == 1 && g[i][j] == 0)
			{
				DFS(i, j, ++group_max);
			}
		}
	}
}

int main()
{

	Input();

	divide_group();

	BFS();

	return 0;
}