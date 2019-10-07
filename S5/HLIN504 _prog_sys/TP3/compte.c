#include <stdio.h>
#include <stdlib.h>

void compte(char const *argv)
{

    int f = open(argv, 0);
    if( f == -1 ){
        perror("[ ERROR ] no file name give \n");
        exit(0);
    }

    char buffer[256];
    for (int i = 0; i < 256; i++) { buffer[i] = 0; }

    // on récupère le caractère
    char c;

    // Tant qu'on est pas à la fin du fichier
    while ( read(f, &c, 1) == 1 )
    {
        buffer[c]++;
    }

    int total = 0;
    printf("les différents caractères sont : ");

    for (int i = 0; i < 256; i++)
    {
        if (buffer[i] != 0)
        {
            total++;
            printf("%c:%i, ", i, buffer[i]);
        }
    }
    printf("\nIl y a %i caractère différents\n", total);

    close(f);
}

int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        perror("[ ERROR ] no file name give \n");
        exit(0);
    }
    compte(argv[1]);

    return 0;
}