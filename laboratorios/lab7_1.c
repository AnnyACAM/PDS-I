#include <stdio.h>
#include <string.h>

#define MAX 500

int main() {
    
    char S1[MAX], S2[MAX];
    
    scanf("%s", S1);
    scanf("%s", S2);

    strcat(S1, S2);
    
    printf("%s", S1);
    
    return 0;
}
