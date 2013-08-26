#include <cstdio>
#include <cstring>
const char 	F1[34]="+---+---+---+---+---+---+---+---+",
			FA[34]="|...|:::|...|:::|...|:::|...|:::|",
			FB[34]="|:::|...|:::|...|:::|...|:::|...|";
char answer[9][36];
char S1[200],S2[200];
int main()
{
	int i,j,k;
	memset(S1,0,sizeof(S1));
	memset(S2,0,sizeof(S2));
	gets(S1+1);
	gets(S2+1);
	memset(answer,0,sizeof(answer));
	
	for (i=1;i<=8;i++)
		if (i%2)
			strcpy(answer[i]+1,FA);
		else
			strcpy(answer[i]+1,FB);
	for (i=8;S1[i]<'a';i+=4)
		answer[9-(S1[i+2]-'0')][4*(S1[i+1]-'a'+1)-1]=S1[i];
	for (;S1[i-1]==',';i+=3)
		answer[9-(S1[i+1]-'0')][4*(S1[i]-'a'+1)-1]='P';
	for (i=8;S2[i]<'a';i+=4)
		answer[9-(S2[i+2]-'0')][4*(S2[i+1]-'a'+1)-1]=S2[i]+('a'-'A');
	for (;S1[i-1]==',';i+=3)
		answer[9-(S2[i+1]-'0')][4*(S2[i]-'a'+1)-1]='p';
	puts(F1);
	for (i=1;i<=8;i++)
	{
		puts(answer[i]+1);
		puts(F1);
	}
	return 0;
}
/*
White: Ke1,Qd1,Ra1,Rh1,Bc1,Bf1,Nb1,a2,c2,d2,f2,g2,h2,a3,e4
*/
