#include <stdio.h>
#include <stdlib.h>

typedef struct Person
{
    const char *name;
    int age;
    struct Person *pointer_next;
}Person;



/* Create the list */

struct Person *arrayPointer = NULL;

Person createList(const char *name, int age)
{

    struct Person *temp = arrayPointer;
    temp = (Person *)malloc(sizeof(Person));
    temp->name = name;
    temp->age = age;
    temp->pointer_next = NULL;
}

void add(const char *name, int age)
{
    struct Person *newElement, *current;
    newElement = (struct Person *)malloc(sizeof(struct Person));
    newElement->name = name;
    newElement->age = age;
    newElement->pointer_next = NULL;
    if (arrayPointer == NULL)
    {
        arrayPointer = newElement;
        return;
    }
    current = arrayPointer;

    while (current->pointer_next != NULL)
    {
        current = current->pointer_next;
    }

    current->pointer_next = newElement;
}

// void printList(arrayPointer *P){
//     arrayPointer temp;
//     while (temp) {
//         printf("%d\n ", temp->age);
//         printf("%s\n",temp->name);
//         temp = temp->pointer_next;
//     }
// }

int main()
{

    createList("Owidiusz", 28);

    return 0;
}