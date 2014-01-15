#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int arr[7];
int main()
{
	while (1)
	{
		int orsum=0,ans=0;
		for (int i=1;i<=6;i++)
		{
			scanf("%d",&arr[i]);
			orsum|=arr[i];
		}
		if (!orsum)
			break;
		ans+=arr[6]+arr[5]+arr[4];
		arr[1]-=min(arr[1],arr[5]*11);
		int need2=arr[4]*5;
		int use2=min(arr[2],need2);
		arr[2]-=use2;
		need2-=use2;
		arr[1]-=min(arr[1],need2*4);
		//3
		ans+=arr[3]/4;
		arr[3]%=4;
		if (arr[3])
		{
			ans++;
			need2=7-2*arr[3];
			use2=min(arr[2],need2);
			arr[2]-=use2;
			arr[1]-=min(arr[1],36-arr[3]*9-use2*4);
		}
		//2
		ans+=arr[2]/9;
		arr[2]%=9;
		if (arr[2])
		{
			ans++;
			arr[1]-=min(arr[1],36-arr[2]*4);
		}
		//1
		ans+=arr[1]/36;
		arr[1]%=36;
		if (arr[1])
			ans++;
		printf("%d\n",ans);
	}
	return 0;
}