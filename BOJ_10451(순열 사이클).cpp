#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int T, N;
vector<int> a[1001];
int chk[1001];
int ans;

void dfs(int node)
{
	chk[node] = 1;
	//cout << node << " ";
	for (int i = 0; i < a[node].size(); i++)
	{
		int next = a[node][i];
		if (chk[next] != 1)
		{
			dfs(next);
		}
	}
}

int main()
{
	cin >> T;

	while (T--)
	{
		cin >> N;

		for (int i = 1; i <= N; i++)
		{
			int v; cin >> v;
			a[i].push_back(v);
		}

		for (int i = 1; i <= N; i++)
		{
			if (chk[i] != 1)
			{
				dfs(i); ans++;
			}
		}

		cout << ans << "\n";

		for (int i = 1; i <= N; i++)
		{
			fill(a[i].begin(), a[i].end(), 0);
		}

		memset(chk, 0, sizeof(chk));

		ans = 0;

	}

	return 0;
}