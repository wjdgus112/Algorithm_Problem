#include <iostream>
#include <queue>

using namespace std;

#define MAX 201

bool chk[MAX][MAX];
bool ans[MAX];
int A, B, C;

void push_ans(queue<pair<int,int>> &q,int x, int y,int z)
{
	if (chk[x][y] == false)
	{
		chk[x][y] = true;
		q.push(make_pair(x, y));
		// 물통 A가 비어있는 경우 물통 C의 남아있는 물의 양
		if (x == 0)
		{
			ans[z] = true;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> A >> B >> C;

	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	chk[0][0] = true;
	ans[C] = true;

	while (!q.empty())
	{
		int x = q.front().first, y = q.front().second;
		int z = C - x - y;
		q.pop();

		int nx, ny, nz;

		nx = x; ny = y; nz = z;

		// x -> y
		ny += nx; nx = 0;
		if (ny >= B)
		{
			nx = ny - B;
			ny = B;
		}

		push_ans(q, nx, ny, nz);

		nx = x; ny = y; nz = z;
		// x -> z;
		nz += nx; nx = 0;
		if (nz >= C)
		{
			nx = nz - C;
			nz = C;
		}

		push_ans(q, nx, ny, nz);

		nx = x; ny = y; nz = z;
		// y -> x
		nx += ny;  ny = 0;
		if (nx >= A)
		{
			ny = nx - A;
			nx = A;
		}

		push_ans(q,nx, ny, nz);
		nx = x; ny = y; nz = z;
		// y -> z
		nz += ny; ny = 0;
		if (nz >= C)
		{
			ny = nz - C;
			nz = C;
		}
		push_ans(q, nx, ny, nz);
		nx = x; ny = y; nz = z;
		// z -> x 
		nx += nz; nz = 0;
		if (nx >= A)
		{
			nz = nx - A;
			nx = A;
		}
		push_ans(q, nx, ny, nz);
		nx = x; ny = y; nz = z;

		// z -> y
		ny += nz; nz = 0;
		if (ny >= B)
		{
			nz = ny - B;
			ny = B;
		}
		push_ans(q, nx, ny, nz);
	}

	for (int i = 0; i < MAX; i++)
	{
		if (ans[i])
			cout << i << " ";
	}

	cout << "\n";

	return 0;
}