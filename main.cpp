#include <stdio.h>
#include <stdlib.h>

struct Node
{
	Node *next;
	int data;
};

typedef Node *List;

Node *createNode(int x)
{
	Node *p = new Node;
	if(!p)
        exit(1);
	p->data = x;
	p->next = NULL;
	return p;
}

void addTail(List &l, int x)
{
	Node *p = createNode(x);
	if(!l)
        l = p;
	else
	{
		Node *r = l;
		while (r->next)
            r = r->next;
		r->next = p;
		r = p;
	}
}

void xuat(List l)
{
	while(l)
    {
		if(l->next)
            printf ("%d -> ", l->data);
		else
            printf ("%d ", l->data);
		l = l->next;
	}
}

void nhap(List &l)
{
	int n, x;
	printf ("Nhap vao so phan tu cua List : ");
	scanf ("%d", &n);
	for( int i = 0; i< n; i++ )
    {
		printf ("Nhap phan tu thu %d : ", i+1);
		scanf ("%d", &x);
		addTail(l,x);
	}
}

Node *merge(List l1, List l2)
{
	if(!l2)
        return l1;
	else if(!l1)
        return l2;
    List l = NULL;
	if(l1->data < l2->data)
	{
		l = l1;
		l->next = merge(l1->next, l2);
    }
	else
    {
		l = l2;
		l->next = merge(l1, l2->next);
	}
	return l;
}

Node *getMid(List l)
{
	if(!l)
        return l;
	Node *p, *q;
	p = q = l;
	while(q->next && q->next->next)
	{
		p = p->next;
		q = q->next->next;
	}
	return p;
}

void tach(List l, List &l1, List &l2)
{
	Node *mid = getMid(l);
	l1 = l;
	l2 = mid->next;
	mid->next = NULL;
}

void mergeSort(List &l)
{
	List l1 = NULL, l2 = NULL;
	if( !l || !l->next )
        return;
	tach(l, l1, l2);
	mergeSort(l1);
	mergeSort(l2);
	l = merge( l1, l2);
}

int main()
{
	List l;
	l = NULL;
	nhap(l);
	xuat(l);
	mergeSort(l);
	printf ("\n");
	xuat(l);
	return 0;
}
