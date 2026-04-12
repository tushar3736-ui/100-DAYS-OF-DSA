// Problem Statement
// Implement a hash table using quadratic probing with formula:

// h(k, i) = (h(k) + i*i) % m

// Input Format
// Same as previous.

// Output Format
// Result of SEARCH operations.

// Sample Input
// 7
// 4
// INSERT 49
// INSERT 56
// SEARCH 49
// SEARCH 15

// Sample Output
// FOUND
// NOT FOUND

// Explanation
// Collisions resolved using i² jumps.

#include <stdio.h>
#include <string.h>

#define EMPTY -1

int main() {
    int m, q;
    scanf("%d", &m);
    scanf("%d", &q);

    int table[m];
    for(int i = 0; i < m; i++) table[i] = EMPTY;

    while(q--) {
        char op[10];
        int key;
        scanf("%s %d", op, &key);

        int h = key % m;

        if(strcmp(op, "INSERT") == 0) {
            for(int i = 0; i < m; i++) {
                int idx = (h + i*i) % m;
                if(table[idx] == EMPTY) {
                    table[idx] = key;
                    break;
                }
            }
        }
        else if(strcmp(op, "SEARCH") == 0) {
            int found = 0;
            for(int i = 0; i < m; i++) {
                int idx = (h + i*i) % m;
                if(table[idx] == EMPTY) break;
                if(table[idx] == key) {
                    found = 1;
                    break;
                }
            }
            if(found) printf("FOUND\n");
            else printf("NOT FOUND\n");
        }
    }

    return 0;
}