#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;


int w[10][10];
int d[10];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;

	cin >> n;


	for (int i = 0; i < n; i++)
	{
		// d[[i] -> 모든 도시를 탐색하기 위해 도시번호를 저장. 나중에 순열로 만든다.
		d[i] = i;
		// w배열 입력
		for (int j = 0; j < n; j++)
		{
			cin >> w[i][j];
		}
	}

	int ans = 2147483647;

	do
	{
		// 경로가 존재하는가의 여부
		bool ok = true;
		int sum = 0;
		for (int i = 0; i < n-1; i++)
		{
			// 갈 수 없다면 false 
			if (w[d[i]][d[i + 1]] == 0) ok = false;
			// 갈 수 있으면 비용을 더해준다.
			else sum += w[d[i]][d[i + 1]];
		}

		// 돌아오는 경로까지 존재한다면 돌아오는 비용을 더해준다.
		if (ok && w[d[n - 1]][d[0]] != 0)
		{
			sum += w[d[n - 1]][d[0]];
			ans = ans > sum ? sum : ans;
		}
	} while (next_permutation(d, d+n));

	cout << ans << "\n";

	return 0;

}