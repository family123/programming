#include <iostream>
#include <vector>

using namespace std;


int main(){
	int tc;
	cin>>tc;

	while(tc--){
		int size;
		cin>>size;
		vector<int> arr(size);
		for(int i=0;i<size;i++)
			cin>>arr[i];
        
		int ele;
		cin>>ele;
		int index = -1;
		int low = 0;
        int high = size-1;
        while(low <= high) {
            int mid = (low+high)/2;
            if(arr[mid] == ele) {
                index = mid;
                break;
            }
            else if(arr[low] < arr[mid]) { // start array sorted
                if(ele >= arr[low] && ele < arr[mid])
                    high = mid-1;
                else
                    low = mid+1;
            }
            else {//if(arr[mid] < arr[high]) { // last array sorted
                if(ele <= arr[high] && ele > arr[mid])
                    low = mid+1;
                else
                    high = mid-1;
            }
        }
	    cout<<index<<endl;
	}
return 0;
}
