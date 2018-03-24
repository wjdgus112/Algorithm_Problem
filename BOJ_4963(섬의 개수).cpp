#include <iostream>

using namespace std;

int map[51][51];
int visited[51][51];
int dx[8] = { 0,0,1,-1,-1,-1,1,1 };
int dy[8] = { 1,-1,0,0,-1,1,-1,1 };
int w, h;

void dfs(int x,int y)
{
	visited[y][x] = 1;
	for (int k = 0; k < 8; k++)
	{
		int nx = x + dx[k]; int ny = y + dy[k];
		if (nx >= 0 && nx < w && ny >= 0 && ny < h)
		{
			if(map[ny][nx] == 1 && visited[ny][nx] == 0)
				dfs(nx, ny);
		}
	}

}
int main()
{

	while(true)
	{
		cin >> w >> h;

		if (w == 0 && h == 0) break;

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> map[i][j];
				visited[i][j] = 0;
			}
			
		}

		int cnt = 0;

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (visited[i][j] == 0 && map[i][j] == 1)
				{
					dfs(j, i);
					cnt++;
				}

			}
		}

		cout << cnt << "\n";
	}

	
	return 0;
}