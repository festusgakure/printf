#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// Define the mygetline() function
ssize_t mygetline(char **lineptr, size_t *n, FILE *stream) {
    ssize_t read;   // The number of characters read by getline()
    size_t len = 0; // The size of the buffer allocated by getline()
    char *line = NULL; // A pointer to the buffer allocated by getline()

    // Read lines of input until there is no more input left
    while ((read = getline(&line, &len, stream)) != -1) {
        // If the buffer pointed to by *lineptr is NULL, allocate a new buffer
        if (*lineptr == NULL) {
            *lineptr = line;
            *n = len;
        }
        // If the new line is longer than the buffer size, reallocate the buffer
        else if (len > *n) {
            *lineptr = realloc(*lineptr, len);
            // If realloc() fails to allocate memory, return an error
            if (*lineptr == NULL) {
                perror("realloc");
                return -1;
            }
            // Copy the contents of the new line to the new buffer
            strcpy(*lineptr, line);
            *n = len;
        }
        // If the new line fits in the buffer, copy it to the buffer
        else {
            strcpy(*lineptr, line);
        }
        // Return the number of characters read by getline()
        return read;
    }
    // Free the buffer allocated by getline()
    free(line);
    // Return -1 to indicate that there is no more input to read
    return -1;
}

// Define the main function
int main() {
    char *line = NULL; // A pointer to the buffer used to store input lines
    size_t len = 0;    // The size of the buffer pointed to by line
    ssize_t read;      // The number of characters read by mygetline()

    // Read lines of input until there is no more input left
    while ((read = mygetline(&line, &len, stdin)) != -1) {
        // Print the line of input
        printf("Line: %s", line);
	// Print the number of characters read by mygetline()
        printf("Characters read: %zd\n", read);
    }

    // Free the buffer pointed to by line
    free(line);

    // Return 0 to indicate successful program execution
    return 0;
}

