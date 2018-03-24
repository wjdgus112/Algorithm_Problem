#include <iostream>
#include <string>

int main()
{
	std::cin.sync_with_stdio(false);

	std::string s;

	std::cin >> s;

	std::cout << s.length();

	return 0;
}