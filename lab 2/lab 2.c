#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    #define SIZE 30
    typedef struct Node
    {
        char denumire[SIZE];
        char adresa[SIZE];
        char telefon[SIZE];
        int nr_locuri;
        int pret_bilet;
        struct Node *next;
    } Node;

    typedef struct List
    {
        Node *head;
        size_t size;
    } List;

    List *create_list()
    {
        List *list = malloc(sizeof(List));
        list->head = NULL;
        return list;
    }

    Node *create_node(char *denumire, char *adresa, char *telefon, int nr_locuri, int pret_bilet)
    {
        Node *node = (Node*)malloc(sizeof(Node));
        node->nr_locuri = nr_locuri;
        node->pret_bilet = pret_bilet;
        strcpy(node->denumire, denumire);
        strcpy(node->adresa, adresa);
        strcpy(node->telefon, telefon);
        node->next = NULL;
        return node;
    }

    void push_front(List *list,char *denumire, char *adresa, char *telefon, int nr_locuri, int pret_bilet)
    {
        Node *new_node = create_node(denumire, adresa, telefon, nr_locuri, pret_bilet);
        new_node->next = list->head;
        list->head = new_node;
    }

    void push_end(List *list,char *denumire, char *adresa, char *telefon, int nr_locuri, int pret_bilet)
    {
        Node *new_node = create_node(denumire, adresa, telefon, nr_locuri, pret_bilet);
        if(list->head == NULL) list->head = new_node;
        else
        {
            Node *tail = list->head;
            for(; tail->next; tail = tail->next);
            tail->next = new_node;
        }
        new_node->next = NULL;
    }

    void print_list(List *list)
    {
        if(list->head == NULL) return;
        int i=1;
        for(Node *current_node = list->head; current_node; current_node = current_node->next)
        {
            printf("Cinematograf %d:\n", i);
            printf("denumire : %s\n", current_node->denumire);
            printf("adresa : %s\n", current_node->adresa);
            printf("telefon : %s\n", current_node->telefon);
            printf("Nr locuri : %d\n", current_node->nr_locuri);
            printf("Pret bilet : %d\n", current_node->pret_bilet);
            i+=1;
        }
    }

    int cautare_denumire(List *list, char *denumire)
    {
        if(list->head == NULL) return 0;
        int i = 1;
        for(Node *current_node = list->head; current_node; current_node = current_node->next)
        {
            if(strcmp(current_node->denumire, denumire) == 0)
            {
                return i;
            }
            i +=1;
        }
        return 0;
    }

    int cautare_adresa(List *list, char *adresa)
    {
        if(list->head == NULL)return 0;
        int i=1;
        for(Node *current_node = list->head; current_node; current_node = current_node->next)
        {
            if(strcmp(current_node->adresa, adresa) == 0)
            {
                return i;
            }
            i +=1;
        }
        return 0;
    }

    int cautare_telefon(List *list, char *telefon)
    {
        if(list->head == NULL)return 0;
        int i=1;
        for(Node *current_node = list->head; current_node; current_node = current_node->next)
        {
            if(strcmp(current_node->telefon, telefon) == 0)
            {
                return i;
            }
            i +=1;
        }
        return 0;
    }

    int cautare_nr_locuri(List *list, int nr_locuri)
    {
        if(list->head == NULL)return 0;
        int i=1;
        for(Node *current_node = list->head; current_node; current_node = current_node->next)
        {
            if(current_node->nr_locuri == nr_locuri)
            {
                return i;
            }
            i +=1;
        }
        return 0;
    }

    int cautare_pret_bilet(List *list, int pret_bilet)
    {
        if(list->head == NULL)return 0;
        int i=1;
        for(Node *current_node = list->head; current_node; current_node = current_node->next)
        {
            if(current_node->pret_bilet == pret_bilet)
            {
                return i;
            }
            i +=1;
        }
        return 0;
    }

    void free_mem(List *list)
    {
        for(Node *current_node = list->head; current_node; current_node = current_node->next)
        {
            free(current_node);
        }
        free(list);
    }

    void sort_nr_locuri(List *list)
    {
        if(list->head == NULL)return ;
        for(Node *current_node1 = list->head; current_node1; current_node1 = current_node1->next)
        {
            for(Node *current_node2 = list->head; current_node2; current_node2 = current_node2->next)
            {
                if(current_node1->nr_locuri < current_node2->nr_locuri)
                {
                    int temp = current_node1->nr_locuri;
                    current_node1->nr_locuri = current_node2->nr_locuri;
                    current_node2->nr_locuri = temp;
                }
            }
        }
    }

    void sort_pret_bilet(List *list)
    {
        if(list->head == NULL)return ;
        for(Node *current_node1 = list->head; current_node1; current_node1 = current_node1->next)
        {
            for(Node *current_node2 = list->head; current_node2; current_node2 = current_node2->next)
            {
                if(current_node1->pret_bilet < current_node2->pret_bilet)
                {
                    int temp = current_node1->pret_bilet;
                    current_node1->pret_bilet = current_node2->pret_bilet;
                    current_node2->pret_bilet = temp;
                }
            }
        }
    }

    void sort_denumire(List *list)
    {
        if(list->head == NULL)return;
        for(Node *current_node1 = list->head; current_node1; current_node1 = current_node1->next)
        {
            for(Node *current_node2 = list->head; current_node2; current_node2 = current_node2->next)
            {
                if(strcmp(current_node1->denumire, current_node2->denumire) <0)
                {
                    char *temp;
                    temp = strdup(current_node1->denumire);
                    strcpy(current_node1->denumire, current_node2->denumire);
                    strcpy(current_node2->denumire, temp);
                }
            }
        }
    }

    void sort_adresa(List *list)
    {
        if(list->head == NULL)return;
        for(Node *current_node1 = list->head; current_node1; current_node1 = current_node1->next)
        {
            for(Node *current_node2 = list->head; current_node2; current_node2 = current_node2->next)
            {
                if(strcmp(current_node1->adresa, current_node2->adresa) <0)
                {
                    char *temp;
                    temp = strdup(current_node1->adresa);
                    strcpy(current_node1->adresa, current_node2->adresa);
                    strcpy(current_node2->adresa, temp);
                }
            }
        }
    }

    void sort_telefon(List *list)
    {
        if(list->head == NULL)return;
        for(Node *current_node1 = list->head; current_node1; current_node1 = current_node1->next)
        {
            for(Node *current_node2 = list->head; current_node2; current_node2 = current_node2->next)
            {
                if(strcmp(current_node1->telefon, current_node2->telefon) <0)
                {
                    char *temp;
                    temp = strdup(current_node1->telefon);
                    strcpy(current_node1->telefon, current_node2->telefon);
                    strcpy(current_node2->telefon, temp);
                }
            }
        }
    }
    void push_x(List *list, char *denumire, char *adresa, char *telefon, int nr_locuri, int pret_bilet, int x)
    {
        Node *new_node = malloc(sizeof(Node));
        new_node->nr_locuri = nr_locuri;
        new_node->pret_bilet = pret_bilet;
        strcpy(new_node->denumire, denumire);
        strcpy(new_node->adresa, adresa);
        strcpy(new_node->telefon, telefon);
        if(list->head == NULL)
        {
            list->head = new_node;
            new_node->next = NULL;
            return;
        }

        int i=2;
        for(Node *current_node = list->head; current_node; current_node = current_node->next)
        {
            if(i == x)
            {
                Node *temp = current_node->next;
                current_node->next = new_node;
                new_node->next = temp;
                return;
            }
            i+=1;
        }
    }
    void delete_x(List *list, char *denumire, char *adresa, char *telefon, int nr_locuri, int pret_bilet, int x)
    {
        if(list->head == NULL)return;
        int i=2;
        for(Node *current_node = list->head; current_node; current_node = current_node->next)
        {
            if(i == x)
            {
                Node *temp = current_node;
                current_node = current_node->next;
                temp->next = current_node->next;
            }
            i++;
        }
    }
    void reverse_list(List *list)
    {
        if (list->head == NULL)
        {
            return;
        }
        Node* temp = list->head;
        Node* new_head = NULL;
        while (temp != NULL)
        {
            Node* new_node = create_node(temp->denumire, temp->adresa, temp->telefon, temp->nr_locuri, temp->pret_bilet);
            new_node->next = new_head;
            new_head = new_node;
            temp = temp->next;
        }
        list->head = new_head;
    }
    void clear_list(List *list)
    {
        for(Node *current_node = list->head; current_node; current_node = current_node->next)
        {
            current_node->nr_locuri = 0;
            current_node->pret_bilet = 0;
            strcpy(current_node->denumire, "NULL");
            strcpy(current_node->adresa, "NULL");
            strcpy(current_node->telefon, "NULL");
        }
    }
    int main()
    {
        printf("-------------------------------------------------------------------\n");
        printf("|1)Citirea de la tastatura a elementelor listei;                  |\n");
        printf("-------------------------------------------------------------------\n");
        printf("|2)Afisarea la consola a elementelor listei;                      |\n");
        printf("-------------------------------------------------------------------\n");
        printf("|3)Cautarea unui element dupa o valoarea a unui camp din structura|\n"
               "|si returnarea pozitiei unde se afla primul element gasit;        |\n");
        printf("-------------------------------------------------------------------\n");
        printf("|4)Eliberarea memoriei listei;                                    |\n");
        printf("-------------------------------------------------------------------\n");
        printf("|5)Sortarea elementelor dupa un camp a structurii;                |\n");
        printf("-------------------------------------------------------------------\n");
        printf("|6)Inserarea unui element nou la capatul listei;                  |\n");
        printf("-------------------------------------------------------------------\n");
        printf("|7)Inserarea unui element nou la inceputul listei;                |\n");
        printf("-------------------------------------------------------------------\n");
        printf("|8)Insearea unui element la o pozitie X(introdusa de la tastatura)|\n"
               "|in cadrul listei;                                                |\n");
        printf("-------------------------------------------------------------------\n");
        printf("|9)Stergerea unui element de pe o pozitie X ( introdusa de la     |\n"
               "|tastatura) din cadrul listei;                                    |\n");
        printf("-------------------------------------------------------------------\n");
        printf("|10)Inversarea ordinei elementelor din lista;                     |\n");
        printf("-------------------------------------------------------------------\n");
        printf("|11)Curatirea listei.                                             |\n");
        printf("-------------------------------------------------------------------\n");
        int p;
        scanf("%d", &p);
        List *list = create_list();
        do
        {
            switch(p)
            {
            case 1:
            {
                int nr_locuri;
                int pret_bilet;
                char denumire[SIZE];
                char adresa[SIZE];
                char telefon[SIZE];
                int num;
                printf("Introduceti numarul de elemente ale listei: ");
                scanf("%d", &num);
                for(int i=0; i<num; i++)
                {
                    printf("cinematograful %d:\n",i+1);
                    printf("Demumire : ");
                fflush(stdin);
                    gets(denumire);
                    printf("Adresa : ");
                fflush(stdin);
                    gets(adresa);
                    printf("Telefon : ");
                fflush(stdin);
                    gets(telefon);
                    printf("Nr de locuri = ");
                    scanf("%d", &nr_locuri);
                    printf("Pret bilet = ");
                    scanf("%d", &pret_bilet);
                    push_end(list, denumire, adresa, telefon, nr_locuri, pret_bilet);
                }
                break;
            }
            case 2:
            {
                print_list(list);
                break;
            }
            case 3:
            {
                printf("------------------------------------\n");
                printf("|Alegeti un camp din strucrura:    |\n");
                printf("------------------------------------\n");
                printf("|1)Denumire                        |\n");
                printf("|2)Adresa                          |\n");
                printf("|3)Telefon                         |\n");
                printf("|4)Nr de locuri                    |\n");
                printf("|5)Pret bilet                      |\n");
                printf("------------------------------------\n");
                int camp;
                scanf("%d", &camp);
                switch(camp)
                {
                case 1:
                {
                    char denumire[SIZE];
                    printf("Denumire : ");
                fflush(stdin);
                    gets(denumire);
                    printf("Elementul \"%s\" se afla pe pozitia %d in lista\n", denumire, cautare_denumire(list, denumire));
                    break;
                }
                case 2:
                {
                    char adresa[SIZE];
                    printf("Adresa : ");
                fflush(stdin);
                    gets(adresa);
                    printf("Elementul \"%s\" se afla pe pozitia %d in lista\n", adresa, cautare_adresa(list, adresa));
                    break;
                }
                case 3:
                {
                    char telefon[SIZE];
                    printf("Telefon = ");
                fflush(stdin);
                    gets(telefon);
                    printf("Elementul \"%s\" se afla pe pozitia %d in lista\n", telefon, cautare_telefon(list, telefon));
                    break;
                }
                case 4:
                {
                    int nr_locuri;
                    printf("Nr locuri = ");
                    scanf("%d", nr_locuri);
                    printf("Elementul \"%d\" se afla pe pozitia %d in lista\n", nr_locuri, cautare_nr_locuri(list, nr_locuri));
                    break;
                }
                case 5:
                {
                    int pret_bilet;
                    printf("Nr locuri = ");
                    scanf("%d", pret_bilet);
                    printf("Elementul \"%d\" se afla pe pozitia %d in lista\n", pret_bilet, cautare_pret_bilet(list, pret_bilet));
                    break;
                }
                }
                break;
            }
            case 4:
            {
                free_mem(list);
                printf("\nMemoria listei a fost eliberata!!\n");
                break;
            }
            case 5:
            {
                printf("--------------------------------\n");
                printf("|Alegeti un camp din strucrura:|\n");
                printf("--------------------------------\n");
                printf("|1)Denumire                    |\n");
                printf("|2)Adresa                      |\n");
                printf("|3)Telefon                     |\n");
                printf("|4)Nr locuri                   |\n");
                printf("|5)Pret bilet                  |\n");
                printf("--------------------------------\n");
                int camp1;
                scanf("%d", &camp1);
                switch(camp1)
                {
                case 1:
                {
                    sort_denumire(list);
                    break;
                }
                case 2:
                {
                    sort_adresa(list);
                }
                break;
                case 3:
                {
                    sort_telefon(list);
                }
                break;
                case 4:
                {
                    sort_nr_locuri(list);
                }
                break;
                case 5:
                {
                    sort_pret_bilet(list);
                }
                break;
                }
            }
            case 6:
            {
                int nr_locuri;
                int pret_bilet;
                char denumire[SIZE];
                char adresa[SIZE];
                char telefon[SIZE];
                printf("Denumire : ");
                scanf("%c");
                gets(denumire);
                printf("Adresa : ");
                scanf("%c");
                gets(adresa);
                printf("Telefon : ");
                scanf("%c");
                gets(telefon);
                printf("Nr locuri : ");
                scanf("%d", &nr_locuri);
                printf("Pret bilet : ");
                scanf("%d", &pret_bilet);
                push_end(list, denumire, adresa, telefon, nr_locuri, pret_bilet);
                break;
            }
            case 7:
            {
                int nr_locuri;
                int pret_bilet;
                char denumire[SIZE];
                char adresa[SIZE];
                char telefon[SIZE];
                printf("Denumire : ");
                scanf("%c");
                gets(denumire);
                printf("Adresa : ");
                scanf("%c");
                gets(adresa);
                printf("Telefon : ");
                scanf("%c");
                gets(telefon);
                printf("Nr locuri : ");
                scanf("%d", &nr_locuri);
                printf("Pret bilet : ");
                scanf("%d", &pret_bilet);
                push_front(list, denumire, adresa, telefon, nr_locuri, pret_bilet);
                break;
            }
            case 8:
            {
                int x;
                int nr_locuri;
                int pret_bilet;
                char denumire[SIZE];
                char adresa[SIZE];
                char telefon[SIZE];
                printf("Pozitia X = ");
                scanf("%d", &x);
                printf("Denumire : ");
                scanf("%c");
                gets(denumire);
                printf("Adresa : ");
                scanf("%c");
                gets(adresa);
                printf("Telefon : ");
                scanf("%c");
                gets(telefon);
                printf("Nr locuri : ");
                scanf("%d", &nr_locuri);
                printf("Pret bilet : ");
                scanf("%d", &pret_bilet);
                push_x(list, denumire, adresa, telefon, nr_locuri, pret_bilet, x);
                break;
            }
            case 9:
                {
                int x;
                int nr_locuri;
                int pret_bilet;
                char denumire[SIZE];
                char adresa[SIZE];
                char telefon[SIZE];
                printf("Pozitia X = ");
                scanf("%d", &x);
                printf("Denumire : ");
                fflush(stdin);
                gets(denumire);
                printf("Adresa : ");
                fflush(stdin);
                gets(adresa);
                printf("Telefon : ");
                fflush(stdin);
                gets(telefon);
                printf("Nr locuri : ");
                scanf("%d", &nr_locuri);
                printf("Pret bilet : ");
                scanf("%d", &pret_bilet);
                delete_x(list, denumire, adresa, telefon, nr_locuri, pret_bilet, x);
                    break;
                }
            case 10:
                {
                    reverse_list(list);
                    break;
                }
                case 11:
                    {
                        clear_list(list);
                        break;
                    }
            }
            printf("-------------------------------------------------------------------\n");
            printf("|1)Citirea de la tastatura a elementelor listei;                  |\n");
            printf("-------------------------------------------------------------------\n");
            printf("|2)Afisarea la consola a elementelor listei;                      |\n");
            printf("-------------------------------------------------------------------\n");
            printf("|3)Cautarea unui element dupa o valoarea a unui camp din structura|\n"
                   "|si returnarea pozitiei unde se afla primul element gasit;        |\n");
            printf("-------------------------------------------------------------------\n");
            printf("|4)Eliberarea memoriei listei;                                    |\n");
            printf("-------------------------------------------------------------------\n");
            printf("|5)Sortarea elementelor dupa un camp a structurii;                |\n");
            printf("-------------------------------------------------------------------\n");
            printf("|6)Inserarea unui element nou la capatul listei;                  |\n");
            printf("-------------------------------------------------------------------\n");
            printf("|7)Inserarea unui element nou la inceputul listei;                |\n");
            printf("-------------------------------------------------------------------\n");
            printf("|8)Insearea unui element la o pozitie X(introdusa de la tastatura)|\n"
                   "|in cadrul listei;                                                |\n");
            printf("-------------------------------------------------------------------\n");
            printf("|9)Stergerea unui element de pe o pozitie X ( introdusa de la     |\n"
                   "|tastatura) din cadrul listei;                                    |\n");
            printf("-------------------------------------------------------------------\n");
            printf("|10)Inversarea ordinei elementelor din lista;                     |\n");
            printf("-------------------------------------------------------------------\n");
            printf("|11)Curatirea listei.                                             |\n");
            printf("-------------------------------------------------------------------\n");
            scanf("%d", &p);
        }
        while(p > 0 && p <12);
        return 0;
    }



