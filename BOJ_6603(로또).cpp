//#include <iostream>
//#include <vector>
//
//#define MAX_N 13
//using namespace std;
//
//int S[MAX_N];
//int lotto[MAX_N];
//int k;
//
//void lotto_print()
//{
//	for (int i = 0; i < 6; i++) cout << lotto[i] << " ";
//	cout << "\n";
//}
//
//void DFS(int start,int depth)
//{
//	if (depth == 6) lotto_print(); // 6개면 출력
//	
//	// 6개가 쌓이기 전에
//	for (int i = start; i < k; i++)
//	{
//		lotto[depth] = S[i];
//		DFS(i + 1, depth + 1);
//	}
//}
//int main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//
//	do
//	{
//		cin >> k;
//
//		for (int i = 0; i < k; i++)
//		{
//			int tmp; 
//			cin >> tmp;
//			S[i] = tmp;
//		}
//
//		DFS(0,0);
//
//		cout << "\n";
//
//	} while (k != 0);
//
//	return 0;
//}


// 순열을 이용한 풀이

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int a[13];
vector<int> tmp;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int k;

	while (1)
	{
		cin >> k;

		if (k == 0) break;

		for (int i = 0; i < k; i++)	cin >> a[i];

		// 0을 n-6개 , 1을 6개 넣어준다.
		for (int i = 0; i < 6; i++) tmp.push_back(1);
		for (int i = 0; i < k - 6; i++) tmp.push_back(0);

		// 1이 있는 index만 뽑아준다.
		do
		{
			for (int i = 0; i < tmp.size(); i++)
			{
				if (tmp[i] == 1)
					cout << a[i] << " ";
			}
			cout << "\n";
		} while (prev_permutation(tmp.begin(), tmp.end()));

		cout << "\n";

		tmp.clear();
	}

	return 0;
}