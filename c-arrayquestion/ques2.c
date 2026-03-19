//Find the sum of array elements.
#include<stdio.h>
int main(){
    int n, sum =0;
    printf(" enter the size of array:");
    scanf("%d", &n);
    int arr[n];
    printf(" enter the elements of array:");
    for( int i=1; i <= n; i++){
        scanf("%d", &arr[i]);
    }
    for( int i =1; i<=n; i++ ){
        sum = sum +arr[i];
    }
    printf(" the sum of elements of array is: %d\n", sum);
    return 0;
}