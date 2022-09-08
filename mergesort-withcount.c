#include <stdio.h>
#include <stdlib.h>
int n;
int count=0;

void merge(int* a, int l, int mid, int h){
      int i,j,k;
      i=l;
      j=mid+1;
      k=l;
      int b[100];
      while(i<=mid && j<=h){
            count++;
            if(a[i]>a[j]) b[k++]=a[j++];
            else b[k++]=a[i++];
      }
      while(i<=mid) {b[k++]=a[i++];count++;}
      while(j<=h) {b[k++]=a[j++];count++;}
      for(i=l;i<=h;i++)
            a[i]=b[i];
}

void mergesort(int* a, int l, int h){
      if(l<h){
            int mid=((l+h)/2);
            mergesort(a,l,mid);
            mergesort(a,mid+1,h);
            merge(a,l,mid,h);
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
      mergesort(a,0,n-1);
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
            mergesort(x,0,i-1);
            c1=count;
            count=0;
            mergesort(y,0,i-1);
            c2=count;
            count=0;
            mergesort(z,0,i-1);
            c3=count;
            printf("%d\t%d\t%d\t%d\n",i,c1,c2,c3);
      }
      return 0;
}