
#include <stdio.h>

#define SIZE 10

int parent[SIZE];
int rank[SIZE];

// Initialize sets
void initialize() {
    for (int i = 0; i < SIZE; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

// Find with path compression
int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

// Union by rank
void unionSet(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);

    if (rootA == rootB) {
        printf("Already in the same set.\n");
        return;
    }

    if (rank[rootA] < rank[rootB]) {
        parent[rootA] = rootB;
    } else if (rank[rootA] > rank[rootB]) {
        parent[rootB] = rootA;
    } else {
        parent[rootB] = rootA;
        rank[rootA]++;
    }

    printf("Union successful.\n");
}

// Check connectivity
void connected(int a, int b) {
    if (find(a) == find(b)) {
        printf("%d and %d are connected.\n", a, b);
    } else {
        printf("%d and %d are not connected.\n", a, b);
    }
}

int main() {
    int choice, a, b;

    initialize();

    while (1) {
        printf("\n--- Disjoint Set Union ---\n");
        printf("1. Union\n");
        printf("2. Check Connection\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter two elements (0-9): ");
                scanf("%d%d", &a, &b);

                if (a < 0 || a >= SIZE ||
                    b < 0 || b >= SIZE) {
                    printf("Invalid elements!\n");
                    break;
                }

                unionSet(a, b);
                break;

            case 2:
                printf("Enter two elements (0-9): ");
                scanf("%d%d", &a, &b);

                if (a < 0 || a >= SIZE ||
                    b < 0 || b >= SIZE) {
                    printf("Invalid elements!\n");
                    break;
                }

                connected(a, b);
                break;

            case 3:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
