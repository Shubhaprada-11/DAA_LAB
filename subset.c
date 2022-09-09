#include <stdio.h>
#include <stdlib.h>

int d;
int s[10];
int x[10];

void subset(int sum, int k, int r){
      //printf("entered %d %d\n",k,r);
      int i;
      static int b=1;
      x[k]=1;
      if(sum+s[k]==d){
            printf("subset %d ",b++);
            for(i=1;i<=k;i++)
                  if(x[i]==1)
                        printf("%d ",s[i]);
      }
      else if(sum+s[k]+s[k+1]<=d){
            subset(sum+s[k],k+1,r-s[k]);
      }
      if((sum+r-s[k]>=d)&&(sum+s[k+1]<=d)){
            x[k]=0;
            subset(sum,k+1,r-s[k]);
      }

}

int main(){
      int n,sum=0;
      int i,j;
      scanf("%d",&n);
      for(i=1;i<=n;i++) {scanf("%d",&s[i]);sum+=s[i];}
      scanf("%d",&d);
      if((sum<d) || s[1]>d){
            printf("not possible\n");
            return 0;
      }
      //printf("%d\n",sum);
      subset(0,1,sum);
      return 0;
}