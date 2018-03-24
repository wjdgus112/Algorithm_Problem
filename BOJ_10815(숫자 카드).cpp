#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 500001

int N, M;
int card[MAX_N];
int target[MAX_N];


bool Binary_search(int target)
{
	int left, right;

	left = 0; right = N - 1;

	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (card[mid] < target) left = mid + 1;
		else if (card[mid] > target) right = mid - 1;
		else if (card[mid] == target) return true;
	}

	return false;
}

int main()
{
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++) cin >> card[i];

	sort(card, card + N);

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> target[i];
	}

	for (int i = 0; i<M; i++)
	{
		if (Binary_search(target[i])) cout << "1 ";
		else cout << "0 ";
	}

	return 0;
}