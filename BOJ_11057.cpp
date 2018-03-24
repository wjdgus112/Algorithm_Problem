#include <iostream>

using namespace std;

#define NUM_MAX 10 // 0~9 까지의 수 (10개)
#define mod 10007

int N,ans;
long long D[1001][NUM_MAX]; // D[i][j] = 수의 길이가 i이며 마지막 숫자가 j인 수의 오르막 수의 개수 

int main()
{	
	cin >> N;

	for (int i = 0; i < NUM_MAX; i++) D[1][i] = 1; // 길이가 1인 숫자들의 오르막 수 초기화

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < NUM_MAX; j++)
		{
			for (int k = 0; k <= j; k++)
			{
				// 길이가 i, 마지막 숫자가 j인 수의 오르막 수의 개수는 
				// 길이가 i-1이고 마지막 숫자가 j 이하인 오르막 수의 개수들의 모든 합으로 표현할 수 있다.
				D[i][j] += D[i - 1][k];
				D[i][j] = mod;
			}
		}
	}

	for (int i = 0; i < NUM_MAX; i++) ans += D[N][i];

	cout << ans%mod << "\n";

	return 0;
}