#include <iostream>

using namespace std;

#define MAX_M 1000000

// ���峭 ��ư�� üũ
bool chk[10];

// c��� ���ڸ� ��ư���� ���� �̵��� ��� �̵��� �� �ִٸ� ���ڹ�ư�� ������ Ƚ���� ����
int possible(int c)
{
	// 0�� ��� ó��
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

	// ���峭 ��ư ó��
	while (M--)
	{
		int broken_btn;
		cin >> broken_btn;
		chk[broken_btn] = true;
	}

	int ans = abs(N - 100);

	// ����Ž�� ���� 1���� ���ʴ�� �˻��ؼ� 
	for (int i = 0; i < MAX_M; i++)
	{
		int c = i;
		// ���ڹ�ư�� ���峪�� �ʾƼ� �� ä�η� �̵��� �� �ִٸ� (���ڹ�ư�� ������ Ƚ�� + �̵��Ϸ��� ä�ΰ��� ����)
		int cmp_ans=possible(c) ? possible(c)+abs(N-c):abs(N-100);
		
		if (ans > cmp_ans)
			ans = cmp_ans;
	}

	cout << ans << "\n";

	return 0;
}