
#include <stdio.h>

int N;
int M;
int TotalSize;

typedef struct Point
{
    int x;
    int y;
} Point;

int getPoint(int N, int M, char field[N][M], Point point) {
    // destructure point
    int x = point.x;
    int y = point.y;
    
    // return 0 for out of bounds
    if (x >= N || x < 0 || y >= M || y < 0) {
        return 0;
    }
    // get value
    char fieldValue = field[x][y];
    return fieldValue == '.' ? 0 : 1;
}

int checkAdjacent(int N, int M, char field[N][M], Point point, int checked[N][M], int adjacent[N][M], int depth[N][M]) {
    Point newPoint;
    newPoint.x = point.x;
    newPoint.y = point.y;
    int total = 0;

    for(int i = -1; i < 2; i++) {
        newPoint.x = point.x + i;
        for(int j = -1; j < 2; j++) {
            newPoint.y = point.y + j;
            if(!checked[newPoint.x][newPoint.y]) {
                int value = getPoint(N, M, field, newPoint);
                checked[newPoint.x][newPoint.y] = 1;
                adjacent[newPoint.x][newPoint.y] = value;
                total+=value;
            }
            if(checked[newPoint.x][newPoint.y] && adjacent[newPoint.x][newPoint.y] && !depth[newPoint.x][newPoint.y]) {
                depth[newPoint.x][newPoint.y] = 1;
                total+=checkAdjacent(N, M, field, newPoint, checked, adjacent, depth);
                
            }
        }
    }

    return total;
}

int main() {
    // read bessies field size
    scanf("%d %d", &N, &M);
    
    // declare field size information
    TotalSize = N*M;
    char field[N][M];
    Point shelter;
    int found = 0;

    // scan bessies field
    for (int i = 0; i < N; i++) {
        scanf("%s", field[i]);

        //look for shelter if not found yet
        if (found == 0){
            for(int j = 0; j < M; j++){
                if(field[i][j] == '*') {
                    shelter.x = i;
                    shelter.y = j;
                    found = 1;
                }
            }
        }
        // printf("%s\n", field[i]);
    }
    
    Point point;
    point.y = shelter.y;
    point.x = shelter.x;

    // initialize empty checked array
    int checked[N][M];
    int adjacent[N][M];
    int depth[N][M];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            checked[i][j] = 0;
            adjacent[i][j] = 0;
            depth[i][j] = 0;
        }
    }

    printf("%d\n", checkAdjacent(N, M, field, shelter, checked, adjacent, depth));
}



