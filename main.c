#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 40
#define PALINDROME_DEFAULT "IRONX"

const char *progname;
void usage();

int main(int argc, char* argv[]) {
    unsigned int i=0, length; char *name;
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
            const char c = toupper(name[i]);
            if (c < 'A' || 'Z' < c) {
                printf("Character not valid: %c\n", c);
                return 1;
            }
            name[i] = c; i++;
        }
    }
    length = (unsigned int) strlen(name);
    printf("Palindrome of \"%s\" (length=%u):\n\n", name, length);
}

void usage() {
    printf("Usage: %s <string>\n\n", progname);
}
