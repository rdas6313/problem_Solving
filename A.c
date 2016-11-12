#include<stdio.h>
int main(){
	int n,b,d,s=0,mark=0,x,i;
	scanf("%d%d%d",&n,&b,&d);
	for(i=0;i<n;i++){
		scanf("%d",&x);
		if(x<=b){
			s+=x;
			if(s>d){
				mark++;
				s=0;
			}
		}
	}
	printf("%d\n",mark);
	return 0;
}