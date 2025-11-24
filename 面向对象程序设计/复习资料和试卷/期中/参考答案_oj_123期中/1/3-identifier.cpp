
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isValidIdentifier(char *identifier) {
    
    if (!isalpha(identifier[0]) && identifier[0] != '_') {
        return 0;
    }

    
    for (int i = 1; i < strlen(identifier); i++) {
        
        if (!isalnum(identifier[i]) && identifier[i] != '_') {
            return 0;
        }
    }

    
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char identifier[101]; 
        scanf("%s", identifier);
        if (isValidIdentifier(identifier)) {
            printf("Great\n");
        } else {
            printf("Bad\n");
        }
    }

    return 0;
}