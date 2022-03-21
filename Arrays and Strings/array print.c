#include<stdio.h>
void printarray(int a[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}
int main(){
    int n,a[10];
    printf("Enter total number of elements:  ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    printarray(a,n);
    return 0;
}