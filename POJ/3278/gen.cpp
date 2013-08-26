#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
int N;
int main()
{
	srand((unsigned)time(NULL) + (unsigned)clock());
    scanf("%d",&N);
	
	while (N--)
		printf("%d %d\n",rand(),rand());
}
