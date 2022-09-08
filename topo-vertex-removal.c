#include <stdio.h>
#include <stdlib.h>

int n,count=0;
int G[50][50];
int V[50];

void sort(int source){
      V[source]=1;
      count++;
      printf("%d\n",source);
      for(int j=1;j<=n;j++){
            G[source][j]=0;
      }
}

int main(){
      int i,j,comp=0,flag=0;
      printf("enter n: ");
      scanf("%d",&n);
      printf("enter adj matrix\n");
      for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                  scanf("%d",&G[i][j]);
      for(i=1;i<=n;i++)
            V[i]=0;
      for(i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                  if(G[j][i]!=0) 
                        flag=1;
            }
            if(flag==0)
                  sort(i);
      }
}