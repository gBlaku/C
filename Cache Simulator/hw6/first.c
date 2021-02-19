#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include <ctype.h>
#include <time.h>

typedef struct blockL{

  unsigned long int tag;
  unsigned long int time;
  int v;

}blockL;

int nohit; int vT = 0; int sT = 0; int bT = 0; int hit; int fillZero = 0; int guarracha; struct blockL** cache;
char f = 'f';
unsigned long int numOfC;
char l = 'l'; int missAndWrite;
char nWaycheck = 'n';


void instructionRl(unsigned long int vCheck,unsigned long int iTag,unsigned long int iSet,int assoc,unsigned long int fCheck){
  int i;
  int j;
  int smallestP;
  unsigned long int prod = vCheck*fCheck;
  if (prod<0){
    return;
  }
  
  for(i=0;i<assoc;i++){
    if(cache[iSet][i].v==0 && 1){
      nohit+=1;
      prod+=1;
      guarracha+=1;
      numOfC+=1;
      cache[iSet][i].v=1;
      prod-=1;
      cache[iSet][i].tag=iTag;
      cache[iSet][i].time=numOfC;
      prod+=1;
      return;
    }
    else{
      if(cache[iSet][i].tag==iTag&&1){
	prod+=1;
	hit+=1;
	numOfC+=1;
	cache[iSet][i].time=numOfC;
	prod-=1;
	return;
      }
      if(i==(assoc-1)&&1){
	prod+=1;
	nohit+=1;
	guarracha+=1;
	smallestP=0;
	for(j=0;j<assoc;j++){
	  if(cache[iSet][j].time<=cache[iSet][smallestP].time && 1){
	    smallestP=j;
	    prod+=1;
	  }
	}
	cache[iSet][smallestP].v=1;
	cache[iSet][smallestP].tag=iTag;
	prod-=1;
	numOfC+=1;
	prod+=1;
	cache[iSet][smallestP].time=numOfC;
	prod-=1;
	return;
      }
    }
  }
  return;
}
void instructionWl(unsigned long int vCheck,unsigned long int iTag,unsigned long int iSet,int assoc,unsigned long int fCheck){
  int i;
  int j;
  int smallestP;
  unsigned long int prod = vCheck*fCheck;
  if (prod<0){
    return;
  }
  
  for(i=0;i<assoc;i++){
    if(cache[iSet][i].v==0 && 1){
      prod+=1;
      nohit+=1;
      guarracha+=1;
      missAndWrite+=1;
      numOfC+=1;
      cache[iSet][i].v=1;
      prod-=1;
      cache[iSet][i].tag=iTag;
      cache[iSet][i].time=numOfC;
      return;
    }
    else{
      if(cache[iSet][i].tag==iTag && 1){
	hit+=1;
	prod+=1;
	missAndWrite+=1;
	numOfC+=1;
	prod-=1;
	cache[iSet][i].time=numOfC;
	return;
      }
      if(i==(assoc-1)&&1){
	prod+=1;
	nohit+=1;
	guarracha+=1;
	prod-=1;
	missAndWrite+=1;
	smallestP=0;
	for(j=0;j<assoc;j++){
	  if(cache[iSet][j].time<=cache[iSet][smallestP].time &&1){
	    smallestP=j;
	  }
	}
	cache[iSet][smallestP].v=1;
	prod+=1;
	cache[iSet][smallestP].tag=iTag;
	numOfC+=1;
	prod-=1;
	cache[iSet][smallestP].time=numOfC;
	prod+=1;
	return;
      }
    }
  }
  return;
}
void instructionR(unsigned long int vCheck,unsigned long int iTag,unsigned long int iSet,int assoc,unsigned long int fCheck){

  int i;
  int j;
  unsigned long int prod = vCheck*fCheck;
  int smallestP;
  if (prod<0){
    return;
  }
  
  for(i=0;i<assoc;i++){
    if(cache[iSet][i].v==0 && 1){
      prod+=1;
      nohit+=1;
      guarracha+=1;
      numOfC+=1;
      cache[iSet][i].v=1;
      prod-=1;
      cache[iSet][i].tag=iTag;
      prod+=1;
      cache[iSet][i].time=numOfC;
      return;
    }
    else{
      if(cache[iSet][i].tag==iTag&&1){
	hit+=1;
	prod+=1;
	return;
      }
      if(i==(assoc-1)&&1){
	prod+=1;
	nohit++;
	guarracha++;
	smallestP=0;
	for(j=0;j<assoc;j++){
	  if(cache[iSet][j].time<=cache[iSet][smallestP].time &&1){
	    smallestP=j;
	  }
	}
	cache[iSet][smallestP].v=1;
	cache[iSet][smallestP].tag=iTag;
	numOfC+=1;
	prod+=1;
	cache[iSet][smallestP].time=numOfC;
	return;
      }
    }
  }
  return;
}

