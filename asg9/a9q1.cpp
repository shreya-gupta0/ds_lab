#include<stdio.h>
#define N 100

int g[N][N], vis[N], v;

void dfs(int u){
    vis[u]=1;
    for(int i=0;i<v;i++) if(g[u][i] && !vis[i]) dfs(i);
}

int main(){
    int e,u,x;
    scanf("%d%d",&v,&e);
    
    while(e--) {
        scanf("%d%d",&u,&x);
        g[u][x]=g[x][u]=1;
    }
    
    int cnt=0;
    for(int i=0;i<v;i++) if(!vis[i]) dfs(i), cnt++;
    printf("%d\n",cnt);
}
