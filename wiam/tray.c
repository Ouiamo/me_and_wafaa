#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** tokenize(char* str) {
  int num_tokens = 1; 
  char* token;
  char** tokens = NULL;
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == ' ') {
      num_tokens++;
    }
  }
  tokens = (char**)malloc(sizeof(char*) * num_tokens);
  if (tokens == NULL) {
    printf("Memory allocation error!\n");
    return NULL;
  }

  int j = 0;
  token = strtok(str, " ");
  while (token != NULL) {
    tokens[j] = (char*)malloc(strlen(token) + 1);
    if (tokens[j] == NULL) {
      printf("Memory allocation error!\n");
      return NULL;
    }
    strcpy(tokens[j], token); 
    token = strtok(NULL, " ");

  return tokens;
}

int main() {
  char input[100];
  printf("Enter a command: ");
  fgets(input, sizeof(input), stdin); 
  input[strcspn(input, "\n")] = '\0';
  char** tokens = tokenize(input);
  if (tokens != NULL) {
    for (int i = 0; tokens[i] != NULL; i++) {
      printf("Token %d: %s\n", i + 1, tokens[i]);
    }
    for (int i = 0; tokens[i] != NULL; i++) {
      free(tokens[i]);
    }
    free(tokens);
  }

  return 0;
}