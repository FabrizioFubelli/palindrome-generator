#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <string>\n\n", argv[0]);
        return 1;
    }
    char *palindrome_of = argv[1];
    printf("Palindrome of \"%s\":\n\n", palindrome_of);
}
