#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


bool ispalindrome(const string a)
{
	string temp(a);
	reverse(temp.begin(), temp.end());

	if (temp.compare(a) == 0)
		return true;
	else
		return false;
}

int checksuffix(const string a)
{
	string temp;
	for (int i = 0; i < a.length(); i++)
	{
		temp = a.substr(i, a.length() - i);
		if (ispalindrome(temp))
			return temp.length();
	}
}

string getsubstr(int index, const string a)
{
	string temp;

	temp = a.substr(0, index);

	reverse(temp.begin(), temp.end());

	return temp;
}

int main()
{
	string str;

	cin >> str;

	/*for (int i = 0; i < str.length(); i++)
	{
		string temp="";
		temp = str + getsubstr(i, str);
		if (ispalindrome(temp))
		{
			cout << temp.length();
			break;
		}
	}*/

	string temp;
	temp = str + getsubstr(str.length()-checksuffix(str),str);
	cout << temp.length();
	
	return 0;
}