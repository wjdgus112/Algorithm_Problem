#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	int ans=0;
	string input_bracket;
	stack<int> bracket_stack;

	cin >> input_bracket;

	int n = input_bracket.length();

	for (int i = 0; i < n; i++)
	{
		if (input_bracket[i] == '(')
		{
			bracket_stack.push(i);
		}
		else
		{
			if (bracket_stack.top() + 1 == i)
			{
				bracket_stack.pop();
				ans += bracket_stack.size();
			}
			else
			{
				bracket_stack.pop();
				ans += 1;
			}
		}
	}

	cout << ans << '\n';

	return 0;
}