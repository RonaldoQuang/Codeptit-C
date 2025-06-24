#include <stdio.h>
#include <math.h>
int check(long long x){
	long long f1=0,f2=1,fn;
	if(x==0||x==1) return 1;
	for(int i=1;i<=92;i++){
		fn=f1+f2;
		f1=f2;
		f2=fn;
		if(fn==x) return 1;
	}
	return 0;
}
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		long long a;
		scanf("%lld",&a);
		if(check(a)) printf("YES\n");
		else printf("NO\n");
	}
}