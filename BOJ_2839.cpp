#include <iostream>

using namespace std;

int main()
{

	int n, ans=-1,cnt,temp, five, three;

	cin >> n;

	cnt = n / 5;

	if (n % 3 == 0) ans = n / 3; // 6, 9, ���� ���ڵ��� ���� ����ó��
	while(cnt!=0)
	{
		temp = n - (cnt * 5); // n �Ʒ��� ���ڵ� �߿� ���� ����� 5�� ����� �� ������
		if (temp % 3 == 0) // �� �������� 3�� ����̸� ���� cnt ���� 5kg ������
		{
			five = cnt;
			three = temp / 3;
			ans = five + three;
			break;
		}
		cnt--;
	}

	cout << ans;

	return 0;
}