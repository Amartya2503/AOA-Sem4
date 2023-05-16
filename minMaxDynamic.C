#include<stdio.h>
#include<stdlib.h>

#define MAX 100

struct holder{
    int min;
    int max;
};

struct holder minMaxfinder(int arr[MAX],int left , int right){
    int mid;
    struct holder minmax,mml,mmr;

    if(left == right ){
        minmax.min = arr[left];
        minmax.max = arr[left];
    }

    else if(left == right-1){
        if(arr[left] > arr[right]){
            minmax.min = arr[left];
            minmax.max = arr[right];
        }
        else{
            minmax.max = arr[right];
            minmax.min = arr[left];
        }

    }
    else{

        mid = (left+right)/2;
        mml = minMaxfinder(arr,left,mid);
        mmr = minMaxfinder(arr,mid+1 , right);
        if(mml.max >= mmr.max ){
            minmax.max = mml.max;
        }
        else{
            minmax.max = mmr.max;
        }
        if( mml.min <= mmr.min ){
            minmax.min = mml.min;
        }
        else{
            minmax.min = mmr.min;
        }
    }

    return minmax;
}

void main(){
    int i,n,arr[MAX];
    struct holder minmax;
    printf("enter then number of elements in array ");
    scanf("%d",&n);

    printf("enter the elements of array :\n");
    for(i= 0 ; i<n ; i++){
        scanf("%d",&arr[i]);
    }
    printf("finding min max with dynamic programming");
    minmax = minMaxfinder(arr,0,n-1);

    printf("the min val is : %d\nthe max val is: %d",minmax.min,minmax.max);

}