#include <stdio.h>
#include <string.h>

void convertDateFormat(char *date) {
    char day[3], month[3], year[5];
    
    // Extract day, month, and year using sscanf
    sscanf(date, "%2s/%2s/%4s", day, month, year);

    // Check if month is "04"
    if (strcmp(month, "04") == 0) {
        printf("%s-Apr-%s\n", day, year);
    } else {
        printf("Month is not April. No conversion applied.\n");
    }
}

int main() {
    char date[20];
    printf("Enter date in dd/mm/yyyy format: ");
    scanf("%s", date);

    convertDateFormat(date);
    return 0;
}