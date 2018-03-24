#include <iostream>
#include <string>
#include <vector>

using namespace std;
int S;

bool chk(int x)
{
	// 집합에 x가 있는지 확인
	return (S & (1 << x));
}

void add(int x)
{
	if (!chk(x))
	{
		S = (S | (1 << x));
	}
}

void remove(int x)
{
	// 집합에 x가 있으면 제거과정을 진행한다.
	if (chk(x))
	{
		S = (S & ~(1 << x));
	}
}

void process(string cmd)
{
	int x;

	if (cmd == "add")
	{
		cin >> x;
		add(--x);
	}
	else if (cmd == "remove")
	{
		cin >> x;
		remove(--x);
	}
	else if (cmd == "check")
	{
		cin >> x;
		if (chk(--x)) cout << "1\n";
		else cout << "0\n";
	}
	else if (cmd == "toggle")
	{
		cin >> x;
		S = (S ^ (1 << --x));
	}
	else if (cmd == "all")
	{
		S = (1 << 20) - 1;
	}
	else if (cmd == "empty")
	{
		S = 0;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int M,x;
	string cmd;

	cin >> M;

	for(int i=0;i<M;i++)
	{
		cin >> cmd;

		process(cmd);
	}
	return 0;
}