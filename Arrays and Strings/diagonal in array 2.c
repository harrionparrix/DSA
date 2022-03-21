#include<stdio.h>
void diagonal(int a[10][10],int n){
  for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>=i;j--){
        printf("%d ",a[i][j]);
    }
    printf("\n");
    
}
    
}
int main(){
    int n,a[10][10];
    printf("Enter total number of rows and columns: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
    scanf("%d",&a[i][j]);
    }}
    diagonal(a,n);
    return 0;
}