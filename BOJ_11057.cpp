#include <iostream>

using namespace std;

#define NUM_MAX 10 // 0~9 ������ �� (10��)
#define mod 10007

int N,ans;
long long D[1001][NUM_MAX]; // D[i][j] = ���� ���̰� i�̸� ������ ���ڰ� j�� ���� ������ ���� ���� 

int main()
{	
	cin >> N;

	for (int i = 0; i < NUM_MAX; i++) D[1][i] = 1; // ���̰� 1�� ���ڵ��� ������ �� �ʱ�ȭ

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < NUM_MAX; j++)
		{
			for (int k = 0; k <= j; k++)
			{
				// ���̰� i, ������ ���ڰ� j�� ���� ������ ���� ������ 
				// ���̰� i-1�̰� ������ ���ڰ� j ������ ������ ���� �������� ��� ������ ǥ���� �� �ִ�.
				D[i][j] += D[i - 1][k];
				D[i][j] = mod;
			}
		}
	}

	for (int i = 0; i < NUM_MAX; i++) ans += D[N][i];

	cout << ans%mod << "\n";

	return 0;
}