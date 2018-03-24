#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 0 : 빈칸, 1: 벽, 2: 바이러스
#define MAX_SIZE 8

int map[MAX_SIZE][MAX_SIZE];
int tmp_map[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int ans;
int N, M;
vector<pair<int, int>> virus;

void recovery()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			tmp_map[i][j] = map[i][j];
			visited[i][j] = 0;
		}
	}

}

int get_safetyArea()
{
	int safetyArea = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (tmp_map[i][j] == 0) 
				safetyArea++;
		}
	}

	return safetyArea;
}

void dfs_for_virus()
{
	queue<pair<int, int>> q;
	
	for (int i = 0; i < virus.size(); i++)
		q.push(virus[i]);

	while (!q.empty())
	{
		int x = q.front().first; int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k]; int ny = y + dy[k];
			if (0 <= nx && nx < N && 0 <= ny && ny < M && tmp_map[nx][ny] == 0)
			{
				tmp_map[nx][ny] = 2;
				q.push(make_pair(nx, ny));
			}
		}
	}
}

void dfs_for_wall(int x, int y,int cnt_wall)
{
	visited[x][y] = true;
	tmp_map[x][y] = 1;

	if (cnt_wall == 3)
	{
		dfs_for_virus();

		ans = max(ans,get_safetyArea());

		recovery();

		visited[x][y] = 0;
		tmp_map[x][y] = 0;
		return;
	}

	for (int i = x; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (tmp_map[i][j] == 0 && visited[i][j] == 0)
			{
				dfs_for_wall(i, j, cnt_wall + 1);
			}
		}
	}

	tmp_map[x][y] = 0;
	visited[x][y] = 0;
}

int main()
{
	cin.sync_with_stdio(false);
	
	cin >> N >> M;

	// 연구소의 지도모양 입력
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 2) virus.push_back(make_pair(i, j));
			tmp_map[i][j] = map[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			// 벽 세우기
			if (map[i][j] != 0) continue;
			dfs_for_wall(i, j, 1);
		}
	}

	cout << ans;


	return 0;
}