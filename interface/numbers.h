/* Numbers manipulating functions */

#pragma once

#include <stdio.h>
#include <stdint.h>

#include "system.h"
#include "io.h"
#include "locale.h"


/* STRUCTURES */

/* Natural number */

typedef struct {
    
    signed char *digits;
    size_t length;
    size_t offset_digits;       /* Service */
    size_t offset_struct;       /* Service */
    
} natural;


/* Integer number */

typedef struct {
    
    signed char *digits;
    size_t length;
    size_t offset_digits;       /* Service */
    size_t offset_struct;       /* Service */
    bool sign;
    
} integer;



/* FUNCTIONS */

int read_int(char *message);							/* Read from stdin */

void write_int(int n);									/* Write to stdout */

void write_bool(bool value);							/* Write to stdout */


/* Natural numbers */

natural *init_natural(size_t length);                   /* Initialize */

void resize_natural(natural *N, size_t new_length);     /* Resize */

void free_natural(natural *N);                          /* Remove from memory */

natural *read_natural(char *message);                   /* Read from stdin */

void write_natural(natural *N);                         /* Write to stdout */


/* Integer numbers */

integer *init_integer(size_t length);                   /* Initialize */

void resize_integer(integer *N, size_t new_length);     /* Resize */

void free_integer(integer *N);                          /* Remove from memory */

integer *read_integer(char *message);                   /* Read from stdin */

void write_integer(integer *N);                         /* Write to stdout */



/* FUNCTIONS IMPLEMENTATIONS */


int read_int(char *message) {
	
    int result = 0;
    bool success = false;
	bool sign = true;
    
    while(success == false) {
        
        success = true;
        
        print(message);
        
        char current = skip_spaces();   /* Reading first non-space symbol */
        
        if(current == '-') {
            
            sign = false;
            current = skip_spaces();
        }
        
        while(!feof(stdin) && current != '\n') {
            
            if(isdigit(current) && result <= 100000000) {
                
                result *= 10;
                result += current - '0';
                current = getchar();
                
            } else if(current == ' ') {
                
                current = getchar();
                
            } else {
                
                /* Unexpected symbol */
                
                success = false;
                print(UNEXP_SYMBOL "\n\n");
                
                while(!feof(stdin) && current != '\n') current = getchar();
            }
        }
        
        if(feof(stdin)) terminate(RCODE_EOF);
    }
    
    if(sign == false) result = -result;
    
    return result;
}


void write_int(int n) {
	
	printf("%d\n", n);
}

void write_bool(bool value) {
	
	if(value == true)
		printf(TRUE "\n");
	else
		printf(FALSE "\n");
}


natural *init_natural(size_t length) {
    
    size_t offset;
    
    natural *N = mallocate(sizeof(*N), &offset);
    
    N -> offset_struct = offset;
    
    N -> digits = mallocate(length * sizeof(*(N -> digits)), &offset);
    
    N -> offset_digits = offset;
    
    N -> length = length;
    
    return N;
}


void resize_natural(natural *N, size_t new_length) {
    
    N -> digits = reallocate(N -> digits, new_length * sizeof(*(N -> digits)), N -> offset_digits);
}


void free_natural(natural *N) {
    
    free_logged(N -> digits, N -> offset_digits);
    
    free_logged(N, N -> offset_struct);
}


natural *read_natural(char *message) {
    
    /* Reading number to string */
    
    size_t offset;
    
    size_t str_size = 2;
    size_t str_offset = 0;
    
    bool success = false;
    
    char *str = mallocate(2 * sizeof(*str), &offset);
    
    while(success == false) {
        
        success = true;
        
        print(message);
        
        char current = skip_spaces();   /* Reading first non-space symbol */
        
        while(!feof(stdin) && current != '\n') {
            
            if(isdigit(current)) {
                
                if(str_offset == str_size) {
                    
                    str_size *= 2;
                    str = reallocate(str, str_size * sizeof(*str), offset);
                }
                
                str[str_offset++] = current;
                
                current = getchar();
                
            } else if(current == ' ') {
                
                current = getchar();
                
            } else {
                
                /* Unexpected symbol */
                
                success = false;
                
                print(UNEXP_SYMBOL "\n\n");
                
                str_offset = 0;
                
                while(!feof(stdin) && current != '\n') current = getchar();
            }
        }
        
        if(feof(stdin)) terminate(RCODE_EOF);
    }
    
    /* Initializing number */
    
    natural *result = init_natural(str_offset);
    
    /* Copying */
    
    size_t j = 0;
    
    for(size_t i = str_offset - 1; i != SIZE_MAX; --i)
        result -> digits[j++] = str[i] - '0';
    
    free_logged(str, offset);
    
    return result;
}


void write_natural(natural *N) {
    
    for(size_t i = N -> length - 1; i != SIZE_MAX; --i)
        putchar(N -> digits[i] + '0');
    
    putchar('\n');
}


integer *init_integer(size_t length) {
    
    size_t offset;
    
    integer *N = mallocate(sizeof(*N), &offset);
    
    N -> offset_struct = offset;
    
    N -> digits = mallocate(length * sizeof(*(N -> digits)), &offset);
    
    N -> offset_digits = offset;
    
    N -> length = length;
    
    return N;
}


void resize_integer(integer *N, size_t new_length) {
    
    N -> digits = reallocate(N -> digits, new_length * sizeof(*(N -> digits)), N -> offset_digits);
}


void free_integer(integer *N) {
    
    free_logged(N -> digits, N -> offset_digits);
    
    free_logged(N, N -> offset_struct);
}


integer *read_integer(char *message) {
    
    /* Reading number to string */
    
    size_t offset;
    
    size_t str_size = 2;
    size_t str_offset = 0;
    bool sign = true;
    
    bool success = false;
    
    char *str = mallocate(2 * sizeof(*str), &offset);
    
    while(success == false) {
        
        success = true;
        
        print(message);
        
        char current = skip_spaces();   /* Reading first non-space symbol */
        
        if(current == '-') {
            
            sign = false;
            current = skip_spaces();
        }
        
        while(!feof(stdin) && current != '\n') {
            
            if(isdigit(current)) {
                
                if(str_offset == str_size) {
                    
                    str_size *= 2;
                    str = reallocate(str, str_size * sizeof(*str), offset);
                }
                
                str[str_offset++] = current;
                
                current = getchar();
                
            } else if(current == ' ') {
                
                current = getchar();
                
            } else {
                
                /* Unexpected symbol */
                
                success = false;
                
                print(UNEXP_SYMBOL "\n\n");
                
                str_offset = 0;
                
                while(!feof(stdin) && current != '\n') current = getchar();
            }
        }
        
        if(feof(stdin)) terminate(RCODE_EOF);
    }
    
    /* Initializing number */
    
    integer *result = init_integer(str_offset);
    
    result -> sign = sign;
    
    /* Copying */
    
    size_t j = 0;
    
    for(size_t i = str_offset - 1; i != SIZE_MAX; --i)
        result -> digits[j++] = str[i] - '0';
    
    free_logged(str, offset);
    
    return result;
}


void write_integer(integer *N) {
    
    if(N -> sign == false) putchar('-');
    
    for(size_t i = N -> length - 1; i != SIZE_MAX; --i)
        putchar(N -> digits[i] + '0');
    
    putchar('\n');
}