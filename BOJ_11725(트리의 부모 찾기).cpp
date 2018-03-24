#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 100001

int N;
int parent[MAX];
bool chk[MAX];
vector<int> a[MAX];

int main()
{
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N-1; i++)
	{
		int u, v;

		cin >> u >> v;
		
		a[u].push_back(v); a[v].push_back(u);
	}

	queue<int> q;

	parent[1] = 0; // ��Ʈ�� �θ�� ���� 
	chk[1] = true;
	q.push(1);

	// BFS ����
	while (!q.empty())
	{
		int x = q.front(); q.pop();
		for (int y : a[x]) // ���� ��� for�� 
		{
			if (!chk[y])
			{
				chk[y] = true;
				parent[y] = x;
				q.push(y);
			}
		}
	}

	for (int i = 2; i <= N; i++)
		cout << parent[i] << "\n";

	return 0;
}