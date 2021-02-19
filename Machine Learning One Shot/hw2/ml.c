/* 
 * 
 * This code calculates the house price of a house by learing from
 * training data. It uses pseudo inverse of a given matrix to find the 
 * weight of different features.
 * 
 * Predicted Price : Y = W0 + W1*x1 + W2*X2 + W3*X3 + W4*X4
 * Weight Matrix : W = pseudoInv(X)*Y
 * pseudoInv(X) = inverse(transpose(X)*X) * transpose(X)  
 * 
 * weight(w) = pseudoInv(X) * Y
 * 			where	X = Input data matrix
 * 					Y = Target vector
 * 
 */
 
#include<stdio.h>
#include<stdlib.h>

// all methods declarations
// I will pass in the matrices, so I can initiate all my frees in main
double** multiplyMatrix(double **matA, double **matB,double** matAB, int r1, int c1, int r2, int c2);
double** transposeMatrix(double** mat,double** matT, int row, int col);
double** inverseMatrix(double **matA, double** matAI, int dimension);

// main method starts here
int main(int argc, char** argv){

    // your code goes here


  if (argc!=3){ //3 args: program, training file, testing file
    printf("error\n");
    return(1);
}
 
  FILE* trainingFile = fopen(argv[1], "r");

  if (trainingFile == NULL){
    printf("0\n");
    return(1);
  }

  int attributesK;
  int numOfTrainingSets;
  
  fscanf(trainingFile, "%d", &attributesK);//read first line(num of attributes)
  
  fscanf(trainingFile, "%d", &numOfTrainingSets);//read second line(num of houses)

 
  int attSize = attributesK + 1;
  //Now we have to malloc each matrix since we know the size
  // THESE ARE K+1 MATRIX, ATTRIBUTES +1
  double** a    = (double**)malloc(sizeof(double*) * numOfTrainingSets);//a (x)
  double** house= (double**)malloc(sizeof(double*) * numOfTrainingSets);//house prices training data(y)
  double** aT  = (double**)malloc(sizeof(double*) * (attSize));//tranpose of a(xT)
  double** aTa = (double**)malloc(sizeof(double*) * (attSize));//aT multiply a(xTx)
  double** aTaI = (double**)malloc(sizeof(double*) * (attSize));//inverse of aTa(xTx)^-1
  double** psuedoInverse = (double**)malloc(sizeof(double*) * (attSize));//inverse(xTx) * xT


  double**finalW = (double**)malloc(sizeof(double*) * (attSize));//final weights matrix


  //finalW = aTaI * aT * house
  //1. set up a
  //2. transpose a, store in another matrix aT
  //3. multiply aT by a, store in aTa
  //4. invert aTa, store in aTaI
  //5. multiply aTaI by aT and by house, store answer into finalW


  //Loop through and malloc each column


  // printf("About to malloc each row for aT, aTa, psuedo, aTaI, finalW\n");
   for (int column=0; column<attSize; column++){
    aT[column]     = malloc(sizeof(double) * numOfTrainingSets);
    aTa[column]    = malloc(sizeof(double) * attSize);
    psuedoInverse[column] = malloc(sizeof(double) * numOfTrainingSets);
    aTaI[column]   = malloc(sizeof(double) * attSize);
    // aTY[column]    = malloc(sizeof(double) * attSize);
    finalW[column] = malloc(sizeof(double));
  }
  
   // printf("About to malloc each row of a and house\n");
  //Loop through and malloc each row of a, house
  for (int column=0; column<numOfTrainingSets; column++){
    house[column] = malloc(sizeof(double));
      a[column]     = malloc(sizeof(double) * attSize);
  }

  //We can now insert into our matrices.

  // printf("Set column 1 of a to all 1\n");
  for (int i=0; i<numOfTrainingSets; i++){
    a[i][0] = 1;
  }

  // printf("%d\n", attributesK);
  // printf("%d\n", numOfTrainingSets);
  
  for (int i=0; i<numOfTrainingSets; i++){
    for (int j= 1; j<attSize; j++){
      //plug in attribs 
      fscanf(trainingFile,"%lf,", &a[i][j]);
      //  printf("Just inserted: ");
      // printf("%lf", a[i][j]);
      // printf(" into a at");
      // printf("[%d][%d]\n", i,j);
    }
    fscanf(trainingFile,"%lf,", &house[i][0]);
    // printf("Just inserted: ");
    // printf("%lf", house[i][0]);
    // printf(" into house at");
    // printf("[%d][%d]\n", i,0);
  }
  fclose(trainingFile);

  
  // printf("About to transpose a\n");
  aT   = transposeMatrix(a,aT,attSize, numOfTrainingSets);
  
  
	      
  // printf("About to multiply aT by a\n");
  aTa  = multiplyMatrix(aT, a, aTa, attSize, numOfTrainingSets, numOfTrainingSets, attSize);
  
  


  
  // printf("About to Invert aTa\n");
  aTaI = inverseMatrix(aTa,aTaI, attSize);
  
  

  
  // printf("About to multiply aTaI by aT to make psuedoInverse matrix\n");
  psuedoInverse  = multiplyMatrix(aTaI, aT,psuedoInverse, attSize, attSize, attSize, numOfTrainingSets);
 
  

  // printf("About to make W matrix, multiplying psuedoInverse by house (y)\n");
  finalW = multiplyMatrix(psuedoInverse, house,finalW, attSize, numOfTrainingSets, numOfTrainingSets, 1);
  
 


  // printf("W is now done. About to move on to test file \n");
  
  //W matrix is now done. Now we read through the test file
  FILE* testFile = fopen(argv[2], "r");
  int numOfCases;
  double attributePrice;
  // double testAtt;
  double housePrice;
  fscanf(testFile, "%d", &numOfCases);

  for (int house=0; house<numOfCases; house++){
     housePrice = finalW[0][0];
    //  housePrice = 0;
    for (int attribs =1; attribs<attSize; attribs++){
      fscanf(testFile, "%lf,", &attributePrice);
      housePrice += (finalW[attribs][0] * attributePrice);
    }
    
    printf("%0.0lf\n", housePrice);
  }

  fclose(testFile);

  //TIME TO FREE
  for (int i=0; i<attSize; i++){
    free(aT[i]);
    free(aTa[i]);
    free(aTaI[i]);
    free(psuedoInverse[i]);
    free(finalW[i]);
  }
  free(aT);
  free(aTa);
  free(aTaI);
  free(psuedoInverse);
  free(finalW);

  for (int i =0; i<numOfTrainingSets; i++){
    free(house[i]);
    free(a[i]);
  }
  free(house);
  free(a);
  
  

  
	return 0;
}

