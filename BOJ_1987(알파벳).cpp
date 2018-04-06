#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define MAX 21

int r, c;
char alpha[MAX][MAX]; // 입력되는 보드판
bool chk_alpha[26]; // 사용된 알파벳 
int dx[4] = { 0, 0,-1,1 };
int dy[4] = { -1,1,0,0 };


int DFS(int x, int y,int chk)
{
	// 사용한 알파벳 체크
	chk_alpha[chk-'A'] = true;

	int ans = 0;
	for (int k = 0; k < 4; k++)
	{
		int nx = x + dx[k]; int ny = y + dy[k];

		if (0 <= nx && nx < r && 0 <= ny && ny < c)
		{
			int next = alpha[nx][ny];
			// 다른 알파벳을 가진 판이면 방문한다.
			if (chk_alpha[next-'A']==false)
			{
				chk_alpha[next - 'A'] = true;
				// 최대값만 저장
				ans = max(ans,DFS(nx, ny,next));
				// 백트래킹
				chk_alpha[next - 'A'] = false;
			}
		}
	}

	return ans+1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> r >> c;
		
	for (int i = 0; i < r; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < s.length(); j++)
		{
			alpha[i][j] = s[j];
		}
	}
	cout << DFS(0, 0,alpha[0][0]) << "\n";

	return 0;
}