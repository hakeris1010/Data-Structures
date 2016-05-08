#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include "c_avltree.h"

char clearBuffer()
{
    char c;
    char wereChars=0;
    while((c=getchar())!='\n' && c!=EOF) //let's clear a buffer!
        wereChars=1;

    return !wereChars; //let's return if there were unised chars in a buffer
}

int cgetValidatedConInt(const char *stringToWrite, int min, int max)
{                  //min - minimum possible number, max- maximum.
    int rc, num;
    while(1)
    {
        printf("%s", stringToWrite);
        rc=scanf("%7d", &num);     // maximum of 7 chars

        char clearRet = clearBuffer();

        if(rc!=1 || num<min || num>max || !clearRet) //if scanf failed, number is wrong, or were unused chars
        {
            printf("Tai blogas skaicius. (Per didelis, per mazas, arba isvis nesamone.)\n");
        }
        else
            break; //get out of da loop
    }
    return num;
}

//Void secshon.

char elemEvaluator_voidInt( void* el1,  void* el2)
{
    if(!el1 || !el2) return 2;
    if(*((int*)el1) > *((int*)el2)) return 1;
    if(*((int*)el1) < *((int*)el2)) return -1;
    return 0; //el1 = el2
}

void valDest_voidInt(void** val)
{
    if(!val ? 1 : !(*val)) return; //non-existent.
    printf("[valueDestructor()]: valDest called with **val = %d, *val = %p, and val = %p\n", *((int*)(*val)), *val, val);

    free(*val);
    *val = NULL;

    printf("[valueDestructor()]: *val delete'd. *val = NULL. Done!\n");
}

const char* elemToString(void* val)
{
    char* st = (char*)malloc(16*sizeof(char));
    sprintf(st, "%d\0", *((int*)val));
    return st;
}

void* voidifyInt(int val)
{
    void* patr = malloc(sizeof(int));
    *((int*)patr) = val;
    return patr;
}

void C_Test_VoidPointr()
{
    C_AVLTree cavl;
    avl_initTree(&cavl);
    avl_setCallbacks(&cavl, valDest_voidInt, elemEvaluator_voidInt, elemToString);

    int n = cgetValidatedConInt("\nEnter how many nums you'll write.\n>> ", 1, 20);
    for(int i=0; i<n; i++)
    {
        printf("[%d]: ", i);
        int tm = cgetValidatedConInt("", INT_MIN+1, INT_MAX-1);
        avl_addElement( &cavl, voidifyInt(tm), 0, 1 );
    }

    avl_showTree(cavl, 4, 0, 0);

    printf("\n* - * - * - * - * - * - * -\n");

    int elem2delete = cgetValidatedConInt("\nEnter elem2delete\n>> ", INT_MIN+1, INT_MAX-1);
    printf("\nDeleting elem: %d\n", elem2delete);
    avl_deleteElement( &cavl, voidifyInt(elem2delete) );

    avl_showTree(cavl, 4, 0, 0);

    int searchFor = cgetValidatedConInt("\nEnter elem2search\n>> ", INT_MIN+1, INT_MAX-1);
    printf("\nSearhing for element: %d\n", searchFor);

    if(avl_findElement(cavl, voidifyInt(searchFor)))
        printf("Element F O U N D !!!\n");
    else
        printf("Element not found.\n");

    avl_clearTree(&cavl, 1);
    printf("Clear() ended!\n\n");
}


int main()
{
    C_Test_VoidPointr();
    //woot!

    return 0;
}
