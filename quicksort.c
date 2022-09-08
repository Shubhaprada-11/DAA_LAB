#include <stdio.h>
#include <stdlib.h>
int n;

int partition(int* a, int l, int h){
      int pivot,i,j,temp;
      pivot=a[l];
      i=l+1;
      j=h;
      while(i<=h && j>=l){
            while(a[i]<pivot) i++;
            while(a[j]>pivot) j--;
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
}