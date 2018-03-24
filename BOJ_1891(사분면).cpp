#include <iostream>
#include <string>

using namespace std;


int d;
long long x, y;
string q_Num;

// ��и� ������ ��ȣ�� ����Ǿ� �ִ� ���ڿ��� �ϳ��ϳ��� �˻��Ͽ� ��ǥ�� ��� �Լ�
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

	// d ; ��и� ���� ��ȣ�� �ڸ���, q_Num : ��и��� ���� ��ȣ
	cin >> d >> q_Num;

	// �̵��� ������ ��Ÿ���� x,y
	cin >> x >> y;

	long long size = (1LL << d);

	// ��и� ������ ��ȣ�� �ش��ϴ� ��ǥ�� ��´�.
	auto p = get_Coordinate(q_Num, 0, 0, 0, size);

	// ��ǥ �̵�
	p.first -= y;
	p.second += x;

	if(0<=p.first && p.first<size && 0<=p.second && p.second<size)
		cout << go(0, 0, size, p.first, p.second);
	// ��ǥ�� ���� �ȿ� �������� ������ -1 ���
	else cout << "-1" << "\n";

	return 0;
}