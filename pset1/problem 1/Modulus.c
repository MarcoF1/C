#include <stdio.h>
// #include <stdlib.h>

int main() {

    int N, m, M;
    // scan N, m, and M
    scanf("%d %d %d", &N, &m, &M);  

    int congruentCount = 0;
    int num;
    int remainder;
    // count how many inputs ar congruent to m mod M
    for(int i = 0; i < N; i++) {
        scanf("%d", &num);  
        remainder = m-num % M;

        if (remainder == 0) {
            congruentCount++;
        }
    }

    printf("%d", congruentCount);
    return 0;
}