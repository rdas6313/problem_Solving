#include<stdio.h>
#include<vector>
#define Max 1000000
using namespace std;
int main(){
	vector<int>vec;
	int n1,n2,n3,i;
	int a[Max],x;
	for(i=0;i<Max;i++)
		a[i]=0;
	scanf("%d%d%d",&n1,&n2,&n3);
	for(i=0;i<n1;i++){
		scanf("%d",&x);
		a[x]++;
		
	}
	for(i=0;i<n2;i++){
		scanf("%d",&x);
		a[x]++;
		
	}
	for(i=0;i<n3;i++){
		scanf("%d",&x);
		a[x]++;
	}
	for(i=0;i<Max;i++){
		if(a[i]>1){
			vec.push_back(i);
		}
	}
	printf("%lu\n",vec.size());
	for(i=0;i<vec.size();i++)
		printf("%d\n",vec[i]);
	vec.clear();
	return 0;
}