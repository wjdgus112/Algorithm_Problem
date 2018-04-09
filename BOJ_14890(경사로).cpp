#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX_SIZE 101

int n, l;
int map[MAX_SIZE][MAX_SIZE];
int runway_row[MAX_SIZE];
int runway_col[MAX_SIZE];
int ans;

// prev_h : ���� ĭ�� ����
// x, y : ���� ĭ�� x, y ��ǥ
// cnt : ������� ������ ĭ�� ����
void RecurRow(int prev_h, int x, int y, int cnt)
{
	// �� �˻簡 ������
	if (y == n)
	{
		bool isway = true;
		for (int i = 0; i < n; i++)
		{
			// ������ ������ �� �� �̻��̸� ��� ������ ���Ѵ�
			if (runway_row[i] > 1)
				isway = false;
		}

		if (isway)
			ans++;

		memset(runway_row, 0, sizeof(runway_row));
		return;
	}
	
	int abs_sub = abs(map[x][y] - prev_h);

	if (abs_sub == 0)
	{
		RecurRow(map[x][y], x, y + 1, cnt + 1);
	}
	// ���� 1�̸�
	else if (abs_sub == 1)
	{
		// ���� ĭ�� ���̰� ���� ĭ���� ���� ĭ�̸�
		if (prev_h < map[x][y])
		{
			if (cnt >= l)
			{
				for (int i = y - 1, l_cnt = 0; l_cnt < l; i--, l_cnt++)
				{
					if (i < 0)
					{
						memset(runway_row, 0, sizeof(runway_row));
						return;
					}
					// ���� ���� �߰�
					runway_row[i] += 1;
				}
				RecurRow(map[x][y], x, y + 1, 1);
			}
			else
			{
				memset(runway_row, 0, sizeof(runway_row));
				return;
			}
			
		}
		// ���� ĭ�� �� ���� ĭ�̸�
		else
		{
			// ������� l���� ĭ�� ���η� ������ش�
			for (int i = y, l_cnt = 0; l_cnt < l; i++, l_cnt++)
			{
				if (i >= n)
				{
					memset(runway_row, 0, sizeof(runway_row));
					return;
				}
				if (map[x][i] == map[x][y])
					runway_row[i] += 1;
				// ���� l���� ĭ �߿��� ���̰� �ٸ� ĭ�� �����ϸ� ���θ� �������
				else
				{
					memset(runway_row, 0, sizeof(runway_row));
					return;
				}
			}
			RecurRow(map[x][y], x, y + 1, 1);
		}
	}
	// ���� 1�� �ƴϰ� 0�� �ƴϸ� ���� �� �� �����Ƿ� ȣ�� ����
	else
	{
		memset(runway_row, 0, sizeof(runway_row));
		return;
	}
}

void RecurCol(int prev_h, int x, int y, int cnt)
{
	// �� �˻簡 ������
	if (x == n)
	{
		bool isway = true;
		for (int i = 0; i < n; i++)
		{
			// ������ ������ �� �� �̻��̸� ��� ������ ���Ѵ�
			if (runway_col[i] > 1)
				isway = false;
		}
		if (isway)
			ans++;

		memset(runway_col, 0, sizeof(runway_col));
		return;
	}

	int abs_sub = abs(map[x][y] - prev_h);

	if (abs_sub == 0)
	{
		RecurCol(map[x][y], x+1, y, cnt + 1);
	}
	// ���� 1�̸�
	else if (abs_sub == 1)
	{
		// ���� ĭ�� ���̰� ���� ĭ���� ���� ĭ�̸�
		if (prev_h < map[x][y])
		{
			if (cnt >= l)
			{
				for (int i = x - 1, l_cnt = 0; l_cnt < l; i--, l_cnt++)
				{
					if (i < 0)
					{
						memset(runway_col, 0, sizeof(runway_col));
						return;
					}
					// ���� ���� �߰�
					runway_col[i] += 1;
				}
				RecurCol(map[x][y], x+1, y, 1);
			}
			else
			{
				memset(runway_col, 0, sizeof(runway_col));
				return;
			}
		}
		// ���� ĭ�� �� ���� ĭ�̸�
		else
		{
			// ������� l���� ĭ�� ���η� ������ش�
			for (int i = x, l_cnt = 0; l_cnt < l; i++, l_cnt++)
			{
				if (i >= n)
				{
					memset(runway_col, 0, sizeof(runway_col));
					return;
				}
				if (map[i][y] == map[x][y])
					runway_col[i] += 1;
				// ���� l���� ĭ �߿��� ���̰� �ٸ� ĭ�� �����ϸ� ���θ� �������
				else
				{
					memset(runway_col, 0, sizeof(runway_col));
					return;
				}
			}
			RecurCol(map[x][y], x+1, y, 1);
		}
	}
	// ���� 1�� �ƴϰ� 0�� �ƴϸ� ���� �� �� �����Ƿ� ȣ�� ����
	else
	{
		memset(runway_col, 0, sizeof(runway_col));
		return;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> l;

	// #1. ���� �Է�
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}

	// #2. ��, �� �˻�
	for (int i = 0; i < n; i++)
	{
		RecurRow(map[i][0], i, 0, 0);
		RecurCol(map[0][i], 0, i, 0);
	}

	cout << ans << "\n";

	return 0;
}