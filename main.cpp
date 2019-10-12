#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    Node *next;
};

typedef Node *List;

Node *createNode (int x)
{
    Node *p = new Node;
    p->data = x;
    p->next = NULL;
    return p;
}

void addTail (List &L, int x)
{
    Node *p = createNode(x);
    if(!L)
      L = p;
    else
    {
        Node *r = L;
        while (r->next)
            r = r->next;
        r->next = p;
    }
}

void xuat (List L)
{
    Node *p;
    for (p=L; p->next!=NULL; p = p->next)
    {
        printf ("%d -> ", p->data);
    }
    printf ("%d", p->data);
}

void nhap (List &L)
{
    int n,x;
    printf ("Nhap so phan tu cho List: ");
    scanf ("%d", &n);
    for (int i=0; i<n; i++)
    {
        printf ("Nhap gia tri cho phan tu thu %d: ", i+1);
        scanf ("%d", &x);
        addTail(L,x);
    }
}

Node *merge (List L1, List L2)
{
    if(!L1)
        return L2;
    else if(!L2)
        return L1;
    List L = NULL;
    if(L1->data < L2->data)
    {
        L = L1;
        L->next = merge(L1->next,L2);
    }
    else
    {
        L = L2;
        L->next = merge(L1,L2->next);
    }
    return L;
}

Node *getMid (List L)
{
    Node *p, *q;
    p = q = L;
    while (q->next && q->next->next)
    {
        p = p->next;
        q = q->next->next;
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
    List L1 = NULL, L2 = NULL;
    if(!L || !L->next)
        return;
    tach(L,L1,L2);
    mergeSort(L1);
    mergeSort(L2);
    L = merge(L1,L2);
}

int main()
{
    List L;
    L = NULL;
    nhap(L);
    printf ("List ban dau:\n");
    xuat(L);
    mergeSort(L);
    printf ("\nList sau khi da sap xep:\n");
    xuat(L);
    return 0;
}
