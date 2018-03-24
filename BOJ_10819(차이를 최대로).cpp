#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calculate(vector<int> &a)
{
	int result = 0;

	for (int i = 1; i < a.size(); i++)
	{
		result += abs(a[i - 1] - a[i]);
	}

	return result;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;

	cin >> n;

	vector<int> a(n);

	for (int i = 0; i < n; i++) cin >> a[i];
	
	sort(a.begin(), a.end());

	int ans = 0;

	do
	{
		int tmp = calculate(a);
		ans = max(ans, tmp);
	} while (next_permutation(a.begin(), a.end()));

	cout << ans << "\n";

	return 0;
}