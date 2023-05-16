#include<stdio.h>
// #include<conio.h>
#include<stdlib.h>

#define ARRAY_SIZE(a) sizeof(a)/aizeof(a[0])

void findMinMax(int arr[],int n ){
    int i,j;
    int min = arr[0],max=arr[0];
    for(i=0;i<n;i++){
        if(arr[i]<min){
            min = arr[i];
        }
        if(arr[i]>max){
            max = arr[i];
        }
    }
    printf("min value : %d\tmax value is : %d\n",min,max);
}

void main(){
    int i,n,arr[100];
    printf("enter the number of elements: ");
    scanf("%d",&n);
    printf("enter the elements one by one : \n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    findMinMax(arr,n);

}