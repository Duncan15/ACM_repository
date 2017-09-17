#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
int N,M;
int minArea;//最优表面积
//int area;//正在搭建中的侧面积
int minV[30];//n层佛塔的最小体积
int minA[30];//n层佛塔的最小侧面积
int maxVNRH[30][200][200];
int MaxVforNRH(int m,int r,int h)
{
    int v=0;
    if(maxVNRH[m][r][h])return maxVNRH[m][r][h];
    for(int i=0;i<m;i++)
    {
        v+=(r-i)*(r-i)*(h-i);
    }
    maxVNRH[m][r][h]=v;
    return v;
}
int dfs(int n,int m,int area,int r,int h)
//用n层凑体积v,最底层半径不超过r,高度不超过h
//求出最小表面积放入minArea
{
    if(m==0)
    {
        if(n==0)
        {
            minArea=min(minArea, area);
        }
        return 0;
    }
    if(n<0)return 0;
    if(h<m||r<m)return 0;
    if(minV[m]>n||area+minA[m]>=minArea)return 0;
    if(MaxVforNRH(m, r, h)<n)return 1;
    for(int rr=r;rr>=m;rr--)
    {
        
        for(int hh=h;hh>=m;hh--)
        {
            if(m==M)
            {
                if(dfs(n-rr*rr*hh,m-1,area+rr*rr+2*rr*hh,rr-1,hh-1))
                {
                    break;
                }
            }
            else{
                if(dfs(n-rr*rr*hh,m-1,area+2*rr*hh,rr-1,hh-1))
                {
                    break;
                }
            }
        }
    }
    return 0;
}
int main()
{
    for(int i=1;i<=30;++i)
    {
        minV[i]=minV[i-1]+i*i*i;
        minA[i]=minA[i-1]+2*i*i;
    }
    while(cin>>N>>M)
    {   if(minV[M]>N)
        {
            printf("%d\n",0);
            continue;
        }
        int maxH=(N-minV[M-1])/(M*M);
        int maxR=sqrt(double(N-minV[M-1])/M);
        minArea=1<<30;
        dfs(N, M, 0,maxR, maxH);
        if(minArea==(1<<30))
            printf("%d\n",0);
        else
            printf("%d\n",minArea);
        
    }
    return 0;
}
