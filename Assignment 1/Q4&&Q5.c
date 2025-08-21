#include<stdio.h>
void add(int r, int c,int arr1[][c],int arr2[][c]){
    int x,y;
    int sum[r][c];
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
        sum[i][j]= arr1[i][j] + arr2[i][j];  
        }
    } 
     printf("Sum of matrices:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }
    return;
}
void divide(int r, int c,int arr1[][c],int arr2[][c]){
    int x,y;
    int divide[r][c];
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
        divide[i][j]= arr1[i][j]/arr2[i][j];  
        }
    } 
     printf("Division of matrices:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", divide[i][j]);
        }
        printf("\n");
    }
    return;
}
void subtract(int r, int c,int arr1[][c],int arr2[][c]){
    int x,y;
    int subtract[r][c];
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
        subtract[i][j]= arr1[i][j] - arr2[i][j];  
        }
    } 
     printf("Subtraction of matrices:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", subtract[i][j]);
        }
        printf("\n");
    }
    return;
}


void transpose(int r,int c, int arr[][c]){
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if(arr[i][j]==arr[j][i]) continue;
            int temp=arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i]= temp;
        }   
        printf("\n");
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return;
}


void multiply(int r, int c,int arr1[][c],int arr2[][c]){
    int multiply1[r][c];
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            multiply1[i][j]=0;
            for (int k=0 ; k<r; k++){
                multiply1[i][j] += arr1[i][k] * arr2[k][j];
            }  
        }
    } 
     printf("Multiplication of matrices:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", multiply1[i][j]);
        }
        printf("\n");
    }
    return;
}

int main (){
    int r,c;
    printf("Enter the number of rows:");
    scanf("%d",&r);
    printf("Enter the number of colunms:");
    scanf("%d",&c);
    int arr1[r][c];
    printf("Enter the elements:\n");
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++)
        {
            scanf("%d",&arr1[i][j]);
        }
    }

    int arr2[r][c];
    printf("Enter the number of rows:");
    scanf("%d",&r);
    printf("Enter the number of colunms:");
    scanf("%d",&c);
    printf("Enter the elements:\n");
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++)
        {
            scanf("%d",&arr2[i][j]);
        }
    }
    multiply(r,c,arr1,arr2);
    
    
    return 0;
}