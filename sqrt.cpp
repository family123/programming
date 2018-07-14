#include<stdio.h>
int Sqrt_found(int A) {
    int i;
    if(A == 2 || A == 1)
        return 1;
    if(i == 3)
        return 2;
    for(i = 2 ; i*i <= A ; i++) {
        //printf("%d",i);
    }
    printf("came here\n");
    if(i*i == A)
        return i;
    else
        return i-1;
}

int main()
{
    printf("\nSqrt : %d",Sqrt_found(50));
    return 0;
}
