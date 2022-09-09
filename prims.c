#include <stdio.h>
#include<stdlib.h>
#define INF 99999

int main(){
      int n, G[100][100],V[100];
      int i,j,x,y;
      int edges,min,cost=0;
      printf("enter n: ");
      scanf("%d",&n);
      for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                  scanf("%d",&G[i][j]);
      edges=0;
      for(j=0;j<n;j++)
            V[j]=0;
      printf("mst\n");
      printf("V - V :edge \n");
      i=j=0;
      V[0]=1;
      while(edges<n-1){
            min=INF;
            x=0;
            y=0;
            for(i=0;i<n;i++){
                  if(V[i]==1){
                        for(j=0;j<n;j++){
                              if(!V[j] && G[i][j]){
                                    if(min>G[i][j]){
                                          min=G[i][j];
                                          x=i;
                                          y=j;
                                    }
                              }
                        }
                  }
            }
            printf("%d - %d: %d\n",x,y,G[x][y]);
            edges++;
            V[y]=1;
            cost+=G[x][y];
      }
      printf("min cost: %d\n",cost);
      return 0;
}