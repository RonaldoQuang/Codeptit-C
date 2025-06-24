//Cho số tự nhiên N và số nguyên tố P. 
//Nhiệm vụ của bạn là tìm số x lớn nhất để N! chia hết cho px. 
//Ví dụ với N=7, p=3 thì x=2 là số lớn nhất để 7! Chia hết cho 32.
//Input
//3
//62  7
//76  2
//3  5
//Output
//9
//73
//0
#include <stdio.h>
#include <math.h>
int mod(int n, int p){
	int demp=0;
	while(n%p==0){
		++demp;
		n/=p;
	}
	return demp;
}
int main(){
	int x; scanf("%d",&x);
	for(int i=1;i<=x;i++){
		int N,p,dem=0; scanf("%d%d",&N,&p);
		for(int j=p;j<=N;j+=p){
			dem=dem+mod(j,p);
		}
		printf("%d\n",dem);
	}
}