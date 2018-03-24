#include <iostream>

using namespace std;

int main()
{
	// M : 벨트의 개수
	// a,b :벨트로 이어진 두 바퀴의 회전수의 비
	// s : 벨트의 형태 (안꼬인 형태는 0,꼬인 형태는 1)
	// r : 회전 방향 (시계방향은 true, 반시계방향은 false), 첫 시작은 시계방향 
	// r_num : M+1번 바퀴의 분당 회전수
	int M, a=1, b=1,s,r_num=1; 
	bool r = true;

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> s;
		r_num = (r_num / a)*b;
		r = s == 1 ? !r : r; // 꼬인 형태면 방향이 반대
	}
	
	if (r) cout << "0 " << r_num;
	else cout <<"1 " << r_num;

	return 0;
}