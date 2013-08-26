#include <cstdio>
#include <cstring>
const int C[5]={9,4,4,4,7};
char str[100];
char pr[5][7];
double E,FE,le,sumle,sump;
int main()
{
  int i,j,x[5];
  char  c[5];
	while (gets(str),str[0]!='-')
	{
			E=FE=0;
		  do
		  {
		  	le=sumle=sump=0;
		  	sscanf(str,"%s %s %s %s %s",pr[0],pr[1],pr[2],pr[3],pr[4]);
				for (i=0;i<5;i++)
				{
					sscanf(pr[i],"%d%c",&x[i],&c[i]);
					if (c[i]=='g')
						sumle+=x[i]*C[i];
					if (c[i]=='C')
							sumle+=x[i];
					if (c[i]=='%')
							sump+=(double)x[i]/100;
				}
					le=sumle/(1.000-sump);
					E+=le;
					if (c[0]=='%')
						FE+=x[0]*le/100;
					if (c[0]=='C')
						FE+=x[0];
					if (c[0]=='g')
						FE+=x[0]*C[0];
					//printf("%c|sumle=%f,le=%f\n",c[1],sumle,le);
		  }while (gets(str),str[0]!='-');
		  printf("%.0f\%\n",(FE/E)*100);
	}
		
}
