#include <stdio.h>
#include <string.h>
#define SIZE 100

struct SV
{
    char hoTen[30];
    char MSSV [10];
    float t,l,h;
    float dTB;
};

struct Node
{
    SV data;
    Node *next;
};

typedef Node *List;

void nhap (List &L, SV A[]);
void nhap1SV (SV &x);
void addTail (List &L, SV x);
Node *createNode (SV x);
void xuat (List L);
void mergeSort (List &L);
void tach (List L, List &L1, List &L2);
Node *getMid (List L);
Node *merge (List L1, List L2);

int main()
{
    SV A[SIZE];
    List L;
    L = NULL;
    nhap(L,A);
    xuat(L);
    mergeSort(L);
    Node *p;
    printf ("\nList sau khi sap xep la: ");
    for (p=L; p->next != NULL; p = p->next)
    {
        printf ("%s -> ", p->data.hoTen);
    }
    printf ("%s", p->data.hoTen);
    return 0;
}

Node *merge (List L1, List L2)
{
    if (!L1)
        return L2;
    else
        if (!L2)
            return L1;
    List L = NULL;
    if (strcmp(L1->data.hoTen,L2->data.hoTen) < 0)
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
    p=q=L;
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
    List L1=NULL, L2=NULL;
    if(!L || !L->next)
        return;
    tach(L,L1,L2);
    mergeSort(L1);
    mergeSort(L2);
    L = merge(L1,L2);
}

void xuat (List L)
{
    Node *p;
    printf ("List ban dau la: ");
    for (p=L; p->next != NULL; p = p->next)
    {
        printf ("%s -> ", p->data.hoTen);
    }
    printf ("%s", p->data.hoTen);
}

Node *createNode (SV x)
{
    Node *p = new Node;
    p->data = x;
    p->next = NULL;
    return p;
}

void addTail (List &L, SV x)
{
    Node *p = createNode(x);
    if (!L)
        L = p;
    else
    {
       Node *r = L;
       while (r->next)
            r = r->next;
       r->next = p;
    }
}

void nhap1SV (SV &x)
{
    fflush(stdin);
    gets(x.hoTen);
    gets(x.MSSV);
    float t,l,h;
    scanf ("%f%f%f", &t, &l, &h);
    x.t = t;
    x.l = l;
    x.h = h;
    x.dTB = (t+l+h)/3;
}

void nhap (List &L, SV A[])
{
    int n;
    printf ("Nhap so phan tu cua List: ");
    scanf ("%d", &n);
    for (int i=0; i<n; i++)
    {
        printf ("Nhap thong tin cho sinh vien %d: ", i+1);
        nhap1SV(A[i]);
        addTail(L,A[i]);
    }
}
