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
	// ��� �׷���� ���ε��� BFS�� Ž���ؼ� �Ÿ��� ����Ѵ�.
	for (int gpnum = 1; gpnum <= group_max; gpnum++)
	{
		queue<pair <int, int>> q;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				grup_dis[i][j] = -1;

				// ���� �׷쿡 �ش��ϴ� ��ǥ�� �湮�� �������� ť�� �����Ѵ�.
				if (g[i][j] == gpnum)
				{
					q.push(make_pair(i, j));
					// �ش� �׷��� �ش��ϴ� ��ǥ�� �Ÿ����� 0���� �ʱ�ȭ �Ѵ�.
					grup_dis[i][j] = 0;
				}
			}
		}
		// BFS�� ���� �׷쿡�� �ٸ� �׷���� �Ÿ��� ����ϴ� ����.
		while (!q.empty())	
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			// �����¿�� �̵��ϸ� Ž��
			for (int k = 0; k < 4; k++)
			{
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (chk(nx, ny))
				{
					// �̵��� ���� �ش��ϴ� �׷��� ��ǥ�� �ƴϰ� �Ÿ����� ������
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
				// ���� �׷��� ���� �ƴ� �ٸ� ���� �湮�� ���
				if (a[i][j] == 1 && g[i][j] != gpnum)
				{
					// ���� �׷��� ������ ���� ��ǥ�� �������� �Ÿ��� ����� �ּҰ��� ans�� �����Ѵ�.
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