// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int top=0;
int arr2[3];

int linear1_search(int arr[],int n,int val) {


    
    int len = sizeof(arr)/sizeof(arr[0]);

    std::cout << "SIZE:" <<  len << std::endl;
    for(int i=0;i<n; i++){
        if(arr[i]==val){
            //cout<<i<<endl;
            return i;
    
        }

        }
        
        return 0;
        
}




int main() {
   int arr[]= {1,2,2,4, 4};
   int n = sizeof(arr)/sizeof(arr[0]);
   cout<<"The value is present at index"<<endl;
  cout << linear1_search(arr,n,4);

  cout<<"----------------------------"<<endl;

}