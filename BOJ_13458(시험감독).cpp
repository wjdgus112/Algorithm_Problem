#include <iostream>

using namespace std;

#define MAX_N 1000001

int n;
int b, c;
long long ans;
int test_room[MAX_N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// ������ ��
	cin >> n;
	
	// �� �������� ������ ��
	for (int i = 0; i < n; i++)
	{
		cin >> test_room[i];
	}

	// �Ѱ�����, �ΰ������� ������ �� �ִ� ������ ��
	cin >> b >> c;

	// �� �����帶�� �� �������� 1�� ����
	ans += n;

	for (int i = 0; i < n; i++)
	{
		int curr_test_num = test_room[i] - b;
		
		// �� ������������ �����ϸ� ���� ����������
		if (curr_test_num <= 0) continue;
		
		if (curr_test_num % c > 0)
			ans += curr_test_num / c + 1;
		else
			ans += curr_test_num / c;
	}

	cout << ans << "\n";

	return 0;
}