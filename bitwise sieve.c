#include<stdio.h>
#include<math.h>
#define Max 1000000
#define Len (Max/32)+1
int prime[Len];
void bit_sieve(){
	int i,index,shift_val,j;
	for(i=0;i<Len;i++)
		prime[i]=(prime[i]&0);
	for(i=4;i<Max;i+=2){
		index = (i/32);
		shift_val = (i%32);
		prime[index] = (prime[index] | (1 << shift_val));
	}
	int sqr = sqrt(Max);
	for(i=3;i<=sqr;i++){
		for(j=i*i;j<Max;j+=i){
			index = (j/32);
			shift_val = (j%32);
			prime[index] = (prime[index] | (1 << shift_val));		
		}
	}

}
int main(){
	int i;
	bit_sieve();
	for(i=2;i<Max;i++){
		int index = (i/32);
		int s = (i%32);
		int val = (prime[index] & (1<<s));
		if(val==0){
			printf("%d \n",i);
		}
	}
	printf("\nLength-%d\n",Len);
	return 0;
}