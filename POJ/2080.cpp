#include <cstdio>
#include <cstring>
const char Week[8][10]={"","Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" , "Saturday"};
int main()
{
	int y,m,d,w,Day;
	while (scanf("%d",&Day),Day!=-1)
	{
		y=2000;
		m=1;
		d=1;
		w=7;
		w+=Day;
		
		while (Day--)
		{
			d++;
			if (d<29 && Day>29)
			{
				Day-=(29-d);
				d=29;
			}
				
			switch (m)
			{
				case 1:case 3:case 5:case 7:case 8:case 10:case 12:
					if (d>31)
					{
						d=1;
						m++;
					}
					break;
				case 2:
					if ((y%4==0 && y%100!=0) || y%400==0)
					{
						if (d>29)
						{
							d=1;
							m++;
						}
					}
					else
					{
						if (d>28)
						{
							d=1;
							m++;
						}
					}
					break;
				default:
					if (d>30)
					{
						d=1;
						m++;
					}
					break;
			}
			if (m>12)
			{
				m=1;
				y++;
				while (Day>366)
				{
					if ((y%4==0 && y%100!=0) || y%400==0)
						Day-=366;
					else
						Day-=365;
					y++;
				}
			}
		}
		w=(w-1)%7+1;
		printf("%04d-%02d-%02d ",y,m,d);
		puts(Week[w]);
	}
}
