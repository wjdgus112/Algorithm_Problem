#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


bool chk(string &password)
{
	int ja = 0, mo = 0;
	int length = password.length();

	for (int i = 0; i < length; i++)
	{
		char c = password[i];

		if (c == 'a' || c == 'i' || c == 'o' || c == 'u' || c == 'e')
			mo += 1;
		else ja += 1;
	}

	// 암호는 최소 한 개의 모음과 두 개의 자음으로 이루어져있다.
	return ja >= 2 && mo >= 1;
}

// n : 만들어야 하는 암호의 길이
// vector<char> alpha : 사용할 수 있는 알파벳
// password : 현재까지 만든 암호
// 사용할지 말지 결정해야 하는 알파벳의 인덱스
void recur(int n, vector<char> &alpha, string password, int i)
{
	// 현재 만들어진 암호가 만들어야되는 암호의 길이랑 같으면
	if (password.length() == n)
	{
		// 암호의 조건을 만족한다면 출력
		if (chk(password))
		{
			cout << password << "\n";
		}
		return;
	}

	// 재귀함수가 끝나는 조건
	if (i >= alpha.size()) return;

	// 알파벳을 사용하는 경우
	recur(n, alpha, password + alpha[i], i + 1);
	// 사용하지 않는 경우
	recur(n, alpha, password, i + 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int L, C;

	cin >> L >> C;
	
	vector<char> alpha(C);

	for (int i = 0; i < C; i++)
	{
		cin >> alpha[i];
	}

	sort(alpha.begin(), alpha.end());
	recur(L, alpha, "", 0);

	return 0;
}