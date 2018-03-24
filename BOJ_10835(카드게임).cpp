#include <iostream>
#include <algorithm>
using namespace std;

// N : 한 더미의 카드의 개수
// A : 왼쪽 카드 더미
// B : 오른쪽 카드 더미
// DP[i][j] : 왼쪽 카드뭉치의 카드가 i개 남아있을 경우 
int N, A[2001], B[2001], DP[2001][2001];

int solution(int left, int right)
{
	// 카드 더미가 남아있지 않으면
	if (left == N || right == N) return 0;
	int &val = DP[left][right];
	if (val != 0) return val;
	// 왼쪽 카드의 숫자가 오른쪽 카드의 숫자보다 클 경우면 오른쪽 카드를 버릴 경우와 비교
	// 오른쪽 카드의 숫자가 크면 왼쪽 카드만 버릴 경우와 둘다 버릴 경우를 비교
	val = A[left] > B[right] ? max(val, solution(left, right + 1) + B[right])  : max(solution(left + 1, right), solution(left + 1, right + 1));

	return val;

}
int main()
{
	
	cin >> N;

	//입력
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < N; i++) cin >> B[i];

	cout << solution(0, 0);

	return 0;
}


