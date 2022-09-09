#include <stdio.h>
#include<stdlib.h>
#define INF 99999

int G[100][100];

void dij(int n, int src,int dist[],int pred[]){
      int i,count,V[n],v,w,min;
      for(i=0;i<n;i++){
            V[i]=0;
            dist[i]=G[src][i];
            if(dist[i]!=999)
                  pred[i]=src;
      }
      V[src]=1;
      pred[src]=-1;
      dist[src]=0;
      count=1;
      while(count<n){
            min=999;
            for(w=0;w<n;w++){
                  if(!V[w] && dist[w]<min){
                        min=dist[w];
                        v=w;
                  }
            }
            V[v]=1;
            count++;
            for(w=0;w<n;w++){
                  if(!V[w] && dist[w]>dist[v]+G[v][w]){
                        dist[w]=dist[v]+G[v][w];
                        pred[w]=v;
                  }
            }
      }
}

int main(){
      int n,V[100],dist[100],pred[100];
      int i,j,x,y;
      int src,min,cost=0;
      printf("enter n: ");
      scanf("%d",&n);
      for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                  scanf("%d",&G[i][j]);
      printf("enter source: ");
      scanf("%d",&src);
      dij(n,src,dist,pred);
      for(i=0;i<n;i++){
            if(i!=src){
                  printf("dist to %d = %d\n", i,dist[i]);
                  printf("Path= %d",i);
                  j=i;
                  do{
                        j=pred[j];
                        printf("<-%d",j);
                  }while(j!=src);
            }
      }
}