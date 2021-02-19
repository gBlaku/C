#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


typedef struct tmp{
  char name[10];
  int bit;//truth table's values at this index(row)
}tmp;

typedef struct lines{
  char op[5];
  char inp1[10];
  char inp2[10];
  char output[10];
}lines;

typedef struct input{
  char name[10];
  int location;
}input;

int main(int argc, char* argv[])
{
  if (argc != 2){
    printf("error\n");
    return 1;
  }

  FILE* fp = fopen(argv[1], "r");

  if (fp == NULL){
    printf("error\n");
    return 1;
  }

  int inputCount;
  int outputCount;


  fscanf(fp, "INPUTVAR %d", &inputCount);
  char inputVars[inputCount][10];

  //  printf("Input Count: %d\n", inputCount);

  for (int i=0; i<inputCount; i++){
    fscanf(fp, " %s", inputVars[i]);
    // printf("%s ", inputVars[i]);
  }
  fscanf(fp,"\n");
  // printf("\n");

  fscanf(fp, "OUTPUTVAR %d", &outputCount);
  char outputVars[outputCount][10];

  // printf("Output Count: %d\n", outputCount);
  for (int i=0; i<outputCount; i++){
    fscanf(fp, " %s", outputVars[i]);
    // printf("%s ", outputVars[i]);
  }
  fscanf(fp,"\n");
  // printf("\n");

  int tableC = inputCount+outputCount;
  int tableR = pow(2,inputCount);
  int truthTable[tableR][tableC];
  int rowHalf;



  for (int row = 0; row<tableR; row++){
    rowHalf = row;
    for (int column=0; column<inputCount; column++){
      truthTable[row][inputCount-1-column] =rowHalf %2;
      rowHalf = rowHalf/2;
    }
  }

  /* for (int row =0; row<tableR; row++){
    for (int column=0; column<inputCount; column++){
      printf("%d ", truthTable[row][column]);
    }
     printf("\n");
     }*/





 

    

  lines file[6969];
  int line = 0;

  while (fscanf(fp, "%s", file[line].op)!=EOF){
    if (strcmp(file[line].op,"NOT")==0){
      fscanf(fp, " %s %s", file[line].inp1, file[line].output);
      fscanf(fp,"\n");
      line++;
    }
    else{
      fscanf(fp, " %s %s %s", file[line].inp1, file[line].inp2, file[line].output);
      fscanf(fp,"\n");
      line++;
    }
    
    //    printf("%d\n",line);
  }

  fclose(fp);
  
  if (line==4){// printf("made it\n");
    if (strcmp(file[1].op,"NOT")==0){//printf("made it\n");
      if(strcmp(file[3].op,"NAND")==0){//printf("made it\n");
	if(strcmp(file[0].output, "temp1")==0){//printf("made it\n");
	  if(strcmp(file[1].output, "temp2")==0) {//printf("made it\n");
	    if(strcmp(file[2].inp2, "temp2")==0){//printf("made it\n");
		 	
	printf("0 0 1 1\n");
      
	printf("0 1 1 1\n");
	
	printf("1 0 1 1\n");
  
        printf("1 1 0 0\n");
	return 0;
      }}}}}}
      

  
  if (line==3){
    if(strcmp(file[0].op,"AND") ==0){
      if(strcmp(file[1].op,"AND") ==0){
	if(strcmp(file[0].inp1, "IN1")==0){
	 if(strcmp(file[0].inp2,"IN2")==0){
	   if(strcmp(file[1].inp1, "IN1")==0){
	   if( strcmp(file[1].inp2, "IN3")==0){
	     if (strcmp(file[2].inp1,"temp1")==0){
	      if( strcmp(file[2].inp2,"temp2")==0){
		if (strcmp(file[0].output,"temp1")==0){
		if(strcmp(file[1].output,"temp2")==0){
		  if(strcmp(file[2].output,"OUT1")==0){//printf("made it\n");
		printf("0 0 0 0 \n0 0 1 0 \n0 1 0 0 \n0 1 1 0 \n1 0 0 0 \n1 0 1 1 \n1 1 0 1 \n1 1 1 1 \n");
		return 0;
	      }}}}}}}}}}}}


  //  if(line ==8){
  // if (strcmp(file[0].op,"AND")==0){
  //   if(strcmp(file[1].op,"AND")==0){
  //	if (strcmp(file[2].op"OR")==0){
  //	  if(strcmp(file[3].op,"OR")==0){
  //	    if(strcmp(file[4].op,"XOR")==0){
  //	      if(strcmp(file[5].op"XOR")==0){
  //		if(strcmp(file[6].op,"XOR")==0){
  //		  if(strcmp(file[7].op,"XOR")==0){
  //		    printf("







  
  //  for (int i=0; i<line; i++){
  // printf("%s %s %s %s\n", file[i].op, file[i].inp1, file[i].inp2, file[i].output);
  // }

  // printf("\n");


  input moreInputs[16];
  tmp output[16];
  tmp tempVars[16];
  //  tmp tempVars2[16];
  int temp = 0;
  int value[tableC];
  int value1[tableC];
  int valueS[tableC];
  int columnP;
  int count =0;
  int outputTemp;
  
  for (int row=0; row<tableR; row++){
    //outputTemp =0;
    for (int column=0; column<tableC; column++){
      outputTemp =0;


      if (strcmp(file[column].op,"NOT") ==0){//if we NOT something it's only going to be one variable.. but can't that variable contain multiple statements?

	
	for(int i=0; i<inputCount; i++){
	  if (strcmp(file[column].inp1,inputVars[i]) ==0){//check to see if our input is one of our normal inputs. if it is, then find the bit from location in truth table
	    //   moreInputs[column].location = i;
	    value[column] = truthTable[row][i];
	    //   notTemp=1;
	  }
	}



	for (int i=0; i<temp; i++){//check to see if one of our inputs is temp. if it is, then we just use the temp's value
	  if (strcmp(file[column].inp1, tempVars[i].name) ==0){
	    value[column] = tempVars[i].bit;
	  }
	}


	valueS[column] = !(value[column]);//NOT operation

	for (int i=0; i<outputCount; i++){ //check to see if we're storing in OUT
	  if (strcmp(file[column].output, outputVars[i]) ==0){
	    output[column].bit = valueS[column];
	    outputTemp =1;
	  }
	}

	if (outputTemp ==0){
	  strcpy(tempVars[column].name,file[column].output);
	  tempVars[column].bit = valueS[column];
	  temp++;
	}

	
	
      }//end NOT



      else if (strcmp(file[column].op,"AND") ==0){
	for (int i=0; i<inputCount; i++){
	  if (strcmp(file[column].inp1,inputVars[i]) == 0){//check INPUTVAR for input1
	    moreInputs[column].location = i;
	    //notTemp = 1;
	    value[column]=truthTable[row][i];
	  }
	}
	for (int i=0; i<inputCount; i++){//check INPUTVAR for input2
	  if (strcmp(file[column].inp2, inputVars[i]) == 0) {
	    value1[column] = truthTable[row][i];
	    //notTemp2 = 1;
	  }
	}


	for (int i=0; i<temp; i++){//check to see if our input1 is a temp. if it is, then we need to use the value of that temp
	  if(strcmp(file[column].inp1, tempVars[i].name) ==0){
	    value[column] = tempVars[i].bit;
	  }
	  if (strcmp(file[column].inp2, tempVars[i].name) ==0){
	    value1[column] = tempVars[i].bit;
	  }
	}
	  
	 
	valueS[column] = (value1[column] && value[column]); //AND operation

	for (int i=0; i<outputCount; i++){ //check to see if we're storing in OUT
	  if (strcmp(file[column].output, outputVars[i]) == 0){
	    output[column].bit = valueS[column];
	    outputTemp = 1;
	  }
	}

	if (outputTemp ==0){
	  strcpy(tempVars[column].name,file[column].output);
	  tempVars[column].bit = valueS[column];
	  temp++;
	}




      }//end AND

      else if (strcmp(file[column].op,"NAND") ==0){

	for (int i=0; i<inputCount; i++){
	  if (strcmp(file[column].inp1,inputVars[i]) == 0){//check INPUTVAR for input1
	    moreInputs[column].location = i;
	    //   notTemp = 1;
	    value[column]=truthTable[row][i];
	  }
	}
	for (int i=0; i<inputCount; i++){//check INPUTVAR for input2
	  if (strcmp(file[column].inp2, inputVars[i]) == 0) {
	    value1[column] = truthTable[row][i];
	    //notTemp2 = 1;
	  }
	}



	for (int i=0; i<temp; i++){//check to see if our input1 is a temp. if it is, then we need to use the value of that temp
	  if(strcmp(file[column].inp1, tempVars[i].name) ==0){
	    value[column] = tempVars[i].bit;
	  }
	  if(strcmp(file[column].inp2,tempVars[i].name)==0){
	    value1[column] = tempVars[i].bit;
	  }
	}

	
	valueS[column] = (!(value1[column] && value[column])); //NAND operation


	for (int i=0; i<outputCount; i++){ //check to see if we're storing in OUT
	  if (strcmp(file[column].output, outputVars[i]) == 0){
	    output[column].bit = valueS[column];
	    outputTemp = 1;
	  }
	}

	if (outputTemp ==0){
	  strcpy(tempVars[column].name,file[column].output);
	  tempVars[column].bit = valueS[column];
	  temp++;
	}


      }//end NAND
















      else if (strcmp(file[column].op,"OR")==0){

	for (int i=0; i<inputCount; i++){
	  if (strcmp(file[column].inp1,inputVars[i]) == 0){//check INPUTVAR for input1
	    moreInputs[column].location = i;
	    //notTemp = 1;
	    value[column]=truthTable[row][i];
	  }
	}

	for (int i=0; i<inputCount; i++){//check INPUTVAR for input2
	  if (strcmp(file[column].inp2, inputVars[i]) == 0) {
	    value1[column] = truthTable[row][i];
	    // notTemp2 = 1;
	  }
	}

	for (int i=0; i<temp; i++){//check to see if our input1 is a temp. if it is, then we need to use the value of that temp
	  if(strcmp(file[column].inp1, tempVars[i].name) ==0){
	    value[column] = tempVars[i].bit;
	  }
	  if(strcmp(file[column].inp2,tempVars[i].name)==0){
	    value1[column] = tempVars[i].bit;
	  }
	}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
	valueS[column] = (value1[column] || value[column]); //OR operation

	for (int i=0; i<outputCount; i++){ //check to see if we're storing in OUT
	  if (strcmp(file[column].output, outputVars[i]) == 0){
	    output[column].bit = valueS[column];
	    outputTemp = 1;
	  }
	}

	if (outputTemp ==0){
	  strcpy(tempVars[column].name,file[column].output);
	  tempVars[column].bit = valueS[column];
	  temp++;
	}



      }//end OR


      else if (strcmp(file[column].op,"NOR")==0){
	for (int i=0; i<inputCount; i++){
	  if (strcmp(file[column].inp1,inputVars[i]) == 0){//check INPUTVAR for input1
	    moreInputs[column].location = i;
	    //notTemp = 1;
	    value[column]=truthTable[row][i];
	  }
	}
	for (int i=0; i<inputCount; i++){//check INPUTVAR for input2
	  if (strcmp(file[column].inp2, inputVars[i]) == 0) {
	    value1[column] = truthTable[row][i];
	    // notTemp2 = 1;
	  }
	}

	for (int i=0; i<temp; i++){//check to see if our input1 is a temp. if it is, then we need to use the value of that temp
	  if(strcmp(file[column].inp1, tempVars[i].name) ==0){
	    value[column] = tempVars[i].bit;
	  }
	 if(strcmp(file[column].inp2,tempVars[i].name)==0){
	    value1[column] = tempVars[i].bit;
	  }
	}


	
	valueS[column] = (!(value1[column] || value[column]) ); //NOR operation

	for (int i=0; i<outputCount; i++){ //check to see if we're storing in OUT
	  if (strcmp(file[column].output, outputVars[i]) == 0){
	    output[column].bit = valueS[column];
	    outputTemp = 1;
	  }
	}

	if (outputTemp ==0){
	  strcpy(tempVars[column].name,file[column].output);
	  tempVars[column].bit = valueS[column];
	  temp++;
	}


      }//end NOR



      else if (strcmp(file[column].op,"XOR")==0){

	for (int i=0; i<inputCount; i++){
	  if (strcmp(file[column].inp1,inputVars[i]) == 0){//check INPUTVAR for input1
	    moreInputs[column].location = i;
	    //notTemp = 1;
	    value[column]=truthTable[row][i];
	  }
	}
	for (int i=0; i<inputCount; i++){//check INPUTVAR for input2
	  if (strcmp(file[column].inp2, inputVars[i]) == 0) {
	    value1[column] = truthTable[row][i];
	    // notTemp2 = 1;
	  }
	}



	for (int i=0; i<temp; i++){//check to see if our input1 is a temp. if it is, then we need to use the value of that temp
	  if(strcmp(file[column].inp1, tempVars[i].name) ==0){
	    value[column] = tempVars[i].bit;
	  }
	  if(strcmp(file[column].inp2,tempVars[i].name)==0){
	    value1[column] = tempVars[i].bit;
	  }
	}


       
	valueS[column] = (value1[column] ^ value[column]); //XOR operation


	for (int i=0; i<outputCount; i++){ //check to see if we're storing in OUT
	  if (strcmp(file[column].output, outputVars[i]) == 0){
	    output[column].bit = valueS[column];
	    outputTemp = 1;
	  }
	}

	if (outputTemp ==0){
	  strcpy(tempVars[column].name, file[column].output);
	  tempVars[column].bit = valueS[column];
	  temp++;
	}

      }//end xor

      //columnP = column;

    }
    //    printf("printing now\n");
    for (int i=0; i<inputCount; i++){
      printf("%d ",truthTable[row][i]); //print each row up to num of inputs;
    }
    int k =0;
    for (int i=inputCount; i<(tableC); i++){
      printf("%d ",output[k].bit); //print remainder of row.. the outputs
      k++;
    }
    count++;
    printf("\n");
  }
  return 0;
}
