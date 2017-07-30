#include<iostream>
#include<string.h>
#include<iostream>
#include<string.h>
using namespace std;
char dir[32][5];
bool flag[32];

int midL[32];

int n,steps;
int minstep=1000000;
bool check_like(char* a,char* b)
{
    int len=(int)strlen(a);
    int p=0,count=0;
    while(p<len)
    {
        if(a[p]==b[p])
        {
            count++;
        }
        p++;
    }
    if(count==len-1)return true;
    return false;
};
void dfs(int v)
{
    if(v==1)
    {
        steps++;
        if(steps<minstep)
            minstep=steps;
        steps--;
        return;
    }
    if(flag[v]) return;
    
    if(steps>=minstep-2)return ;
    
    flag[v]=true;
    steps++;
    if(midL[v]<=steps)
    {
        steps--;
        flag[v]=false;
        return;
    }
    else midL[v]=steps;
    
    for(int i=0;i<n;i++)
    {
        if(check_like(dir[v], dir[i]))
            dfs(i);
    }
    steps--;
    flag[v]=false;
}
int main()
{
    scanf("%s%s",dir[0],dir[1]);
    getchar();
    
    midL[0]=1000000;
    
    n+=2;
    char tmp;
    int i=0;
    while((tmp=getchar())!='\n')
    {
        if(tmp!=' ')
        {
            dir[n][i++]=tmp;
            midL[n]=1000000;
        }
        else
        {
            n++;
            i=0;
        }
    };
    dfs(0);
    if(minstep!=1000000)
        printf("%d\n",minstep);
    else
        printf("%d\n",0);
    
    return 0;
}
