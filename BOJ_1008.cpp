#include <iostream>
#pragma warning(disable:4996)
using namespace std;

int main()
{
	double A, B;

	scanf("%lf %lf", &A, &B);
	printf("%.9lf", A/B);

	return 0;
}