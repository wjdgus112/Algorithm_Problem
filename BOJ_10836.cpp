#include <iostream>
#include <vector>

using namespace std;

int main()
{
	// M : ����ĭ ũ��, N : ��¥��
	int M, N;

	cin >> M >> N;

	// �ڶ󳪴� ũ�⸦ �����ϴ� ����
	vector<int> border(2*M-1, 1);
	
	// ������������ �ڶ󳪴� ũ�⸦ ��� ���ؼ� �����Ѵ�.
	// ù��° ���� ������ ������ ���� ���� �Ѱ��� ���� ������ ���� ������.
	while (N--)
	{
		int zero, one, two;
		cin >> zero >> one >> two;

		// 0�� ������ŭ �ٰ� �������� 1�� ������ŭ �ش� ���Ҹ� 1 ������Ų��
		for (int i = zero; i < zero + one; i++)
		{
			border[i]++;
		}
		// 0,1�� ������ŭ �ٰ� 2�� ������ŭ 2 ������Ų��.
		for (int i = zero + one; i < 2 * M - 1; i++)
		{
			border[i] += 2;
		}
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
		{
			// ù ��° ��
			if (j == 0)
				cout << border[M - i - 1] << ' ';
			// ������ ��
			else
				cout << border[M + j - 1] << ' ';
		}
		cout << endl;
	}

	return 0;
}