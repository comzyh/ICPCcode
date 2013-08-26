#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
char str[1000009];
int main()
{
	while (gets(str),str[0]!='.')
	{
		int solved=0;
		for (int k=1;k<=100000;k++)
		{
			int j;
			for (j=0;str[j];j++)
				if (str[j]!=str[j%k])
					break;
			if (str[j]==0)
			{
				printf("%d\n",j/k);
				break;
			}
		}
	}
	return 0;
}