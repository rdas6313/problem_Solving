#include<stdio.h>
#include<algorithm>
using namespace std;
int bit(int x){
	int tmp=0;
	while(x){
		if(x&1)
			tmp++;
		x=x>>1;
	}
	return tmp;
}
int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		int n,k,i;
		scanf("%d%d",&n,&k);
		int x,a[n];
		for(i=0;i<n;i++){
			scanf("%d",&x);
			a[i]=bit(x);
		}
		sort(a,a+n);
		int sum=0;
		for(i=n-1;i>=n-k;i--){
			sum+=a[i];
		}
		printf("%d\n",sum);
	}
}