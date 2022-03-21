#include<stdio.h>
void printarray(int a[],int n, int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
        printf("%d ",a[i]);
    }
    printf("\n");
    }
    printf("\n");
}
int main(){
    int n,m,a[10][10];
    printf("Enter total number of rows: ");
    scanf("%d",&n);
    printf("Enter total number of columns: ");
    scanf("%d",&m);
    for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
    scanf("%d",&a[i][j]);
    }}
    printarray(a,n,m);

    return 0;
}