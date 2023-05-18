#include<iostream>
using namespace std;
#include<ctime>


void swap(int *a, int *b){
    int temp;
    temp  = *a;
    *a = *b;
    *b = temp;
}
void selectionsort(int arr[], int n){
    int i=0,j,min;

    
    for(int i =0;i<n ; i++){
        min = i;

        for(j=i+1; j<n; j++){
            
            if(arr[min]>arr[j]){
    
                min = j;
            }
                
            
        }
        swap(arr[i],arr[min]);
    }
}
void print(int arr[],int n){
    for(int i = 0; i<n; i++){
        cout<<"\t"<<arr[i];
    }
}

int main(){
    int n ;
    clock_t start_t,end_t; 
    cout<<"enter the number of elements in array :";
    cin>>n;
    int arr[n];

    for(int i =0; i<n; i++){
        cout<<"enter the "<<i<<"th element: ";
        cin>>arr[i];
    }
    start_t = clock();
    selectionsort(arr,n);
    end_t = clock();
    print(arr,n);
    cout<<"\n Time required for this case is :"<<end_t - start_t;
}
