#include <iostream>
using namespace std;
int table[51][51];
int n;
int fx(int num,int maxDiv)
{
    if(num==1||maxDiv==1)return 1;
    else if(num<maxDiv)return table[num][num];
    else if(num==maxDiv)return 1+table[num][maxDiv-1];
    else if(num>maxDiv)return table[num-maxDiv][maxDiv]+table[num][maxDiv-1];
    return -1;
}
int main(int argc, const char * argv[]) {
    while(cin>>n)
    {
         for(int num=1;num<=n;num++)
         {
             for(int maxDiv=1;maxDiv<=n;maxDiv++)
             {
                 table[num][maxDiv]=fx(num, maxDiv);
             }
         }
        printf("%d\n",table[n][n]);
    }
   
    return 0;
}
