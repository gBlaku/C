#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
  unsigned short x = atoi(argv[1]);
  int binary[16];
  int palindrome = 0;

  for (int i=0; i<16; i++){
    binary[i] = (x%2);
    x = x>>1;
  }

  int j = 15;
  for (int i=0; i<16; i++){
    if (binary[i] != binary[j]){
      palindrome = 0;
      break;
    }
    else{
      palindrome = 1;
    }
    j --;
  }


  if (palindrome ==1)
    printf("Is-Palindrome\n");
  else
    printf("Not-Palindrome\n");

  return 0;


  
  
}
