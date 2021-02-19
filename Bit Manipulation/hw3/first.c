#include <stdio.h>
#include <string.h>


unsigned short binToDec(int binary[16], int width);
int* set(int binary[16],  int n, int v, int width);
int* comp(int binary[16], int n, int ignore, int width);
int get(int binary[16], int n);

int main(int argc, char* argv[])
{
  //int binary[16];
  //  int* binaryP;
  
  unsigned short x;
  

  //  char setS[4] = {'s', 'e', 't', '\0'};
  // char getS[4] = {'g', 'e', 't', '\0'};
  //char compS[5] = {'c', 'o', 'm', 'p', '\0'};
  
  // int getBit;
  // LSB (index 0) should be binary[15] -- the last element


  FILE* file = fopen(argv[1], "r");
  if (file == NULL){
    printf("error\n");
    return 1;
  }
  fscanf(file,"%hu", &x);
  
  
  
  /*
  for (int i=0; i<16; i++){
    if (x==0)
      break;
    binary[i] = (x % 2);
    x = x >>1;
    width+=1;
  }
  binaryP = binary;
  */

  while(1){
    char instruction[10];
    int n, v;
    int k = fscanf(file, "%s\t%d\t%d", instruction, &n, &v);
      if (k !=3){
	break;
      }
  switch(instruction[0]){
    //get	
  case 'g':
    printf("%d\n", (1&&(x&(1<<n))));
    break;
    //set
  case 's':
    if (v==1)
      x = (x | (1<<n));
    else if (v ==0)
      x = (x & (~(1<<n)));
	   
    printf("%u\n", x);
    break;
    //comp
  case 'c':
    x = (x ^ (1<<n));
    printf("%u\n", x);
    break;

    //should never happen... i hope 
  default:
    printf("error\n");
    
   } //endSwitch
  
  }//end readfile
  
  fclose(file);
  return 0;
  
}

unsigned short binToDec(int binary[16], int width){
  unsigned short decimal = 0;
  unsigned short twos = 1;
  unsigned short binIndex = 0;
  
  for (int i=0; i<width; i++){
    twos = 1;
    
    if (i == 0 && binary[0] ==1){
      decimal += 1;
      binIndex +=1;
      continue;
    }
    
    else{
      if (binary[i] == 1){
	for (int j=0; j<binIndex; j++)
	  twos *=2;
      
	decimal += twos;
      }
    } // end else
    binIndex +=1; 
  }
      
      return decimal;
}

int* set(int binary[16], int n, int v, int width){
  // unsigned short decimal;
  
  binary[n] = v;
  //decimal = binToDec(binary, width);
  
  return binary;
}
int* comp(int binary[16], int n, int ignore, int width){
  //unsigned short decimal;
  binary[n] = ~(binary[n]);

  //  decimal = binToDec(binary, width);
  
  return binary;
}
  
int get(int binary[16], int n){
  return binary[n];
}
