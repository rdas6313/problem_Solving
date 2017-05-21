#include<stdio.h>
#include<vector>
#include<map>
#include<string>
#include<iostream>
#include<algorithm>
#define Max 10000
using namespace std;
struct node{
	int x,y,z;
	bool operator <(const node &a)const
	{
		return (z==a.z)?1:(z<a.z);
	}
};
vector<struct node>vec;
map<string, int>mymap;
int tmp;

int convert(string x){
	if(mymap[x]==0){
		tmp++;
		mymap[x]=tmp;
	}
	return mymap[x];
}
int find(int x,int par[]){
	if(par[x]==x)
		return x;
	par[x] = find(par[x],par);
	return par[x];
}
int kruskal(){
	int par[tmp+1],i;
	for(i=0;i<=tmp;i++){
		par[i]=i;
	}
	int a,b,c,s=0;
	sort(vec.begin(),vec.end());
	for(i=0;i<vec.size();i++){
		a = vec[i].x;
		b = vec[i].y;
		c = vec[i].z;
		a = find(a,par);
		b = find(b,par);
		if(a!=b){
			par[a] = b;
			s+=c;
		}
	}

	int vis[tmp+1];
	for(i=0;i<=tmp;i++)
		vis[i]=0;
	vis[find(1,par)]=1;
	for(i=2;i<=tmp;i++){
		int val = find(i,par);
		if(vis[val]==0)
			return -1;
	}
	return s;
}
void clear(){
	vec.clear();
	mymap.clear();
}
int main(){
	int test,k=1;
	scanf("%d",&test);
	while(k<=test){
		int m,i,w;
		tmp = 0;
		string x1,x2;
		scanf("\n%d",&m);
		for(i=0;i<m;i++){
			cin >> x1;
			cin >> x2;
			cin >> w;
			struct node temp;
			temp.x = convert(x1);
			temp.y = convert(x2);
			temp.z = w;
			vec.push_back(temp);
			//printf("%d---%d---%d\n",temp.x,temp.y,temp.z);
		}
		int temp = kruskal();
		printf("Case %d: ",k);
		if(temp == -1)
			printf("Impossible\n");
		else
			printf("%d\n",temp);

		clear();
		k++;
	}
	return 0;
}