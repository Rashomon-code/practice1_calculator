#include <stdio.h>
#include "calculator.h"
#include "get_input.h"

int main(void){
    double num1, num2, result;
    char operator;

    for(;;){
        int check = 0;
        check = get_num(&num1);
        if(check == 1){
            puts("Error.");
            return 1;
        }

        operator = get_operator();
        if(operator == '\0'){
            puts("Error.");
            return 1;
        }

        check = get_num(&num2);
        if(check == 1){
            puts("Error.");
            return 1;
        }
    }
    
    return 0;
}