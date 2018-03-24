#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

#define MAX 10001

bool visited[MAX];
int dist[MAX];
int from[MAX];
char how[MAX];
char cmd[4] = { 'D','S','L','R' };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	
	for (int test_case = 0; test_case < T; test_case++)
	{
		int a, b;
		cin >> a >> b;

		queue<int> q;
		q.push(a);
		visited[a] = true;
		dist[a] = 0;
		
		while (!q.empty())
		{
			int now = q.front(); q.pop();

			for (int i = 0; i < 4; i++)
			{
				if (cmd[i] == 'D')
				{
					int next = (now * 2) % 10000;
					if (visited[next] == false)
					{
						q.push(next);
						visited[next] = true;
						dist[next] = dist[now] + 1;
						from[next] = now;
						how[next] = cmd[i];
					}
				}
				else if (cmd[i] == 'S')
				{
					int next = now == 0 ? 9999 : now - 1;
					if (visited[next] == false)
					{
						q.push(next);
						visited[next] = true;
						dist[next] = dist[now] + 1;
						from[next] = now;
						how[next] = cmd[i];
					}
				}
				else if (cmd[i] == 'L')
				{
					int next = (now % 1000) * 10 + now / 1000;
					if (visited[next] == false)
					{
						q.push(next);
						visited[next] = true;
						dist[next] = dist[now] + 1;
						from[next] = now;
						how[next] = cmd[i];
					}
				}
				else if (cmd[i] == 'R')
				{
					int next = (now / 10) + (now % 10) * 1000;
					if (visited[next] == false)
					{
						q.push(next);
						visited[next] = true;
						dist[next] = dist[now] + 1;
						from[next] = now;
						how[next] = cmd[i];
					}
				}
			}
		}

		string ans = "";

		while (a != b)
		{
			ans += how[b];
			b = from[b];
		}

		// <algorithm> 필요
		reverse(ans.begin(), ans.end());

		cout << ans << "\n";
		
		// memset의 헤더는 <cstring>
		memset(dist, 0, sizeof(dist));
		memset(visited, false, sizeof(visited));
		memset(how, 0, sizeof(how));
		memset(from, 0, sizeof(from));
	}	

	return 0;
}