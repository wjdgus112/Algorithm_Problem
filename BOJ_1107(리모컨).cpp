#include <iostream>

using namespace std;

#define MAX_M 1000000

// 고장난 버튼을 체크
bool chk[10];

// c라는 숫자를 버튼으로 눌러 이동할 경우 이동할 수 있다면 숫자버튼을 누르는 횟수를 리턴
int possible(int c)
{
	// 0인 경우 처리
	if (c == 0)
	{
		return chk[0] ? 0 : 1;
	}

	int len = 0;
	while (c > 0)
	{
		if (chk[c % 10]) return 0;
		len += 1;
		c /= 10;
	}

	return len;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N,M;

	cin >> N;

	cin >> M;

	// 고장난 버튼 처리
	while (M--)
	{
		int broken_btn;
		cin >> broken_btn;
		chk[broken_btn] = true;
	}

	int ans = abs(N - 100);

	// 완전탐색 과정 1부터 차례대로 검사해서 
	for (int i = 0; i < MAX_M; i++)
	{
		int c = i;
		// 숫자버튼이 고장나지 않아서 그 채널로 이동할 수 있다면 (숫자버튼을 누르는 횟수 + 이동하려는 채널과의 차이)
		int cmp_ans=possible(c) ? possible(c)+abs(N-c):abs(N-100);
		
		if (ans > cmp_ans)
			ans = cmp_ans;
	}

	cout << ans << "\n";

	return 0;
}