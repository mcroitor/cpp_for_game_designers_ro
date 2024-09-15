#include <cstdio>

// int main(int argc, char **argv)
int main(int argc, char *argv[]) {
    printf("total arguments: %d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("argument %d: %s\n", i, argv[i]);
    }

    return 0;
}