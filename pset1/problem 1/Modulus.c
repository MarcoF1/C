#include <stdio.h>

int main() {

    int N, m, M;
    scanf("%d %d %d", &N, &m, &M);  
    printf("%d %d %d\n", N, m, M);

    int num;
    for(int i = 0; i < N; i++) {
        scanf("%d", &num);  
        printf("%d\n", num);
    }

    return 0;
}