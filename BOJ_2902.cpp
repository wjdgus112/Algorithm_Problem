#include <iostream>
#include <string>
using namespace std;

// ** 예외처리 **
// 최대 100글자의 알파벳 대문자,소문자,그리고 하이픈('-', 아스키코드 45)
// 첫번째 글자는 항상 대문자
// 하이픈 뒤에는 반드시 대문자
// 그 외의 모든 문자는 모두 소문자
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