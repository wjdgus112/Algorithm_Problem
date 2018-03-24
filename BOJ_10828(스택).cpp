#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> stack;

void push(int data)
{
	stack.push_back(data);
}

void pop()
{
	cout << stack[stack.size() - 1];

	stack.pop_back();
}

int main()
{
	int N,data;
	string command;
	cin >> N;

	while (--N)
	{
		cin >> command;

		if (command == "push")
		{
			cin >> data;
			push(data);
		}
		else if (command == "pop")
		{
			pop();
		}

	}
	return 0;
}