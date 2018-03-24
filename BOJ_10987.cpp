#include <iostream>
#include <string>
using namespace std;

int main()
{
	string input;
	int cnt = 0;
	cin >> input;

	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u') cnt++;
	}

	cout << cnt;

	return 0;
}