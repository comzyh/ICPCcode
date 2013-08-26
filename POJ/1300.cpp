#include <cstdio>
#include <cstring>
int N,M;
int D[25],Door;
int main()
{
	char str[100];
	while (gets(str),strcmp(str,"ENDOFINPUT")!=0)
	{
		char tmp[100];
		sscanf(str,"%s %d%d",tmp,&M,&N);
		memset(D,0,sizeof(D));
		Door=0;
		D[0]++;
		D[M]++;
		for (int i=0;i<N;i++)
		{
			gets(str);
			int x;
			for (int j=0;str[j]!='\0';)
			{
				while (str[j]==' ')j++;
				sscanf(str+j,"%d",&x);
				//printf("x=%d\n",x);
				D[x]++;
				D[i]++;
				while (str[j]>='0' && str[j]<='9')j++;
			}
		}
		int E =1;
		for (int i=0;i<N;i++)
		{
			E&=(!(D[i]&1));
			Door+=D[i];
			//printf("%3d ",D[i]);
		}
		//printf("---%d\n",M!=0); 
		
		if (E)
			printf("YES %d\n",(Door/2)-1);
		else
			printf("NO\n");
		gets(str);
	}
}
