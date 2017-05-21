#include<stdio.h>
#include<math.h>
#define Max 1000
void sieveofEroto(int visit[]){
  int i,j,top=0;

  for(i=0;i<Max;i++)
    visit[i]=0;
  for(i=4;i<Max;i+=2)
    visit[i]=1;
  int sqr=sqrt(Max);
  for(i=3;i<=sqr;i++){
    if(visit[i]==0){
      for(j=i*i;j<Max;j+=i){
        visit[j]=1;
      }
    }
  }
}
int sphenic(int list[],int top,int n){
  int i,j=0,prime_fact[top];
  for(i=0;i<top;i++){
    while(n%list[i]==0){
      prime_fact[j++]=list[i];
      n=n/list[i];
    }
  }
  if(j>3)
    return 0;
  else if(j==3){
    if(prime_fact[0]!=prime_fact[1] && prime_fact[0]!=prime_fact[2] && prime_fact[1]!=prime_fact[2])
      return 1;
    else
      return 0;
  }else
    return 0;
}
int main(){
  int i,visit[Max],list[Max],top=0;
  sieveofEroto(visit);
  for(i=2;i<Max;i++)
    if(visit[i]==0)
      list[top++]=i;
  int test;
  scanf("%d",&test);
  while(test--){
      int n;
      scanf("%d",&n);
      int tmp=sphenic(list,top,n);
      printf("%d\n",tmp);
  }
  return 0;
}
