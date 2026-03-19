

#include <stdio.h>
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int cost_green, cost_purple;
        scanf("%d %d", &cost_green, &cost_purple);

        int n;
        scanf("%d", &n);

        int solved_first = 0, solved_second = 0;
        for (int i = 0; i < n; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            if (a) solved_first++;
            if (b) solved_second++;
        }

        // Option 1: green for first, purple for second
        int cost1 = solved_first * cost_green + solved_second * cost_purple;
        // Option 2: purple for first, green for second
        int cost2 = solved_first * cost_purple + solved_second * cost_green;

        int min_cost = cost1 < cost2 ? cost1 : cost2;
        printf("%d\n", min_cost);
    }
    return 0;
}