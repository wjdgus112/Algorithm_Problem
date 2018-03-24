#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX 200000

bool chk[200000]; // i에 방문했는지의 여부
int dist[200000]; // dist[i] i까지 가는데 걸린 비용

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, k;

	cin >> n >> k;

	queue<int> q;
	chk[n] = true;
	q.push(n);
	dist[n] = 0;

	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		int num[3] = { node - 1,node + 1,node * 2 };

		for (int i = 0; i < 3; i++)
		{
			if (num[i] >= 0 && num[i] < MAX)
			{
				if (chk[num[i]] == false)
				{
					q.push(num[i]);
					chk[num[i]] = true;
					dist[num[i]] = dist[node] + 1;
				}
			}
		}
		
	}
	
	if (n == k) cout << 0 << "\n";
	else cout << dist[k] << "\n";

	return 0;
}