#include <stdio.h>
int n;
int H[100];
//int output[100];

void heapify(){
      //printf("heapify..\n");
      int i,j,k,v,heap=0;
      for(i=n/2;i>0;i--){
            heap=0;
            k=i;
            v=H[k];
            while(!heap && 2*k<=n){
                  j=2*k;
                  if(j<n){
                        if(H[j]<H[j+1]) j=j+1;}
                        if(v>H[j]) heap=1;
                        else{
                              H[k]=H[j];
                              k=j;
                        }
            }
            H[k]=v;
      }
}

void heapsort(){
      //printf("entered heapsort\n");
      heapify();
      for(int i=n;i>=1;i--){
            //printf("deleteing..\n");
            int temp=H[1];
            H[1]=H[n];
            H[n]=temp;
            n--;
            heapify();
      }
}
      
int main(){
      int i,num;
      printf("enter n: ");
      scanf("%d",&n);
      num=n;
      printf("enter the array: \n");
      for(i=1;i<=num;i++) scanf("%d", &H[i]);
      printf("unsorted array: \n");
      for(i=1;i<=num;i++) printf("%d ", H[i]);
      printf("\n");
      heapsort();
      printf("sorted array: \n");
      for(i=1;i<=num;i++) printf("%d ", H[i]);
      printf("\n");
}