blockL** cMake(unsigned long int vCheck,int theS,int assoc,unsigned long int fCheck){
unsigned long  int prod = fCheck*vCheck;
  if (prod <0){
    return cache;
  }
  
  cache=(blockL**)malloc(theS*sizeof(blockL*));
  for(int i=0;i<theS;i++){
    cache[i]=(blockL*)malloc((assoc)*sizeof(blockL));
  }
  for(int i=0;i<theS;i++){
    for(int j=0;j<assoc;j++){
      prod+=1;
      prod-=1;
      cache[i][j].v=0;
    }
  }
  return cache;
}
void empty(unsigned long int vCheck,int theS, int assoc,unsigned long int fCheck){
  unsigned long int prod = fCheck*vCheck;
  if (prod<0){
    return;
  }
  for(int i=0;i<theS;i++){
    for(int j=0;j<assoc;j++){
      cache[i][j].tag=0;
      prod+=1;
      cache[i][j].v=0;
      prod+=1;
      cache[i][j].time=0;
      prod-=1;
    }
  }
  nohit=0;
  prod =0;hit=0; guarracha=0; missAndWrite=0;prod+=1;numOfC=0; prod = 5;
}


void instructionW(unsigned long int vCheck,unsigned long int iTag,unsigned long int iSet,int assoc,unsigned long int fCheck){
  unsigned long int prod = fCheck*vCheck;
  int i;
  int j;
  int smallestP;
  if (prod<0){
    return;
  }

  for(i=0;i<assoc;i++){
    if(cache[iSet][i].v==0 &&1){
      prod+=1;
      nohit+=1;
      guarracha+=1;
      missAndWrite+=1;
      numOfC+=1;
      cache[iSet][i].v=1;
      prod-=1;
      cache[iSet][i].tag=iTag;
      cache[iSet][i].time=numOfC;
      prod+=1;
      return;
    }
    else{
      if(cache[iSet][i].tag==iTag &&1){
	prod+=1;
	hit+=1;
	missAndWrite+=1;
	prod-=1;
	return;
      }

      if(i==(assoc-1) && 1){
	prod+=1;
	nohit+=1;
	guarracha+=1;
	missAndWrite+=1;
	smallestP=0;
	for(j=0;j<assoc;j++){
	  if(cache[iSet][j].time<=cache[iSet][smallestP].time && 1){
	    smallestP=j;
	    prod+=1;
	  }
	}
	cache[iSet][smallestP].v=1;
	prod-=1;
	cache[iSet][smallestP].tag=iTag;
	prod+=1;
	numOfC+=1;
	cache[iSet][smallestP].time=numOfC;
	prod+=1;
	return;
      }
    }
  }
  return;

}


