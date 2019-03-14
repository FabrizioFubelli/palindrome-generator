/*
EXAMPLE:

SATOR
AREPO
TENET
OPERA
ROTAS
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

#define ALPHABET "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define ALPHABET_LENGTH 26
#define PALINDROME_DEFAULT "IRONX"

const char *progname;
void usage();
char **new_palindrome(char *name, unsigned int length);
void print_palindrome(char **palindrome, unsigned int length);
void free_palindrome(char **palindrome, unsigned int length);
char rand_char();
char *rand_string(unsigned int length);
unsigned int summary(unsigned int n);

/**
 * The main function
 * @param argc Count of arguments
 * @param argv Array of arguments
 * @return 0 if done, otherwise > 0
*/
int main(int argc, char* argv[]) {
    unsigned int i=0, length; char *name; char c;
    progname = argv[0];
    if (argc < 2) {
        name = PALINDROME_DEFAULT;
    } else {
        name = argv[1];
        if  (strcmp(name, "-h") == 0 || strcmp(name, "--help") == 0) {
            usage();
            return 0;
        }
        while( name[i] ) {
            c = toupper(name[i]);
            if (c < 'A' || 'Z' < c) {
                printf("Character not valid: %c\n\n", c);
                return 1;
            }
            name[i] = c; i++;
        }
    }
    length = (unsigned int) strlen(name);
    srand(time(NULL));
    char **palindrome = new_palindrome(name, length);
    printf("\nPalindrome of \"%s\":\n\n", name);
    print_palindrome(palindrome, length);
    free_palindrome(palindrome, length);   // Clear memory
    printf("\n");
}

/**
 * The usage method
 * @return void
*/
void usage() {
    printf("Usage: %s <string>\n\n", progname);
}

/**
 * Generates a new palindrome
 * @param name The starter string
 * @param length The length of the string
 * @return A new palindrome (array of string)
*/
char **new_palindrome(char *name, unsigned int length) {
    unsigned int i, j, x, y, x_last, y_last;
    char c; char **palindrome;
    // Allocate space for n string pointers (n=length)
    palindrome = (char **) malloc(sizeof(char*)*length);
    palindrome[0] = name;
    palindrome[length-1] = name;
    for (i=0; i<length; i++) {
        // Allocate space for 5 characters in each line
        palindrome[i] = malloc(sizeof(char)*length);
        for (j=0; j<length; j++) {
            // Allocate space for 5 characters in each line
            palindrome[i][j] = '_';
        }
    }
    y = 0;
    y_last = length-1;
    for (i=0; i<length; i++) {
        x_last = i;
        x = length-1-i;
        // Vertical
        palindrome[x][y] = name[x];
        palindrome[x_last][y_last] = name[x];
        // Horizontal
        palindrome[y][x] = name[x];
        palindrome[y_last][x] = name[x_last];
    }
    if (length > 2) {
        unsigned int inner_length = length-2;
        char *rand_inner = rand_string(inner_length);
        char **inner_palindrome = new_palindrome(rand_inner, inner_length);
        for (i=0; i<inner_length; i++) {
            for (j=0; j<inner_length; j++) {
                palindrome[j+1][i+1] = inner_palindrome[i][j];
            }
        }
        free_palindrome(inner_palindrome, inner_length);
        free(rand_inner);
    }
    return palindrome;
}

/**
 * Clean a palindrome from RAM
 * @param palindrome A palindrome
 * @param length The length of the palindrome's start string
 * @return void
*/
void free_palindrome(char **palindrome, unsigned int length) {
    unsigned int i;
    for (i=0; i<length; i++) {
        free(palindrome[i]);
    }
    free(palindrome);
}

/**
 * Print a palindrome
 * @param palindrome A palindrome
 * @param length The length of the palindrome's start string
 * @return void
*/
void print_palindrome(char **palindrome, unsigned int length) {
    unsigned int i;
    for (i=0; i<length; i++) {
        printf("%s\n", palindrome[i]);
    }
}

/**
 * Generate a random character
 * @return The random character
*/
char rand_char() {
    return ALPHABET[rand() % ALPHABET_LENGTH];
}

/**
 * Generate a random string
 * @param length The string length
 * @return The random string
*/
char *rand_string(unsigned int length) {
    unsigned int i;
    char *r_string = (char *) malloc(sizeof(char)*length);
    for (i=0; i<length; i++) {
        r_string[i] = rand_char();
    }
    return r_string;
}
