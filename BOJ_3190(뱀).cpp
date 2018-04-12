#include <iostream>
#include <map>
#include <deque>

using namespace std;

#define MAX_N 101

int ans;
int n;
int k;
int l_cnt;
deque<pair<int, int>> snake; // ���� ��ǥ�� ����
int board[MAX_N][MAX_N]; // ���� ���� 2, ����� 1, �� ĭ�� 0
map<int, char> direcion;
// ����,������,��,�Ʒ�
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

// ���� ���¸� �����ִ� �Լ�
void PrintCurrent()
{
	cout << "���� ����ð� : " << ans << "\n";
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
	// ��ȸ��
	if (direcion[ans] == 'L')
	{
		// ����(0) -> �Ʒ���(3) , ������(1) -> ����(2)
		// ����(2) -> ����(0), �Ʒ���(3) -> ������(1)
		if (curr_d == 0) changed_d = 3;
		else if (curr_d == 1) changed_d = 2;
		else if (curr_d == 2) changed_d = 0;
		else if (curr_d == 3) changed_d = 1;
	}
	// ��ȸ��
	else if (direcion[ans] == 'D')
	{
		// ����(0) -> ����(2) , ������(1) -> �Ʒ���(3)
		// ����(2) -> ������(1), �Ʒ���(3) -> ����(0)
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

	// ���� �ð��� �ش�Ǵ� ���� ������ �ִٸ� ������ �ٲ��ش�
	if (direcion.find(ans) != direcion.end())
		curr_direction = ChangeDirection(curr_direction);
	

	// ���⿡ �´� ��ȯ
	int next_x = x + dx[curr_direction], next_y = y + dy[curr_direction];

	if (0 <= next_x && next_x < n && 0 <= next_y && next_y < n)
	{
		// �ڽ��� �� ������ ����
		if (board[next_x][next_y] == 2)
		{
			ans++;
			return;
		}
		// ����� ���� ĭ�̸�
		else if (board[next_x][next_y] == 0)
		{
			// ���� ��ǥ�� ���� ������ ������ְ� ��ǥ ����
			snake.push_back(make_pair(next_x, next_y));
			board[next_x][next_y] = 2;
			// ����ĭ�� ����ش�
			board[back_x][back_y] = 0;
			snake.pop_front();
			ans++;
			// �̵�
			Dfs(next_x, next_y, curr_direction, snake[0].first, snake[0].second);
		}
		// ����� �ִ� ĭ�̸� �����̸� �ø���
		else if (board[next_x][next_y] == 1)
		{
			snake.push_back(make_pair(next_x, next_y));
			board[next_x][next_y] = 2;
			ans++;
			Dfs(next_x, next_y, curr_direction, back_x, back_y);
		}
	}
	// �� ������ ����
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
		// ����� ���´�
		board[r - 1][c - 1] = 1;
	}

	// ���� ���⺯ȯ ����
	cin >> l_cnt;

	for (int i = 0; i < l_cnt; i++)
	{
		int x; char c;
		cin >> x >> c;
		direcion[x] = c;
	}

	// ���� ù ��ġ�� ������ ����� ��ǥ ����
	board[0][0] = 2;
	snake.push_back(make_pair(0, 0));

	// ���� ����
	Dfs(0, 0, 1, 0, 0);

	cout << ans << "\n";

	return 0;
}