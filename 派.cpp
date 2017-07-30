#include <iostream>
#include <math.h>
using namespace std;
float v[10010];
bool judge(int n,float pv,int f)
{
    int step=0;
    for(int i=0;i<n;i++)
    {
    		step+=floor(v[i]/pv);
    }
    
    return step>=f;
}
int main(int argc, const char * argv[]) {
    int n,f,tmp;
    scanf("%d%d",&n,&f);
    f+=1;
    
    
    float max=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&tmp);
        v[i]=M_PI*tmp*tmp;
        if(v[i]>max)max=v[i];
        
    }
    float l=max/f,r=max,mid=0;
    bool flag=false;
    while((r-l)>=0.0005)
    {
        mid=l+(r-l)/2;
        flag=judge( n, mid, f);
        if(flag)
        {
            
            l=mid;
        }
        else
        {
            r=mid;
        }
        
    }
    
    printf("%.3f",mid);
    
    return 0;
}
