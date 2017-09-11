#include<iostream>
#include<algorithm>
using namespace std;
int ballNum,power,ghostNum;
int dp[1000][500];
int ghostInfo[100][2];
int main()
{
    scanf("%d%d%d",&ballNum,&power,&ghostNum);
    for(int i=1;i<=ghostNum;i++)
    {
        scanf("%d%d",ghostInfo[i],ghostInfo[i]+1);
    }
    for(int i=1;i<=ghostNum;i++)
    {
        for(int j=ballNum;j>=ghostInfo[i][0];j--)
        {
            for(int t=power;t>ghostInfo[i][1];t--)
            {
                dp[j][t]=max(dp[j][t], dp[j-ghostInfo[i][0]][t-ghostInfo[i][1]]+1);
            }
        }
    }
    int ans=0,res=power;
    for (int i=1;i<=power;++i)
        if (dp[ballNum][i]>ans){
            ans=dp[ballNum][i]; res=power-i+1;
        }
    printf("%d %d",ans,res);
    return 0;
}
