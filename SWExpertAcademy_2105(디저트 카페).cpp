#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX_N 21
#define MIN_INF -987654321

#define LEFT_UP 0
#define LEFT_DOWN 1
#define RIGHT_UP 2
#define RIGHT_DOWN 3

int T;
int N;
int cafe[MAX_N][MAX_N];
int ans = MIN_INF;
bool check_dessert[101];
bool check_dir[4];

// 좌상, 좌하, 우상, 우하
int dx[4] = { -1,1,-1,1 };
int dy[4] = { -1,-1,1,1 };

void Initialize()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cafe[i][j] = 0;
		}
	}
}

bool IsRange(int x, int y)
{
	return 1 <= x && x <= N && 1 <= y && y <= N;
}

int GetConverse(int dir)
{
	int cdir = dir;

	if (dir == LEFT_UP) cdir = RIGHT_DOWN;
	else if (dir == LEFT_DOWN) cdir = RIGHT_UP;
	else if (dir == RIGHT_UP) cdir = LEFT_DOWN;
	else if (dir == RIGHT_DOWN) cdir = LEFT_UP;

	return cdir;
}

// 출발점, 현재좌표, 현재까지 먹은 디저트 개수
void Dfs(int start_x, int start_y, int curr_x, int curr_y, int cnt, int dir)
{

	if (curr_x == start_x && curr_y == start_y)
	{
		ans = max(ans, cnt);
		return;
	}
	
	for (int k = 0; k < 4; k++)
	{
		// 현재 방향과 반대 방향은 가지 않는다.
		if (k == GetConverse(dir)) continue;

		// 현재 방향과 다르지만 이전에 썻던 방향이면 가지 않는다.
		if (k != dir && check_dir[k]) continue;

		int next_x = curr_x + dx[k], next_y = curr_y + dy[k];

		// 범위 벗어나는 곳은 안간다.
		if (!IsRange(next_x,next_y)) continue;
		
		int next_dessert = cafe[next_x][next_y];

		bool IsStart = (next_x == start_x) && (next_y == start_y);

		if (IsStart)
			Dfs(start_x, start_y, next_x, next_y, cnt, k);
		
		// 먹었던 디저트를 가지고 있는 카페면 다음 방향
		if (check_dessert[next_dessert]) continue;

		check_dir[k] = true;
		check_dessert[next_dessert] = true;
		Dfs(start_x, start_y, next_x, next_y, cnt + 1, k);
		check_dessert[next_dessert] = false;
		check_dir[k] = false;
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> N;

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				cin >> cafe[i][j];
			}
		}

		ans = MIN_INF;

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				int next_x = i + dx[3], next_y = j + dy[3];

				if (!IsRange(next_x, next_y)) 
					continue;

				int start_dessert = cafe[i][j];
				int next_dessert = cafe[next_x][next_y];

				if (start_dessert != next_dessert)
				{
					check_dessert[start_dessert] = true;
					check_dessert[next_dessert] = true;
					check_dir[3] = true;
					Dfs(i, j, next_x, next_y, 2, 3);
					check_dessert[next_dessert] = false;
					check_dessert[start_dessert] = false;
					check_dir[3] = false;
				}
			}
		}

		if(ans==MIN_INF)
			cout << "#" << tc << " -1"<< "\n";
		else
			cout << "#" << tc << " " << ans << "\n";

		Initialize();
		memset(check_dessert, false, sizeof(check_dessert));
		memset(check_dir, false, sizeof(check_dir));
	}

	return 0;
}