#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;
struct Pos
{
    int r,c;
    int keyNum;
    int time;
    short layout;//守卫的情况
    Pos(int a=0,int b=0,int c=0,int d=0,int e=0):r(a),c(b),keyNum(c),time(d),layout(e){}
};
Pos dir[]={
    Pos(-1,0),
    Pos(0,1),
    Pos(1,0),
    Pos(0,-1)
};
char graph[110][110];
int layoutGraph[110][110];
bool visited[110][110][10][33];
int res[1000];
Pos K,T;
int m,n;
queue<Pos> q;
int main ()
{
    int a=0;
    while(1)
    {
        
        scanf("%d%d",&m,&n);
        if(m==0&&n==0)break;
        memset(visited, 0, sizeof(visited));
        memset(layoutGraph, 0, sizeof(layoutGraph));
        int layoutNum=0;
        for(int i=0;i<m;i++)
        {
            scanf("%s",graph[i]);
            for(int j=0;j<m;j++)
            {
                if(graph[i][j]=='K')
                {
                    K.r=i;
                    K.c=j;
                    K.keyNum=0;
                    K.time=0;
                    K.layout=0;
                }
                else if(graph[i][j]=='T')
                {
                    T.r=i;
                    T.c=j;
                }
                else if(graph[i][j]=='S')
                {
                    layoutGraph[i][j]=layoutNum++;
                }
            }
        }
        Pos p=K;
        q.push(p);
        while(!q.empty())
        {
            p=q.front();
            if(p.r==T.r&&p.c==T.c&&p.keyNum==n)break;
            q.pop();
            if(graph[p.r][p.c]=='S')
            {
                short pLayout=p.layout|(1<<layoutGraph[p.r][p.c]);
                if(pLayout!=p.layout)
                {
                    q.push(Pos(p.r,p.c,p.keyNum,p.time+1,pLayout));
                    visited[p.r][p.c][p.keyNum][pLayout]=true;
                    continue;
                }
            }
            for(int i=0;i<4;i++)
            {
                int pr=p.r+dir[i].r,pc=p.c+dir[i].c,pkeyNum=p.keyNum,ptime=p.time,pLayout=p.layout;
                if(pr<0||pr>=m||pc<0||pc>=m)continue;
                if(visited[pr][pc][pkeyNum][pLayout])continue;
                if(graph[pr][pc]=='#')continue;
                if((graph[pr][pc]-'0')==(pkeyNum+1))pkeyNum++;
                q.push(Pos(pr,pc,pkeyNum,ptime+1,pLayout));
                visited[pr][pc][pkeyNum][pLayout]=true;
            }
        }
        if(q.empty())
        {
            res[a++]=0;
        }
        else
        {
            res[a++]=p.time;
            while(!q.empty())q.pop();
        }
    }
    for(int i=0;i<a;i++)
    {
        if(res[i]==0)printf("impossible\n");
        else
        {
            printf("%d\n",res[i]);
        }
    }
    return 0;
}
