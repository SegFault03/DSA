#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char n;
    struct Node *next;
}Node;

int MAX,c;
Node *top;

Node* create(char n)
{
    Node *temp;
    temp = (Node*)malloc(sizeof(Node));
    temp->n=n;
    temp->next=NULL;
    return temp;
}

void push(char ch)
{
    Node *t=NULL;
    if(top!=NULL)
    {
        t=create(ch);
        t->next=top;
        top=t;
        c++;
    }
    else if(top==NULL)
    {
        top=create(ch);
        c++;
    }
    else
    printf("\nThe stack is full");
}

char pop()
{
    char ch;
    if(top!=NULL)
    {
        ch=top->n;
        Node *t=top;
        top=top->next;
        c--;
        free(t);
    }
    else
    printf("\nStack is empty!");
    return ch;
}

int isFull()
{
    if(c==MAX)
    return 1;
    else
    return 0;
}

int isEmpty()
{
    if(c==0)
    return 1;
    else
    return 0;
}

char peek()
{
    return top->n;
}

void display()
{
    Node *t=top;
    printf("\n");
    while(t)
    {
        printf("%c\t",t->n);
        t=t->next;
    }
}

//DRIVER FUNCTION:
// int main()
// {
//     int ch=0, p;
//     char cha;
//     c=0;
//     top=NULL;
//     printf("\nEnter the maximum number of nodes:\n");
//     scanf("%d",&MAX);
//     printf("Enter 1 to push, 2 to pop, 3 to peek, 4 to display\n5 to check if empty, 6 to check if full, 0 to exit\n");
//     scanf("%d",&ch);
//     while(ch)
//     {
//         switch(ch)
//         {
//             case 1:
//             push();
//             display();
//             break;

//             case 2:
//             cha=pop();
//             display();
//             break;

//             case 3:
//             printf("\n%c",peek());
//             break;

//             case 4:
//             display();
//             break;

//             case 5:
//             if(isEmpty())
//             printf("\nStack is empty");
//             break;

//             case 6:
//             if(isFull())
//             printf("\nStack full");
//             break;

//             default:
//             printf("\nEnter correct choice:");
//             break;
//         }
//         printf("\n\nEnter 1 to push, 2 to pop, 3 to peek, 4 to display\n5 to check if empty, 6 to check if full, 0 to exit\n");
//         scanf("%d",&ch);
//     }
// }

