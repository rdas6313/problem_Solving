#include<stdio.h>
int gcd(int x,int y){
	if(y>x){
		int temp=y;
		y=x;
		x=temp;
	}
	int r=x%y;
	if(r==0)
		return y;
	return gcd(y,r);
}
int main(){
	int test,i;
	scanf("%d",&test);
	while(test--){
		int n,x,r;
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&x);
			if(i==0)
				r=gcd(x,x);
			else
				r=gcd(r,x);
		}
		printf("%d\n",r);
	}
	return 0;
}