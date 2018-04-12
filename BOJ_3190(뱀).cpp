#include <iostream>
#include <map>
#include <deque>

using namespace std;

#define MAX_N 101

int ans;
int n;
int k;
int l_cnt;
deque<pair<int, int>> snake; // 뱀의 좌표를 저장
int board[MAX_N][MAX_N]; // 뱀의 몸은 2, 사과는 1, 빈 칸은 0
map<int, char> direcion;
// 왼쪽,오른쪽,위,아래
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

// 현재 상태를 보여주는 함수
void PrintCurrent()
{
	cout << "현재 경과시간 : " << ans << "\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

int ChangeDirection(int curr_d)
{
	int changed_d;
	// 좌회전
	if (direcion[ans] == 'L')
	{
		// 왼쪽(0) -> 아래쪽(3) , 오른쪽(1) -> 위쪽(2)
		// 위쪽(2) -> 왼쪽(0), 아래쪽(3) -> 오른쪽(1)
		if (curr_d == 0) changed_d = 3;
		else if (curr_d == 1) changed_d = 2;
		else if (curr_d == 2) changed_d = 0;
		else if (curr_d == 3) changed_d = 1;
	}
	// 우회전
	else if (direcion[ans] == 'D')
	{
		// 왼쪽(0) -> 위쪽(2) , 오른쪽(1) -> 아래쪽(3)
		// 위쪽(2) -> 오른쪽(1), 아래쪽(3) -> 왼쪽(0)
		if (curr_d == 0) changed_d = 2;
		else if (curr_d == 1) changed_d = 3;
		else if (curr_d == 2) changed_d = 1;
		else if (curr_d == 3) changed_d = 0;
	}

	return changed_d;
}

void Dfs(int x, int y, int curr_direction, int back_x, int back_y)
{
	//PrintCurrent();

	// 현재 시간에 해당되는 방향 정보가 있다면 방향을 바꿔준다
	if (direcion.find(ans) != direcion.end())
		curr_direction = ChangeDirection(curr_direction);
	

	// 방향에 맞는 변환
	int next_x = x + dx[curr_direction], next_y = y + dy[curr_direction];

	if (0 <= next_x && next_x < n && 0 <= next_y && next_y < n)
	{
		// 자신의 몸 만나면 종료
		if (board[next_x][next_y] == 2)
		{
			ans++;
			return;
		}
		// 사과가 없는 칸이면
		else if (board[next_x][next_y] == 0)
		{
			// 다음 좌표를 뱀의 몸으로 만들어주고 좌표 저장
			snake.push_back(make_pair(next_x, next_y));
			board[next_x][next_y] = 2;
			// 꼬리칸을 비워준다
			board[back_x][back_y] = 0;
			snake.pop_front();
			ans++;
			// 이동
			Dfs(next_x, next_y, curr_direction, snake[0].first, snake[0].second);
		}
		// 사과가 있는 칸이면 몸길이를 늘린다
		else if (board[next_x][next_y] == 1)
		{
			snake.push_back(make_pair(next_x, next_y));
			board[next_x][next_y] = 2;
			ans++;
			Dfs(next_x, next_y, curr_direction, back_x, back_y);
		}
	}
	// 벽 만나면 종료
	else
	{
		ans++;
		return;
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	cin >> k;

	for (int i = 0; i < k; i++)
	{
		int r, c;
		cin >> r >> c;
		// 사과를 놓는다
		board[r - 1][c - 1] = 1;
	}

	// 뱀의 방향변환 개수
	cin >> l_cnt;

	for (int i = 0; i < l_cnt; i++)
	{
		int x; char c;
		cin >> x >> c;
		direcion[x] = c;
	}

	// 뱀의 첫 위치를 뱀으로 만들고 좌표 저장
	board[0][0] = 2;
	snake.push_back(make_pair(0, 0));

	// 게임 진행
	Dfs(0, 0, 1, 0, 0);

	cout << ans << "\n";

	return 0;
}