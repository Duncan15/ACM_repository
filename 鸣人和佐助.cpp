#include <iostream>
#include <queue>
using namespace std;
int m,n,t;
char graph[201][201];
bool visted[201][201][11];
struct Pos
{
    int r,c;
    int time;
    int leftCkl;
    Pos(int a=0,int b=0,int c=0,int d=0):r(a),c(b),time(c),leftCkl(d){}
    
};
Pos dir[]={
    Pos(-1,0),
    Pos(0,1),
    Pos(1,0),
    Pos(0,-1)
};
Pos minren,zuozu;
queue<Pos> q;
int main()
{
    scanf("%d%d%d",&m,&n,&t);
    for(int i=0;i<m;i++)
    {
        scanf("%s",graph[i]);
        for(int j=0;j<n;j++)
        {
            if(graph[i][j]=='@')
            {
                minren.r=i;
                minren.c=j;
                minren.leftCkl=t;
            }
            else if(graph[i][j]=='+')
            {
                zuozu.r=i;
                zuozu.c=j;
            }
        }
    }
    Pos s=minren;
    q.push(s);
    visted[s.r][s.c][s.leftCkl]=true;
    while(!q.empty())
    {
        s=q.front();
        if(s.r==zuozu.r&&s.c==zuozu.c)
        {
            printf("%d\n",s.time);
            return 0;
        }
        else
        {
            for(int i=0;i<4;i++)
            {
                int pr=s.r+dir[i].r,pc=s.c+dir[i].c,pCkl=s.leftCkl;
                if(pr<0||pr>=m||pc<0||pc>=n)continue;
                
                if(graph[pr][pc]=='#')
                {
                    if(s.leftCkl>0)
                    {
                        pCkl--;
                    }
                    else
                    {
                        continue;
                    }
                }
                if(visted[pr][pc][pCkl])continue;
                
                q.push(Pos(pr,pc,s.time+1,pCkl));
                visted[pr][pc][pCkl]=true;
                
            }
        }
        q.pop();
    }
    printf("%d\n",-1);
    return 0;
}
