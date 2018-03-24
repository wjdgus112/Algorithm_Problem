#include <iostream>
#include <cstring>
using namespace std;
#define SIZE 1000000

int main()
{
	char std[SIZE];
	int cnt = 0;
	
	// 보통 cin은 공백을 만나면 입력을 끝낸다
	// cin.geline(변수 주소,최대 입력 가능 문자수,종결 문자)
	cin.getline(std,SIZE);

	for (int i = 0; i < strlen(std); i++)

	{
		if (std[i-1]!=32 && std[i] == 32 ) // 연속 공백 제거
			cnt++;
	}

	if (std[0] == ' ')
		cnt--;

	if (std[strlen(std) - 1] == ' ')
		cnt--;

	cout << ++cnt;

	return 0;
}