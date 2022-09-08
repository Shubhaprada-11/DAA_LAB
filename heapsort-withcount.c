#include <stdio.h>
#include <stdlib.h>
//int n;
int H[100];
int count=0;

void heapify(int* H, int n){
      int i,j,k,v,heap=0;
      for(i=n/2;i>0;i--){
            heap=0;
            k=i;
            v=H[k];
            while(!heap && 2*k<=n){
                  count++;
                  j=2*k;
                  if(j<n){
                        count++;
                        if(H[j]<H[j+1]) j=j+1;
                        }
                        count++;
                  if(v>H[j]) heap=1;
                  else{
                        H[k]=H[j];
                        k=j;
                  }
            }
            H[k]=v;
      }
}

void heapsort(int* H, int n){
      //printf("entered heapsort\n");
      heapify(H,n);
      for(int i=n;i>=1;i--){
            //printf("deleteing..\n");
            int temp=H[1];
            H[1]=H[n];
            H[n]=temp;
            n--;
            heapify(H,n);
      }
}
      
int main(){
      int n,i,num;
      printf("enter n: ");
      scanf("%d",&n);
      num=n;
      printf("enter the array: \n");
      for(i=1;i<=num;i++) scanf("%d", &H[i]);
      printf("unsorted array: \n");
      for(i=1;i<=num;i++) printf("%d ", H[i]);
      printf("\n");
      heapsort(H,n);
      printf("sorted array: \n");
      for(i=1;i<=num;i++) printf("%d ", H[i]);
      printf("\n");
      printf("count: %d\n",count);
      int x[100],y[100],z[100];
      int c1,c2,c3;
      printf("size\t asc\t desc\t rand\n");
      for(i=16;i<100;i=i*2){
            //n=i;
            for(int j=1;j<=i;j++){
                  x[j]=j;
                  y[j]=i-j;
                  z[j]=rand()%i;
            }
            count=0;
            heapsort(x,i);
            c1=count;
            count=0;
            heapsort(y,i);
            c2=count;
            count=0;
            heapsort(z,i);
            c3=count;
            printf("%d\t%d\t%d\t%d\n",i,c1,c2,c3);
      }
      return 0;
}