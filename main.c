#include <stdio.h>
#include "calculator.h"
#include "get_input.h"

int main(void){
    double num1, num2, result;

    for(;;){
        int check;
        check = get_num(&num1);
        printf("%f", num1);
    }
    
    return 0;
}