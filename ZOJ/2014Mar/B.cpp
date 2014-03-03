#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int True=1,False=0;
/*
F[a_, b_] := Sum[a^k, {k, 0, b - 1}]
Table[PrimeQ[F[b, N]], {b, 2, 16}, {N, 1, 16}]
*/
const int tab[15][16]={{False, True, True, False, True, False, True, False, False, False, 
  False, False, True, False, False, False}, {False, False, True, 
  False, False, False, True, False, False, False, False, False, True, 
  False, False, False}, {False, True, False, False, False, False, 
  False, False, False, False, False, False, False, False, False, 
  False}, {False, False, True, False, False, False, True, False, 
  False, False, True, False, True, False, False, False}, {False, True,
   True, False, False, False, True, False, False, False, False, False,
   False, False, False, False}, {False, False, False, False, True, 
  False, False, False, False, False, False, False, True, False, False,
   False}, {False, False, True, False, False, False, False, False, 
  False, False, False, False, False, False, False, False}, {False, 
  False, False, False, False, False, False, False, False, False, 
  False, False, False, False, False, False}, {False, True, False, 
  False, False, False, False, False, False, False, False, False, 
  False, False, False, False}, {False, False, False, False, False, 
  False, False, False, False, False, False, False, False, False, 
  False, False}, {False, True, True, False, True, False, False, False,
   False, False, False, False, False, False, False, False}, {False, 
  False, False, False, True, False, True, False, False, False, False, 
  False, False, False, False, False}, {False, False, True, False, 
  False, False, True, False, False, False, False, False, False, False,
   False, False}, {False, False, True, False, False, False, False, 
  False, False, False, False, False, False, False, False, 
  False}, {False, True, False, False, False, False, False, False, 
  False, False, False, False, False, False, False, False}};
int main()
{
	int a,b;
	while (scanf("%d%d",&a,&b)!=EOF)
		printf("%s\n",tab[a-2][b-1]?"YES":"NO");
	return 0;
}