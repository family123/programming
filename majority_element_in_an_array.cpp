#include <iostream>

using namespace std;

bool majority_ele(int arr[], int size, int &num) {
    num = arr[0];
    int count = 1;
    for(int i = 1 ; i < size ; i++) {
        if(num == arr[i]) {
            count++;
        }
        else {
            count--;
            if(0 == count) {
                num = arr[i];
                count = 1;
            }
        }
    }
    count = 0;
    for(int i = 0 ; i < size ; i++) {
        if(num==arr[i])
            count++;
    }
    if(count >= ((size/2) + 1) )
        return true;

    return false;
}

int main(){
	int tc;
	cin>>tc;
	while(tc--){
		int size;
		cin>>size;
		int *arr=new int[size];
		for(int i=0;i<size;i++)
			cin>>arr[i];
		int num;
		if(majority_ele(arr,size, num))
		    cout<< num <<endl;
	    else
	        cout <<"NO Majority Element" <<endl;
	}
return 0;
}
