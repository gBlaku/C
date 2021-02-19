#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* next;
}Node;

struct Node* recursiveDelList(Node* head, int num){
  
  if (head == NULL)
    return NULL;

  if (head->data == num){
    Node* nextPtr = head->next;
    free(head);
    return nextPtr;
  }
  head ->next = recursiveDelList(head->next, num);
  return head;
}


struct Node* sortedInsert(Node* head, int num){

  Node* loop;


  //THIS MEANS LIST IS EMPTY, INSERT INTO HEAD
  if (head == NULL){
    head =(Node*) (Node*)malloc(sizeof(struct Node));
    head->data = num;
    head->next = NULL;
    return head;
  }
  
  // Num is less than head, so insert it right before and make it new head
  
  
  else if ( head->data > num){
    Node* node = (Node*)malloc(sizeof(struct Node));
    node->data = num;
    node-> next = head;
    return node;
  }
  
  //Otherwise, we have to loop through LL until our num is greater than prev and less than or equal to current
  else{
    for (Node* loopTwo = head; loopTwo !=NULL; loopTwo = loopTwo->next){
      if (loopTwo -> data >= num){
	Node* node = (Node*)malloc(sizeof(struct Node));
	node->data = num;
	node->next = loop->next;
	loop   ->next = node;
        return head;
      }
      loop = loopTwo;
    }
  
    //END LOOP


    //If we get here, we are inserting to end of LL (highest number)
    Node* node = (Node*)malloc(sizeof(struct Node));
    node->data = num;
    node->next = NULL;
    loop->next = node;

    return head;
   
  }
}
  
        
  
  

int main(int argc, char* argv[])
{
  Node* head = NULL;

  
  int lineNum;
  char  lineChar;
  int nodeCounter = 0;

  if (argc !=2){
    printf("error\n");
    return 1;
  }

  FILE *inputFile = fopen(argv[1], "r");
  
  if (inputFile == NULL){
     printf("error\n");
    return 1;
  }
  
  
  while(fscanf(inputFile, "%c\t%d\n", &lineChar, &lineNum)==2){
   
    if (lineChar == 'i'){
          head = sortedInsert(head,lineNum);
  }

    else if (lineChar == 'd'){
	head = recursiveDelList(head,lineNum);
    }
   

  }
  
  


   Node * headC = head;
  while(headC!=NULL){
    nodeCounter +=1;
    headC = headC->next;
  }

  printf("%d\n", nodeCounter);

  
  headC = head;
  while (headC!=NULL){
    printf("%d\t", headC->data);
    headC = headC->next;
  }
  
  
  Node* temp = NULL;
  while (head!=NULL){
    temp = head;
    head = head->next;
    free(temp);
  }
  
  
  fclose(inputFile);
  return 0;
}
