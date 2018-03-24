#include <iostream>

using namespace std;

int DP[16][16]; // 해당 위치까지 올 수 있는 경로의 개수
int N,M,K,point_x,point_y;

int main()
{
	int cnt=1,sum_1;

	cin >> N >> M >> K;

	DP[1][1] = 1;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (cnt == K) // o자로 표시된 번호의 격자칸 좌표 저장
			{
				point_x = j;
				point_y = i;
			}
			cnt++;
			if (i == 1 && j == 1) continue;
			DP[i][j] = DP[i - 1][j] + DP[i][j - 1];
		}
	}

	if (K == 0) cout << DP[N][M];
	else
	{
		sum_1 = DP[point_y][point_x];

		DP[point_y][point_x] = 1;

		for (int i = point_y; i <= N; i++)
		{
			for (int j = point_x; j <= M; j++)
			{
				if (i == point_y && j == point_x) continue;
				DP[i][j] = 0;
				if (i > point_y) DP[i][j] += DP[i - 1][j];
				if (j > point_x) DP[i][j] += DP[i][j - 1];
			}
		}
		
		cout << sum_1 * DP[N][M];
	}
	return 0;
}