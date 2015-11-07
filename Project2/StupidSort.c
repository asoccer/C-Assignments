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
int getMaX(int arr[])
{
    int max = arr[0];
    int i =0;
    for(i=1;i<sizeof(arr)/sizeof(int);i++)
        if(max<arr[i])
            max=arr[i];
    return max;
}
int getMultiples(int bigNumber)
{

    int t,multiplier=1;
    while(bigNumber!=0)
        bigNumber = bigNumber%(int)pow(10,multiplier);
        //if(multiplier>1){bigNumber/=pow(10,multiplier-1);}
        multiplier++;
        printf("%d\n",bigNumber);
        printf("%d\n",multiplier);
    return multiplier;
}
int main(int argc,char* argv[])
{
    Node *bucket0,*bucket1,* bucket2,* bucket3,* bucket4,* bucket5,* bucket6,* bucket7,* bucket8,* bucket9;
    bucket0 = newList(),bucket1 = newList(),bucket2= newList(),bucket3= newList(),bucket4= newList(),bucket5= newList(),bucket6= newList(),bucket7= newList(),bucket8= newList(),bucket9= newList();
    //int S[] = {32, 100, 11, 554, 626, 122, 87, 963,265, 108, 9};
    
    //printf("%s",argv[0]);
    /*printf("Seed is: %s\n",argv[1]);
    printf("N is: %s\n",argv[2]);
    printf("low is: %s\n",argv[3]);
    printf("high is: %s\n",argv[4]);*/
    int seed = atoi(argv[1]);
    int N = atoi(argv[2]);
    int low=atoi(argv[3]);
    int high=atoi(argv[4]);
    int S[N];
    int i = 0,t,multiplier =1;
    int max;
    srand(seed);
    for(i=0;i<N;i++)
    {
        S[i] = rand()%(high+1-low)+low;
        printf("%d ",S[i]);
    }
    max = getMaX(S);
    printf("\nMAX %d\n",max);
    max = getMultiples(max);
    printf("Muliples %d\n",max);
    while(multiplier<max){
        for(i=0;i<N;i++)
        {
            t = S[i]%(int)pow(10,multiplier);
            if(multiplier>1){t/=pow(10,multiplier-1);}
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
        Node *buckets[] = {bucket0,bucket1,bucket2,bucket3,bucket4,bucket5,bucket6,bucket7,bucket8,bucket9};
        int count =0 ;
        for(i=0;i<10;i++)
        {
            Node*ptr = buckets[i]->next;
            while(ptr!=NULL)
            {
                S[count] = ptr->data;
                count++;
                ptr = ptr->next;
            }
        }
        for(i=0;i<sizeof(S)/sizeof(int);i++){printf("%d ",S[i]);}
        printf("\n\n");
        multiplier++;
        deletelist(&bucket0);deletelist(&bucket1);deletelist(&bucket2);deletelist(&bucket3);deletelist(&bucket4);
        deletelist(&bucket5);deletelist(&bucket6);deletelist(&bucket7);deletelist(&bucket8);deletelist(&bucket9);
    }
}


