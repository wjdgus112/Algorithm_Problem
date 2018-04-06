#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define MAX_N 9

int n, m;
int map[MAX_N][MAX_N];
int temp_map[MAX_N][MAX_N];
int ans;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

vector<pair<int, int>> virus;
vector<int> safety_Zone;

void copy_map(int(*a)[MAX_N], int(*b)[MAX_N])
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			a[i][j] = b[i][j];
}

// BFS�� ���̷����� ������Ų��.
void BFS_Virus()
{
	int after_Wall[MAX_N][MAX_N];
	// ������ ���� �� ��Ȳ ����
	copy_map(after_Wall, temp_map);

	queue<pair<int, int>> q;
	// �ʱ� ���̷��� ��ǥ�� ť�� �ִ´�
	for (int i = 0; i < virus.size(); i++) q.push(virus[i]);

	while (!q.empty())
	{
		int x = q.front().first, y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k], ny = y + dy[k];
			if (0 <= nx && nx < n && 0 <= ny && ny < m)
			{
				// �� ĭ�̸� ������Ų��.
				if (after_Wall[nx][ny] == 0)
				{
					after_Wall[nx][ny] = 2;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}

	// ���������� ũ�⸦ ���Ѵ�.
	int safety_Size = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (after_Wall[i][j] == 0)
				safety_Size++;
		}
	}

	ans = ans > safety_Size ? ans : safety_Size;
}

// x,y�� ���� ���� ��, cnt�� ���� ����
void DFS_Wall(int cnt) 
{
	
	// ���� 3���� ���������� ũ�� ����
	if (cnt == 3)
	{
		BFS_Virus();
		return;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			// �� ĭ�̸�
			if (temp_map[i][j] == 0)
			{
				// ���� ���´�
				temp_map[i][j] = 1;
				// ���� �Ѱ� �߰��Ѵ�.
				DFS_Wall(cnt + 1);
				temp_map[i][j] = 0;
			}
		}
	}
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
			cin >> map[i][j];
			// ���̷��� ��ǥ ����
			if (map[i][j] == 2)
			{
				virus.push_back(make_pair(i, j));
			}
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 0)
			{
				copy_map(temp_map, map);
				temp_map[i][j] = 1;
				DFS_Wall(1);
				temp_map[i][j] = 0;
			}
		}
	}

	cout << ans << "\n";

	return 0;
}