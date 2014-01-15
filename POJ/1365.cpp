#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
int nextint(char *&s)
{
	int ans=0;
	while (*s && (*s<'0' || *s>'9'))s++;
	if (!*s)
		return -1;

	for (;*s>='0' && *s<='9';s++)
	{
		ans*=10;
		ans+=*s-'0';
		//printf("c=%c ",*s);
	}
	return ans;
}
int main()
{
	while (1)
	{
		int a,b,num=1;
		char str[1000],*tmp=str;
		gets(tmp);
		a=nextint(tmp);
		if (!a)
			break;
		do
		{
			b=nextint(tmp);
			while (b--)
				num*=a;
			a=nextint(tmp);
		}while(a>0);
		num--;
		vector<int> ans;
		for (int i=2;i*i<=num;i++)
			if (num%i==0)
			{
				ans.push_back(i);
				num/=i;
				i--;
			}
		if (num)
			ans.push_back(num);
		for (int i=ans.size()-1;i>=0;i--)
		{
			int rep=1;
			while(i>0 && ans[i-1]==ans[i])
			{
				rep++;
				i--;
			}
			printf("%d %d ",ans[i],rep);
		}
		printf("\n");
	}
}