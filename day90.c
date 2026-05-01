#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int isPossible(int boards[], int n, int k, int mid) {
    int painters = 1;
    int total = 0;

    for(int i = 0; i < n; i++) {
        total += boards[i];
        if(total > mid) {
            painters++;
            total = boards[i];
            if(painters > k) return 0;
        }
    }
    return 1;
}

int minTime(int boards[], int n, int k) {
    int low = 0, high = 0, ans = 0;

    for(int i = 0; i < n; i++) {
        high += boards[i];
        low = max(low, boards[i]);
    }

    while(low <= high) {
        int mid = (low + high) / 2;
        if(isPossible(boards, n, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int boards[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
    }

    printf("%d\n", minTime(boards, n, k));
    return 0;
}