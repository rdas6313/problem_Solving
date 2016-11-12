#include<stdio.h>
void heapify(long long int a[],int src,int n){
	int left=(2*src)+1;
	int right=left+1,max;
	if(left<n && a[left]>a[src])
		max=left;
	else
		max=src;
	if(right<n && a[right]>a[max])
		max=right;
	if(max!=src){
		long long int temp=a[max];
		a[max]=a[src];
		a[src]=temp;
		heapify(a,max,n);
	}
}
int main(){
	int test,n,k,i;
	scanf("%d",&test);
	while(test--){
		scanf("%d%d",&n,&k);
		long long int a[n],sum=0;
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		int par=(n-2)/2;
		for(i=par;i>=0;i--)
			heapify(a,i,n);
		for(i=0;i<k;i++){
			sum+=a[0];
			a[0]/=2;
			heapify(a,0,n);
		}
		printf("%lld\n",sum);
	}
	return 0;
}