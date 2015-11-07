#include <stdlib.h>
#include <stdio.h>
#include <math.h>


typedef struct Node
{
    int data;
    struct Node* next;
}Node;

void insert(int data,Node *pointer)
{
    while(pointer->next!=NULL)
    {
            pointer = pointer -> next;
    }
    pointer->next = (Node *)malloc(sizeof(Node));
    pointer = pointer->next;
    pointer->data = data;
    pointer->next = NULL;
}

void print(Node *pointer)
{
    if(pointer==NULL)
    {
        return;
    }
    printf("%d ",pointer->data);
    print(pointer->next);
}
Node *newList(void)
{
    Node *start,*temp;
    start = (Node*)malloc(sizeof(Node));
    start->next = NULL;
    return start;
}

void deletelist(Node **head)
{
    Node* current = *head;
    current = current->next;
    Node* n;
    while(current!=NULL)
    {
        n = current->next;
        free(current);
        current = n;
    }
    *head= newList();
}
int collect[](Node *head)
{
    int sum[20] = {};
    int count=0;
    Node *current = head->next;
    while(current!=NULL)
    {
        sum[count] =current->data;
        current = current->next;
        count++;
    }
    return sum;
}


int Length(Node* head)
{
    int count = 0;
    Node* current = head;
    while(current!=NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}
void main()
{
    Node *bucket0,*bucket1,* bucket2,* bucket3,* bucket4,* bucket5,* bucket6,* bucket7,* bucket8,* bucket9;
    bucket0 = newList(),bucket1 = newList(),bucket2= newList(),bucket3= newList(),bucket4= newList(),bucket5= newList(),bucket6= newList(),bucket7= newList(),bucket8= newList(),bucket9= newList();
    int S[] = {32, 100, 11, 554, 626, 122, 87, 963,265, 108, 9};
    int i = 0,t,multiplier =1;
    while(multiplier<4){
        for(i=0;i<11;i++)
        {
            t = S[i]%(int)pow(10,multiplier);
            if(multiplier>1){t/=10;t/=10;}
            if(t==0){insert(S[i],bucket0);}
            if(t==1){insert(S[i],bucket1);}
            if(t==2){insert(S[i],bucket2);}
            if(t==3){insert(S[i],bucket3);}
            if(t==4){insert(S[i],bucket4);}
            if(t==5){insert(S[i],bucket5);}
            if(t==6){insert(S[i],bucket6);}
            if(t==7){insert(S[i],bucket7);}
            if(t==8){insert(S[i],bucket8);}
            if(t==9){insert(S[i],bucket9);}
        }

        print(bucket0->next);print(bucket1->next);print(bucket2->next);print(bucket3->next);print(bucket4->next);
        print(bucket5->next);print(bucket6->next);print(bucket7->next);print(bucket8->next);print(bucket9->next);
        int arr[] = {collect(bucket0)};

        printf("\n\n");
        multiplier++;
        deletelist(&bucket0);deletelist(&bucket1);deletelist(&bucket2);deletelist(&bucket3);deletelist(&bucket4);
        deletelist(&bucket5);deletelist(&bucket6);deletelist(&bucket7);deletelist(&bucket8);deletelist(&bucket9);
    }

}




