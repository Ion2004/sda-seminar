#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
# define MAX 30
typedef struct treeNode
{
    int data;
    struct treeNode *left;
    struct treeNode *right;
} treeNode;
treeNode *create_node(int data)
{
    treeNode *result = malloc(sizeof(treeNode));
    if(result != NULL)
    {
        result->left = NULL;
        result->right = NULL;
        result->data = data;
    }
    return result;
}
bool insert_node(treeNode **rootptr, int data)
{
    treeNode *root = *rootptr;

    if(root == NULL)
    {
        //tree empty
        (*rootptr) = create_node(data);
        return true;
    }
    if(data == root->data)
    {
        //do nothing
        return false;
    }
    if(data < root->data)
    {
        return insert_node(&(root->left), data);
    }
    else
    {
        return insert_node(&(root->right), data);
    }
}
void printtabs(int numtabs)
{
    for(int i=0; i<numtabs; i++)
    {
        printf("\t");

    }
}
void print_tree_rec(treeNode *root, int level)
{
    if(root == NULL)
    {
        printtabs(level);
        printf("-------<empty>-------\n");
        return;
    }
    printtabs(level);
    printf("Data : %d\n", root->data);
    printtabs(level);
    printf("left\n");

    print_tree_rec(root->left, level+1);
    printtabs(level);
    printf("right\n");

    print_tree_rec(root->right, level+1);
    printtabs(level);
    printf("done\n");
}
void print_tree(treeNode *root)
{
    print_tree_rec(root, 0);
}
int calc_depth(treeNode *root)
{
    if (root == NULL)
        return 0;
    else
    {
        int left_depth = calc_depth(root->left);
        int right_depth = calc_depth(root->right);

        if (left_depth > right_depth)
            return (left_depth + 1);
        else
            return (right_depth + 1);
    }
}
int count = 0;
int find_number(treeNode *root, int data)
{
    count += 1;
    if(root == NULL) return 0;
    if(data = root->data) return count;
    if(data < root->data)
    {
        return find_number(root->left, data);
    }
    else
    {
        return find_number(root->right, data);
    }
}
int calc_depth_node(treeNode *root, int node_data)
{
    if(root == NULL)
        return 0;
    if(node_data == root->data)
        return calc_depth(root);
    if(node_data < root->data)
        return calc_depth_node(root->left, node_data);
    else
    {
        return calc_depth_node(root->right, node_data);
    }
}
int calc_height(treeNode *root)
{
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        int left_height = calc_height(root->left);
        int right_height = calc_height(root->right);
        if(left_height > right_height)
            return (left_height +1);
        else
            return (right_height +1);
    }
}
int print_leafs(treeNode *root)
{
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        if(root->left == NULL && root->right == NULL)
            printf("%d, ", root->data);
        else
        {
            int left_print = print_leafs(root->left);
            int right_print = print_leafs(root->right);
        }

    }
}
void clear_tree(treeNode *root) {
   if (root == NULL) return;
   clear_tree(root->left);
   clear_tree(root->right);
   root->data = NULL;
}
void free_tree(treeNode *root) {
   if (root == NULL) return;
   free_tree(root->left);
   free_tree(root->right);
   printf(
          "Node deleted, value is %d\n", root->data);
   free(root);
}
void show_menu()
{
    printf("----------------------------------------------------\n");
    printf("|1) Citirea de la tastatura a elementelor arborelui|\n");
    printf("----------------------------------------------------\n");
    printf("|2) Afisarea la consola a elementelor arborelui    |\n");
    printf("----------------------------------------------------\n");
    printf("|3) Calcularea adancimilor arborelui               |\n");
    printf("----------------------------------------------------\n");
    printf("|4) Cautarea unui nod in baza unei cai de cautare  |\n");
    printf("----------------------------------------------------\n");
    printf("|5) Calcularea adancimii unui nod ( nodul va fi    |\n"
           "|selectat in baza unei chei de cautare )           |\n");
    printf("----------------------------------------------------\n");
    printf("|6) Calcularea Inaltimii unui nod ( nodul va fi    |\n"
           "|selectat in baza unei chei de cautare )           |\n");
    printf("----------------------------------------------------\n");
    printf("|7) Afisarea tuturor frunzelor arborelui           |\n");
    printf("----------------------------------------------------\n");
    printf("|8) Curatirea elementelor arborelui                |\n");
    printf("----------------------------------------------------\n");
    printf("|9) Eliberarea memoriei arborelui                  |\n");
    printf("----------------------------------------------------\n");
}
int main()
{
    treeNode *root = NULL;
    show_menu();
    int p;
    scanf("%d", &p);
    do
    {
        switch(p)
        {
        case 1:
        {
            int num;
            printf("Numarul de elemente ale arborelui:");
            scanf("%d", &num);
            for(int i=0; i<num; i++)
            {
                int data;
                printf("Element%d = ", i+1);
                scanf("%d", &data);
                insert_node(&(root), data);
            }
            break;
        }
        case 2:
        {
            print_tree(root);
            break;
        }
        case 3:
        {
            printf("Adancimea arborelui este %d\n", calc_depth(root));
            break;
        }
        case 4:
        {
            int data;
            printf("Valoarea elmentului = ");
            scanf("%d", &data);
            if(find_number(root, data) == 0)
                printf("Elementul %d nu se gaseste in Arbore!\n");
            else printf("Elementul \"%d\" se afla la nivelul %d in arbore!\n", data, find_number(root, data)+1);
            break;
        }
        case 5:
        {
            int data;
            printf("Cheia de cautare = ");
            scanf("%d", &data);
            printf("Adancimea arborelui din nodul \"%d\" este %d\n", data, calc_depth_node(root, data));
            break;
        }
        case 6:
        {
            printf("Inaltimea arborelui este %d (au fost calculate nr de muchii)\n", calc_height(root)-1);
            break;
        }
        case 7:
        {
            printf("Frunzele arborelui sunt :\n");
            print_leafs(root);
            printf("\n");
            break;
        }
        case 8:
        {
            clear_tree(root);
            break;
        }
        case 9:
            {
                free_tree(root);
            root = NULL;
            printf("Tree deleted!!!\n");
            break;
            }
        }
        show_menu();
        scanf("%d", &p);
    }
    while(p != 0);
    return 0;
}

