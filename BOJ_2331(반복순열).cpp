#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> D;
int A, P;


int solution(int A)
{
	D.push_back(A);
	
	while (1)
	{
		int next_num=0;

		while (A != 0)
		{
			next_num += pow(A % 10, P);
			A /= 10;
		}

		for (int i = 0; i < D.size(); i++)
		{
			if (D[i] == next_num)
				return i;
		}

		D.push_back(next_num);

		A = next_num;
	}
}

int main()
{
	cin >> A >> P;
	
	cout << solution(A) << endl;

	//for (int i = 0; i < D.size(); i++)
	//	cout << D[i] << " ";

	return 0;
}