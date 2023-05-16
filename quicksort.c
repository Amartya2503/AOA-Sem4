#include<stdio.h>

#define MAX 100

void quicksort(int arr[MAX], int left, int right){
    int i,j,pivot,temp;

    i=left;
    j= right;
    pivot = left;

    if( left < right){

        while(i < j){

            while(arr[i] <= arr[pivot] ){
                i++;
            }

            while(arr[j] > arr[pivot]){
                j--;
            }

            if(i < j){
                temp = arr[i];
                arr[i]= arr[j];
                arr[j] = temp;
            }
        }
        
        temp = arr[pivot];
        arr[pivot] = arr[j];
        arr[j] = temp;

        quicksort(arr , left , j-1);
        quicksort(arr , j+1 , right);
    }

}

void main(){
    int n ,i;
    int arr[MAX];
    printf("enter the nunber of elements in the array: ");
    scanf("%d", &n);
    printf("enter the elements one by one \n");
    for(i=0 ; i<n ; i++){
        scanf("%d",&arr[i]);
    } 
    quicksort(arr,0,n-1);
    for(i=0; i<n ; i++){
        printf("%d\t",arr[i]);
    }
}
