#include<stdio.h>
#define MOD 1000000007
int main(){
	int n,i;
	scanf("%d",&n);
	int a[n],front[n],back[n],even=1;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(a[i]&1){
			front[i]=0;
		}else{
			front[i]=even;
			if(even==1)
				even++;
		}
	}

	even=1;
	for(i=n-1;i>=0;i--){
		if(a[i]&1){
			if(i!=n-1)
				back[i]=back[i+1];
			else
				back[i]=0;
		}else{
			if(i!=n-1)
				back[i]=back[i+1]+even;
			else
				back[i]=even;
			if(even==1)
				even++;
		}	
	}
	long long int ans=0;
	for(i=0;i<n-1;i++){
		ans = (ans%MOD+(front[i]%MOD*back[i+1]%MOD)%MOD)%MOD;
	}
	printf("%lld\n",ans);
	return 0;
}