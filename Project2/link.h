#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int num;
  struct Node *next;
} ListNode;

ListNode *insert_tail(ListNode *tail, int num);             // insert and element at tail
ListNode *insert_tail_node(ListNode *tail, ListNode *node); // insert node at tail
ListNode *delete(ListNode *prev);                           // deletes the node after previous
ListNode *newList(void);                                    // make a new list with a dummy head
void deleteList(ListNode **head);//Done                            // delete the entire list
void printList(ListNode *head);//Done                             // print the list
ListNode *find(ListNode *head, int num);                    // find the position of the prev node for num



