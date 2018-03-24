#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#pragma warning(disable:4996)

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i].first, &a[i].second);
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < a.size(); i++) {
		printf("%d %d\n", a[i].first, a[i].second);
	}

	return 0;
}

// 구조체를 직접 만들 경우

//struct Point {
//	int x, y;
//};
//
//bool cmp(const Point &u, const Point &v)
//{
//	if (u.x < v.x) {
//		return true;
//	}
//	else if (u.x == v.x) {
//		return u.y < v.y;
//	}
//	else {
//		return false;
//	}
//}
