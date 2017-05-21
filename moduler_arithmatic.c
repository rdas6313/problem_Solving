#include<stdio.h>
#include<string.h>
int mod(char s[],int m){
    int i,len=strlen(s),ans=0;
    for(i=0;i<len;i++){
        int val = s[i]-'0';
        ans=((ans%m)*(10%m))%m;
        ans=((ans%m)+(val%m))%m;
    }
    return ans;
}
int expo(char a[],int b,int m){
  if(b==1)
    return mod(a,m);
  if(b%2==0){
      int tmp = expo(a,b/2,m);
      return ((tmp%m)*(tmp%m))%m;
  }else{
      int tmp = expo(a,b-1,m);
      return (mod(a,m)*(tmp%m))%m;
  }
}
int main(){
  int test;
  scanf("%d",&test);
  while(test--){
    int b,m;char a[1000009];
    scanf("%s%d%d",a,&b,&m);
    int tmp=expo(a,b,m);
    printf("%d\n",tmp);
  }
  return 0;
}
