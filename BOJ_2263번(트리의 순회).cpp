#include <iostream>

using namespace std;

#define MAX_N 100001

int n;
int position[MAX_N];
int in_Order[MAX_N];
int post_Order[MAX_N];
int pre_Order[MAX_N];

void solve(int in_start,int in_end,int post_start,int post_end)
{
	if (in_start > in_end || post_start > post_end) return;

	int root = post_Order[post_end]; // root는 항상 post_Order의 끝 값
	cout << root << " ";

	int p = position[root]; // root 값이 있는 곳 Idx 값 저장

	int left = p - in_start;

	solve(in_start,p-1,post_start,post_start+left-1);
	solve(p + 1, in_end, post_start + left, post_end - 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	
	for (int i = 0; i < n; i++) cin >> in_Order[i];
	for (int i = 0; i < n; i++) cin >> post_Order[i];
	
	for (int i = 0; i < n; i++) position[in_Order[i]] = i; // Idx 저장

	solve(0,n-1,0,n-1);

	return 0;
}