#include <stdio.h>
int n;

void merge(int* a, int l, int mid, int h){
      int i,j,k;
      i=l;
      j=mid+1;
      k=l;
      int b[n];
      while(i<=mid && j<=h){
            if(a[i]>a[j]) b[k++]=a[j++];
            else b[k++]=a[i++];
      }
      while(i<=mid) b[k++]=a[i++];
      while(j<=h) b[k++]=a[j++];
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
}