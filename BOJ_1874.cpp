#include <iostream>
#include <stack>
#include <vector>

std::stack<int> stk; // 1~n까지 수를 저장할 스택
std::vector<char> ans; // +, - 를 저장할 벡터
int input_seq[100001]; // 입력 수열을 저장할 배열

int main()
{
	std::cin.sync_with_stdio(false);

	int n, cnt = 1;

	std::cin >> n;

	// 수열 입력
	for (int i = 1; i <= n; i++)
	{
		std::cin >> input_seq[i];
	}

	for (int i = 1; i <= n; i++)
	{
		// 스택에 1~n 삽입
		stk.push(i);
		ans.push_back('+');
		// 스택이 비어있지 않을 때 스택의 top 원소가 입력 수열에 존재하면 pop 시킨다
		while (!stk.empty() && (stk.top() == input_seq[cnt]))
		{
			stk.pop();
			ans.push_back('-');
			cnt++;
		}
	}

	// 입력된 수열을 만들 수 있는 경우에는 항상 스택이 비어있다. 비어있지 않으면 만들 수 없는 경우이기 때문에 NO를 출력한다.
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