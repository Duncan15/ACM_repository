#include<iostream>
using namespace std;
int n,k;
int divide[100][100];
int tmp[100][100];
void init(int a)
{
    for(int i=0;i<=a;i++)
    {
        for(int j=0;j<=a;j++)
        {
            divide[i][j]=0;
        }
    }
}
int divideByNum(int n,int k)
{
    init(n);
    for(int i=1;i<=n;i++)
    {
        divide[i][1]=1;
    }
    
    divide[1][1]=1;
    
    for(int i=2;i<=n;i++)
    {
        for(int j=2;j<=i;j++)
        {
            divide[i][j]=divide[i-1][j-1]+divide[i-j][j];
        }
    }
    return divide[n][k];
}
int divideNotSame(int n)
{
    init(n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i>j)
            {
                divide[i][j]=divide[i-j][j-1]+divide[i][j-1];
            }
            else if(i==j)
            {
                divide[i][j]=1+divide[i][i-1];
            }
            else if(i<j)
            {
                divide[i][j]=divide[i][i];
            }
        }
    }
    
    return divide[n][n];
}
int divideToOdd(int n)
{
    init(n);
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            tmp[i][j]=0;
        }
    }
    divide[0][0]=1,tmp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            tmp[i][j]=divide[i-j][j];
            divide[i][j]=divide[i-1][j-1]+tmp[i-j][j];
        }
    }
    int total=0;
    for(int i=1;i<=n;i++)
    {
        total+=divide[n][i];
    }
    return total;
}
int main()
{
    while(cin>>n>>k)
    {
        cout<<divideByNum(n, k)<<endl;
        cout<<divideNotSame(n)<<endl;
        cout<<divideToOdd(n)<<endl;
    }
    return 0;
}
