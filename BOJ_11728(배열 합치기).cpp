#include <iostream>

#define MAX 1000001

using namespace std;

int A[MAX];
int B[MAX];
int ans[MAX];
int N, M;

void merge()
{
	int i = 0; int j = 0; int k = 0;

	while (i < N && j < M)
	{
		if (A[i] <= B[j]) ans[k++] = A[i++];
		else ans[k++] = B[j++];
	}

	// 남은 배열의 원소들을 모두 넣는 과정
	while (i < N) ans[k++] = A[i++];
	while (j < M) ans[k++] = B[j++];
}

int main()
{
	ios::sync_with_stdio(false);
	
	cin >> N >> M;

	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < M; i++) cin >> B[i];
	
	int length = N + M;

	merge();

	for (int i = 0; i < length; i++)
	{
		cout << ans[i]; if (i != length - 1) cout << " ";
	}

	cout << "\n";

	return 0;
}