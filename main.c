#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void pause(void);
void generer(char *str, char *let,char *cp, int taille);

int main()
{
    int taille = -1;
    char buffer[18];
    char lettres[3] = {'a','b','c'};
    char caracteres_speciaux[8] = {'#','!','$','/','?','&',';',':'};

    while(taille > 18 || taille < 1)
    {
        printf("\nNombre de caracteres [0-18]?:");
        scanf("%d",&taille);

        if(taille > 18)
            printf("\nQuota depasse");
        else if(taille < 1)
            taille = 2;


    }

    printf("Mot de passe: ");
    generer(buffer,lettres,caracteres_speciaux,taille);
    printf("\n");


    system("PAUSE");


    return 0;



}
void generer(char *str, char *let,char *cp, int taille)
{

int nb;
int i;
srand(time(NULL));
    for(i=0;i<taille;i++)
    {
        int choix = rand()%3;
        if(choix == 0)
        {
        nb = rand()%10;
        printf("%d",nb);

        }
        else if(choix == 1)
        {
            nb = rand()%3;
            printf("%c",let[nb]);
        }
        else if(choix == 2)
        {
            nb = rand()%3;
            printf("%c",cp[nb]);

        }

    }



}
void pause(void)
{
    char c;

    printf("\nAppuyer sur ENTER pour terminer... ");
    fflush(stdout);

    c = getchar();

    /* -tc- si nécessaire, on vide le tampon du flux d'entree standard */
    if (c != '\n')
    {
        while ((c = getchar()) != '\n' && c != EOF)
        {
        }
    }
}
