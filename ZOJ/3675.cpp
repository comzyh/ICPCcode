#include <cstdio>
#include <cstring>
int N,M;
int t1,t2,na;//ָ�׵�1,ָ�׵�2,Ŀ��״̬
int mem[1048576];//���仯����
int find(int n,int k);//ָ��״̬,���
inline int lowbit(int x)//ȡ���λ
{
	return x&(x^(x-1));
}
//inline void pri(int n);
int main()
{

	int i,j;
	char c;
	while (scanf("%d",&N)!=EOF)
	{
		
		t1=t2=0;
		getchar();
		for (i=0;i<N;i++)
		if(scanf("%c",&c),c=='*')
		{
				t1+=1<<i;
				t2+=1<<(N-i-1);
		}
		scanf("%d",&M);
		memset(mem,0x3f,1<<(M+2));
		
		//ȥ��ָ�׵����õĲ���
		if (t1)
		{
		while (!(t1 & 1))
		{
			t1>>=1;
			N--;
		}
		while (!(t2 & 1))
		{ 
			t2>>=1;
			N--;
		}
		na=(1<<M)-1;
		if (t1)
		{
			find(0,0);
			printf("%d\n",mem[na]);
		}
		}
		else
			printf("-1\n");
	}
	
}
int find(int n,int k)//Nails,deep
{
	n&=na;
	//printf("k=%d ",k);pri(n);getchar();//�뿴���������̵Ŀ���ȥ��ע��
	if (k>=mem[n])return 0;
	mem[n]=k;
	int l=lowbit(~n);//�ӵ�λ����һ����Ҫ��������
	for (int i=l;i;i>>=1)//ָ�׵����λ�ƶ�
	{
		if (l&(t1*i))find(n | (t1*i),k+1);
		if (l&(t2*i))find(n | (t2*i),k+1);
	}
}
/*
inline void pri(int n)
{
	int b=M;
	if (N>b)b=N;
	for (int i=0;i<b;i++)
		if ((n & (1<<i))!=0)
			printf("1");
		else 
			printf("0");
	printf(" %d\n",n);
}*/