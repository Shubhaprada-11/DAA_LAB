#include <stdio.h>

int max(int a, int b){
      return (a>b)?a:b;
}

int knapsack(int n, int W, int w[], int val[]){
      int i,j;
      int k[100][100];
      for(i=0;i<=n;i++){
            for(j=0;j<=W;j++){
                  if(i==0 || j==0) k[i][j]=0;
                  if(j>=w[i]){
                        k[i][j]=max(k[i-1][j],k[i-1][j-w[i]]+val[i]);
                  }
                  else k[i][j]=k[i-1][j];
            }
      }
      for(i=0;i<n;i++){
            for(j=0;j<W;j++){
                  printf("%d ",k[i][j]);
            }
            printf("\n");
      }
      printf("items: ");
      i=n;
      j=W;
      while(i!=0 && j!=0){
            if(k[i][j]!=k[i-1][j]){
                  printf("%d ",i);
                  j--;
            }
            i--;
      }
      printf("\n");
      return k[n][W];
}

int main(){
      printf("enter n: ");
      int n,W,i;
      scanf("%d",&n);
      printf("enter W: ");
      scanf("%d",&W);
      int w[100],val[100];
      printf("enter weights\n");
      for(i=0;i<n;i++) scanf("%d",&w[i]);
      printf("enter values\n");
      for(i=0;i<n;i++) scanf("%d",&val[i]);
      int res;
      res=knapsack(n,W,w,val);
      printf("max value: %d",res);
}