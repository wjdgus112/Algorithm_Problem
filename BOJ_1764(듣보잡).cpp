#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
string cmp_Str;
map<string, int> m;
vector<string> ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		m.insert(pair<string,int>(s, 0));
	}

	for (int i = 0; i < M; i++)
	{
		string find_str;
		cin >> find_str;

		if (m.find(find_str)!=m.end())
			ans.push_back(find_str);
	}

	sort(ans.begin(), ans.end());

	cout << ans.size() << "\n";

	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << "\n";
	}

	return 0;
}