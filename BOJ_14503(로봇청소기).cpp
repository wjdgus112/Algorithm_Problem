#include <iostream>

using namespace std;

#define MAX_SIZE 51

// �ٶ󺸴� ����(��, ��, ��, ��)
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

// �ٶ󺸴� ���⿡ ���� ���� (��, ��, ��, ��)
int back_dx[4] = { 1,0,-1,0 };
int back_dy[4] = { 0,-1,0,1 };

int ans; // �κ�û�ұⰡ û���ϴ� ĭ�� ����
int map[MAX_SIZE][MAX_SIZE];
int n, m; // ������ ũ��
int r, c, d; // �κ�û�ұ��� ��ǥ(r,c), �ٶ󺸴� ����(d) : ��(0), ��(1), ��(2), ��(3)


void Dfs(int x, int y, int direction)
{
	// ���̸� ��
	if (map[x][y] == 1) return;

	// �� ĭ�̸� û���Ѵ�.
	if (map[x][y] == 0)
	{
		map[x][y] = 2;
		ans++;
	}

	// �� ���� �˻�
	for (int k = 0; k < 4; k++)
	{
		// ��(0) -> ��(3), ��(1) -> ��(0), ��(2) -> ��(1), ��(3) -> ��(2)
		int next_direction = direction-1 < 0 ? 3 : direction-1;
		int next_x = x + dx[next_direction], next_y = y + dy[next_direction];

		// �� ĭ�̸� û��
		if (map[next_x][next_y] == 0)
		{
			Dfs(next_x, next_y, next_direction);
			// ���� ĭ���� �Ѿ ��쿡 �� �̻� ������ ������ �˻����� �ʴ´�.
			return;
		}
		// û���߰ų� ���̸� ���⸸ �ٲ��ش�.
		else
		{
			direction = next_direction;
		}
	}
	// �˻� ��

	// �� ���� ��� û���߰ų� ���̸� ������ ������ä�� �����Ѵ�.
	int next_x = x + back_dx[direction], next_y = y + back_dy[direction];

	Dfs(next_x, next_y, direction);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;

	cin >> r >> c >> d;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	
	Dfs(r, c, d);

	cout << ans << "\n";

	return 0;
}