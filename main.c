#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define SIZE 40
#define PALINDROME_DEFAULT "IRONX"

const char *progname;
void usage();
char **new_palindrome(char *name, unsigned int length);
void print_palindrome(char **palindrome, unsigned int length);

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
    char **palindrome = new_palindrome(name, length);
    printf("\nPalindrome of \"%s\":\n\n", name);
    print_palindrome(palindrome, length);
    free(palindrome);   // Clear memory
}

void usage() {
    printf("Usage: %s <string>\n\n", progname);
}

char **new_palindrome(char *name, unsigned int length) {
    unsigned int i;
    // Allocate space for n string pointers (n=length)
    char **palindrome_array = (char **) malloc(sizeof(char*)*length);
    palindrome_array[0] = name;
    palindrome_array[length-1] = name;
    for (i=0; i<length; i++) {

    }
    return palindrome_array;
}

void print_palindrome(char **palindrome, unsigned int length) {
    unsigned int i;
    for (i=0; i<length; i++) {
        printf("%s\n", palindrome[i]);
    }
}