double** multiplyMatrix(double **matA, double **matB,double** matAB, int r1, int c1, int r2, int c2)
{
  /* double** result=malloc(r1*sizeof(double*)); 

     // your code goes here
    for (int i=0; i<r1; i++)
      result[i] = (double*)malloc((c2)*sizeof(double));
  */
   double total;
    for (int i =0; i< r1; i++){
      for (int j =0; j<c2; j++){
	total = 0.0;
	for (int k=0; k<r2; k++){
	  total = total+  (matA[i][k] * matB[k][j]);
	}
	matAB[i][j] = total;
      }
    }
    
	  
    return matAB;
}


double** transposeMatrix(double** mat,double** matT, int row, int col)
{
  // printf("Made it into transposeMatrix\n");
  /*
  double** matTran=malloc((row+1)*sizeof(double*)); 
	 // your code goes here
	for (int i=0; i<row+1; i++)
	  matTran[i] = (double*)malloc(col*sizeof(double));
					    */
  //	printf("matTran has been fully initialized. Now going to try and transpose\n");
       	for (int i=0; i<row; i++){
	  for (int j=0; j<col; j++){
	    matT[i][j] = mat[j][i];
	  }
	}

	//	printf("matTran is now inverted. returning now\n");
    return matT;        
}


double** inverseMatrix(double **matA,double** matAI, int dimension)
{

  /* double** matI=malloc(dimension*sizeof(double*)); 
    
    // your code goes here


    //This is square matrix, so dimensions are same ( r = c)

    for (int i=0; i<dimension; i++)
      matI[i] = (double*)malloc(dimension*sizeof(double));
  */
    // Set all diagnols to 1, everything else to 0
    for (int i=0; i<dimension; i++){
      for (int j=0; j<dimension; j++){
	if ( i == j)
	  matAI[i][j] = 1;
	else
	  matAI[i][j] = 0;
      }
    }

    //alg from pdf
    double index;
    for (int i=0; i<dimension; i++){
      index = matA[i][i];
      for (int j =0; j<dimension; j++){
	matA[i][j] = matA[i][j] / index;
	matAI[i][j] = matAI[i][j] / index;
      }

      for (int p = i+1; p<dimension; p++){
	index = matA[p][i];
	for (int k =0; k<dimension; k++){
	  matA[p][k] -= ((matA[i][k]) * (index));
	  matAI[p][k] -= ((matAI[i][k]) * (index));

	}
      }
    }


    for (int p = dimension-1; p>=0; p--){
      for (int i = p-1; i>=0; i--){
	index = matA[i][p];
	  for (int j =0; j<dimension; j++){
	    matA[i][j]-= (matA[p][j] * index);
	    matAI[i][j]-= (matAI[p][j] * index);
	  }
      }
    }
    
	return matAI;
}



