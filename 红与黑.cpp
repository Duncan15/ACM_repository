#include <iostream>
#include <string.h>
using namespace std;
int w,h;
char floor[25][25];
int flag[25][25];
int newr,newc;
int steps;
int results[1000];
struct point
{
    int r,c;
    point(int a,int b):r(a),c(b){}
};
point dir[]={point(-1,0),point(0,1),point(1,0),point(0,-1)};



void dfs(int r,int c)
{
    if(flag[r][c]==1)
        return;
    flag[r][c]=1;
    steps++;
    for(int i=0;i<4;i++)
    {
        if(0<=(r+dir[i].r)&&(r+dir[i].r)<h&&0<=(c+dir[i].c)&&(c+dir[i].c)<w)
        {
            if(flag[r+dir[i].r][c+dir[i].c]!=2)
            {
                dfs(r+dir[i].r,c+dir[i].c);
            }
            
            
        }
    }
}
int main()
{
    point init(0,0);
    int s=0;
    while(1)
    {
        memset(floor, 0, sizeof(floor));
        memset(flag, 0, sizeof(flag));
        steps=0;
        scanf("%d%d",&w,&h);
        if(w==0&&h==0)
        {
            break;
        }
        
        for(int i=0;i<h;i++)
        {
            scanf("%s",floor[i]);
            for(int j=0;j<w;j++)
            {
                if(floor[i][j]=='#')
                    flag[i][j]=2;
                if(floor[i][j]=='@')
                {
                    init.r=i;
                    init.c=j;
                }
            }
        }
        dfs(init.r,init.c);
        results[s++]=steps;
    }
    for(int i=0;i<s;i++)
    {
        printf("%d\n",results[i]);
    }
    return 0;
}
