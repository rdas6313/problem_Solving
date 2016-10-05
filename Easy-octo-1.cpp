#include<stdio.h>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
struct node{
	char name[21];
	int q;
	bool operator<(const node &a)const{
	
		return (q==a.q)?((strcmp(name,a.name)<0)?1:0):q>a.q;
	}
};
vector<struct node>vec;
int main(){
	int n,t,i;
	scanf("%d%d",&n,&t);
	for(i=0;i<n;i++){
		struct node tmp;
		scanf("%s%d",tmp.name,&tmp.q);
		vec.push_back(tmp);
	}
	sort(vec.begin(),vec.end());
	for(i=0;i<t;i++)
		printf("%s\n",vec[i].name);
	return 0;
}