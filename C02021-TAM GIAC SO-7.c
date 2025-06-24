#include <stdio.h>
int main(){
    int n; scanf("%d",&n);
    printf("1\n");
    for(int i=2;i<=n;i++){
        if(i%2==0){
            for(int j=i*(i+1)/2;j>=i*(i+1)/2-i+1;j--){
                printf("%d ",j);
            }
        }
        if(i%2!=0){
            for(int k=(i-1)*i/2+1;k<=(i-1)*i/2+i;k++){
                printf("%d ",k);
            }
        }
        printf("\n");
    }
}