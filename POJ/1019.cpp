#include <cstdio>
#include <cstring>
#include <cstdlib>
int T,tab[100000];
inline int numlen(int n);
char str[200000];
int main()
{
    int i,j,k,n,pos,len,END;
    scanf("%d",&T);
    pos=0;len=0;
    for (i=1;pos<=0x7fffffff;i++)
    {
        
        len+=numlen(i);    
        pos+=len;
        if (pos<0)break;
        tab[i]=pos;
    }
    END=i-1;
    //for (i=1;i<100;i++)
    //printf("tab[%5d]=%10d\n",i,tab[i]);
    //printf("%d",END);
    while (T--)
    {
          scanf("%d",&n);
          for (i=1;tab[i]<n && i<END;i++);
          if (!(n>tab[END]))i--;
          //pos=0;len=0;
		  //printf("i=%d\n",i);
          n=n-tab[i];
		  str[0]=0;
		  int offset=0;
          for (j=1;j<=i+1;j++)
          {
              offset+=sprintf(str+offset,"%d",j);
			  //pos+=numlen(j);
          }
		  //printf("%s\n",str);
		  //printf("n=%d\n",n);
		  printf("%c\n",str[n-1]);
    }
    system("pause");
}
inline int numlen(int n)
{
       if (n<10)return 1;
       else{
       if (n<100)return 2;
       else{
       if (n<1000)return 3;
       else{
       if (n<10000)return 4;
       else return 5;
       }
       }         
       }
}
