#include <stdio.h>
void mtxo(int a[100][100], int m, int n, int x, int y){
	if(m==0) a[m][m]=1;
	else a[m][m]=a[m][m-1]+1;
	a[m][n]=a[m][m]+x-1;
	a[n][n]=a[m][n]+x-1;
	a[n][m]=a[n][n]+x-1;
	for(int i=1;i<n-m;i++){
		a[m][m+i]=a[m][m+i-1]+1;
		a[n-i][m]=a[n-i+1][m]+1;
		a[m+i][n]=a[m+i-1][n]+1;
		a[n][n-i]=a[n][n-i+1]+1;
	}
}
int main(){
	int a[100][100],n; scanf("%d",&n);
	int c=n/2;
	if(n%2!=0){
		a[c][c]=n*n;
	}
	for(int i=0;i<c;i++){
		int k=n-2*i;
		int h=n-1-i;
		mtxo(a,i,h,k,n);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}