#include <stdio.h>
#include <string.h>
#define maxn 1010
int max(int a,int b) {return a>b?a:b;}
int LongestCommonSubsequence(char S[],char T[])
{  int Slength=strlen(S);
   int Tlength=strlen(T);
   int i,j;
   for(i=Slength;i>=1;i--)
           S[i]=S[i-1];
   for(i=Tlength;i>=1;i--)
           T[i]=T[i-1];
   int common[Slength+1][Tlength+1];
   memset(common,0,sizeof(common));
  for(i=1;i<=Slength;i++)
          for(j=1;j<=Tlength;j++)
                  if(S[i]==T[j]) common[i][j]=common[i-1][j-1]+1;
                  else common[i][j]=max(common[i][j-1],common[i-1][j]);
        return common[Slength][Tlength];
}
int main()
{  char S[maxn],T[maxn];
 while(gets(S)) {gets(T);printf("%d\n",LongestCommonSubsequence(S,T));}
   return 0;
}
