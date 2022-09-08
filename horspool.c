#include <stdio.h>
#include <stdlib.h>

int Table[1000];
int n,m;

void shiftTable(char *p){
      int i,j;
      for(i=0;i<1000;i++)
            Table[i]=m;
      for(j=0;j<=m-2;j++)
            Table[p[j]]=m-1-j;
}

int Horspool(char *p, char* t){
      shiftTable(p);
      int i,j,k;
      i=m-1;
      while(i<=n-1){
            k=0;
            while(k<=m-1 && p[m-1-k]==t[i-k]) k++;
            if(k==m) return i-m+1;
            else i=i+Table[t[i]];
      }
      return -1;
}

int main(){
      char p[100],t[100];
      printf("enter m: ");
      scanf("%d", &m);
      printf("enter n: ");
      scanf("%d", &n);
      printf("enter pattern\n");
      scanf("%s", p);
      printf("enter text\n");
      scanf("%s", t);
      int res=Horspool(p,t);
      if(res==-1) printf("not found\n");
      else printf("found at %d\n",res+1);
}