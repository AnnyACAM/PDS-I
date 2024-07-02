#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int palindromo(char* string){
    int tam = strlen(string), j = 0;
    char aux[MAX];
    
    for(int i = 0; i < tam; i++){
        string[i] = toupper(string[i]);
        
        if((string[i] >= 'A')||(string[i] <= 'Z')){
            aux[j] = string[i];
            j++;
        }
    }
    
    aux[j+1] = '\0';
    strcpy(string, aux);
    
    j = tam;
    for(int i = 0; i < tam; i++){
        j--;
        if(!(string[i] == aux[j])){
            return 0;
        }else{
            return 1;
        }
    }
}

int main()
{
    char string[MAX];
    strcpy(string, "Anotaram a data da maratona");
    
    printf("%d", palindromo(string));

    return 0;
}
