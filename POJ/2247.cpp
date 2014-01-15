#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const char suffix[10][3]={"th","st","nd","rd","th","th","th","th","th","th"};
int ans[5842+1];
int main()
{
	ans[1]=1;
	int p2=1,p3=1,p5=1,p7=1;
	for (int i=2;i<=5842;i++)
	{
		ans[i]=min(min(ans[p2]*2,ans[p3]*3),min(ans[p5]*5,ans[p7]*7));
		if (ans[i]==ans[p2]*2)p2++;
		if (ans[i]==ans[p3]*3)p3++;
		if (ans[i]==ans[p5]*5)p5++;
		if (ans[i]==ans[p7]*7)p7++;
	}
	int N;
	while (scanf("%d",&N),N)
		printf("The %d%s humble number is %d.\n",N,(N%100>=10 && N%100<=13)?"th":suffix[N%10],ans[N]);
	return 0;
}