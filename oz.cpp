#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<map>
using namespace std;
vector<int>vec;
map<int,int >m;
void fact(int val){
	int sqr = sqrt(val);
	int i;
	for(i=1;i<=sqr;i++){
		if(val%i==0){
			vec.push_back(i);
			vec.push_back(val/i);
		}
	}
	sort(vec.begin(),vec.end());
}
int main(){
	int n,i,j;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	int diff = a[1]-a[0];
	fact(diff);
	int f;
	for(i=1;i<vec.size();i++){
		if(m[vec[i]]>0)
			continue;
		int tmp = (a[0]%vec[i]);
		f=1;
		for(j=1;j<n;j++){
			if(tmp != (a[j]%vec[i])){
				f=0;
				break;
			}
		}
		if(f){
			m[vec[i]]++;
			printf("%d ",vec[i]);
		}
	}
	printf("\n");
	return 0;
}