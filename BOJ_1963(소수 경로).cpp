#include <iostream>
#include <cstring>
#include <string>
#include <queue>

using namespace std;

#define MAX 10001

bool chk[MAX];
bool prime[MAX];
int dist[MAX];
int n[4];


// 풀이과정
// 에라토스테네스의 체 알고리즘으로 모든 소수를 구한다
// change(num,index,digit) : num이라는 숫자의 index를 digit으로 바꾼다.
// BFS로 모든 경우 탐색하며 dist 저장

int change(int num, int index, int digit)
{
	if (index == 0 && digit == 0) return -1; // 첫번째 자리는 0으로 바꾸지 못한다.

	string tmp = to_string(num);

	tmp[index] = digit + '0';

	return stoi(tmp);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);


	for (int i = 2; i <= 10000; i++) prime[i] = true;

	// 소수저장
	for (int i = 2; i <= 10000; i++)
	{
		if (prime[i])
		{
			// i의 배수들은 모두 소수가 아니기 때문에 false값으로 저장.
			for (int j = i*i; j <= 10000; j += i) prime[j] = false;
		}
	}

	int T;

	cin >> T;

	for (int test_case = 0; test_case < T; test_case++)
	{
		int a, b;

		cin >> a >> b;

		memset(dist, 0, sizeof(dist));
		memset(chk, false, sizeof(chk));
		
		queue<int> q;
		chk[a] = true;
		dist[a] = 0;
		q.push(a);

		while (!q.empty())
		{
			int now = q.front(); q.pop();

			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					int next = change(now, i, j);

					if (next != -1)
					{
						// 다음 숫자가 소수이며 아직 방문하지 않은 수이면 방문한다.
						if (prime[next] && chk[next] == false)
						{
							q.push(next);
							dist[next] = dist[now] + 1;
							chk[next] = true;
						}
					}
				}
			}
		}

		cout << dist[b] << "\n";
	}

	return 0;
}