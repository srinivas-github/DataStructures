#include <cstdio>
#include <cstdlib>

struct SNode
{
    int data;
    struct SNode* next;
};

struct Queue
{
    struct SNode* stack1;
    struct SNode* stack2;
};

void push(struct SNode** top_ref, int data)
{
    struct SNode* newNode = (struct SNode*)malloc(sizeof(struct SNode));
    newNode->data = data;
    newNode->next = *top_ref;
    *top_ref = newNode;
}

int pop(struct SNode** top_ref)
{
    int res;
    struct SNode* top;
    if (*top_ref == NULL)
    {
        printf("Stack Overflow\n");
	return -1;
    }
    else
    {
        top = *top_ref;
	res = top->data
	*top_ref = top->next;
	free(top);
	return res;
    }
}

void enQueue(struct Queue* q, int d)
{
    push(&q->stack1, d);
}

int deQueue(struct Queue* q)
{
    int x;
    if( q->stack1 == NULL && q->stack2 == NULL)
    {
        printf("Q is Empty\n");
	return -1;
    }
    
    if (q->stack2 == NULL)
    {
        while (q->stack1 != NULL)
	{
	    x = pop(&q->stack1);
	    push(&q->stack2, x);
	}
    }
    x = pop(&q->stack2);
    return x;
}

int main()
{
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    enQueue(q, 10);
    enQueue(q, 20);
    enQueue(q, 30);

    printf("%d ", deQueue(q));
    printf("%d ", deQueue(q));
    printf("%d ", deQueue(q));

    return 0;   
}
