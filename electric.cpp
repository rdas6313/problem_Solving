#include<stdio.h>
#include<set>
#include<map>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	int a[n],i;
	map<int,int>dic;
	map<int,int>vis;
	set<int>s;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		dic[a[i]]++;
		vis[a[i]]=0;
		s.insert(a[i]);
	}
	long long int ans=0;
	for(i=0;i<n-1;i++){
		dic[a[i]]--;
		if(dic[a[i]]==0)
			s.erase(a[i]);
		if(vis[a[i]]==0){
			vis[a[i]]=1;
			ans+=s.size();
		}
	}
	printf("%lld\n",ans);
	return 0;
}