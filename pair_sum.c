#include<stdio.h>
#define max 1000001
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	int a[n],i,f=0,tmp;
	int h[max];
	for(i=0;i<max;i++)
		h[i]=0;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		h[a[i]]++;
	}
	for(i=0;i<n;i++){
		h[a[i]]--;
		tmp=k-a[i];
		if(tmp>max)
			break;
		if(tmp>=0 && h[tmp]>0){
			f=1;
			break;
		}
	}
	if(f)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}