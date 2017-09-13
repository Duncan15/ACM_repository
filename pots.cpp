#include <iostream>
#include <vector>
using namespace std;

struct Status
{
    int lef1,lef2;
    int opNum;
    int father;
    Status(int a=0,int b=0,int c=0,int d=0):lef1(a),lef2(b),opNum(c),father(d){}
};
Status que[2000000];
bool visited[101][101];
int head,tail;
char op[6][10]=
{
    "FILL(1)",
    "FILL(2)",
    "DROP(1)",
    "DROP(2)",
    "POUR(1,2)",
    "POUR(2,1)"
};
int a,b,c;
void operation(int &l1,int &l2,int opCode)
{
    switch (opCode)
    {
        case 0:
            l1=a;
            break;
        case 1:
            l2=b;
            break;
        case 2:
            l1=0;
            break;
        case 3:
            l2=0;
            break;
        case 4:
            if(b>=(l1+l2))
            {
                l2=l2+l1;
                l1=0;
            }
            else
            {
                l1=l1+l2-b;
                l2=b;
            }
            break;
        case 5:
            if(a>=(l1+l2))
            {
                l1=l1+l2;
                l2=0;
            }
            else
            {
                l2=l1+l2-a;
                l1=a;
            }
            break;
        default:
            break;
    }
    
}

int main()
{
    scanf("%d%d%d",&a,&b,&c);
    head=0;
    tail=1;
    que[head]=Status(0,0,-1,-1);
    while(head!=tail)
    {
        Status sta=que[head];
        if(sta.lef1==c||sta.lef2==c)
        {
            vector<int> res;
            while(true)
            {
                if(sta.father==-1)
                {
                    break;
                }
                res.push_back(sta.opNum);
                sta=que[sta.father];
            }
            printf("%d\n",(int)res.size());
            for(int i=(int)res.size()-1;i>=0;i--)
            {
                printf("%s\n",op[res[i]]);
            }
            return 0;
        }
        else
        {
            for(int i=0;i<6;i++)
            {
                int l1=sta.lef1,l2=sta.lef2;
                operation(l1, l2, i);
                if(!visited[l1][l2])
                {
                    que[tail++]=Status(l1,l2,i,head);
                    visited[l1][l2]=true;
                }
            }
            head++;
        }
    }
    if(head==tail)
    {
        printf("impossible\n");
    }
    return 0;
    
}
