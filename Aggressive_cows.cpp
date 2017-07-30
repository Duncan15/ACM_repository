#include <iostream>
#include <algorithm>
using namespace std;

bool test(int d,int c,int n_loc[],int n)
{
    int init=n_loc[0],step=0;
    for(int i=1;i<c;i++)
    {
        init=init+d;
        while(n_loc[step]<init)
        {
            step++;
            if(step==n)
            {
                return false;
            }
        }
        init=n_loc[step];
    }
    return true;
}
int main(int argc, const char * argv[]) {
    int n,c;
    scanf("%d%d",&n,&c);
    int* n_loc=new int[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",n_loc+i);
    }
    sort(n_loc,n_loc+n);
    
    int l=1,r=1000000000/c,mid=0,pre=0;
    bool flag=false;
    while(l<=r)
    {
        mid=l+(r-l)/2;
        flag=test(mid, c, n_loc, n);
        if(flag)
        {
            pre=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    if(!flag)mid=pre;
    printf("%d",mid);
    
    
    return 0;
}
