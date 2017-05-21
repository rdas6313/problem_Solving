#include<stdio.h>
#include<string.h>
#define Max 2*100000+10
int BIT[26][Max];
void update(int pos,int idx,int val){
	while(idx<Max){
		BIT[pos][idx]+=val;
		idx+=idx & -idx;
	}
}
int query(int pos,int idx){
	int sum=0;
	while(idx>0){
		sum+=BIT[pos][idx];
		idx-=idx & -idx;
	}
	return sum; 
}
int search(int pos,int val){
	int start=1,end=Max-1,ans,mid;
	while(start<=end){
		mid=start+((end-start)/2);
		if(query(pos,mid)==val){
			ans=mid;
			end=mid-1;
		}else if(query(pos,mid)<val){
			start=mid+1;
		}else{
			end=mid-1;
		}
	}
	update(pos,ans,-1);
	return ans;
}
int main(){
	char s[Max],ch[2];
	int i,n,j,q,x,vis[Max];
	for(i=0;i<26;i++)
		for(j=0;j<Max;j++){
			BIT[i][j]=0;
			vis[j]=0;
		}
	scanf("%s",s);
	int len=strlen(s);
	for(i=0;i<len;i++){
		update(s[i]-'a',i+1,1);
	}
	scanf("%d\n",&q);
	for(i=0;i<q;i++){
		scanf("%d%s",&x,ch);
		int tmp=search(ch[0]-'a',x);
	//	printf("%d\n",tmp-1);
		vis[tmp-1]=1;
	}
	for(i=0;i<len;i++){
		if(!vis[i])
			printf("%c",s[i]);
	}
	printf("\n");
	return 0;
}