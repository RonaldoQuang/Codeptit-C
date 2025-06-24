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
char upper(char a){
	if(a>='A'&&a<='Z') return a;
	if(a>='a'&&a<='z') return a-32;
}
char lower(char a){
	if(a>='a'&&a<='z') return a;
	if(a>='A'&&a<='Z') return a+32;
}
int main(){
	int t; scanf("%d",&t);
	while(t--){
		char a[100];
	    int b[100];
	    scanf("\n");
	    gets(a);
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
	    for(int i=0;i<=m;i++){
		    int n=b[i];
		    printf("%c",upper(a[n]));
		    for(int j=n+1;j<=cuoi(a,n);j++){
			    printf("%c",lower(a[j]));
		    }
		    printf(" ");
	    }
	    printf("\n");
	}
}