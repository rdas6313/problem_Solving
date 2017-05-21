#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
	vector<int>vec;
	int n;
	scanf("%d",&n);
	int i,x,y;
	for(i=0;i<n;i++){
		scanf("%d%d",&x,&y);
		if(y<x)
			x=y;
		vec.push_back(x);
	}
	sort(vec.begin(),vec.end());
	int tmp=1;
	for(i=0;i<vec.size();i++){
		if(tmp<=vec[i]){
			tmp++;
		}
	}
	printf("%d\n",tmp-1);
	return 0;
}