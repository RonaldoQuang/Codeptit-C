#include <stdio.h>
#include <math.h>
int stn(int n){
	int rev=0, m=n;
	while(n!=0){
		rev=rev*10+n%10;
		n/=10;
	}
	if(rev==m) return 1;
	return 0;
}
int sum(int n){
	int sum=0;
	while(n!=0){
		sum=sum+n%10;
		n/=10;
	}
	return sum;
}
int main(){
    int n; scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int a, dem=0; scanf("%d",&a);
        int x=a;
	    int b=pow(10,a-1)+1,c=pow(10,a)-1;
	    for(int j=b;j<=c;j++){
		    if(stn(j)==1&&sum(j)%10==0) ++dem;
	    }  
	    printf("%d\n",dem);
    }
}