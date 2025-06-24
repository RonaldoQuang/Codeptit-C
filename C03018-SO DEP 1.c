#include <stdio.h>
#include <math.h>
int nt(int n){
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) return 0;
    }
    return n>1;
}
int fib(long long n){
    long long a[100];
    a[0]=0;
    a[1]=1;
    for(long long i=2;i<=100;i++){
        a[i]=a[i-2]+a[i-1];
        if(a[i]==n){
            return 1;
            break;
        }
        if(a[i]>n){
    	    return 0;
    	    break;
	    }
    }
}
int tong(int n){
	int sum=0;
	while(n!=0){
	    sum=sum+n%10;
	    n/=10;		
	}
	return sum;
}
int main(){
	int a,b,m; scanf("%d%d",&a,&b);
	if(a<b){
	    for(int i=a;i<=b;i++){
		    m=tong(i);
		    if(nt(i)&&fib(m)==1) printf("%d ",i);
	    }
	}
	if(a>b){
	    for(int i=b;i<=a;i++){
		    m=tong(i);
		    if(nt(i)&&fib(m)==1) printf("%d ",i);
	   }
    }
}