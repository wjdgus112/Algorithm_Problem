#include <iostream>

using namespace std;

int main()
{
	// T : 요리시간(초)
	// A : 5분(300초), B : 1분(60초), C : 10초
	int T,A=0,B=0,C=0;

	cin >> T;

	// 10으로 나눠떨어지지 않으면 해결못한다. -1 출력
	if(T%10) printf("-1");
	else
	{
		A = T / 300;
		T %= 300;
		B = T / 60;
		T %= 60;
		C = T / 10;
		T %= 10;
		printf("%d %d %d", A, B, C);
	}

	return 0;
}