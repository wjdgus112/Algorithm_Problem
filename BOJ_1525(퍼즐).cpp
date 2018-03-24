#include <iostream>
#include <string>
#include <map>
#include <queue>

using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n = 3;
	int start = 0;

	// 2차원 배열이 아닌 하나의 정수로 나타낸다. (0을 9로 입력해서)
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			int temp;
			cin >> temp;
			if (temp == 0) {
				temp = 9;
			}
			start = start * 10 + temp;
		}
	}

	map<int, int> dist;
	queue<int> q;
	q.push(start);
	dist[start] = 0;

	while (!q.empty())
	{
		int now_num = q.front();
		string now = to_string(now_num);
		q.pop();

		int z = now.find('9');
		int x = z / 3;
		int y = z % 3;

		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n)
			{
				string next = now;
				swap(next[x * 3 + y], next[nx * 3 + ny]);
				int num = stoi(next);

				if (dist.count(num) == 0)
				{
					dist[num] = dist[now_num] + 1;
					q.push(num);
				}
			}
		}
	}

	// dist[123456789] : 2차원 배열이 123 / 456 / 780 으로 완성됐다는 의미.
	if (dist.count(123456789) == 0)
		cout << "-1" << "\n";
	else
		cout << dist[123456789] << "\n";

	return 0;
}