#include<iostream>
#include<string.h>
#define MAX 50
using namespace std;
int n,Len;
char num[MAX];
char min_Sum[MAX][MAX][MAX];
char Num[MAX][MAX][MAX];

char res[15][50];
void add_and_cmp(char* a,char* b,char* c)
{
    int flag = 0;
    char res[MAX];
    for (int i = MAX - 1; i >= 0; i--)
    {
        int tmp = (a[i] - '0') + (b[i] - '0')+flag;
        if (tmp > 9)
        {
            tmp = tmp % 10;
            flag = 1;
        }
        else
            flag = 0;
        res[i] = tmp + '0';
    }
    
    if (strcmp(res, c) < 0)
    {
        memcpy(c, res, MAX);
    }
    
}
int main()
{
    int c=0;
    while(cin>>n>>num)
    {
        Len =(int) strlen(num);
        
        //预处理
        for (int i = 0; i < Len; i++)
        {
            for (int j = i; j < Len; j++)
            {
                int tmp = MAX - (j - i + 1);
                memset(Num[i][j], '0', tmp );
                memcpy(Num[i][j]+tmp, &num[i], j - i + 1);
            }
        }
        
        for (int i = 0; i < Len; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (j == 0)
                {
                    int seg = MAX - i - 1;
                    memset(min_Sum[0][i], '0', seg);
                    memcpy(min_Sum[0][i] + seg, num, i + 1);
                }
                else if (i < j)
                {
                    memset(min_Sum[j][i], '9', MAX);
                }
                else
                {
                    memset(min_Sum[j][i], '9', MAX);
                    for (int k = j ; k < i+1; k++)
                    {
                        add_and_cmp(min_Sum[j - 1][k-1], Num[k][i], min_Sum[j][i]);
                    }
                }
            }
        }
        
        int step = 0;
        while (min_Sum[n][Len - 1][step] == '0')
        {
            step++;
        }
        memcpy(res+c,min_Sum[n][Len - 1] + step,MAX-step);
        
        c++;
    }
//    scanf("%d", &n);
//    scanf("%s", num);
    for(int i=0;i<c;i++)
    {
        printf("%s\n",res[i]);
    }
   
    return 0;
}
