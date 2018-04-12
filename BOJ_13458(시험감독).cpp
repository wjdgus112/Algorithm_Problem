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

	// 시험장 수
	cin >> n;
	
	// 각 시험장의 응시자 수
	for (int i = 0; i < n; i++)
	{
		cin >> test_room[i];
	}

	// 총감독관, 부감독관이 감시할 수 있는 응시자 수
	cin >> b >> c;

	// 각 시험장마다 총 감독관은 1명씩 존재
	ans += n;

	for (int i = 0; i < n; i++)
	{
		int curr_test_num = test_room[i] - b;
		
		// 총 감독관만으로 가능하면 다음 시험장으로
		if (curr_test_num <= 0) continue;
		
		if (curr_test_num % c > 0)
			ans += curr_test_num / c + 1;
		else
			ans += curr_test_num / c;
	}

	cout << ans << "\n";

	return 0;
}