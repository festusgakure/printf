#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline() {
  char* line = NULL;
  size_t bufsize = 0; // default buffer size
  ssize_t num_chars;

  // Read the line from standard input
  num_chars = getline(&line, &bufsize, stdin);

  // If there was an error or we reached EOF, return NULL
  if (num_chars == -1) {
    free(line);
    return NULL;
  }

  // Replace the newline character with a null terminator
  if (line[num_chars - 1] == '\n') {
    line[num_chars - 1] = '\0';
  }

  // Return the line
  return line;
}

int main() {
  char* line;

  // Print a prompt to let the user know that they should enter a line of text
  printf("Enter a line of text: ");

  // Read a line of text from standard input
  line = readline();

  // If there was an error or we reached EOF, exit with an error code
  if (line == NULL) {
    fprintf(stderr, "Error reading input\n");
    exit(1);
  }

  printf("You entered: %s\n", line);

  // Free the memory allocated by readline()
  free(line);

  return 0;
}

