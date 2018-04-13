#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX_SIZE 21
#define MIN_INF -987654321

#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

int ans = MIN_INF;
int n;
int board[MAX_SIZE][MAX_SIZE];


void ChangeBoard(int direction)
{
	queue<int> q;

	switch (direction)
	{
		case UP:

			for (int col = 0; col < n; col++)
			{
				for (int row = 0; row < n; row++)
				{
					if (board[row][col] != 0)
					{
						q.push(board[row][col]);
						board[row][col] = 0;
					}	
				}

				int idx = 0;
				while (!q.empty())
				{
					int block = q.front();
					q.pop();

					if (board[idx][col] == 0)
						board[idx][col] = block;
					else if (board[idx][col] == block)
					{
						board[idx][col] *= 2;
						idx++;
					}
					else
						board[++idx][col] = block;
				}
			}
			break;

		case DOWN:

			for (int col = 0; col < n; col++)
			{
				for (int row = n - 1; row >= 0; row--)
				{
					if (board[row][col] != 0)
					{
						q.push(board[row][col]);
						board[row][col] = 0;
					}
				}
				int idx = n-1;
				while (!q.empty())
				{
					int block = q.front();
					q.pop();

					if (board[idx][col] == 0)
						board[idx][col] = block;
					else if (board[idx][col] == block)
					{
						board[idx][col] *= 2;
						idx--;
					}
					else
						board[--idx][col] = block;
				}
			}
			break;
		case LEFT:

			for (int row = 0; row < n; row++)
			{
				for (int col = 0; col < n; col++)
				{
					if (board[row][col] != 0)
					{
						q.push(board[row][col]);
						board[row][col] = 0;
					}
				}
				int idx = 0;
				while (!q.empty())
				{
					int block = q.front();
					q.pop();

					if (board[row][idx] == 0) 
						board[row][idx] = block;
					else if (board[row][idx] == block)
					{
						board[row][idx] *= 2;
						idx++;
					}
					else
						board[row][++idx] = block;
				}
			}
			break;
		case RIGHT:

			for (int row = 0; row < n; row++)
			{
				for (int col = n - 1; col >= 0; col--)
				{
					if (board[row][col] != 0)
					{
						q.push(board[row][col]);
						board[row][col] = 0;
					}
				}

				int idx = n-1;
				while (!q.empty())
				{
					int block = q.front();
					q.pop();

					if (board[row][idx] == 0)
						board[row][idx] = block;
					else if (board[row][idx] == block)
					{
						board[row][idx] *= 2;
						idx--;
					}
					else
						board[row][--idx] = block;
				}
			}
			break;

	}

}

int FindMax()
{
	int ret_max = MIN_INF;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (ret_max < board[i][j]) ret_max = board[i][j];
		}
	}

	return ret_max;
}

void Dfs(int depth)
{
	// 5�� �̵������� �ִ밪 ����
	if ( depth == 5 )
	{
		ans = max(ans, FindMax());
		return;
	}

	int tmp_map[MAX_SIZE][MAX_SIZE];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			tmp_map[i][j] = board[i][j];

	for (int k = 0; k < 4; k++)
	{
		// ��� �������� �ٲ� ��� Ž��
		ChangeBoard(k);
		Dfs(depth+1);
		// ���� ���·� �����ش�
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				board[i][j] = tmp_map[i][j];
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
			ans = max(ans, board[i][j]);
		}
	}
	
	Dfs(0);

	cout << ans << "\n";

	return 0;
}