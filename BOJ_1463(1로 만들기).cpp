#include <iostream>

using namespace std;

#define MAX 1000001

int D[MAX];

int solution(int N)
{
	if (N==1) return 0;
	if (D[N] > 0) return D[N];

	D[N] = solution(N - 1) + 1;

	if (N % 2 == 0)
	{
		int tmp = solution(N / 2) + 1;
		if (D[N] > tmp) D[N] = tmp;
	}
		
	if (N % 3 == 0)
	{
		int tmp = solution(N / 3) + 1;
		if (D[N] > tmp) D[N] = tmp;
	}

	return D[N];
}
int main()
{
	int N;

	cin >> N;

	cout << solution(N);

	return 0;
}