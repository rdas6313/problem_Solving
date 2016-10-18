#include<stdio.h>
int cal(int tmp,int a){
	if(tmp<=a)
		return 1;
	return (tmp%a==0)?(tmp/a):(tmp/a)+1;
}
int main(){
	int n,m,a;
	scanf("%d%d%d",&n,&m,&a);
	long long int tmp=(long long int)cal(n,a)*cal(m,a);
	printf("%lld\n",tmp);
	return 0;
}