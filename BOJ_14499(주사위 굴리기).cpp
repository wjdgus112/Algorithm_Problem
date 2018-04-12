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
int cube[6]; // 주사위 상태 저장
// 동(1), 서(2), 북(3), 남(4)
int dx[5] = { 0,0,0,-1,1 };
int dy[5] = { 0,1,-1,0,0 };

// 명령에 따라서 주사위 상태를 바꿔주는 함수
void ChangeCubeState(int curr_command)
{
	int left = cube[0], right = cube[1];
	int back = cube[2], front = cube[3];
	int top = cube[4], bottom = cube[5];

	// 동쪽 이동
	if (curr_command == 1)
	{
		// left = bottom, right = top
		cube[0] = bottom;
		cube[1] = top;
		// bottom = right, top = left
		cube[4] = left;
		cube[5] = right;
	}
	// 서쪽 이동
	else if (curr_command == 2)
	{
		// left = top, right = bottom
		cube[0] = top;
		cube[1] = bottom;
		// bottom = left, top = right
		cube[4] = right;
		cube[5] = left;
	}
	// 북쪽 이동
	else if (curr_command == 3)
	{
		// back = top , front = bottom
		cube[2] = top;
		cube[3] = bottom;
		// top = front, bottom = back
		cube[4] = front;
		cube[5] = back;
	}
	// 남쪽 이동
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
	
	// 다음 칸의 좌표
	int next_x = x + dx[curr_command], next_y = y + dy[curr_command];

	// 지도 밖이면 다음 명령을 실행하고 출력하지 않는다.
	if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= m)
	{
		Dfs(x, y, command_index + 1,false);
		return;
	}

	// 다음 칸이 0이면 다음 칸을 바닥면에 적힌 숫자로 복사
	if (a[next_x][next_y] == 0)
	{
		ChangeCubeState(curr_command);
		a[next_x][next_y] = cube[5];
		Dfs(next_x, next_y, command_index + 1,true);
	}
	// 0이 아닌 경우에는 칸에 써있는 수를 바닥면으로 복사해주고 칸에 써있는 수는 0으로 만든다.
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

	// 이동명령 저장
	for (int i = 0; i < k; i++)
	{
		int com;
		cin >> com;
		command.push_back(com);
	}

	Dfs(x, y, 0,false);

	return 0;
}