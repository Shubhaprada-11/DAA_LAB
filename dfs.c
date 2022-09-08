#include <stdio.h>
#include <stdlib.h>
#define MAX 50;

int n;
int G[50][50];
int V[50];

void dfs(int source){
      V[source]=1;
      for (int i=1;i<=n;i++){
            if(G[source][i]==1 && V[i]==0){
                  printf("%d ",i);
                  dfs(i);
            }
      }
}

int main(){
      int i,j,comp=0;
      printf("enter n: ");
      scanf("%d",&n);
      printf("enter adj matrix\n");
      for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                  scanf("%d",&G[i][j]);
      for(i=1;i<=n;i++)
            V[i]=0;
      for(i=1;i<=n;i++){
            if(V[i]==0){
                  printf("%d ",i);
                  dfs(i);
                  comp++;
            }
      }
      if(comp==1) printf("\nconnected\n");
      else printf("\nnot connected\n");
}