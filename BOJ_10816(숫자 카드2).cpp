#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX_N 500001

int N, M;
vector<int> card;
int target[MAX_N];

int main()
{
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int card_num;
		cin >> card_num;
		card.push_back(card_num);
	}

	sort(card.begin(),card.end());

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> target[i];
	}

	
	for (int i = 0; i<M; i++)
	{
		auto a = equal_range(card.begin(), card.end(), target[i]);
		//cout << upper_bound(card.begin(), card.end(), target[i])-lower_bound(card.begin(),card.end(),target[i]) << " ";
		cout << a.second-a.first << " ";
	}

	return 0;
}