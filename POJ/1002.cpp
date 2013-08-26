#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;
int N;
int exist[10000000];
inline int readL();
inline void format_print(int k);
int main()
{
    scanf("%d\n",&N);
    //string str;
    //getline(cin,str);
    memset(exist,0,sizeof(exist));
    for (int i=1;i<=N;i++)
    {
        //cout<<readL()<<endl;
        exist[readL()]++;
    }
    int No_ans=1;
    for (int i=0;i<=9999999;i++)
    if(exist[i]>1){No_ans=0;format_print(i);cout<<' '<<exist[i]<<endl;}
    if (No_ans==1)cout<<"No duplicates."<<endl;
    //system("pause"); 
}
inline int readL()
{
       char str[100];
       int ans=0;
       gets(str);
       for(int i=0;i<strlen(str);i++)
       switch  (str[i])
       {
               case '0':
                    ans*=10;ans+=0;break;
               case '1':
                    ans*=10;ans+=1;break;
               case '2': case 'A': case 'B': case 'C':
                    ans*=10;ans+=2;break;
               case '3': case 'D': case 'E': case 'F':
                    ans*=10;ans+=3;break;
               case '4': case 'G': case 'H': case 'I':
                    ans*=10;ans+=4;break;
               case '5': case 'J': case 'K': case 'L':
                    ans*=10;ans+=5;break;
               case '6': case 'M': case 'N': case 'O':
                    ans*=10;ans+=6;break;
               case '7': case 'P': case 'R': case 'S':
                    ans*=10;ans+=7;break;
               case '8': case 'T': case 'U': case 'V':
                    ans*=10;ans+=8;break;
               case '9': case 'W': case 'X': case 'Y':
                    ans*=10;ans+=9;break;
               case '-':
                    break;
       }
       return ans;
}
  
inline void format_print(int k)
{
       string str("999-9999");
       for (int i=7;i>=0;i--)
       {
           if (i==3){str[i]='-';i--;}
           str[i]=(k%10)+48;
           k/=10;
       }
       cout<<str;
}
