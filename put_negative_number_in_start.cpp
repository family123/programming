#include<stdio.h>
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int arr[] = {1, -1, 3, 5, -6, 7, 8, 9, -2, -3, -4, -5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int neg = 0;
    for(int i = 0 ; i < n ; i ++) {
        if( arr[i] < 0) {
            swap(arr[neg], arr[i]);
            neg++;
        }
    }
    for(int i = 0 ; i < n; i++) {
        printf("%d\t",arr[i]);
    }
    return 0;
}
