#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NO_FLAG 0
#define SC 1
void pause(void);
void password_generate(char *str, char *let,char *cp, int taille,unsigned long flags);

int main()
{
    unsigned long mode; //Flags
    char rep = 'O';
    int n = 25;
    int taille = -1;

    char lettres[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r',
    's','t','u','v','w','x','y','z'};
    char caracteres_speciaux[8] = {'#','!','$','/','?','&',';',':'};

    char buffer[n];

    printf("\nVersion 1.0 | Developpe par Boucenine Mounir ©2019");
    printf("\n\nCaracteres specials ? (O/N):");
    scanf("%c",&rep);

    if(rep == 'O')
        mode=SC;
    else
        mode=NO_FLAG;
    while(taille > n || taille < 1)
    {
        printf("\nNombre de caracteres [0-%d]?:",n);
        scanf("%d",&taille);

        if(taille > n)
            printf("\nQuota depasse");
        else if(taille < 1)
            taille = 2;


    }






    printf("Mot de passe: ");
    password_generate(buffer,lettres,caracteres_speciaux,taille,mode);
    printf("\n");


    system("PAUSE");


    return 0;



}
void password_generate(char *str, char *let,char *cp, int taille,unsigned long flags)
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
            nb = rand()%26;
            printf("%c",let[nb]);
        }
        else if(choix == 2)
        {
            if(((flags && SC) != 0))
            {
              nb = rand()%8;
              printf("%c",cp[nb]);

            }
            else
            {
                nb = rand()%26;
                printf("%c",let[nb]);
            }




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
