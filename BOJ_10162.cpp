#include <iostream>

using namespace std;

int main()
{
	// T : �丮�ð�(��)
	// A : 5��(300��), B : 1��(60��), C : 10��
	int T,A=0,B=0,C=0;

	cin >> T;

	// 10���� ������������ ������ �ذ���Ѵ�. -1 ���
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