#include<stdio.h>
#define Mod 1000003
int mem[Mod];
void init(){
	int i;
	mem[0]=1;
	for(i=1;i<Mod;i++){
		mem[i] = (i*(long long int)mem[i-1])%Mod;
	}
}
int main(){
	int test;
	init();
	scanf("%d",&test);
	while(test--){
		long long int n,x;
		scanf("%lld%lld",&n,&x);
		if(n>=Mod)
			printf("0\n");
		else{
			x = (x%Mod);
			int tmp = (mem[n]*x)%Mod;
		//	printf("%d---  %d\n",mem[n],x);
			printf("%d\n",tmp);
		}
	}
	return 0;
}