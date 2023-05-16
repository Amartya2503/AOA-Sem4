#include<iostream>
using namespace std;
#include<ctime>


int main(){
    int n;
    clock_t start_t,end_t;
    cout<<"enter the no of el in array: ";
    cin>>n;
    int arr[n];
    for(int i =1; i<=n ; i++){
        cout<<"enter the "<<i<<"th element : ";
        cin>>arr[i];
    }
    cout<<"original array : "<<endl;
    for(int i = 1; i<=n ; i++){
        cout<<"\t"<<arr[i];
    }
    int j;
    start_t = clock();
    for(int i = 1;i <=n; i++){
        j = i;
        while(j>=0 && arr[j]<arr[j-1]){
            cout<<"\t shifting "<<arr[j]<<"\n";
            swap(arr[j],arr[j-1]);
            
            j-=1;
        }
    }
    end_t = clock();
    cout<<"\t"<< end_t - start_t<<" is the time required to sort";

    cout<<"\nsorted array is : "<<endl;
    for(int i =1; i<=n; i++){
        cout<<"\t"<<arr[i];
    }
}
