#include <iostream>
#include <vector>

using namespace std;

int arr_T[50];

void init()
{
	for (int i = 1; i <= 50; i++)
	{
		arr_T[i - 1] = i*(i + 1) / 2;
		//cout << arr_T[i - 1] << endl;
	}
}

bool solution(int num)
{
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			for (int k = 0; k < 50; k++)
			{
				int sum = arr_T[i] + arr_T[j] + arr_T[k];
				if (sum == num)
					return true;
			}
		}
	}

	return false;
}

int main()
{
	ios::sync_with_stdio(false);

	int T,K;

	cin >> T;

	init();
	
	for (int i = 0; i < T; i++)
	{
		cin >> K;

		if (solution(K)) cout << 1 << "\n";
		else cout << 0 << "\n";
	}


	return 0;
}