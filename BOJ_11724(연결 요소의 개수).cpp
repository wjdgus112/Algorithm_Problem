#include <iostream>
#include <vector>
using namespace std;

vector<int> a[1001];
bool check[1001];

int N, M, ans;

void DFS(int node)
{
	check[node] = true;

	for (int i = 0; i < a[node].size(); i++)
	{
		int next = a[node][i];
		if (check[next] == false)
		{
			DFS(next);
		}
	}
}
int main()
{
	cin.sync_with_stdio(false);
	
	cin >> N >> M;

	while (M--)
	{
		int u, v;
		cin >> u >> v;
		a[u].push_back(v); a[v].push_back(u);
	}

	for (int i = 1; i <= N; i++)
	{
		if (check[i] == false)
		{
			DFS(i);
			ans += 1;
		}
	}

	cout << ans << "\n";

	return 0;
}