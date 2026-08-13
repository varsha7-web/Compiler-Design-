#include <stdio.h>
#include <string.h>

struct Symbol
{
    char name[20];
    char type[20];
    int address;
};

struct Symbol table[50];
int n = 0;

void insert()
{
    printf("Enter name: ");
    scanf("%s", table[n].name);

    printf("Enter type: ");
    scanf("%s", table[n].type);

    printf("Enter address: ");
    scanf("%d", &table[n].address);

    n++;
    printf("Inserted successfully.\n");
}

void search()
{
    char name[20];
    int i;

    printf("Enter name to search: ");
    scanf("%s", name);

    for (i = 0; i < n; i++)
    {
        if (strcmp(table[i].name, name) == 0)
        {
            printf("Found: %s %s %d\n",
                   table[i].name,
                   table[i].type,
                   table[i].address);
            return;
        }
    }

    printf("Not found.\n");
}

void display()
{
    int i;

    printf("\nName\tType\tAddress\n");

    for (i = 0; i < n; i++)
        printf("%s\t%s\t%d\n",
               table[i].name,
               table[i].type,
               table[i].address);
}

void deleteSymbol()
{
    char name[20];
    int i, j;

    printf("Enter name to delete: ");
    scanf("%s", name);

    for (i = 0; i < n; i++)
    {
        if (strcmp(table[i].name, name) == 0)
        {
            for (j = i; j < n - 1; j++)
                table[j] = table[j + 1];

            n--;
            printf("Deleted successfully.\n");
            return;
        }
    }

    printf("Not found.\n");
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n1.Insert\n");
        printf("2.Search\n");
        printf("3.Delete\n");
        printf("4.Display\n");
        printf("5.Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: insert(); break;
            case 2: search(); break;
            case 3: deleteSymbol(); break;
            case 4: display(); break;
            case 5: return 0;
            default: printf("Invalid choice.\n");
        }
    }
}