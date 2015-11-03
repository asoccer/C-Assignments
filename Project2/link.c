#include "link.h"


ListNode *newList(void)
// make a new list with a dummy head
{
  ListNode *dummy;
  dummy = (ListNode *)malloc(sizeof(ListNode));
  dummy->next = NULL;
  return dummy;
}

void printList(ListNode *head)
// print the list
{
  ListNode *curr;
  curr = head->next;
  int len = 0;
  while (curr !=NULL)
    {
      if (len == 8)
	{
	  printf("\n"); len = 0;
	}
      printf("%10d ",curr->num);
      len++;
      curr = curr->next;
    }
  printf("\n");
}

// your functions have to be added
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

ListNode *find(ListNode*head,int key)
{
  ListNode*p = head;
  int count = 0;
  while(p!=NULL)
  {
    count++;
    if(count==key)
      return p;
    p = p->next;
  }
}
