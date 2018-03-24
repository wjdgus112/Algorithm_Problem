#include <iostream>
#include <string>
using namespace std;

int main()
{
	int A, B, C, multi;
	int cnt[10] = { 0, };

	cin >> A;
	cin >> B;
	cin >> C;

	multi = A*B*C;

	string str = to_string(multi);

	for (int i = 0; i < str.length(); i++)
	{
		int tmp = str[i]-48;
		switch (tmp)
		{
			case 0: 
				cnt[0]+=1;
				break;
			case 1: 
				cnt[1]+=1;
				break;
			case 2: 
				cnt[2]+=1;
				break;
			case 3: 
				cnt[3]+=1;
				break;
			case 4: 
				cnt[4]+=1;
				break;
			case 5: 
				cnt[5]+=1;
				break;
			case 6: 
				cnt[6]+=1;
				break;
			case 7: 
				cnt[7]+=1;
				break;
			case 8: 
				cnt[8]+=1;
				break;
			case 9: 
				cnt[9]+=1;
				break;
		}
	}

	for (int i = 0; i < 10; i++)
	{
		cout << cnt[i] << endl;
	}

	return 0;
}