 //Print a pattern of numbers from 1 to n as shown below. Each of the numbers is separated by a single space//.
 
 #include <stdio.h>
int main() {
    int rows;
    printf("enter no.of rows:");
    scanf("%d",&rows);
    for (int i =1; i <=rows; i++) {
        int count = rows - i + 1;
               for (int j = 1; j <= count; j++) {
            printf("%d ", j);
        }
               if (i > 1) {
            for (int k = 1; k <= 2 * i-3; k++) {
                printf("  ");
            }
        }
               for (int j = count; j>= 1; j--) {
                   if (j == rows) continue;
            printf("%d ", j);
        }
        printf("\n");
    }
    return 0;
}
