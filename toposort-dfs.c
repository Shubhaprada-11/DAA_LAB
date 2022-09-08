#include <stdio.h>
#include <stdlib.h>
#define MAX 50;
      
int n;
int G[50][50];
int V[50];
int output[50];
int k=0;
int stack[50];
int top=-1;

void dfs(int source){
      V[source]=1;
      stack[++top]=source;
      for (int i=1;i<=n;i++){
            if(G[source][i]==1 && V[i]==0){
                  dfs(i);
            }
      }
      printf("%d ",stack[top--]);
      output[k++]=source;
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
                  output[k++]=i;
                  dfs(i);
            }
      }
}