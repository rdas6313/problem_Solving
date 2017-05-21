#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
	int n,i,x,c=0,y;
	scanf("%d",&n);
	int a[n],b[n];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		b[i]=(2*a[i]);
	}
	sort(a,a+n);
	for(i=0;i<n;i++){
		x=0,y=n-1;
		while(x<y){
			if((a[x]+a[y])<b[i])
				x++;
			else if((a[x]+a[y])>b[i])
				y--;
			else{
				c++;
				break;
			}
		}
	}
	printf("%d\n",c);
	return 0;
}