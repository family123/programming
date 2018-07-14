#include<stdio.h>
#include<math.h>


int fun(char *arr){
    int len = 0, i =0, j = 1, ans = 0, power;
    while(arr[i] != '\0') {
        len++;
        i++;
    }
    while(j < len) {
        ans = ans + pow(26, j);
        j++;
    }
    for ( i = 0, power = len - 1 ; i < len-1  ; i++, power--) {
        ans +=(arr[i] - 'A' )*pow(26,power);
    }
    ans +=arr[i] - 'A' + 1;
    return ans;

}

int main(int argc, char *argv[]) {
    char arr[] = "AAA";
    printf("%d",fun(arr));
    return 0;
}
