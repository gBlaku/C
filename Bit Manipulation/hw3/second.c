#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[])
{
  unsigned short x = atoi(argv[1]);
  int binary[16];//2^16
  int width=0;//how many bits of binary
  int p=0;  //parity.. number of 1's
  int pp=0; //pairs of 1's (not overlapping)
  int P; //final parity check
  //Unsigned short max: 65,535... 2^16... 16 binary values.. array of 16 to represent number in binary

  
  for (int index=0; index<16; index++){
    binary[index] = (x%2);
    x = x>>1;
    width +=1;
  }

  int binaryReal[width];

  for(int i=0; i<width; i++){
    binaryReal[i] = binary[i];
  }


  for (int i=0; i<width; i++){
    if (binaryReal[i] ==1)
      p +=1; //num of 1s
  }

  for (int i=1; i<width; i++){
    if (binaryReal[i] ==1 && binaryReal[i-1] == 1){
      pp +=1; //pairs
      i  +=1; //skip over to ensure no overlapping
    }
  }
    
  P = (p%2);

  if (P ==1)
    printf("Odd-Parity\t");
  else
    printf("Even-Parity\t");

  printf("%d\n", pp);

  return 0;
  
}
