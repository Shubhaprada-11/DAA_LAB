#include <stdio.h>
#include <stdlib.h>
#define MAX 50;

int n,count=0;
int f=0;
int r=0;
int G[50][50];
int V[50];
int queue[50];

void bfs(int source){
      //count++;
      V[source]=1;
      queue[r++]=source;
      while(f!=r){
            source=queue[f];
            for (int i=1;i<=n;i++){
                  if(G[source][i]==1 && V[i]==0){
                        printf("%d ",i);
                        //count++;
                        V[i]=1;
                        queue[r++]=i;
                  }
            }     
      f++; 
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
                  bfs(i);
                  comp++;
            }
      }
      if(comp==1) printf("\nconnected\n");
      else printf("\nnot connected\n");
}