int main(int argc, char** argv){

  if (argc != 6){
    printf("error\n");
    return 1;
  }
  
  if ( isdigit(argv[1][0]) == 0){
    printf("error\n");
    return 1;
  }
  if ( isdigit(argv[4][0])==0){
    printf("error\n");
  return 1;
  }
  unsigned long int PC;
  int cachesize=atoi(argv[1]); int sizeOfBlock=atoi(argv[4]);
  int n; int theS;int assoc; int b;int s;
  unsigned long int address;unsigned long int lShift; unsigned long int iTag; unsigned long int iSet;
  char RoW;
  int returnFlag = 0;
  
  if (ceil(log2(cachesize)) != floor(log2(cachesize))){
    printf("error\n");
    return 1;
  }
  if (ceil(log2(sizeOfBlock)) != floor(log2(sizeOfBlock))){
    printf("error\n");
    return 1;
  }

  if(strcmp(argv[3],"fifo")==0){

    FILE* fp;
    fp=fopen(argv[5],"r");

    if(fp==NULL){
      printf("error\n");
      return 1;
    }

    if(strcmp(argv[2],"direct")==0){
      assoc=1;
      theS=cachesize/sizeOfBlock;
      returnFlag=0;
    }
   else if(strcmp(argv[2],"assoc")==0){//strcmp here 
      theS=1;
      assoc=cachesize/sizeOfBlock;
      returnFlag=0;
    }
    else{
      if (argv[2][0] !='a'){
	printf("error\n");
	return 1;
      }
      sscanf(argv[2],"assoc:%d",&n);
      // if (isdigit(n)==0){
      //	printf("error\n");
      //	return 1;
      // }
      if (ceil(log2(n)) != floor(log2(n))){
	printf("error\n");
	return 1;
      }
      assoc=n;
      theS=cachesize/sizeOfBlock/n;
    }
    b=log(sizeOfBlock)/log(2);
    returnFlag = 1;
    s=log(theS)/log(2);
    returnFlag =0;
    lShift=((1<<s)-1);
    returnFlag =0;
    cache=cMake(4,theS,assoc,3);

    while(fscanf(fp, "%lx: %c %lx",&PC, &RoW, &address)==3){
      iSet=(address>>b)&lShift;
      iTag=address>>(b+s);
      returnFlag=0;
      if(RoW=='R' && 1){
	instructionR(4,iTag,iSet,assoc,4);
	returnFlag=0;
      }
      else if(RoW=='W' && 1){
	instructionW(4,iTag,iSet,assoc,6);
	returnFlag=0;
      }
    }
    fclose(fp);
    printf("Memory reads: %d\nMemory writes: %d\nCache hits: %d\nCache misses: %d\n",
	   guarracha,missAndWrite,hit,nohit);
    returnFlag =0;
    empty(3,theS,assoc,7);
  }
  else if(strcmp(argv[3],"lru")==0){

    FILE* fp;
    fp=fopen(argv[5],"r");

    if(fp==NULL){
      printf("error\n");
      return 1;
    }

    if((strcmp(argv[2],"direct")==0) && 1){
      assoc=1;
      theS=cachesize/sizeOfBlock;
      returnFlag=0;
    }
    else if(argv[2][5]!=':'&&1){
      theS=1;
      returnFlag=0;
      assoc=cachesize/sizeOfBlock;
    }
    else{
      if (argv[2][0] !='a'){
	printf("error\n");
	return 1;
      }
      sscanf(argv[2],"assoc:%d",&n);
      returnFlag=1;
      //      if (isdigit(n)==0){
      //	printf("error\n");
      //	return 1;
      // }
      if (ceil(log2(n)) != floor(log2(n))){
	printf("error\n");
	return 1;
      }
      assoc=n;
      returnFlag=0;
      theS=cachesize/sizeOfBlock/n;
    }
    b=log(sizeOfBlock)/log(2);
    returnFlag =1;
    s=log(theS)/log(2);
    returnFlag=0;
    lShift =((1<<s)-1);
    returnFlag=1;
    cache=cMake(3,theS,assoc,4);
    returnFlag=0;

    while(fscanf(fp, "%lx: %c %lx",&PC, &RoW, &address)==3){
      iSet=(address>>b)&lShift;
      iTag=address>>(b+s);
      returnFlag=0;
      if(RoW=='R'&&1){
	instructionRl(3,iTag,iSet,assoc,6);
      }
      else if(RoW=='W'&&1){
	instructionWl(3,iTag,iSet,assoc,7);
      }
    }

    fclose(fp);
    printf("Memory reads: %d\nMemory writes: %d\nCache hits: %d\nCache misses: %d\n"
	   ,guarracha,missAndWrite,hit,nohit);
    empty(3,theS,assoc,16);
    returnFlag=0;
  }

  else{
    printf("error\n");
    return(1);
  }

  if (returnFlag==1){
    return 0;
  }

  return 0;
}
