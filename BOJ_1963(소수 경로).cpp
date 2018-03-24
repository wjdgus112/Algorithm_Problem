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


// Ǯ�̰���
// �����佺�׳׽��� ü �˰������� ��� �Ҽ��� ���Ѵ�
// change(num,index,digit) : num�̶�� ������ index�� digit���� �ٲ۴�.
// BFS�� ��� ��� Ž���ϸ� dist ����

int change(int num, int index, int digit)
{
	if (index == 0 && digit == 0) return -1; // ù��° �ڸ��� 0���� �ٲ��� ���Ѵ�.

	string tmp = to_string(num);

	tmp[index] = digit + '0';

	return stoi(tmp);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);


	for (int i = 2; i <= 10000; i++) prime[i] = true;

	// �Ҽ�����
	for (int i = 2; i <= 10000; i++)
	{
		if (prime[i])
		{
			// i�� ������� ��� �Ҽ��� �ƴϱ� ������ false������ ����.
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
						// ���� ���ڰ� �Ҽ��̸� ���� �湮���� ���� ���̸� �湮�Ѵ�.
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