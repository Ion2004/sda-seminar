
#include <stdio.h>
#include <stdlib.h>


    struct Data {
        int zi;
        int luna;
        int an;
    };


    struct TablouData {
        struct Data *date;
        int lungime;
    };


    void Read_Data(struct Data *d) {
        printf("Introduceti ziua: ");
        scanf("%d", &d->zi);
        printf("Introduceti luna: ");
        scanf("%d", &d->luna);
        printf("Introduceti anul: ");
        scanf("%d", &d->an);
    }


    void Show_Data(struct Data d) {
        printf("%02d/%02d/%4d\n", d.zi, d.luna, d.an);
    }


    void Free_Memorie(struct TablouData *tab) {
        free(tab->date);
        tab->date = NULL;
        tab->lungime = 0;
    }


    int Find_Data(struct TablouData tab, struct Data cautat) {
        for (int i = 0; i < tab.lungime; i++) {
            if (tab.date[i].zi == cautat.zi &&
                tab.date[i].luna == cautat.luna &&
                tab.date[i].an == cautat.an) {
                return i;
            }
        }
        return -1;
    }


    void Sort_Data(struct TablouData *tab) {
        struct Data temp;
        for (int i = 0; i < tab->lungime - 1; i++) {
            for (int j = i + 1; j < tab->lungime; j++) {
                if (tab->date[i].zi > tab->date[j].zi) {
                    temp = tab->date[i];
                    tab->date[i] = tab->date[j];
                    tab->date[j] = temp;
                }
            }
        }
    }


    void New_End(struct TablouData *tab, struct Data nou) {
        tab->date = (struct Data *)realloc(tab->date, (tab->lungime + 1) * sizeof(struct Data));
        tab->date[tab->lungime] = nou;
        tab->lungime++;
    }

    void New_Begin(struct TablouData *tab, struct Data nou) {
        tab->date = (struct Data *)realloc(tab->date, (tab->lungime + 1) * sizeof(struct Data));
        for (int i = tab->lungime; i > 0; i--) {
            tab->date[i] = tab->date[i - 1];
        }
        tab->date[0] = nou;
        tab->lungime++;
    }


    void New_On_Position(struct TablouData *tab, struct Data nou, int pozitie) {
        if (pozitie < 0 || pozitie > tab->lungime) {
            printf("Pozitie invalida.\n");
            return;
        }
        tab->date = (struct Data *)realloc(tab->date, (tab->lungime + 1) * sizeof(struct Data));
        for (int i = tab->lungime; i > pozitie; i--) {
            tab->date[i] = tab->date[i - 1];
        }
        tab->date[pozitie] = nou;
        tab->lungime++;
    }


    void Delete_On_Position(struct TablouData *tab, int pozitie) {
        if (pozitie < 0 || pozitie >= tab->lungime) {
            printf("Pozitie invalida.\n");
            return;
        }
        for (int i = pozitie; i < tab->lungime - 1; i++) {
            tab->date[i] = tab->date[i + 1];
        }
        tab->lungime--;
        tab->date = (struct Data *)realloc(tab->date, tab->lungime * sizeof(struct Data));
    }

int main() {
    int optiune;
    struct TablouData tab;


    tab.date = NULL;
    tab.lungime = 0;

    do {
        printf("\nMeniu:\n");
        printf("1. Citirea de la tastatura a elementelor tabloului\n");
        printf("2. Afișarea la consolă a elementelor tabloului\n");
        printf("3. Căutarea unui element după o valoare a unui câmp din structură\n");
        printf("4. Eliberarea memoriei tabloului\n");
        printf("5. Sortarea elementelor după zi\n");
        printf("6. Inserarea unui element nou la capătul tabloului\n");
        printf("7. Inserarea unui element nou la începutul tabloului\n");
        printf("8. Inserarea unui element la o poziție X în cadrul tabloului\n");
        printf("9. Ștergerea unui element de pe o poziție X din cadrul tabloului\n");
        printf("0. Ieșire\n");
        printf("Introduceti optiunea: ");
        scanf("%d", &optiune);

        switch (optiune) {
            case 1:
                printf("Introduceti lungimea tabloului: ");
                scanf("%d", &tab.lungime);
                tab.date = (struct Data *)malloc(tab.lungime * sizeof(struct Data));
                for (int i = 0; i < tab.lungime; i++) {
                    printf("Introduceti datele pentru elementul %d:\n", i + 1);
                    Read_Data(&tab.date[i]);
                }
                break;
            case 2:
                printf("Elementele tabloului sunt:\n");
                for (int i = 0; i < tab.lungime; i++) {
                    Show_Data(tab.date[i]);
                }
                break;
            case 3:

                struct Data cautat;
                printf("Introduceti data cautata:\n");
                Read_Data(&cautat);
                int pozitie = Find_Data(tab, cautat);
                if (pozitie != -1) {
                    printf("Data cautata se afla la pozitia %d.\n", pozitie + 1);
                } else {
                    printf("Data cautata nu a fost gasita.\n");
                }
                break;
            case 4:

                Free_Memorie(&tab);
                printf("Memoria tabloului a fost eliberata.\n");
                break;
            case 5:

                Sort_Data(&tab);
                printf("Tabloul a fost sortat dupa zi.\n");
                break;
            case 6:

                printf("Introduceti datele pentru noul element:\n");
                struct Data nou;
                Read_Data(&nou);
                New_End(&tab, nou);
                printf("Noul element a fost inserat la sfarsitul tabloului.\n");
                break;
            case 7:

                printf("Introduceti datele pentru noul element:\n");
                Read_Data(&nou);
                New_Begin(&tab, nou);
                printf("Noul element a fost inserat la inceputul tabloului.\n");
                break;
            case 8:

                printf("Introduceti datele pentru noul element:\n");
                Read_Data(&nou);
                int pozitieInserare;
                printf("Introduceti pozitia la care sa fie inserat noul element: ");
                scanf("%d", &pozitieInserare);
                New_On_Position(&tab, nou, pozitieInserare - 1);
                printf("Noul element a fost inserat la pozitia %d.\n", pozitieInserare);
                break;
            case 9:

                int pozitieStergere;
                printf("Introduceti pozitia de la care sa fie sters elementul: ");
                scanf("%d", &pozitieStergere);
                Delete_On_Position(&tab, pozitieStergere - 1);
                printf("Elementul de la pozitia %d a fost sters.\n", pozitieStergere);
                break;
            case 0:
                printf("Programul s-a încheiat.\n");
                break;
            default:
                printf("Opțiune invalidă! Încercați din nou.\n");
        }
    } while (optiune != 0);


    Free_Memorie(&tab);

    return 0;
}




