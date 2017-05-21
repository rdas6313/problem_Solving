#include<stdio.h>
#include<queue>
using namespace std;
priority_queue<int>max1,max2;
	priority_queue<int, vector<int>, greater<int> >min1,min2;

int count(int val){
	int max=-1;
	if(val==1){
		while(!min1.empty()){
			if(max<min1.top())
				max=min1.top();
			min1.pop();
		}
	}else{
		while(!min2.empty()){
			if(max<min2.top())
				max=min2.top();
			min2.pop();
		}
	}
	return max;
}
int main(){
	
	int n,k,x,i,y;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++){
		scanf("%d",&x);
		max1.push(x);
		min1.push(x);
	}
	for(i=0;i<n;i++){
		scanf("%d",&x);
		max2.push(x);
		min2.push(x);
	}
	for(i=0;i<k;i++){
		int x = max1.top();
		max1.pop();
		int y = min2.top();
		min2.pop();
		min2.push(x);
		max1.push(y);

	    x = max2.top();
		max2.pop();
		y = min1.top();
		min1.pop();
		min1.push(x);
		max2.push(y);
	}
	 x = max1.top()+count(2);
	 y = max2.top()+count(1);
	if(x<y)
		printf("%d\n",x);
	else
		printf("%d\n",y);
	return 0;
}