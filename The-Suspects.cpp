#include <iostream>
#define MAX 30010
using namespace std;
int snum,gnum;//学生总数，团队总数
int snpg,fs;//每个团队学生数，每个团队第一个学生编号
int ls;//后输入的学生编号
int par[MAX],total[MAX];
int get_parent(int a){
    if(par[a]==a)return a;
    par[a]=get_parent(par[a]);
    return par[a];
}
void Merge(int a,int b)
{
    int pa=get_parent(a);
    int pb=get_parent(b);
    if(pa==pb)return;
    total[pa]+=total[pb];
    par[pb]=pa;
}
int main()
{
    while(1){
        scanf("%d%d",&snum,&gnum);
        if(snum==0&&gnum==0)break;
        for(int i=0;i<snum;i++){
            par[i]=i;
            total[i]=1;
        }
        for(int i=0;i<gnum;i++){
            scanf("%d%d",&snpg,&fs);
            for(int j=0;j<snpg-1;j++){
                scanf("%d",&ls);
                Merge(fs, ls);
            }
        }
        printf("%d\n",total[get_parent(0)]);
    }
    return 0;
}
