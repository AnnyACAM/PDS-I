#include <stdio.h>

int EPrimo(int num){
    
    if(num <= 1){
        return 0;
    }

    for(int n = 1; n < num; n++){
        if(n != 1 && num  % n == 0 && n != num){
            return 0;
        }
    }

    return 1;

}

void primos(int m, int *p1, int *p2){

    int num = m;
    
    *p1 = num - 1;
    while(EPrimo(*p1) != 1 && *p1 > 1){
        *p1 -= 1;
    }

    *p2 = num + 1;
    while(EPrimo(*p2) != 1 && *p2 > 1){
        *p2 += 1;
    }
    
}

int main(){

    int num, p1, p2;
    scanf("%d", &num);

    primos(num, &p1, &p2);

    printf("%d\n%d", p1, p2);
    return 0;
}