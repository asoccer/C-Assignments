#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int random;
	struct Node* next;
}Node;


void print_list(Node * head) {
    Node * current = head;
    Node *next;
    while(current!=NULL)
    {
    	printf("%d\n", current->random);	
    	current = current->next;
    }
}

Node *new_node(int rand1)
{
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->random = rand1;
	new_node->next = NULL;
	return new_node;
}
void insertNodeSorted(Node* head, Node* new_node)
{//Insert a Node into the CORRECT place.
	Node* current = head;
	while(current->next!=NULL && current->next->random < new_node->random)
	{
		current = current->next;
	}
	new_node->next = current->next;
	current->next = new_node;
}

void deleteList(Node **head)
{
   Node *current = *head;
   Node *next;
   while(current!=NULL)
   {
   		next = current->next;
   		free(current);
   		current=next;
   }
   *head = NULL;
}
int main(int argc, char** argv)
{
	Node* head = malloc(sizeof(Node));
	int i= 0;
	int temp = 0;
	head->random = 4;
	head->next = NULL;
	printf("Random Number %d | Number of Randoms to make %d\n",atoi(argv[1]),atoi(argv[2]));
	srand(atoi(argv[1]));
	for(i=0;i<atoi(argv[2]);i++)
	{
		temp = rand()%atoi(argv[3]);
		insertNodeSorted(head,new_node(temp));
	}
	printf("List\n");
	print_list(head);
	printf("Deleted List!\n");
	deleteList(&head);
}


