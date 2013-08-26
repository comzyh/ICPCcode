#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
char s1[109],s2[109];
int e1[26],e2[26];
int main()
{
	gets(s1);
	gets(s2);
	memset(e1,0,sizeof(e1));
	memset(e2,0,sizeof(e2));
	for (int i=0;s1[i];i++)
	{
		e1[s1[i]-'A']++;
		e2[s2[i]-'A']++;
	}
	sort(e1,e1+26);
	sort(e2,e2+26);
	int YES=1;
	for (int i=0;i<26;i++)
		if (e1[i]!=e2[i])
			YES=0;
	if (YES && strlen(s1)==strlen(s2))
		printf("YES");
	else
		printf("NO");
	return 0;
}
