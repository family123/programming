#include <stdio.h>
#include <string.h>

int reverseWords(char* A) {
    // reverse whole string;
    // reverse each word
    int len = strlen(A);
    int i, ws, we,index = 0;
    char temp;
    char arr[len+1];
    printf("came here");
    for(i = 0 ; i < len ; i++) {
        while(A[i] == ' ' && i < len) 
            i++;
        while(A[i] != ' ' && i < len)
            arr[index++] = A[i++];
        arr[index++] = ' ';
    }
    arr[--index] = '\0';
    i = 0;
    printf("here");
    while(i < index){
        ws = i;
        while(arr[i] != ' ' || arr[i] != '\0') i++;
        we = i-1;
        while(ws < we)
        {
            temp = arr[ws];
            arr[ws] = arr[we];
            arr[we] = temp;
            ws++;we--;
        }
        i++;
    }
    len = index;
    i = 0;
    while(i < len)
    {
        temp = arr[i];
        arr[i] = arr[len];
        arr[len] = temp;
        i++; len--;
    }
    printf("array is: %s--\n",arr);
    return 0;
}
int main()
{
    char A[] = "the sky is blue";
    printf("returned %d\n",reverseWords(A));
    return 0;
}

