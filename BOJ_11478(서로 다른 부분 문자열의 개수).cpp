#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

string input;
list<string> suffix;
set<string> ans;

int main()
{
	cin.sync_with_stdio(false);

	cin >> input;

	int len = input.length();

	for (int i = 1; i <= len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			suffix.push_back(input.substr(j, i));
		}
	}

	set<string> ans(suffix.begin(),suffix.end());

	cout << ans.size();

	return 0;
}