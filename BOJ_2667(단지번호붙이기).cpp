#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> a[26];
int visited[26][26];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int n;
int ans[25 * 25]; // n 최대값이 25 , 단지번호의 최대수 : 25*25

void dfs(int cnt,int x,int y)
{
	visited[x][y] = cnt;

	for (int k = 0; k < 4; k++)
	{
		int nx = dx[k] + x; int ny = dy[k] + y;
		if (0 <= nx && nx < n && 0 <= ny && ny < n)
		{
			if (a[nx][ny] == 1 && visited[nx][ny] == 0 )
			{
				dfs(cnt,nx, ny);
			}
		}
	}
}

int main()
{
	string str;

	cin.sync_with_stdio(false);

	cin >> n;

	cin.ignore();

	for (int i = 0; i < n; i++)
	{
		getline(cin, str);
		for (int j = 0; j < n; j++)
		{
			a[i].push_back(str[j]-48);
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] == 1 && visited[i][j] == 0)
			{
				dfs(++cnt, i, j);
			}
		}
	}

	cout << cnt << "\n";

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			ans[visited[i][j]] += 1;
		}
	}

	sort(ans + 1, ans + cnt + 1);

	for (int i = 1; i <= cnt; i++)
		cout << ans[i] << "\n";

	return 0;
}