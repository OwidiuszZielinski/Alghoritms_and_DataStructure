#include <stdio.h>
#include <stdlib.h>

//Tu na gorze musi byc nazwa struktury bo w ciele jak uzywam nazwy struktury to nie ogarnia
typedef struct Employee
{
    char name[20];
    int age;
//Pole trzymajace informacje o nastepnym elemencie?
    struct Employee *next;
} Employee;


//, *collection_pointer;
//linie tożsame
//wskaznik na strukture Employee pomoze w zazarzaniu kolejka
typedef Employee *collection_pointer;

//dlaczego robimy start i end typu collection pointer? Okreslaja poczatek i koniec kolekcji i na tym bedziemy operatorowac
collection_pointer start = NULL, end = NULL;

void add_in_end(collection_pointer* start, collection_pointer* end, Employee p){
    collection_pointer temp = (Employee*)malloc(sizeof(Employee));
    temp->name = 
    temp->age = p.age;
    temp->next = NULL;
    if((*start)==NULL)
        (*start) = temp;
    else
    (*start)->next = temp;
    (*end) = temp;
}

void print(collection_pointer start){
    while (start!=NULL)
    {
        printf("%s %d\n", start->name,start->age);
        start = start->next;
    }
    
}


int main()
{
    Employee emp;
    

        printf("    a: ");
        scanf("%c", emp.name);
        printf("    b: ");
        scanf("%d", &emp.age);
        add_in_end(&start, &end, emp);
    
    

    print(start);
    return 0;
}