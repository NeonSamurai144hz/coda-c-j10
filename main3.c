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
        printf("Le fichier test.txt n'a pas pu être ouvert\n");
        return EXIT_FAILURE;
    }

    file_content = get_file(fp);
    
    printf("%s", file_content);
    
    fclose(fp);
    return 0;
}

char ** str_tab;

str_tab[0] = "Tous les hommes";
str_tab[1] = "Naissent et demeurent";
str_tab[2] = "Libres et égaux";
str_tab[3] = "En dignité et en droits";

char ** str_tab = malloc(3 * sizeof(*str_tab));
str_tab[2] = NULL;

str_tab[0] = malloc(6 * sizeof(char));
str_tab[0][4] = '\0';

str_tab[1] = malloc(6 * sizeof(char));
str_tab[1][4] = '\0';

int i = 0;

while(str_tab[i] != NULL)
{
	free(str_tab[i]);
	i = i + 1;
}

free(str_tab);