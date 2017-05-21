#include<stdio.h>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;


struct node{
	int first,second;
	bool operator<(const node &a)const{
		return (first==a.first)?(second<a.second):(first<a.first);
	}
};
vector<struct node >list;
map<int, vector<int> >mymap;
void make(int a,int b){
	struct node tmp;
	if(a>b){
		tmp.first = b;
		tmp.second = a;
	}else{
		tmp.first = a;
		tmp.second = b;
	}
	list.push_back(tmp);
}

int main(){
	int j=1,test;
	scanf("%d",&test);
	while(j<=test){
		
		int n,k,val;
		scanf("%d%d",&n,&k);
		int i,x,a[n];
		for(i=0;i<n;i++){
			scanf("%d",&x);
			val = x%k;
			mymap[val].push_back(x);
			a[i]=val;
		}
		map<int, int >m;
		for(i=0;i<n;i++){
			if(m[a[i]]==0){
				m[a[i]]=1;
				sort(mymap[a[i]].rbegin(),mymap[a[i]].rend());
			}
		}
		printf("Case %d:\n",j);
		if(n%2==1){
			printf("Not Possible\n");
		}else{

			sort(a,a+n);
			for(i=0;i<n;i++){
				val = (k-a[i])%k;
				int pos = a[i];
				if((val==a[i] && mymap[val].size()>1) || (val!=a[i] && mymap[val].size()>0 && mymap[pos].size()>0)){
					
					int a = mymap[pos].back();
					mymap[pos].pop_back();
					int b = mymap[val].back();
					mymap[val].pop_back();
				//	printf("%d---%d\n",a,b);
					make(a,b);
				}
			}

			sort(list.begin(),list.end());
			if(!list.size()){
				printf("Not Possible\n");	
			}else{
				for(i=0;i<list.size();i++){
					printf("%d %d\n",list[i].first,list[i].second);
				}
			}
		}
		list.clear();
		for(i=0;i<n;i++)
			mymap[a[i]].clear();
		j++;
		
	}
	return 0;
}