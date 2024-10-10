#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * get_file(FILE * fp)
{
    char * content;
    char buffer[10];

    content = malloc(sizeof(char));
    content[0] = '\0';

    while(fgets(buffer, 10, fp) != NULL)
    {
        content = realloc(content, (strlen(buffer) * sizeof(char)) + strlen(content) * sizeof(char));
        content = strcat(content, buffer);
    }

    return content;
    }

int main()
{
    FILE *fp = fopen("test.txt", "r");
    char * file_content;

    if (fp == NULL)
    {
        printf("La vie\nL'univers\nEt tout le reste\n");
        return EXIT_FAILURE;
    }

    file_content = get_file(fp);
    
    printf("%s", file_content);
    
    fclose(fp);
    free (file_content);
    return 0;
}