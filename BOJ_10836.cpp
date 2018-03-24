#include <iostream>
#include <vector>

using namespace std;

int main()
{
	// M : 격자칸 크기, N : 날짜수
	int M, N;

	cin >> M >> N;

	// 자라나는 크기를 저장하는 벡터
	vector<int> border(2*M-1, 1);
	
	// 마지막날까지 자라나는 크기를 모두 더해서 저장한다.
	// 첫번째 열을 제외한 나머지 열의 값은 한개의 열씩 동일한 값을 가진다.
	while (N--)
	{
		int zero, one, two;
		cin >> zero >> one >> two;

		// 0의 개수만큼 뛰고 다음부터 1의 개수만큼 해당 원소를 1 증가시킨다
		for (int i = zero; i < zero + one; i++)
		{
			border[i]++;
		}
		// 0,1의 개수만큼 뛰고 2의 개수만큼 2 증가시킨다.
		for (int i = zero + one; i < 2 * M - 1; i++)
		{
			border[i] += 2;
		}
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
		{
			// 첫 번째 열
			if (j == 0)
				cout << border[M - i - 1] << ' ';
			// 나머지 열
			else
				cout << border[M + j - 1] << ' ';
		}
		cout << endl;
	}

	return 0;
}