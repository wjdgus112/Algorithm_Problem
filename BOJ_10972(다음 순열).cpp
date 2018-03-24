#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 10000

int arr[MAX_N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;

	cin >> N;

	for (int i = 0; i < N; i++) cin >> arr[i];

	if (next_permutation(arr, arr + N))
	{
		for (int i = 0; i < N; i++) cout << arr[i] << " ";
	}
	else cout << "-1\n";

	return 0;
}