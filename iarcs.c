#include<stdio.h>
#include<math.h>
int main(){
	int n;
	int p=1,p1lead=0,p2lead=0,a,b,i,maxlead=-1;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d",&a,&b);
		p1lead+=a;
		p2lead+=b;
		if(p1lead>p2lead){
			int diff=(p1lead-p2lead);
			if(maxlead<diff){
				maxlead=diff;
				p=1;
			}
		}else{
			int diff=(p2lead-p1lead);
			if(maxlead<diff){
				maxlead=diff;
				p=2;
			
			}
		}
	}
	printf("%d %d\n",p,maxlead);
	return 0;
}