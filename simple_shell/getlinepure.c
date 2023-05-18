#include <stdio.h>
#include <stdlib.h>
int main() {
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    printf("Enter lines of text (press Ctrl+D to stop):\n");
    while ((nread = getline(&line, &len, stdin)) != -1) {
        printf("Read %zd characters:\n", nread);
        printf("%s", line);
    }

    free(line);
    return 0;
}

