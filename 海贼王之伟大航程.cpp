#include<iostream>
using namespace std;
#define MAX 1<<16
int dp[MAX][17];
int matrix[17][17];
int n;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&matrix[i][j]);
        }
    }
    
    dp[1][0]=0;
    for(int i=1;i<n;i++)
    {
        int tr=(1<<i)+1;
        dp[tr][i]=matrix[0][i];
    }
    int s=0;
    int max=(1<<n);
    for(int i=1,tr=0;;i++)
    {
        tr=(i<<1)+1;
        if(tr>=max)break;
        for(int j=1;j<n;j++)
        {
            if(tr!=(s=tr&(~(1<<j))))
            {
                int min=MAX;
                for(int t=1;t<n;t++)
                {
                    if(s&(1<<t))
                    {
                        if(min>(dp[s][t]+matrix[t][j]))
                        {
                            min=dp[s][t]+matrix[t][j];
                        }
                    }
                
                }
                if(min!=MAX)
                {
                    dp[tr][j]=min;
                }
                
            }
            
        }
    }
    printf("%d\n",dp[max-1][n-1]);
    return 0;
}
