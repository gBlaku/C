#include <stdio.h>


int main(int argc, char* argv[])
{

  if (argc < 2){
      printf("\n");
      return 0;
    }


  // VOWELS = (a, e, i, o, u, A, E, I, O, U)

  //For each word in argv, end at null
  for (char** pntArgV = argv+1; *pntArgV !=NULL; *pntArgV++){
    
    //Loop through each char in each individual word (pntArgV)
    char *ptrPtr = *pntArgV;
    while (*ptrPtr != 0){
      if (*ptrPtr == 'a' || *ptrPtr == 'A' || *ptrPtr =='e' || *ptrPtr == 'E' || *ptrPtr == 'i' || *ptrPtr =='I' ||
          *ptrPtr == 'o' || *ptrPtr == 'O' || *ptrPtr =='u' || *ptrPtr == 'U')
	printf("%c", *ptrPtr);

      ptrPtr +=1;
    }
  }
}
