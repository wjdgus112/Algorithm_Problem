#include <iostream>

using namespace std;

int main()
{
	// M : ��Ʈ�� ����
	// a,b :��Ʈ�� �̾��� �� ������ ȸ������ ��
	// s : ��Ʈ�� ���� (�Ȳ��� ���´� 0,���� ���´� 1)
	// r : ȸ�� ���� (�ð������ true, �ݽð������ false), ù ������ �ð���� 
	// r_num : M+1�� ������ �д� ȸ����
	int M, a=1, b=1,s,r_num=1; 
	bool r = true;

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> s;
		r_num = (r_num / a)*b;
		r = s == 1 ? !r : r; // ���� ���¸� ������ �ݴ�
	}
	
	if (r) cout << "0 " << r_num;
	else cout <<"1 " << r_num;

	return 0;
}