#include <stdio.h>
#include <string.h>

#define MAX 500

int main() {
    
    char string[MAX], substring[MAX];
    
    scanf("%s", string);
    scanf("%s", substring);
    
    char *ponteiro = strstr(string, substring);
    
    if(ponteiro != NULL){
        printf("É substring");
    }else{
        printf("Não é substring");
    }
 
    
    return 0;
}
