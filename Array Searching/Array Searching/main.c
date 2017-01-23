#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void SearchItem (int *a, unsigned int b)
{
    int n = 0;
    int i = 0;
    int Search_Item = 0;
    printf("Insert the number to be searched\n");
    scanf("%d", &Search_Item);
    printf("Searching...\n");
    for (i = 0; i < b; i++)
        {
            n = i + 1;
            if (a[i] == Search_Item ) //if we find the item
            {
                printf("The number was found at the position number %d of the array\n", n);
                break;
            }
            else if (i == b-1)
            {
                printf("The number is not present in the array\n");
            }
        };
}

int DataInput (int *a, unsigned int b)
{
    int i = 0;
    int n = 0;
    int c = 0;
    printf("Fill the array with %d elements\n", b);
    for ( i = 0; i < b; i++)
    {
        n = i + 1;
        printf("Insert element #%d\n", n);
        scanf("%d", &c);
        a[i] = c;
    };
    return (int)*a;
}

void PrintArray (int *a, unsigned int b)
{
    int i = 0;
    int n = 0;
    for (i = 0; i < b; i++)
    {
        n = i + 1;
        printf("The element #%d is %d\n", n, a[i]);
    };
}

void CountItemCopies (int *a, unsigned int b)
{
    int i = 0;
    int n = 0;
    int j = 0;
    printf("Insert the element whose copies are to be counted\n");
    scanf("%d", &j);
    for ( i = 0; i < b; i++)
    {
        if ( a[i] == j) //if element in i is equal to j
        {
            n = n + 1;
        }
    };
    printf("%d copies have been found\n", n);
}
/*int ArrayCreation (int *a)
{
                int b = 0;
                printf("Define the size of the array\n");
                scanf("%d",&b);
                printf("The array will be able to contain %d elements\n", b);
                a = (int*) malloc (b * sizeof(int));
                return a;
}*/

int main()
{
    //Array management;
    printf("Simple array management program\n");

    unsigned int dimension = 0;
    char operation;
    int *array = NULL; //good practice, set pointers to null
    printf("List of commands:\nN to define a new array\n");
    printf("I to add data\n");
    printf("S to look for a number\n");
    printf("C to count the copies of an item\n");
    printf("P to print the content of the array\n");
    printf("X to exit\n");
    while(operation != 'X')
    {
        fflush(stdin);
        scanf("%c",&operation);
        operation = toupper(operation); //turn non-capital letters into capital
        switch(operation)
        {
        case 'S':
                if (array == NULL)
                {
                    printf("There isn't an array containing items to search for\n");
                    break;
                }
                else
                {
                    SearchItem (array, dimension);
                    break;
                }
        case 'N':
                if (array == NULL)
                {
                    printf("Define the size of the array\n");
                    do
                    {
                        scanf("%d",&dimension);
                        if (dimension == 0)
                        {
                            printf("%d is not a valid array dimension, insert a valid value\n", dimension);
                        }
                        fflush(stdin);
                    }while (dimension == 0);
                    printf("The array will be able to contain %d elements\n", dimension);
                    array = calloc (dimension, sizeof(*array)); //allocate memory for the array, set it to 0
                    break;
                }
                else
                {
                    printf("Clearing pre-existing array\n");
                    free(array); //clear the memory area assigned to array
                    array = NULL; //point to NULL
                    printf("Define the size of the array\n");
                    do
                    {
                        scanf("%d",&dimension);
                        if (dimension == 0)
                        {
                            printf("%d is not a valid array dimension, insert a valid value\n", dimension);
                        }
                        fflush(stdin);
                    }while (dimension == 0);
                    printf("The array will be able to contain %d elements\n", dimension);
                    array = calloc (dimension, sizeof(*array)); //allocate memory for the array, set it to 0
                    break;
                }
        case 'I':
                if (array == NULL) //check if memory has been allocated
                {
                    printf("Memory not allocated!\n");
                    break;
                }
                else
                {
                    *array = DataInput (array, dimension);
                    break;
                }
        case 'P':
                if(array == NULL)
                {
                    printf("There isn't an array to be printed\n");
                    break;
                }
                else
                {
                    PrintArray(array, dimension);
                    break;
                }
        case 'C':
                if (array == NULL)
                {
                    printf("An array must be created first\n");
                    break;
                }
                else
                {
                    CountItemCopies(array, dimension);
                    break;
                }
        };
    }
    if (array != NULL) //if pointer isn't NULL
    {
        printf("Clearing array memory area\n");
        free(array); //clear the array
        array = NULL; //set pointer to NULL
    }
    printf("Exiting...");
    fflush(stdin);
    return 0;
}
