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

	// ��ȣ�� �ּ� �� ���� ������ �� ���� �������� �̷�����ִ�.
	return ja >= 2 && mo >= 1;
}

// n : ������ �ϴ� ��ȣ�� ����
// vector<char> alpha : ����� �� �ִ� ���ĺ�
// password : ������� ���� ��ȣ
// ������� ���� �����ؾ� �ϴ� ���ĺ��� �ε���
void recur(int n, vector<char> &alpha, string password, int i)
{
	// ���� ������� ��ȣ�� �����ߵǴ� ��ȣ�� ���̶� ������
	if (password.length() == n)
	{
		// ��ȣ�� ������ �����Ѵٸ� ���
		if (chk(password))
		{
			cout << password << "\n";
		}
		return;
	}

	// ����Լ��� ������ ����
	if (i >= alpha.size()) return;

	// ���ĺ��� ����ϴ� ���
	recur(n, alpha, password + alpha[i], i + 1);
	// ������� �ʴ� ���
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