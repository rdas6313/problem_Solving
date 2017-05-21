#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
	long long int a[3];
	scanf("%lld%lld%lld",&a[0],&a[1],&a[2]);
	sort(a,a+3);
	long long int tmp = a[1];
	long long int temp = a[2]-a[1];
	if(temp%2>0){
		tmp+=(temp/2)+1;
	}else
		tmp+=(temp/2);

	printf("%lld\n",tmp);
	return 0;
}