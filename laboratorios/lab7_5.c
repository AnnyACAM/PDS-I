#include <stdio.h>
#include <string.h>

#define MAX 500


int main() {
    
    char string[MAX], caracter;
    
    scanf("%s", string);
    scanf(" %c", &caracter);

    int tam = strlen(string);
    int quantd = 0;
    
    for(int i = 0; i < tam; i++){
        if(string[i] == caracter){
            quantd+= 1;
        }
    }
    
    printf("%d", quantd);
    
    return 0;
}
