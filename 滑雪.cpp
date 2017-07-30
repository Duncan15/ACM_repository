#include <iostream>
#include <algorithm>
using namespace std;
int r,c;
int Max;
struct point
{
    int high;
    int r,c;
    point()
    {
        this->high=0;
        this->r=0;
        this->c=0;
    }
    point(int a,int b,int c=0):high(c),r(a),c(b){}
};
struct Pos
{
    int high;
    int lengths;
};
point dir[4]={point(-1,0),point(0,1),point(1,0),point(0,-1)};
point mountain[100*100];

Pos Len[100][100];


bool compare(point a,point b)
{
    return a.high<b.high;
}

bool check(int x,int y)
{
    if(0<=x&&x<r)
    {
        if(0<=y&&y<c)
        {
            return true;
        }
    }
    return  false;
}
int main()
{
    scanf("%d%d",&r,&c);
    int tmp=0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            mountain[tmp].r=i;
            mountain[tmp].c=j;
            scanf("%d",&mountain[tmp].high);
            Len[i][j].high=mountain[tmp].high;
            Len[i][j].lengths=1;
            tmp++;
        }
    }
    sort(mountain, mountain+(r*c),compare);
    
    for(int i=1;i<r*c;i++)
    {
        for(int j=0;j<4;j++)
        {
            int tmpr=mountain[i].r+dir[j].r;
            int tmpc=mountain[i].c+dir[j].c;
            if(check(tmpr,tmpc))
            {
                if(Len[tmpr][tmpc].high<mountain[i].high&&Len[mountain[i].r][mountain[i].c].lengths<Len[tmpr][tmpc].lengths+1)
                {
                    Len[mountain[i].r][mountain[i].c].lengths=Len[tmpr][tmpc].lengths+1;
                }
            }
        }
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(Len[i][j].lengths>Max)
            {
                Max=Len[i][j].lengths;
            }
        }
    }
    printf("%d\n",Max);
    return 0;
}
