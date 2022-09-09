#include <stdio.h>
#include <stdlib.h>

int x[20];
int place(int k, int i){
      int j;
      for(j=1;j<=k-1;j++)
      if(x[j]==i ||(abs(x[j]-i)==abs(j-k))) return 0;
      return 1;
}

void printqueen(int n){
      int i,j,k;
      static int count=1;
      printf("solution %d:\n",count++);
      for(i=1;i<=n;i++){
            for(j=1;j<=n;j++)
                  if(x[i]==j) printf("Q ");
                  else printf("- ");
            printf("\n");
      }
}

void NQueens(int k, int n){
      int i,j;
      for(i=1;i<=n;i++){
            if(place(k,i)){
                  x[k]=i;
                  if(k==n) printqueen(n);
                  else NQueens(k+1,n);
            }
      }
}

int main(){
      int n;
      scanf("%d",&n);
      if(n==0||n==2||n==3) printf("no soln\n");
      else NQueens(1,n);
}