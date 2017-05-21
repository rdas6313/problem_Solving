#include<stdio.h>
#include<queue>
using namespace std;
struct Hash
{
	long long int val;
	int bitval,pos;
	bool operator<(const Hash &tmp)const{
		return (bitval==tmp.bitval)?(pos>tmp.pos):(bitval>tmp.bitval);
	}	
};
int bit(long long int x){
	int tmp=0;
	while(x){
		if(x&1)
			tmp++;
		x=x>>1;
	}
	return tmp;
}
priority_queue< struct Hash >q;
int main(){
	int test;
	scanf("%d",&test);
	while(test--){
		int n,i;
		scanf("%d",&n);
		long long int x;
		for(i=0;i<n;i++){
			scanf("%lld",&x);
			struct Hash tmp;
			tmp.pos=i;
			tmp.val=x;
			tmp.bitval=bit(x);
			q.push(tmp);
		}
		while(!q.empty()){
			printf("%lld",q.top().val);
			q.pop();
			if(!q.empty())
			    printf(" ");
		}
		printf("\n");
	}
	return 0;
}