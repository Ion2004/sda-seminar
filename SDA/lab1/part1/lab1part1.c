#include <stdio.h>
#include <string.h>


struct Player {

    char name[12];
    int score;
    char country[10];

}player[10];



void Enter_Player_Details(struct Player player[],int n)
{

    for(int i=0;i<n;i++)
    {
        printf("Introdu datele %d jucator\n",i+1);
        scanf("%s %s %d",player[i].name,&player[i].country,&player[i].score);
    }
}

  void Show_Details_Player(struct Player player[],int n)
  {
    printf("Nume\t\tTara\t\tScorul\n");

       for(int i=0;i<n;i++)
       {
        printf("%s\t\t%s\t\t%d\n",player[i].name,player[i].country,player[i].score);
       }

  }
  //player[i].name == valoare || player[i].country == valoare || player[i].score == atoi(&valoare)

  int Find_By_Element(struct Player player[],int n, char valoare, int option)
  {
   for(int i=0;i<n;i++)
   {
       if(option == 1 && strcmp(player[i].name , valoare) == 0) {
           return i;
       } else if(option == 2 && strcmp( player[i].country , valoare) == 0){
           return i;
       } else if(option == 3 && player[i].score == atoi(&valoare)) {
           return i;
       } else {
           return -1;
       }


    }


  }
int main() {

    int n;
        printf("Introdu nr jucatorilor \n");
        scanf("%d",&n);


        printf("Introdu datele jucatorului, ca nume, tara care o reprezinta si scorul final \n");

  Enter_Player_Details(player,n);


        printf("Afisam datele jucatorului: \n");

    Show_Details_Player(player,n);
    char val[10];
        printf("Introdu valoarea cautata: \n");
        scanf("%s", val);

    int option;

        printf("Introdu optiunea cautarii (1 - Nume, 2 - Tara, 3 - Scor): ");
        scanf("%d",&option);


    int position = Find_By_Element(player,n,val,option);

    if(position != -1)
    {
        printf("Sa gasit aparitita valorii la pozitia: %d\n ",position);
    } else {
        printf("Nu sa gasit aparitita valorii ");
    }

  return 0;
}



