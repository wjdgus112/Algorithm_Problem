#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> paper(101,vector<int>(101,-1));


int main()
{
	int N,col,row,width,height;
	int cnt = 0;

	cin >> N; // 색종이의 갯수

	vector<int> ans(N,0); // 색종이 넓이 벡터 

	while (cnt<N)
	{
		cin >> col >> row >> width >> height;
		for (int i = col; i < col+width; i++)
		{
			for (int j = row ;j < row+height; j++)
			{
				paper[i][j] = cnt; // 색종이 번호로 초기화
			}
		}
		cnt++;
	}
	
	for (int chk = 0; chk < N; chk++)
	{
		for (int i = 0; i < paper.size(); i++)
		{
			for (int j = 0; j < paper[i].size(); j++)
			{
				if (paper[i][j] == chk)
					ans[chk]++;
			}
		}
	}

	for (int i = 0; i < ans.size(); i++) cout << ans[i] << endl;

	return 0;
}