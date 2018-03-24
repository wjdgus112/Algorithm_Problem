#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long f[21]; // 1!~20! ���� ���� ������ ����
bool check[21]; // 1~N������ ���ڰ� ������ �ִ��� ������ Ȯ���ϴ� ����

int main()
{
	int N, cmd;

	cin >> N;

	f[0] = 1;

	// ���丮�� �ʱ�ȭ
	for (int i = 1; i < 21; i++)
		f[i] = f[i - 1] * i;
	
	cin >> cmd;

	// �� ��° �������� ����ϱ�.
	if (cmd == 2)
	{
		vector<int> a(N);

		// ���� �Է�
		for (int i = 0; i < N; i++)
			cin >> a[i];

		long long ans = 0;

		for (int i = 0; i < N; i++)
		{
			for (int j = 1; j < a[i]; j++)
			{
				// 1���� �ش��ϴ� ���ұ��� ���丮�� ���� �÷����� �����ش�.
				if (check[j] == false)
					ans += f[N - i - 1];
			}
			// ������ �����ϴ� ���ڴ� �ִٰ� ǥ�����ش�.
			check[a[i]] = true;
		}
		
		cout << ans + 1 << "\n";
	}
	// k ��° ���� ����ϱ�
	else
	{
		long long k;

		cin >> k;

		vector<int> a(N);

		// k��° ���� ã�� ����
		for (int i = 0; i < N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				// ������ �̹� �����ϴ� ���ڸ� �Ѿ��
				if (check[j] == true) continue;
				// ���丮�� ���� k���� ������ k���� ���丮�� ���� ���ش�
				if (f[N - i - 1] < k)
				{
					k -= f[N - i - 1];
				}
				// ���丮�� ���� k���� ũ�� �ش��ϴ� ������ ���ڸ� ã�� ��. 
				// a[i]�� �����ϰ� ������ �����ϴ� ���ڸ� üũ���ش�
				else
				{
					a[i] = j;
					check[j] = true;
					break;
				}
			}
		}

		for (int i = 0; i < N; i++) cout << a[i] << " ";
		cout << "\n";
	}

	return 0;
}