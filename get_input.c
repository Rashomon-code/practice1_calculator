#include "get_input.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <stdlib.h>

int get_num(double *num){
    char buffer[MAX_LEN];
    char *endptr;

    for(;;){
        if(fgets(buffer, MAX_LEN, stdin) == NULL){
            return 1;
        }

        if(strchr(buffer, '\n') == 0){
            puts("Out of range.");
            continue;
        }
        buffer[strcspn(buffer, "\n")] = '\0';

        char *startptr = buffer;
        while(isspace((unsigned char)*startptr)){
            startptr++;
        }
        if(*startptr == '\0' || *startptr == '\n'){
            puts("Empty input.");
            continue;
        }

        errno = 0;
        double n = strtod(startptr, &endptr);

        if(errno == ERANGE){
            puts("The number you entered is outside the valid range.");
            continue;
        }

        while(isspace((const char)*endptr)){
            endptr++;
        }

        if(*endptr != '\0'){
            puts("Invalid input.");
            continue;
        }

        if(num != NULL){
            *num = n;
        }

        return 0;
    }
}