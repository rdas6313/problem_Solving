#include<stdio.h>
int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		int n,i,odd=0,even=0,x;
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&x);
			if(x%2==0)
				even++;
			else
				odd++;
		}
		printf("%d\n",even*odd);
	}
	return 0;
}