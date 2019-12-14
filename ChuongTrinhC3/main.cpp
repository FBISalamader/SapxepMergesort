#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 1000

struct Node
{
    int data;
    Node *next;
};

typedef Node* List;

void nhapMang (List &L);
int random (int minN, int maxN);
void addTail (List &L, int x);
Node *createNode (int x);
void xuatMang (List L);
void mergeSort (List &L);
void tach (List L, List &L1, List &L2);
Node *getMid (List L);
Node *merge (List L1, List L2);

int main()
{
    List L;
    L = NULL;
    nhapMang(L);
    mergeSort(L);
    printf ("List sau khi sap xep la:\n");
    xuatMang(L);
    return 0;
}

Node *merge (List L1, List L2)
{
    List L = NULL;
    if (!L1)
        return L2;
    else if (!L2)
        return L1;
    if (L1->data < L2->data)
    {
        L = L2;
        L->next = merge(L1,L2->next);
    }
    else
    {
        L = L1;
        L->next = merge(L1->next,L2);
    }
    return L;
}

Node *getMid (List L)
{
    Node *p, *q;
    p = q = L;
    while (q->next && q->next->next)
    {
        q = q->next->next;
        p = p->next;
    }
    return p;
}

void tach (List L, List &L1, List &L2)
{
    Node *mid = getMid(L);
    L1 = L;
    L2 = mid->next;
    mid->next = NULL;
}

void mergeSort (List &L)
{
    List L1,L2;
    L1 = L2 = NULL;
    if (!L || !L->next)
        return;
    tach(L,L1,L2);
    mergeSort(L1);
    mergeSort(L2);
    L = merge (L1,L2);
}

void xuatMang (List L)
{
    Node *p;
    for (p = L; p != NULL; p = p->next)
        printf ("%d ", p->data);
}

Node *createNode (int x)
{
    Node *p = new Node();
    p->data = x;
    p->next = NULL;
    return p;
}

void addTail (List &L, int x)
{
    Node *p = createNode(x);
    if (!L)
        L = p;
    else
    {
        Node *q = L;
        while (q->next)
            q = q->next;
        q->next = p;
    }
}

int random (int minN, int maxN)
{
    return minN + rand() % (maxN + 1 - minN);
}

void nhapMang (List &L)
{
    FILE *fo;
    fo = fopen("SoNgauNhien.txt", "wt");
    int A[SIZE];
    srand((int)time(0));
    for (int i=0; i<1000; i++)
    {
        A[i] = random(1,1000);
        addTail(L, A[i]);
        if (i != 0 && i % 50 == 0)
            fprintf(fo, "\n");
        else
            fprintf (fo, "%d ", A[i]);
        i++;
    }
    fclose(fo);
}

