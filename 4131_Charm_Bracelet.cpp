#include <iostream>
#include <string.h>
using namespace std;
int main(int argc, const char * argv[]) {
    int n,m;
    scanf("%d%d",&n,&m);
    int* w=new int[n];
    int* d=new int[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",w+i,d+i);
    }
    int* mr=new int[m+1];
    memset(mr, 0, (m+1)*sizeof(int));
    
    for(int i=0;i<=m;i++)
    {
        if(i<w[0])mr[i]=0;
        else mr[i]=d[0];
    }
    
    for(int i=1;i<n;i++)
    {
        for(int j=m;j>=0;j--)
        {
            if((j-w[i])>=0)
            {
                if(mr[j]<(mr[j-w[i]]+d[i]))
                {
                    mr[j]=mr[j-w[i]]+d[i];
                }
            }
            else
                break;
        }
    }
    printf("%d\n",mr[m]);
    
    return 0;
}
