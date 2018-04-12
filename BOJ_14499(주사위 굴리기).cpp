#include <iostream>
#include <vector>

using namespace std;

#define MAX_SIZE 21
#define MAX_K 1001

int n, m;
int a[MAX_SIZE][MAX_SIZE];
vector<int> command;
int k;
// left, right, back, front, top, bottom
int cube[6]; // �ֻ��� ���� ����
// ��(1), ��(2), ��(3), ��(4)
int dx[5] = { 0,0,0,-1,1 };
int dy[5] = { 0,1,-1,0,0 };

// ��ɿ� ���� �ֻ��� ���¸� �ٲ��ִ� �Լ�
void ChangeCubeState(int curr_command)
{
	int left = cube[0], right = cube[1];
	int back = cube[2], front = cube[3];
	int top = cube[4], bottom = cube[5];

	// ���� �̵�
	if (curr_command == 1)
	{
		// left = bottom, right = top
		cube[0] = bottom;
		cube[1] = top;
		// bottom = right, top = left
		cube[4] = left;
		cube[5] = right;
	}
	// ���� �̵�
	else if (curr_command == 2)
	{
		// left = top, right = bottom
		cube[0] = top;
		cube[1] = bottom;
		// bottom = left, top = right
		cube[4] = right;
		cube[5] = left;
	}
	// ���� �̵�
	else if (curr_command == 3)
	{
		// back = top , front = bottom
		cube[2] = top;
		cube[3] = bottom;
		// top = front, bottom = back
		cube[4] = front;
		cube[5] = back;
	}
	// ���� �̵�
	else if (curr_command == 4)
	{
		// back = top, front = bottom
		cube[2] = bottom;
		cube[3] = top;
		// top = back, bottom = front
		cube[4] = back;
		cube[5] = front;
	}
}

void Dfs(int x, int y, int command_index, bool print)
{
	if (print)
		cout << cube[4] << "\n";

	if (command_index == k) return;

	int curr_command = command[command_index];
	
	// ���� ĭ�� ��ǥ
	int next_x = x + dx[curr_command], next_y = y + dy[curr_command];

	// ���� ���̸� ���� ����� �����ϰ� ������� �ʴ´�.
	if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= m)
	{
		Dfs(x, y, command_index + 1,false);
		return;
	}

	// ���� ĭ�� 0�̸� ���� ĭ�� �ٴڸ鿡 ���� ���ڷ� ����
	if (a[next_x][next_y] == 0)
	{
		ChangeCubeState(curr_command);
		a[next_x][next_y] = cube[5];
		Dfs(next_x, next_y, command_index + 1,true);
	}
	// 0�� �ƴ� ��쿡�� ĭ�� ���ִ� ���� �ٴڸ����� �������ְ� ĭ�� ���ִ� ���� 0���� �����.
	else
	{
		ChangeCubeState(curr_command);
		cube[5] = a[next_x][next_y];
		a[next_x][next_y] = 0;
		Dfs(next_x, next_y, command_index + 1,true);
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int x, y;

	cin >> n >> m >> x >> y >> k;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}

	// �̵���� ����
	for (int i = 0; i < k; i++)
	{
		int com;
		cin >> com;
		command.push_back(com);
	}

	Dfs(x, y, 0,false);

	return 0;
}