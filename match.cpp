#include<stdio.h>
#include<stack>
using namespace std;
int main(){
	stack<int>s;
	stack<int>ds;
	int n,i,depth=0,x,first_nest=-1,max=0,start=-1;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&x);
		if(x==1){
			ds.push(i);
			if(ds.size()>depth){
				depth=ds.size();
				first_nest=i+1;
			}
			s.push(i);
		}else{
			ds.pop();
			int pos=s.top();
			s.pop();
			if(max<(i-pos+1)){
				max=(i-pos)+1;
				start=pos+1;
			}
		}
	}
	printf("%d %d %d %d\n",depth,first_nest,max,start);
	return 0;
}