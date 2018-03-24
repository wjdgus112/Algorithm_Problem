#include <iostream>
#include <algorithm>
using namespace std;

// N : �� ������ ī���� ����
// A : ���� ī�� ����
// B : ������ ī�� ����
// DP[i][j] : ���� ī�并ġ�� ī�尡 i�� �������� ��� 
int N, A[2001], B[2001], DP[2001][2001];

int solution(int left, int right)
{
	// ī�� ���̰� �������� ������
	if (left == N || right == N) return 0;
	int &val = DP[left][right];
	if (val != 0) return val;
	// ���� ī���� ���ڰ� ������ ī���� ���ں��� Ŭ ���� ������ ī�带 ���� ���� ��
	// ������ ī���� ���ڰ� ũ�� ���� ī�常 ���� ���� �Ѵ� ���� ��츦 ��
	val = A[left] > B[right] ? max(val, solution(left, right + 1) + B[right])  : max(solution(left + 1, right), solution(left + 1, right + 1));

	return val;

}
int main()
{
	
	cin >> N;

	//�Է�
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < N; i++) cin >> B[i];

	cout << solution(0, 0);

	return 0;
}


