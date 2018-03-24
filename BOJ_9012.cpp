

#include <iostream>
#include <string>

using namespace std;


int main()
{
	int T, cnt;
	string str;
	
	cin >> T;
	string* result = new string[T];
	for (int i = 0; i < T; i++)
	{
		cnt = 0;
		str = "";
		cin >> str;
		if (str.length() >= 2 && str.length() <=50)
		{
			if (str[0] == '(')
			{
				for (int j = 0; j < str.length(); j++)
				{

					if (str[j] == '(') cnt++;
					else if (str[j] == ')') cnt--;

					if (cnt < 0)
					{
						result[i] = "NO";
						break;
					}
				}

				if (cnt == 0)
					result[i] = "YES";
				else
					result[i] = "NO";

			}
			else
				result[i] = "NO";

		}
		else
			i--;
	
	}

	for (int i = 0; i < T; i++)
	{
		cout << result[i] << endl;
	}

	delete[] result;

	return 0;
}