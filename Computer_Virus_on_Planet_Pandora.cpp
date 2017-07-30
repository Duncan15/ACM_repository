#include <iostream>
#include <string.h>
#include <deque>
#include <algorithm>
#define LETTERS 26
#define INITLETTER 'A'
using namespace std;
char mode[1010];
char String[5100010];
char stringtmp[5100010];
int results[260];
int ans[20];

int nodeCount;

struct trienode
{
    trienode* child[LETTERS];
    trienode* pre;
    bool badnode;
    bool visited;
    int mode_num;
    
    trienode()
    {
        memset(child, 0, sizeof(child));
        pre=NULL;
        badnode=false;
        mode_num=0;
        visited=false;
    }
};

trienode tree[260000];

void build(trienode* root,char* s,int mode_num)
{
    
    for(int i=0;s[i];i++)
    {
        if(root->child[s[i]-INITLETTER]==NULL)
        {
            root->child[s[i]-INITLETTER]=tree+nodeCount;
            nodeCount++;
        }
        root=root->child[s[i]-INITLETTER];
    }
    root->badnode=true;
    root->mode_num=mode_num;
    
}

void build_dfa()
{
    for(int i=0;i<LETTERS;i++)
    {
        tree[0].child[i]=tree+1;
    }
    tree[0].pre=NULL;
    tree[1].pre=tree;
    
    deque<trienode*> q;
    q.push_back(tree+1);
    while(!q.empty())
    {
        trienode* root=q.front();
        q.pop_front();
        for(int i=0;i<LETTERS;i++)
        {
            trienode* p=root->child[i];
            if(p)
            {
                trienode* pre=root->pre;
                while(pre)
                {
                    if(pre->child[i])
                    {
                        p->pre=pre->child[i];
                        if(p->pre->badnode)
                        {
                            p->badnode=true;
                        }
                        break;
                    }
                    else
                    {
                        pre=pre->pre;
                    }
                }
                q.push_back(p);
            }
        }
    }
}

void search_Dfa(char* s)
{
    trienode* p=tree+1;
    for(int i=0;s[i];i++)
    {
        while(true)
        {
            if(p->child[s[i]-INITLETTER])
            {
                p=p->child[s[i]-INITLETTER];
                if(p->badnode&&!p->visited)
                {
                    
                    trienode* tmp=p;
                    while(tmp!=tree+1)
                    {
                        tmp->visited=true;
                        if(tmp->mode_num!=0)
                        {
                            results[tmp->mode_num]=1;
                        }
                        tmp=tmp->pre;
                    }
                    
                }
                break;
            }
            else
            {
                p=p->pre;
            }
        }
    }
}

int main()
{
    
    int T=0,n=0;
    scanf("%d",&T);
    
    for(int i=0;i<T;i++)
    {
        nodeCount=2;
        memset(String, 0, sizeof(String));
        memset(results, 0, sizeof(results));
        memset(tree, 0, sizeof(tree));
        scanf("%d",&n);
        
        
        for(int j=0;j<n;j++)
        {
            scanf("%s",mode);
            build(tree+1, mode,j+1);
        }
        build_dfa();
        
        scanf("%s",stringtmp);
        
        int Len=(int)strlen(stringtmp),tmp=0,num=0,k=0;
        bool flag=false;
        for(int j=0;j<Len;j++)
        {
            if(stringtmp[j]=='[')
            {
                flag=true;
                continue;
            }
            else if(stringtmp[j]==']')
            {
                flag=false;
                
                char compressed_char=stringtmp[j-1];
                memset(String+tmp, compressed_char, num*sizeof(char));
                tmp+=num;
                
                num=0;
                continue;
            }
            if(flag)
            {
                if('0'<=stringtmp[j]&&stringtmp[j]<='9')
                {
                    num=10*num+(stringtmp[j]-'0');
                }
                continue;
            }
            String[tmp++]=stringtmp[j];
        }
        
        
        search_Dfa(String);
        reverse(String, String+tmp);
        search_Dfa(String);
        for(int j=0;j<n+1;j++)
        {
            k+=results[j];
        }
        ans[i]=k;
    }
    
    for(int i=0;i<T;i++)
    {
        printf("%d\n",ans[i]);
        
    }
    
    
    return 0;
}
