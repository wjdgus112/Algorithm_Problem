#include <iostream>
#include <cstring>
using namespace std;
#define SIZE 1000000

int main()
{
	char std[SIZE];
	int cnt = 0;
	
	// ���� cin�� ������ ������ �Է��� ������
	// cin.geline(���� �ּ�,�ִ� �Է� ���� ���ڼ�,���� ����)
	cin.getline(std,SIZE);

	for (int i = 0; i < strlen(std); i++)

	{
		if (std[i-1]!=32 && std[i] == 32 ) // ���� ���� ����
			cnt++;
	}

	if (std[0] == ' ')
		cnt--;

	if (std[strlen(std) - 1] == ' ')
		cnt--;

	cout << ++cnt;

	return 0;
}