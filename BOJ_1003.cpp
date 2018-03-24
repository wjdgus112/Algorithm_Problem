#include <iostream>


using namespace std;
int cnt[2] = { 0, };

int fibonacci(int n)
{
	if (n == 0)
	{
		cnt[0]++;
	}
	else if (n == 1)
	{
		cnt[1]++;
	}
	else
	{
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}

int main()
{
	int T,N; 
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> N;
		fibonacci(N);

		cout << cnt[0] << " " << cnt[1];
		cout << endl;

		cnt[0] = 0;
		cnt[1] = 0;
	}

	return 0;
}