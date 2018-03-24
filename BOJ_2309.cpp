#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int height[9], result;
int index1, index2;
vector<int> ans;

int main()
{
	cin.sync_with_stdio(false);

	for (int i = 0; i < 9; i++)
	{
		cin >> height[i];
		result += height[i];
	}


	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (i != j && (result - height[i] - height[j]) == 100)
			{
				index1 = i; index2 = j;
				break;
			}
		}
	}

	for (int i = 0; i < 9; i++)
	{
		if (index1 != i && index2 != i)
			ans.push_back(height[i]);
	}

	sort(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << "\n";

	return 0;
}