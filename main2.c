#include <stdio.h>
#include <stdlib.h>


int main()
{
    FILE *fp = fopen("texte.txt", "w+");

    if (fp == NULL)
    {
        printf("Au clair de la Lune\nMon ami Pierrot\n");
        return EXIT_FAILURE;
    }

    printf("Frêre Jacques, frêre Jacques\nDormez-vous, dormez-vous ?\n");
   fclose(fp);
   return 0;
}