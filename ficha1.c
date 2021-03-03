#include <stdio.h>
#include <assert.h>

int main(){
    int a, b;
    assert(scanf("%d %d", &a, &b) == 2);
    a = a*a; b = b*b;
    printf("%d\n", a+b);
    return 0;
}