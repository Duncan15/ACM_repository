#include <iostream>
void Merge_and_Count(int a[],int s,int m,int e,int tmp[],long long & counter)
{
    
    int pb=0;
    int p1=s,p2=m+1;
    while(p1<=m&&p2<=e)
    {
        if(a[p1]<=a[p2])
        {
            tmp[pb++]=a[p2++];
        }
        else
        {
            tmp[pb++]=a[p1++];
            counter+=(e-p2+1);//计算s1 s2中能组成逆序数的对
        }
    }
    while(p1<=m)
    {
        tmp[pb++]=a[p1++];
    }
    while(p2<=e)
    {
        tmp[pb++]=a[p2++];
    }
    for(int i=0;i<e-s+1;i++)
    {
        a[s+i]=tmp[i];
    }
}
void MergeSort_and_Count(int a[],int s,int e,int tmp[],long long & counter)
{
    if(s<e)
    {
        int m=s+(e-s)/2;
        MergeSort_and_Count(a, s, m, tmp,counter);
        MergeSort_and_Count(a, m+1, e, tmp,counter);
        Merge_and_Count(a, s, m, e, tmp, counter);
        
    }
}


using namespace std;
int main(int argc, const char * argv[]) {
    int n;
    scanf("%d",&n);
    int* a=new int[n];
    int* tmp=new int[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",a+i);
    }
    
    long long counter=0;
    MergeSort_and_Count(a, 0, n-1, tmp, counter);
    printf("%lld\n",counter);
    return 0;
}

