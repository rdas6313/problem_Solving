#include<stdio.h>
int main(){
	int n,i,x,total=0,four=0,three=0,two=0,one=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&x);
		switch(x){
			case 4:
				four++;
				break;
			case 3:
				three++;
				break;
			case 2:
				two++;
				break;
			case 1:
				one++;
				break;
		}
	}
	total+=four;
	total+=three;
	if(one>=three){
		one-=three;
	}else{
		one=0;
	}
	total+=(two*2)/4;
	two=(two*2)%4;
	if(two!=0){
		total+=1;
	}
	if(one>=two){
		one-=two;
	}else{
		one=0;
	}
	total+=(one/4);
	if(one%4!=0)
		total+=1;
	printf("%d\n",total);
	return 0;
}
