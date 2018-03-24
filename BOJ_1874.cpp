#include <iostream>
#include <stack>
#include <vector>

std::stack<int> stk; // 1~n���� ���� ������ ����
std::vector<char> ans; // +, - �� ������ ����
int input_seq[100001]; // �Է� ������ ������ �迭

int main()
{
	std::cin.sync_with_stdio(false);

	int n, cnt = 1;

	std::cin >> n;

	// ���� �Է�
	for (int i = 1; i <= n; i++)
	{
		std::cin >> input_seq[i];
	}

	for (int i = 1; i <= n; i++)
	{
		// ���ÿ� 1~n ����
		stk.push(i);
		ans.push_back('+');
		// ������ ������� ���� �� ������ top ���Ұ� �Է� ������ �����ϸ� pop ��Ų��
		while (!stk.empty() && (stk.top() == input_seq[cnt]))
		{
			stk.pop();
			ans.push_back('-');
			cnt++;
		}
	}

	// �Էµ� ������ ���� �� �ִ� ��쿡�� �׻� ������ ����ִ�. ������� ������ ���� �� ���� ����̱� ������ NO�� ����Ѵ�.
	if (!stk.empty()) std::cout << "NO\n";
	else
	{
		for (int i = 0; i < ans.size(); i++)
		{
			std::cout << ans[i] << "\n";
		}
	}

	
	return 0;
}