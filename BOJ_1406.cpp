#include <iostream>
#include <string>
#include <stack>

using namespace std;

//// ���ڿ� ����� Ǯ��
//int main()
//{
//
//	cin.sync_with_stdio(false);
//	
//	string str;
//
//	cin >> str;
//
//	int N;
//	int cursor = str.length();
//
//	cin >> N;
//
//	string cmd;
//
//	while (N--)
//	{
//		cin >> cmd;
//
//		// Ŀ�� ���� �̵�
//		if (cmd == "L")
//		{
//			if (cursor > 0) cursor--;
//		}
//		// Ŀ�� ������ �̵�
//		else if (cmd == "D")
//		{
//			if (cursor < str.length()) cursor++;
//		}
//		// ���� �����
//		else if (cmd == "B")
//		{
//			if (cursor > 0)
//			{
//				str.erase(--cursor,1);
//			}
//		}
//		// ���� �߰�
//		else if (cmd == "P")
//		{
//			cin >> cmd;
//			str.insert(cursor++, cmd);
//		}
//	}
//
//	cout << str ;
//
//	return 0;
//}

// ���� ����� Ǯ��
//
//int main()
//{
//	cin.sync_with_stdio(false);
//
//	string str;
//
//	cin >> str;
//
//	int cnt;
//
//	int len = str.length();
//
//	stack<char> left, right;
//
//	for (int i = 0; i < len; i++)
//	{
//		left.push(str[i]);
//	}
//
//	cin >> cnt;
//
//	string cmd;
//
//	while (cnt--)
//	{
//		cin >> cmd;
//
//		if (cmd == "L")
//		{
//			if (!left.empty())
//			{
//				right.push(left.top());
//				left.pop();
//			}				
//		}
//		else if (cmd == "D")
//		{
//			if (!right.empty())
//			{
//				left.push(right.top());
//				right.pop();
//			}
//		}
//		else if (cmd == "B")
//		{
//			if(!left.empty())
//				left.pop();
//		}
//		else if (cmd == "P")
//		{
//			char data;
//			cin >> data;
//			left.push(data);
//		}
//	}
//
//	while (!left.empty())
//	{
//		right.push(left.top());
//		left.pop();
//	}
//
//	while (!right.empty())
//	{
//		cout << right.top();
//		right.pop();
//	}
//
//
//	return 0;
//}

// ���ڿ� Ǯ�� 2 (����, ������ ���ڿ��� ����� Ǯ��)
int main()
{
	cin.sync_with_stdio(false);

	string left,right;

	cin >> left;

	int cnt;

	cin >> cnt;

	char cmd;

	while (cnt--)
	{
		cin >> cmd;

		int left_len = left.length();
		int right_len = right.length();

		if (cmd == 'L')
		{
			if (left_len!=0)
			{
				right = left[left_len - 1]+right;
				left.pop_back();
			}
		}
		else if (cmd == 'D')
		{
			if (right_len!=0)
			{
				left += right[0];
				right = right.substr(1,right_len-1);
			}
		}
		else if (cmd == 'B')
		{
			if (left_len!=0)
				left.pop_back();
		}
		else if (cmd == 'P')
		{
			char data;
			cin >> data;
			left += data;
		}
	}

	cout << left + right;


	return 0;
}