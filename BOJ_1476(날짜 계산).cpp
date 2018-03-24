#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int e, s, m;
	int cmp_e=1, cmp_s=1, cmp_m=1;
	int ans = 1;

	cin >> e >> s >> m;

	while (true)
	{
		if (e == cmp_e && s == cmp_s && m == cmp_m)
		{
			cout << ans << "\n";
			break;
		}

		cmp_e = cmp_e+1 > 15 ? 1 : cmp_e + 1; 
		cmp_s = cmp_s+1 > 28 ? 1 : cmp_s + 1;
		cmp_m = cmp_m+1 > 19 ? 1 : cmp_m + 1;
		ans += 1;
	}

	return 0;
}