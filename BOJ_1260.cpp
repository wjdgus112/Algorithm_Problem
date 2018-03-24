#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M, V;
vector<int> a[1001];
bool chk[1001];

void DFS(int node)
{
	chk[node] = true;
	cout << node <<" ";
	for (int i = 0; i < a[node].size(); i++)
	{
		int next = a[node][i];
		if (chk[next] == false)
			DFS(next);
	}
}

void BFS(int start)
{
	queue<int> q;
	memset(chk, false, sizeof(chk));
	chk[start] = true; q.push(start);

	while (!q.empty())
	{
		int node = q.front(); q.pop();
		cout << node << " ";
		for (int i = 0; i < a[node].size(); i++)
		{
			int next = a[node][i];
			if (chk[next] == false)
			{
				chk[next] = true;
				q.push(next);
			}
		}
	}
}

int main()
{
	cin.sync_with_stdio(false);

	cin >> N >> M >> V;

	for (int i = 0; i < M; i++)
	{
		int x, y;

		cin >> x >> y;

		a[x].push_back(y); a[y].push_back(x);
	}
	
	for (int i = 1; i <= N; i++)
	{
		sort(a[i].begin(), a[i].end());
	}

	DFS(V);
	cout << "\n";
	BFS(V);

	return 0;
}