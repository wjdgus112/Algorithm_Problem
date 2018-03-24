#include <iostream>
#include <string>

using namespace std;

string input_str, bomb,ans;
bool chk_fire;

int main()
{
	cin.sync_with_stdio(false);

	cin >> input_str >> bomb;

	int input_len = input_str.length();
	int bomb_len = bomb.length();

	for (int i = 0; i < input_len; i++)
	{
		ans += input_str[i];
		// ���߹��ڿ��� �� ���ڿ� ��ġ�� ��� ��
		if (input_str[i] == bomb[bomb_len - 1] && i >= bomb_len-1)
		{
			chk_fire = true;
			// ans�� �� �ֱ� ���ڿ��� bomb_len��ŭ ���Ͽ� ���߹��ڿ��� ��ġ�ϴ��� ���Ѵ�.
			for (int j = 1; j < bomb_len; j++)
			{
				// ���߹��ڿ��� �ٸ� ���ڰ� ���� ���
				if (ans[ans.size()-1 - j] != bomb[bomb_len-1 - j])
					chk_fire = false;
			}

			// ���߹��ڿ��� ��ġ�ϸ� ���߹��ڿ��� ���̸�ŭ ans�� ���� pop() �����ش�
			if (chk_fire)
			{
				for (int k = 0; k < bomb_len; k++)
					ans.pop_back();
			}
		}
	}

	if (!ans.empty())
	{
		cout << ans;
	}
	else
		cout << "FRULA";

	return 0;
}