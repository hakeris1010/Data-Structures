#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <sstream>
#include "avltree.h"

//toolz
template<typename T>
std::string toString(const T val)
{
    std::stringstream ss;
    ss<<val;
    return ss.str();
}

int getValidatedConInt(std::string write, int mn = INT_MIN, int mx = INT_MAX)
{
    std::cout<<write;
    int test = 0;
    while(1)
    {
        if( !(std::cin >> test) ? 1 : (test < mn || test > mx))
        {
            std::cin.clear();
            char c;
            while( (c = std::cin.get()) != '\n' && c != EOF );
        }
        else break;
    }
    return test;
}

//tests
void valDest_int(int* val)
{
    std::cout<<"[valueDestructor()]: valDest called with value = "<<*val<<", which's address is "<<val<<"\n";

    *val = 0;

    std::cout<<"[valueDestructor()]: *val = 0. Done!\n";
}

void predefinedTest_int()
{
    std::vector<int> values( {1,3,2} );

    AVLTree<int> tree;

    for(int i=0; i<values.size(); i++)
    {
        std::cout<<"\nAdding value["<<i<<"] : "<<values[i]<<" to AVL Tree...\n";
        tree.addElement( values[i] );
        std::cout<<"\nDone!\n";
    }
    //tree.showTree();
    tree.showTree(DataShowMode::ValueNHeight, PointerShowMode::NoPointers, BranchShowMode::AllBranches);

    std::cout<<"\n* - * - * - * - * - * - * -\n";

    /*int elem2delete = 4;
    std::cout<<"\nDeleting elem: "<<elem2delete<<"\n";
    tree.deleteElement( elem2delete );
    tree.showTree();
    */

    int searchFor = -1;
    std::cout<<"\nSearhing for element: "<<searchFor<<"\n";

    if(tree.findElement( searchFor ))
        std::cout<<"Element F O U N D !!!\n";
    else
        std::cout<<"Element not found.\n";
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
    std::cout<<"[valueDestructor()]: valDest called with **val = "<<*((int*)(*val))<<", *val = "<<*val<<", and val = "<<val<<"\n";

    delete ((int*)(*val));
    *val = nullptr;

    std::cout<<"[valueDestructor()]: *val delete'd. *val = NULL. Done!\n";
}

const char* elemToString(void* val)
{
    /*char st[16];
    sprintf(st, "%d\0", *((int*)val));*/
    return std::string(toString(*((int*)val))).c_str();
}

void* voidifyInt(int val)
{
    void* patr = (void*)(new int);
    *((int*)patr) = val;
    return patr;
}

void userTest_int()
{
    AVLTree<void*> tree;
    tree.setElemDestructor(valDest_voidInt);
    tree.setElemEvaluator(elemEvaluator_voidInt);
    tree.setElemShower(elemToString);

    int n = getValidatedConInt("\nEnter how many nums you'll write.\n>> ", 1);

    for(int i=0; i<n; i++)
    {
        int tm = getValidatedConInt("["+toString(i)+"]: ");
        tree.addElement( voidifyInt(tm) );
    }

    tree.showTree(DataShowMode::ValueNHeight);

    //tree.showTree();
    //tree.showTree(DataShowMode::ValueNHeight, PointerShowMode::NoPointers, BranchShowMode::AllBranches);

    std::cout<<"\n* - * - * - * - * - * - * -\n";

    int elem2delete = getValidatedConInt("\nEnter elem2delete\n>> ");
    std::cout<<"\nDeleting elem: "<<elem2delete<<"\n";
    tree.deleteElement( voidifyInt(elem2delete) );

    tree.showTree(DataShowMode::ValueNHeight);

    int searchFor = getValidatedConInt("\nEnter elem2search\n>> ");
    std::cout<<"\nSearhing for element: "<<searchFor<<"\n";

    if(tree.findElement( voidifyInt(searchFor) ))
        std::cout<<"Element F O U N D !!!\n";
    else
        std::cout<<"Element not found.\n";

    tree.clear();
    std::cout<<"Clear() ended!\n\n";
}

int main()
{
    userTest_int();

    return 0;
}
