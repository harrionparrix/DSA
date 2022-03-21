#include<stdio.h>
void printarray(int a[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}
void kadane(int a[],int n){
    int max=0;
    int current=0;
    int count=0;
    for(int i=0;i<n;i++){
        current+=a[i];
        if(current>max)
            max=current;
        if(max<0)
            max=0;
    }
    for(int i=0;i<n;i++){
        if(a[i]<0)
        count+=1;
    }
    if(count==n){
        max=a[0];
        for(int i=0;i<n;i++){
            if(a[i]>max)
            max=a[i];
        }
    }
    printf("%d",max);
}
int main(){
    int n,a[10];
    printf("Enter total number of elements:  ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    printarray(a,n);
    kadane(a,n);
    return 0;
}