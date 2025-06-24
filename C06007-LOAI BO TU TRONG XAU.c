#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
int sotu(char a[100]){
	int dem=0;
	for(int j=1;j<strlen(a)-1;j++){
		if(a[j]==' '&&a[j-1]!=' '&&a[j+1]!=' '||a[j]==' '&&a[j-1]==' '&&a[j+1]!=' ') ++dem;		
	}
	return dem;
}
int cuoi(char a[100], int b){
	for(int i=b+1;;i++){
		if(a[i]==' '||a[i]=='\0') return i-1;
	}
}
int ss1(char a[100], int x, int y){
	int dem=0;
	for(int i=0;i<=cuoi(a,x)-x;i++){
		if((a[x+i])!=(a[y+i])){
			++dem;
			break;
		}
	}
	return dem;
}
int ss2(char a[100], char c[100], int x, int y){
	int dem=0;
	for(int i=0;i<=cuoi(a,x)-x;i++){
		if((a[x+i])!=(c[y+i])){
			++dem;
			break;
		}
	}
	return dem;
}
int dk(char a[100], int b[100], int x){
	int dem=0;
	int d=b[x];
	for(int i=0;i<x;i++){
		int y=b[i];
		if((cuoi(a,y)-y)!=(cuoi(a,d)-d)){
			++dem;
		}
		if((cuoi(a,y)-y)==(cuoi(a,d)-d)&&ss1(a,d,y)>0){
			++dem;
		}
	}
	return dem;
}
void gan(char a[100], int b[100]){
	int m=sotu(a);
	if(a[0]!=' '){
		b[0]=0;
		int cnt=1;
		for(int i=1;i<strlen(a);i++){
			if(a[i]!=' '&&a[i-1]==' '){
				b[cnt]=i;
				++cnt;
			}
			if(cnt==m+1) break;
		}
	}
	if(a[0]==' '){
		int cnt=0;
		for(int i=0;i<strlen(a);i++){
			if(a[i]!=' '&&a[i-1]==' '){
				b[cnt]=i;
				++cnt;
			}
			if(cnt==m+1) break;
		}
	}
}
int main(){
	char a[100],c[100];
	int b[100],d[100];
	gets(a);
	gets(c);
	gan(a,b);
	gan(c,d);
	int x=sotu(a), y=sotu(c);
	for(int i=0;i<=x;i++){
		int m=b[i];
		int dem=0;
		if(dk(a,b,i)==i){
			for(int j=0;j<=y;j++){
				int n=d[j];
				if((cuoi(a,m)-m)!=(cuoi(c,n)-n)) ++dem;
				if((cuoi(a,m)-m)==(cuoi(c,n)-n)&&ss2(a,c,m,n)>0) ++dem;
			}
			if(dem==y+1){
				for(int j=m;j<=cuoi(a,m);j++){
				    printf("%c",(a[j]));
			    }
			    printf(" ");
			}
		}
	}
}