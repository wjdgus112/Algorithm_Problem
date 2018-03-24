#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
using namespace std;

bool cmp(const pair<int, int> a, const pair<int, int> b)
{
	if (a.first < b.first)
		return true;
	else if (a.first == b.first)
		return a.second < b.second;
	else
		return false;
}

int distance(const pair<int, int> a, const pair<int, int> b)
{
	return (b.first - a.first)*(b.first - a.first) + (b.second - a.second)*(b.second - a.second);
}

int main()
{
	int n;
	int ans;
	cin >> n;
	
	vector<pair<int, int>> a(n);

	// n개의 좌표 입력
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first;
		cin >> a[i].second;
	}

	// 좌표 정렬
	sort(a.begin(), a.end(), cmp);	

	ans = -1;

	for (int i = 1; i < n; i++)
	{	
		int d = distance(a[i - 1], a[i]);
		if (ans==-1 || ans > d) ans = d;
	}

	cout << ans;

	return 0;
}