#include <stdio.h>
#include <stdlib.h>
int n;
int count=0;

int partition(int* a, int l, int h){
      int pivot,i,j,temp;
      pivot=a[l];
      i=l+1;
      j=h;
      while(i<=h && j>=l){
            count++;
            while(a[i]<pivot) {i++;count++;}
            while(a[j]>pivot) {j--;count++;}
            if(i<j){
                  temp=a[i];
                  a[i]=a[j];
                  a[j]=temp;
            }
            else{
                  a[l]=a[j];
                  a[j]=pivot;
                  return j;
            }
      }
}

void quicksort(int* a, int l, int h){
      if(l<h){
            int s=partition(a,l,h);
            quicksort(a,l,s-1);
            quicksort(a,s+1,h);
      }
}

int main(){
      int i;
      printf("enter n: ");
      scanf("%d",&n);
      int a[n];
      printf("enter the array: \n");
      for(i=0;i<n;i++) scanf("%d", &a[i]);
      printf("unsorted array: \n");
      for(i=0;i<n;i++) printf("%d ", a[i]);
      printf("\n");
      quicksort(a,0,n-1);
      printf("sorted array: \n");
      for(i=0;i<n;i++) printf("%d ", a[i]);
      printf("\n");
      printf("count = %d\n", count);
      int x[100],y[100],z[100];
      int c1,c2,c3;
      printf("size\t asc\t desc\t rand\n");
      for(i=16;i<100;i=i*2){
            for(int j=0;j<i;j++){
                  x[j]=j;
                  y[j]=i-j;
                  z[j]=rand()%i;
            }
            count=0;
            quicksort(x,0,i-1);
            c1=count;
            count=0;
            quicksort(y,0,i-1);
            c2=count;
            count=0;
            quicksort(z,0,i-1);
            c3=count;
            printf("%d\t%d\t%d\t%d\n",i,c1,c2,c3);
      }
      return 0;
}