#include <iostream>
#include <string>

using namespace std;


int d;
long long x, y;
string q_Num;

// 사분면 조각의 번호가 저장되어 있는 문자열을 하나하나씩 검사하여 좌표를 얻는 함수
pair<long long, long long> get_Coordinate(string &str,int index, long long r, long long c, long long size)
{
	if (size == 1) return make_pair(r, c);
	else 
	{
		if (str[index] == '1') {
			return get_Coordinate(str, index + 1, r, c + size / 2, size / 2);
		}
		else if (str[index] == '2') {
			return get_Coordinate(str, index + 1, r, c, size / 2);
		}
		else if (str[index] == '3') {
			return get_Coordinate(str, index + 1, r + size / 2, c, size / 2);
		}
		else if (str[index] == '4') {
			return get_Coordinate(str, index + 1, r + size / 2, c + size / 2, size / 2);
		}
	}
	return make_pair(0, 0);
}
string go(long long r,long long c,long long size,long long x,long long y)
{
	if (size == 1) return "";
	if (x < r + size / 2 && y < c+ size / 2) return "2" + go(r, c, size / 2, x, y);
	else if(x < r+size/2 && y >= c+size/2) return "1" + go(r, c + size / 2, size / 2, x, y);
	else if(x>=r+size/2 && y< c+ size/2) return "3" + go(r + size / 2, c, size / 2, x, y);
	else return "4" + go(r + size / 2, c + size / 2, size / 2, x, y);

}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	// d ; 사분면 조각 번호의 자릿수, q_Num : 사분면의 조각 번호
	cin >> d >> q_Num;

	// 이동의 내용을 나타내는 x,y
	cin >> x >> y;

	long long size = (1LL << d);

	// 사분면 조각의 번호가 해당하는 좌표를 얻는다.
	auto p = get_Coordinate(q_Num, 0, 0, 0, size);

	// 좌표 이동
	p.first -= y;
	p.second += x;

	if(0<=p.first && p.first<size && 0<=p.second && p.second<size)
		cout << go(0, 0, size, p.first, p.second);
	// 좌표가 범위 안에 존재하지 않으면 -1 출력
	else cout << "-1" << "\n";

	return 0;
}