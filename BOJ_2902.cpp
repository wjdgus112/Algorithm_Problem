#include <iostream>
#include <string>
using namespace std;

// ** ����ó�� **
// �ִ� 100������ ���ĺ� �빮��,�ҹ���,�׸��� ������('-', �ƽ�Ű�ڵ� 45)
// ù��° ���ڴ� �׻� �빮��
// ������ �ڿ��� �ݵ�� �빮��
// �� ���� ��� ���ڴ� ��� �ҹ���
int main()
{
	string str,result;
	bool check = true;
	while (check)
	{
		cin >> str;

		if (!isupper(str[0])) continue;

		result += str[0];
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == 45)
				result += str[i + 1];
		}
		if (str.length() <= 100) break;
	}

	cout << result << endl;
	return 0;
}