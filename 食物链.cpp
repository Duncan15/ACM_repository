#include <iostream>

using namespace std;
int parent[50000];
int relation[50000];
int n,k,counter;
int get_par(int u)
{
    if(parent[u]!=u)
    {
        
        int fx=get_par(parent[u]);
        relation[u]=(relation[u]+relation[parent[u]])%3;
        parent[u]=fx;
    }
    return parent[u];
}

bool merges(int dd, int x, int y) {
    int rx = get_par(x);
    int ry = get_par(y);
    if (rx == ry) {
        if ((relation[y] - relation[x] + 3) % 3!=dd)
            return 1;
        else
            return 0;
    }
    parent[ry] = rx;
    relation[ry]= (relation[x] - relation[y] + dd + 3) % 3;
    return 0;
}
int main()
{
    
    scanf("%d%d",&n,&k);
    for(int i=0;i<n+1;i++)
    {
        parent[i]=i;
        relation[i]=0;
    }
    int rela,x,y;
    for(int i=0;i<k;i++)
    {
        scanf("%d%d%d",&rela,&x,&y);
        if(x>n||y>n)
        {
            counter++;
            continue;
        }
        else if(rela==2&&x==y)
        {
            counter++;
            continue;
        }
        
        else if(merges(rela-1,x,y))
        {
            counter++;
        }
        
    }
    printf("%d\n",counter);
    
    return 0;
}
