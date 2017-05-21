#include<stdio.h>
int main(){
	int n,h,i;
	scanf("%d%d",&n,&h);
	int a[n];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int x,cval=0,pos=0;
	while(1){
		scanf("%d",&x);
		if(x==0)
			break;
		else if(x==1 && pos>0){
			pos--;
		}else if(x==2 && pos<n-1){
			pos++;
		}else if(x==3 && cval==0 && a[pos]>0){
			a[pos]--;
			cval=1;
		}else if(x==4 && cval==1 && a[pos]<h){
			a[pos]++;
			cval=0;
		}
	}
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}