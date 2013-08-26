#include <cstdio>
int main()
{
	int R,X,Y;
	scanf("%x,%d,%d",&R,&X,&Y);
	R&=(~(1<<X));
	R&=(~(7<<(Y-2)));
	R|=(6<<(Y-2));
	printf("%x",R);
	//1000
	//1110
}
