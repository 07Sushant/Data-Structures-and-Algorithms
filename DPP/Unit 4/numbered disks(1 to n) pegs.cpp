#include <stdio.h>

int countMoves(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return 1;
    }
    
    int moves = 0;
    moves += countMoves(n - 1, source, destination, auxiliary);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    moves += countMoves(n - 1, auxiliary, source, destination);
    
    return moves + 1;
}

int main() {
    int n;
    scanf("%d", &n);
    char source = 'A';
    char auxiliary = 'B';
    char destination = 'C';
    
    int totalMoves = countMoves(n, source, auxiliary, destination);
    
    printf("Total number of moves: %d\n", totalMoves);
    
    return 0;
}

