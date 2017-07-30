#include<iostream>
#include<string.h>
#include<queue>
using namespace std;

int n,m;
char graph[210][210];
int flag[210][210][2];
int output[1000];
struct Point
{
    int r,c;
    int killed;
    int steps;
    Point(int a,int b,int c=0,int d=0):r(a),c(b),killed(c),steps(d){}
};
Point dir[]={Point(-1,0),Point(0,1),Point(1,0),Point(0,-1)};
Point princess=Point(0,0),knight=Point(0,0);
queue<Point> open;
int main()
{
    int a;
    scanf("%d",&a);
    for(int i=0;i<a;i++)
    {
        scanf("%d%d",&n,&m);
        
        memset(graph, '#', sizeof(graph));
        memset(flag, 0, sizeof(flag));
        for(int j=0;j<n;j++)
        {
            
            scanf("%s",graph[j]);
            for(int t=0;t<m;t++)
            {
                if(graph[j][t]=='a')
                {
                    princess.r=j;
                    princess.c=t;
                }
                else if(graph[j][t]=='r')
                {
                    knight.r=j;
                    knight.c=t;
                }
                else if(graph[j][t]=='#')
                {
                    flag[j][t][0]=1;
                }
            }
        }
        
        open.push(knight);
        flag[knight.r][knight.c][0]=1;
        
        
        while(!open.empty())
        {
            Point s=open.front();
            if(s.r==princess.r&&s.c==princess.c)
            {
                output[i]=s.steps;
                break;
            }
            else
            {
                if(graph[s.r][s.c]=='x'&&flag[s.r][s.c][0]==1&&flag[s.r][s.c][1]==0)
                {
                    open.push(Point(s.r,s.c,1,s.steps+1));
                    flag[s.r][s.c][1]=1;
                }
                else
                {
                    for(int t=0;t<4;t++)
                    {
                        if(0<=(s.r+dir[t].r)&&(s.r+dir[t].r)<n&&0<=(s.c+dir[t].c)&&(s.c+dir[t].c)<m)
                        {
                            if(flag[s.r+dir[t].r][s.c+dir[t].c][0]==0)
                            {
                                open.push(Point(s.r+dir[t].r,s.c+dir[t].c,0,s.steps+1));
                                flag[s.r+dir[t].r][s.c+dir[t].c][0]=1;
                            }
                        }
                       
                    }
                }
                    
            }
            open.pop();
            
        }
        if(open.empty()) output[i]=-1;
        else
        {
            while (!open.empty())
            {
                open.pop();
            }
        }
        
    }
    for(int i=0;i<a;i++)
    {
        if(output[i]==-1)
            printf("Impossible\n");
        else
            printf("%d\n",output[i]);
    }
    return 0;
}
