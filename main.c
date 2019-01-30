#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <windows.h>

#define NO_FLAG 0
#define SC 1
void pause(void);
void password_generate(char *str, char *let,char *cp, int taille,unsigned long flags);

int main()
{

    //Variables pour enregistrement dans un fichier
    FILE *fp;
    int nb_mdp;

    unsigned long mode; //Flags
    char rep = 'O';
    int n = 25;
    int taille = -1;

    char lettres[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r',
    's','t','u','v','w','x','y','z'};
    char caracteres_speciaux[8] = {'#','!','$','/','?','&',';',':'};



    char saut = '\n';

    printf("\nVersion 1.1 | Developpe par Boucenine Mounir ©2019");
    printf("\n\nCaracteres specials ? (O/N):");
    scanf("%c",&rep);

    //printf("\n\nCombien de mots de passe ? :");
    //scanf("%d",&nb_mdp);

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

    nb_mdp = -1;
    while(nb_mdp<1 || nb_mdp>30)
    {
    printf("\n\nNombre de mots de passe ? :");
    scanf("%d",&nb_mdp);

    }


     if((fp = fopen("mdp.txt","w")) == NULL)
    {
        fprintf(stderr, "Erreur à l'ouverture de fichier");

    }

    int i = 1;
    char buffer[n+1];
    buffer[n] = '0';
    printf("Generation en cours....");
    int j;
    while(i<=nb_mdp)
    {


    srand(time(NULL));
    password_generate(buffer,lettres,caracteres_speciaux,taille,mode);

      for(j=taille;j<n;j++)
    {
        buffer[j] = ' ';
    }
    printf("Mot de passe=%s",buffer);






    fputs(&buffer,fp);

       for(j=0;j<n;j++)
    {
        buffer[j] = ' ';
    }

    fputs(&saut,fp);
    Sleep(1000);
    i++;
      }

    fclose(fp);


    printf("\n");
    system("PAUSE");


    return 0;



}
void password_generate(char *str, char *let,char *cp, int taille,unsigned long flags)
{
char ch[10] = {'0','1','2','3','4','5','6','7','8','9'};
int nb;
int i;


srand(time(NULL));
    for(i=0;i<taille;i++)
    {
        int choix = rand()%3;
        if(choix == 0)
        {
        nb = rand()%10;
        str[i]=ch[nb];
        //printf("%d",nb);

        }
        else if(choix == 1)
        {
            nb = rand()%26;
            str[i]=let[nb];
            //printf("%c",let[nb]);
        }
        else if(choix == 2)
        {
            if(((flags && SC) != 0))
            {
              nb = rand()%8;
              str[i] = cp[nb];
              //printf("%c",cp[nb]);

            }
            else
            {
                nb = rand()%26;
                str[i] = let[nb];
                //printf("%c",let[nb]);
            }



        }

    }
    printf("\n");



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
