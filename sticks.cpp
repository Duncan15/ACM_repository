#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
bool used[70];
int stickLen[70];
int num,preNum;
int len;
bool cmp(int a,int b){
    return a>b;
}
int dfs(int res,int finish,int index)//剪枝3：添加index
{
    if (res==0)
    {
        res=len;
        finish++;
        index=0;
    }
    if(finish==preNum) return 1;
    for(int i=index;i<num;i++){
        if(i>0&&!used[i-1]&&stickLen[i]==stickLen[i-1])continue;//剪枝2：相同长度不搜索
        if(!used[i]&&res>=stickLen[i]){
            used[i]=true;
            if(dfs(res-stickLen[i],finish,i+1))return 1;
            else{
                used[i]=false;
                if(res==len||stickLen[i]==res)return 0;//剪枝4
            }
        }
    }
    return 0;
}
int main()
{
    while(1)
    {
        scanf("%d",&num);
        if(num==0)return 0;
        int totalLen=0,minLen=0;
        for(int i=0;i<num;i++)
        {
            scanf("%d",stickLen+i);
            totalLen+=stickLen[i];
            if(minLen<stickLen[i])minLen=stickLen[i];
        }
        //减枝1：排序
        sort(stickLen,stickLen+num,cmp);
        for(len=minLen;len<=totalLen/2;len++)
        {
            if((totalLen%len)==0)
            {
                memset(used, 0, sizeof(used));
                preNum=totalLen/len;
                int tmp=len;
                if(dfs(tmp,0,0)==1)
                //if(dfs(num,tmp))
                {
                    printf("%d\n",len);
                    break;
                }
            }
        }
        if(len>totalLen/2)printf("%d\n",totalLen);
    }
    return 0;
}
