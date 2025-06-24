#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
struct thisinh{
	char ten[50];
	char ngaysinh[50];
	float mon1, mon2, mon3;
	float tong;
	int stt;
};
typedef struct thisinh HS;
void nhap(HS a[],int n){
	for(int i=0;i<n;i++){
		getchar();
		gets(a[i].ten);
	    gets(a[i].ngaysinh);
	    scanf("%f%f%f",&a[i].mon1,&a[i].mon2,&a[i].mon3);
	}
}
void in(HS a){
	printf("%d %s %s %.1f\n",a.stt,a.ten,a.ngaysinh,a.tong);
}
void sx(HS a[], int n){
	for(int i=0;i<n;i++){
		int max=i;
		for(int j=i+1;j<n;j++){
			if(a[j].tong>a[max].tong){
				max=j;
			}
		}
		HS temp=a[i];
		a[i]=a[max];
		a[max]=temp;
	}
}
int main(){
	int n; scanf("%d",&n);
	HS a[n];
	nhap(a,n);
	for(int i=0;i<n;i++){
		a[i].tong=a[i].mon1+a[i].mon2+a[i].mon3;
		a[i].stt=i+1;
	}
	sx(a,n);
	for(int i=0;i<n;i++){
		in(a[i]);
	}
}