#include<iostream>
using namespace std;
int n,k,ans;
char map[9][9];
bool visit[9];
void dfs(int row, int leftNum)
{
    if(leftNum==0||row==n+1)
    {
        if(leftNum==0)
        {
            ans++;
        }
        return;
    }
    
    for(int i=row; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(map[i][j]=='.' || visit[j]==1) continue;
            visit[j] = 1;
            dfs(i+1, leftNum-1);
            visit[j] = 0;
        }
    }
}
int main()
{
    while(1)
    {
        ans=0;
        
        scanf("%d%d",&n,&k);
        if(k==-1&&n==-1) break;
        
        for(int i=1;i<=n;i++)
        {
            scanf("%s",map[i]+1);
        }
        dfs(1,k);
        printf("%d\n",ans);
    }
    return 0;
}
