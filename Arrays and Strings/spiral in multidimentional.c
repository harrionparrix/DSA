#include<stdio.h>
void printarray(int a[10][10],int n, int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
        printf("%d ",a[i][j]);
    }
    printf("\n");
    }
    printf("\n");
}
void spiral(int a[10][10],int n, int m){
    int top=0;
    int down=n-1;
    int right=n-1;
    int left=0;
    int dir=0; //0=right,1=down,2=left,3=right
    while(top<=down && left<=right){
        if(dir==0){
            for(int i=left;i<=right;i++){
                printf("%d ",a[top][i]);
            }
        top+=1;
        }
        else if(dir==1){
            for(int i=top;i<=down;i++){
                printf("%d ",a[i][right]);
            }
        right-=1;
        }
        else if(dir==2){
            for(int i=right;i>=left;i--){
                printf("%d ",a[down][i]);
            }
        down-=1;
        }
        else if(dir==3){
            for(int i=down;i>=top;i--){
                printf("%d ",a[i][left]);
            }
        left+=1;
        }
        dir=(dir+1)%4;
    }
    
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
    spiral(a,n,m);
    
    return 0;
}
