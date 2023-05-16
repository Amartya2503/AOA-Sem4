#include<iostream>
using namespace std;
int b[100];

void merge(int arr[], int l, int mid, int r){
    int i,j;
    i=l;
    j=mid+1;
    int index = i;
    while(i<=mid && j<r){
        if(arr[i]<arr[j]){
            cout<<"pushing : "<<arr[i]<<" in array b";
            b[index]=arr[i];
            i++;
            index++;
            
        }
        else{
            cout<<"pushing : "<<arr[j]<<" in array b";
            b[index] = arr[j];
            // swap(arr[i],arr[j])
            j++;
            index++;
        }
    }
}

void merge_sort(int arr[],int l, int r){
    if(l < r){
        int mid = (l+r)/2;
        merge_sort(arr,l,mid);
        merge_sort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }

}

int main(){
    int n;
    cout<<"enter the number of elementsin array :";
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++){
        cout<<"enter the "<<i<<"th element: ";
        cin>>arr[i];
    }
    merge_sort(arr,0,n-1);
    for(int i = 0; i<n; i++){
        cout<<"\t"<<b[i];
    }
}