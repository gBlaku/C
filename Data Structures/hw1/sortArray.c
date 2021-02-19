#include <stdio.h>

void ascendingSort(int evens[], int numSize){
  int curr;
  int j;
  for (int i=1; i<numSize; i++){
    curr = evens[i];
    j = i-1;

    while (curr < evens[j] && j>= 0){
      evens[j+1] = evens[j];
      j -= 1;
    }
    evens[j+1] = curr;
  }

  // printf("Sorted even array: ");
  // for (int i=0; i<numSize; i++){
    // printf("%d ", evens[i]);
  // }
  // printf("\n");
}


  


void descendingSort(int odds[], int oddSize){
  int temp;
  for (int i=0; i<oddSize; i++){
    for (int j=i+1; j<oddSize; j++){
      if (odds[j] > odds[i]){
	temp = odds[i];
	odds[i] = odds[j];
	odds[j] = temp;
      }
    }
  }
}

int main(int argc, char* argv[])
{
  /* We don't need to malloc, it can't be more than 20*/
  int arrSize;
 


  /* Open the file, read it*/
  FILE *arrayFile = fopen(argv[1], "r");

  if (arrayFile == NULL){
    printf("error");
    return 1;
  }

  
  fscanf(arrayFile, "%d", &arrSize);

  int input[arrSize];

  /* Now that we know the size of arr,
     Skip to second line and fill in 
     our array */

  for (int i=0; i<arrSize; i++)
    fscanf(arrayFile, "%d", &input[i]);

  /*Now that we have our array, close
    file to prevent MEMORY LEAK */
  fclose(arrayFile);

  
  int numEvens = 0;
  int numOdds  = 0;

  for (int i=0; i<arrSize; i++){
    if (input[i] %2 ==0)
      numEvens +=1;
  }

  for (int i=0; i<arrSize; i++){
    if (input[i] %2 != 0)
      numOdds +=1;
  }

  int evens[numEvens];
  int odds [numOdds];

  /* Fill in even array */
  int evenLoop =0;
    for (int j=0; j < arrSize; j++){
      if (input[j] % 2 ==0){
	evens[evenLoop] = input[j];
	evenLoop +=1;

      }
    }

    /* Fill in Odd array */
    int oddLoop =0;
    for (int j=0; j < arrSize; j++){
      if (input[j] %2 != 0){
	odds[oddLoop] = input[j];
	oddLoop ++;
      }
    }

   /* Sort both individual arrays */
   ascendingSort  (evens, numEvens);
   descendingSort (odds,  numOdds);


   /*Now combine both (sorted) even and
     odd arrays into one array, evens 
     ascending followed by descending
     odds */
   
   int sorted[arrSize];
   for (int i=0; i<numEvens; i++)
     sorted[i] = evens[i];

   int numEvensClone = numEvens;
   for (int i = 0; i<arrSize; i++){
     sorted[numEvensClone] = odds[i];
     numEvensClone +=1;
   }
     
   
   /* PRINT SORTED ARRAY */
   for (int i =0; i<arrSize; i++)
     printf("%d\t", sorted[i]);

   return 0;
}
