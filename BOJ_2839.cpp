#include <iostream>

using namespace std;

int main()
{

	int n, ans=-1,cnt,temp, five, three;

	cin >> n;

	cnt = n / 5;

	if (n % 3 == 0) ans = n / 3; // 6, 9, 같은 숫자들을 위한 예외처리
	while(cnt!=0)
	{
		temp = n - (cnt * 5); // n 아래의 숫자들 중에 가장 가까운 5의 배수를 뺀 나머지
		if (temp % 3 == 0) // 그 나머지가 3의 배수이면 현재 cnt 값이 5kg 봉지수
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