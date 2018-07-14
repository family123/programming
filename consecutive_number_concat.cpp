#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

void function(int arr[], int n) {
    string str = "";
    for(int i= 0 ; i < n ;) {
        int j = i;
        int num = arr[i];
        int inc = 0;
        int count = 0;
        while(arr[i] == num && i < n) {
            count++;
            i++;
            num++;
        }
        if(count < 3) {
            while( j < i) {
                str = str+to_string(arr[j])+",";
                j++;
            }
        }
        else {
            str = str+to_string(arr[j])+"-"+to_string(arr[i-1])+",";
        }
    }
    if(str[str.length()-1] == ',') {
        std::string str2 = str.substr(0,str.length()-1);
        cout << str2;
    }
    else
        cout << str;
}

int main() {
    int arr[] = {2,3,4,5,6,7,8,9,11,13};
    int n = sizeof(arr)/sizeof(arr[0]);
    function(arr,n);
}
