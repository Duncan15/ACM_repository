#include <iostream>
using namespace std;

bool check(int consume[],int n,int mid,int m)
{
    int stage=0,step=1;
    for(int i=0;i<n;i++)
    {
        stage+=consume[i];
        if(stage>mid)
        {
            step++;
            stage=consume[i];
            if(stage>mid)return false;
        }
    }
    return step<=m;
}
int main(int argc, const char * argv[])
{
    int n,m;
    scanf("%d%d",&n,&m);
    int* consume=new int[n];
    int l=0,r,mid=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",consume+i);
        r+=consume[i];
    }
    
    bool flag=false;
    int pre=0;
    while(l<=r)
    {
        mid=l+(r-l)/2;
        flag=check(consume, n, mid, m);
        if(flag)
        {
            pre=mid;
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
        
        
    }
    if(!flag)mid=pre;
    printf("%d",mid);
    return 0;
}
