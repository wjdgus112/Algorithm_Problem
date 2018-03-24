#include <iostream>
#include <cstring>

using namespace std;

bool checkZero(char *A)
{
	bool result = false;
	for (int i = 0; i < strlen(A); i++)
	{
		if (A[i] == '0')
			result = true;
	}

	return result;
}
void reverseNum(char *A)
{
	char temp;

	temp = A[0];
	A[0] = A[2];
	A[2] = temp;

}
int main()
{
	char A[3], B[3];
	int num_A, num_B;
	// ����ó�� : 0�� ���� �ȵȴ�, A!=B �̿��� �Ѵ�.
	
	cin >> A;
	cin >> B;

	while (checkZero(A) || checkZero(B) || !strcmp(A,B) )
	{
		cin >> A;
		cin >> B;
	}

	reverseNum(A);
	reverseNum(B);

	num_A = atoi(A);
	num_B = atoi(B);

	if (num_A > num_B)
		printf("%15.2f",num_A);
	else
		cout << num_B;

	

	return 0;
}