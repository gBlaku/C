#include <stdio.h>
#include<stdlib.h>

typedef struct Node{
 struct  Node* left;
 struct  Node* right;
 int data;
}Node;


struct Node* createNewNode(int num){
  Node* node = (Node*)malloc(sizeof(struct Node));
  node->data = num;
  node->left = NULL;
  node->right = NULL;
  return node;
}

struct Node* insertNode(Node* bst, int data){

  if(bst == NULL)
    bst = createNewNode(data);

  else{
    if (bst->data > data)
      bst->left = insertNode(bst->left,data);
    else if (bst->data < data)
      bst->right = insertNode(bst->right,data);
    else // duplicate, do nothing
      return bst;
  }
  return bst;
}


void printInOrder(Node*bst){
  if (bst == NULL)//BASE CASE
    return;

  else{
    printInOrder(bst->left);//PRINTS FROM LEFT TO RIGHT, IN ORDER
    printf("%d\t",bst->data);
    printInOrder(bst->right);
  }
}

void freePostOrder(Node* bst){
  if (bst!=NULL){
    freePostOrder(bst->right);
    freePostOrder(bst->left);
    free(bst);
  }
}
    


int main(int argc, char* argv[])
{
  FILE* inputFile = fopen(argv[1],"r");

  if (inputFile == NULL){
    printf("error");
    return 1;
  }
  
  char lineChar;
  int  lineNum;  
  Node* bst = NULL;

  
  while (fscanf(inputFile, "%c\t%d", &lineChar, &lineNum)!=EOF){    
    bst = insertNode(bst,lineNum);
  }
  

  printInOrder(bst);
  freePostOrder(bst);  
  fclose(inputFile);
 
  return 0;
}
