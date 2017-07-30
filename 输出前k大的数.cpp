#include <iostream>
#include <algorithm>
using namespace std;
int compare(const void *a, const void *b)
{
    int *pa = (int*)a;
    int *pb = (int*)b;
    return (*pa )- (*pb);  //从小到大排序
}
void swap(int &a,int &b)
{
    int tmp=b;
    b=a;
    a=tmp;
}
int arrangeRight(int a[],int s,int e,int f)
{
    
    int k=a[s];
    int i=s,j=e;
    while(i!=j)
    {
        while(j>i&&k<a[j])
        {
            j--;
        }
        swap(a[i], a[j]);
        while (i<j&&k>a[i]) {
            i++;
        }
        swap(a[i],a[j]);
    }
    
    int result=e-i+1;
    if(f==result)
    {
        return i;
    }
    else if (f>result)
    {
        return arrangeRight(a, s, i-1, f-result);
    }
    else
    {
        return arrangeRight(a, i+1, e, f);
    }
}
int main(int argc, const char * argv[]) {
    int n;
    scanf("%d",&n);
    int* a=new int[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",a+i);
    }
    int k;
    scanf("%d",&k);
    
    int start=arrangeRight(a, 0, n-1, k);
    qsort(a+start, k, sizeof(int),compare);
    for(int i=n-1,j=0;j<k;j++,i--)
    {
        printf("%d\n",a[i]);
    }
    
    
    return 0;
}
