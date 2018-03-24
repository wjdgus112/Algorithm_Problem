#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int alpha[27];

int main()
{
	string str;
	int center = -1;
	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		alpha[str[i] - 'A']++;
	}

	for (int i = 0; i < 27; i++)
	{
		// ���ĺ��� ������ Ȧ�����̸�
		if (alpha[i] % 2)
		{
			// �� ���ĺ��� �߾ӿ� ��ġ�ؾ��Ѵ�.
			if (center == -1)	center = i;
			// Ȧ�����ΰ� �������̸� �Ӹ������ ������ ���Ѵ�.
			else
			{
				cout << "I'm Sorry Hansoo";
				return 0;
			}
		}
	}

	for (int i = 0; i < 27; i++)
	{

		if (alpha[i]) // ���ĺ��� �����ϸ�
		{
			for(int j=0;j<alpha[i]/2;j++) // ���ĺ��� ������ ���� ����Ѵ�.
				cout << (char)(i + 'A');
		}
	}
	
	// �߾ӿ� ��ġ�� ���ĺ��� �����ϸ� ����Ѵ�. (���ڿ��� ũ�Ⱑ Ȧ���� �ǹ�)
	if (center != -1)
		cout << (char)(center + 'A');	

	for (int i = 26; i >= 0; i--)
	{
		// �Ӹ������ �߾��� �������� �ݴ�� ����ؾ��Ѵ�.
		if (alpha[i])
		{
			for (int j = 0; j<alpha[i]/2; j++)
				cout << (char)(i + 'A');
		}
	}

	return 0;
}