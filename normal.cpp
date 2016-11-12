#include<stdio.h>
#include<set>
#include<map>
using namespace std;
int main(){
	int n,i;
	set<int>par;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		par.insert(a[i]);
	}
	int j=0;
	long long int ans=0;
	set< int >s;
	map<int,int>dic;
	for(i=0;i<n;i++){
	
		while(j<n && s.size()<par.size()){
			if(dic[a[j]]==0){
				s.insert(a[j]);
			}
			dic[a[j]]++;
			j++;
		}
		if(s.size()==par.size()){
		
			ans+=(n-j)+1;
			//printf("%lld\n",ans);
		}
		dic[a[i]]--;
		if(dic[a[i]]==0)
			s.erase(a[i]);
	}
	printf("%lld\n",ans);
	return 0;
}