#include<stdio.h>
#include<math.h>
using namespace std;
int phi(int n){
	int i,result=n;
	int sqr = sqrt(n);
	for(i=2;i<=sqr;i++){
		if(n%i==0){
			while(n%i==0)
				n=n/i;
			result = result-(result/i);
		}
	}
	if(n>1){
		result = result-(result/n);
	}
	return result;
}
int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		int n;
		scanf("%d",&n);
		int tmp = phi(n);
		printf("%d\n",tmp);
	}
	return 0;
}