#include <stdio.h>
#include <string.h>

int main() {
    char participants[20][50];
    char winner[50];
    int points[20] = {0};
    int voters, n, i, temp;
   
    printf("Enter the Number of Participants: ");
    scanf("%d", &n);
   
    printf("Enter the number of voters: ");
    scanf("%d", &voters);
   
    printf("Enter the names of the participants:\n");
    for (i = 0; i < n; i++) {
        scanf("%s", participants[i]);
    }
   
    printf("Participants:\n");
    for (i = 0; i < n; i++) {
        printf("%d. %s\t\t", i + 1, participants[i]);
    }
   
    printf("\n!!Vote in accordance with the number assigned to the participants!!\n");
    for (i = 0; i < voters; i++) {
        scanf("%d", &temp);
        if (temp >= 1 && temp <= n) {
            points[temp - 1]++;
        } else {
            printf("Invalid vote! Please vote between 1 and %d.\n", n);
            i--;
        }
    }
   
    int highest = points[0];
    for (i = 1; i < n; i++) {
        if (highest < points[i]) {
            highest = points[i];
        }
    }
   
    for (i = 0; i < n; i++) {
        if (highest == points[i]) {
            strcpy(winner, participants[i]);
        }
    }
   
    printf("~~~~~~~~%s Wins~~~~~~~~\n", winner);
    return 0;
}