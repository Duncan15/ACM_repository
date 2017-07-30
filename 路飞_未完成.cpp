//
//  main.cpp
//  acm-text
//
//  Created by cwc on 2017/7/17.
//  Copyright © 2017年 cwc. All rights reserved.
#include <iostream>
#include<string.h>
int tb[17][17];
int flag[17];
int status[17];
int min_length=200000,depth,step;

int n;
void dfs(int pre,int now)
{
    if(flag[now])return;
    depth+=tb[pre][now];
    if(now==n)
    {
        for(int i=2;i<n;i++)
        {
            if(!flag[i])
            {
                depth-=tb[pre][now];
                return;
            }
        }
        if(depth<min_length)
        {
            min_length=depth;
        }
        depth-=tb[pre][now];
        return;
    }
    if(depth>=min_length)
    {
        depth-=tb[pre][now];
        return;
    }
    
    
    flag[now]=true;
    for(int i=1;i<=n;i++)
    {
        if(!flag[i])
        {
            dfs(now,i);
        }
    }
    depth-=tb[pre][now];
    flag[now]=false;
    
};
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&tb[i][j]);
        }
        status[i]=1;
    }
    flag[1]=1;
    for(int i=2;i<n;i++)
    {
        step=0;
        depth=0;
        dfs(1, i);
    }
    printf("%d\n",min_length);
    return 0;
}
