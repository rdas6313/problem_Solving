#include<stdio.h>
#include<math.h>
#define Max 1000002
int prime_number[Max],k;
void sieve(){
	int i,j;
	int prime[Max];
	for(i=0;i<Max;i++)
		prime[i]=1;
	for(i=4;i<Max;i+=2)
		prime[i]=0;
	int sqr = sqrt(Max);
	for(i=3;i<=sqr;i++){
		for(j=i*i;j<Max;j+=i){
			prime[j]=0;
		}
	}
	prime[1]=0;
	prime[0]=0;
	k=0;
	for(i=1;i<Max;i++){
		if(prime[i])
			prime_number[k++]=i;
	}
}
int index(int x){
	int start=0,end=k-1,tmp=-1;
	while(start<=end){
		int mid = start+((end-start)/2);
		if(prime_number[mid]<=x){
			tmp = mid;
			start = mid+1;
		}else
			end = mid-1;
	}
//	printf("tmp---%d\n",tmp);
	return tmp+1;
}
int main(){
	int test;
	sieve();
	scanf("%d",&test);
	while(test--){
		int a,b,i,c=0;
		scanf("%d%d",&a,&b);
		if(b<a){
		    a=(a^b);
		    b=(a^b);
		    a=(a^b);
		}
		
		a = index(a-1);
		b = index(b);
		c = (b-a);
		printf("%d\n",c);
	}
	return 0;
}