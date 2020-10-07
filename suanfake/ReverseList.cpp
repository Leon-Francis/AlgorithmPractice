#include <iostream>
using namespace std;
typedef struct Node
{
    int data;
    struct Node *next;
} * Pointer;

void reverseList(Pointer p, Pointer& Head)
{
    if(p == NULL || p->next == NULL)
    {
        Head = p;
        return;
    }
    Pointer ptemp = p->next;
    reverseList(ptemp, Head);
    ptemp->next = p;
    p->next = NULL;
    return;
}

int main(int argc, char const *argv[])
{
    Pointer p = new Node;
    Pointer Head;
    p->data = 1;
    Pointer p1 = new Node;
    p1->data = 2;
    p->next = p1;
    Pointer p2 = new Node;
    p2->data = 3;
    p1->next = p2;
    p2->next = NULL;
    reverseList(p, Head);
    return 0;
}
