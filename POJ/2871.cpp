#include <cstdio>
using namespace std;
int main()
{
	float A,B;
	scanf("%f",&A);
	while (scanf("%f",&B),B<900.0)
	{
		printf("%.2f\n",B-A);
		A=B;
	}
	printf("End of Output\n");
	return 0;
}