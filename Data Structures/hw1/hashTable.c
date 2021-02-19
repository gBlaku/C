#include <stdio.h>
#include <stdlib.h>




typedef struct Node{
  int data;
  struct Node* next;
}Node;



typedef struct hashTable{
  int tenK;
  struct Node** hashR;
}hashTable;


Node* createNode(Node* first, int num){
  Node* new = (Node*)malloc(sizeof(struct Node));
  new->data = num;
  new->next = first;
  first = new;
  return first;
}

int findNum(int number, hashTable* bigTable){
  int index;
  if (number <0){
    index = ((number % 10000) + 10000);
      }
  else{
    index = (number % 10000);
      }
  
  // Node* indexTraverse = bigTable->hashR[index];
  if (bigTable->hashR[index] == NULL){
    return 0;
  }

  if (bigTable->hashR[index]->data == number){
    //    printf("Found ");
    // printf("%d ", number);
    // printf("in index ");
    // printf("%d\n", index);
    return 1;
  }
  
 Node* indexTraverse=bigTable->hashR[index];

 while (indexTraverse!=NULL){
   // printf("indexTraverse->data = ");
   //  printf("%d\n", indexTraverse->data);
   //   printf("Does this match with ");
   //  printf("%d?\n", number);
      if (indexTraverse->data == number){
	
	//    printf("Found ");
        // printf("%d ", number);
        // printf("in index ");
        // printf("%d\n", index);
   
	return 1;
      }
      indexTraverse = indexTraverse->next;
    }
 // printf("\n");
  return 0;
}




int  placeInHash(Node* node, hashTable* bigTable){
  int index;
  Node* ptr;
  int collisionCounter =0;
  int num = node->data;
  
  if (num <0){
     index = ((num % 10000) + 10000);
  }
  else{
    index = (num % 10000);
  }
  
  if (bigTable->hashR[index] == NULL){ // no collision
    bigTable->hashR[index] = node;   // simply add node to this index
    //   printf("Insterted ");
    // printf("%d ", num);
    // printf("in index ");
    // printf("%d\n", index);
    return 0;
  }
  // printf("Collided\n");
  collisionCounter +=1; // If it isn't null then there is a value here.. so collision +=1;

  
  // Node* prev = bigTable ->hashR[index];
  ptr = bigTable ->hashR[index];// Loop through LL of current index
  while (ptr->next !=NULL){            // finding collisions
    // collisionCounter +=1;
    //  printf("Collided\n");
      ptr = ptr->next;
    }
  //  collisionCounter +=1;
  ptr->next  = node;                 // when ptr is NULL (end of LL) insert node
  // printf("Insterted ");
  //  printf("%d ", num);
  //  printf("in index ");
  //  printf("%d\n", index);
   
  return collisionCounter;

}
  
int main(int argc, char* argv[])
{

  FILE *inputFile = fopen(argv[1],"r");
  if (inputFile == NULL){
  printf("error\n");
    return 1;
  }
  
  
  /* Create hash table of 10000 and fill with NULL */ 
  hashTable* table = (hashTable*)malloc(sizeof(struct hashTable));
  table-> tenK = 10000;
  table-> hashR =(Node*)malloc(10000*sizeof(struct Node));
  for (int i=0; i<10000; i++)
    table->hashR[i] = NULL;

  // printf("Hash table is now filled with nulls\n\n");
  
  
  Node* LL = NULL;

  char lineChar;
  int  lineNum;
  int  collisionCounter =0;
  int  searchCounter    =0;
  while (fscanf(inputFile, "%c\t%d\n", &lineChar, &lineNum) !=EOF){
    if (lineChar == 'i'){
      LL = NULL;
      LL = createNode(LL, lineNum);  
      collisionCounter += placeInHash(LL,table);
    }

    if (lineChar == 's'){
      //  printf("Searching for ");
      // printf("%d\n", lineNum);
      searchCounter += findNum(lineNum,table);
    }
  }


  

  
 
  printf("%d\n", collisionCounter);
  printf("%d\n", searchCounter);

  Node* hRow;
  Node* hRowptr;

  
  for (int i =0; i<10000; i++){
    hRow = table->hashR[i];
    while(hRow !=NULL){
      hRowptr = hRow;
      hRow = hRow->next;
      free(hRowptr);
    }
  }
  free(table->hashR);
  free(table);

  fclose(inputFile);
  
    return 0;
}
  
      
      
