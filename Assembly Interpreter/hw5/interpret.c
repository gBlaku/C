#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char* argv[])
{
  FILE *ass = fopen(argv[1], "r");
  char lines    [100][21];
  char linesCopy[100][21];
  signed short ax, bx, cx, dx, num;
  int l  = 0;
  int iC = 0;
  char regOne[10];//first argument reg, aka reg being sent into another reg
  char reg[10];  //receiving register string
  char inst[6]; //mult, mov, etc
 
  if (ass == NULL){
    printf("error");
    return 1;
  }

  //Store each line of asm file into array
  while(fgets(lines[l], 21, ass) != NULL){
    lines[l][strlen(lines[l]) -1 ] = '\0';
    l +=1;
  }

  for (int j=0; j<100; j++){// coppy lines into linesCopy
    for (int k=0; k<21; k++){
      linesCopy[j][k] = lines[j][k];
    }
  }

  
  //Print array
  iC = l;

  int index;

  
  for (int i=0; i<iC; i++){
    

    //    printf("%s %d\n", "On line",i);
    /*if (lines[i][0] == '\0'){
      continue;
    }
    */
    
    if (lines[i][0] == 'r'){ //read in a register, have to figure out which one
      if(lines[i][5] == 'a'){
	scanf("%hi", &ax);
      }
      else if (lines[i][5] == 'b'){
	scanf("%hi", &bx);
      }
      else if (lines[i][5] == 'c'){
	scanf("%hi", &cx);
      }
      else if (lines[i][5] == 'd'){
	scanf("%hi", &dx);
      }
    } //now register should be read in and approriately assigned



    else if (lines[i][0] == 'm' && lines[i][1] == 'o'){ //if we have a mov instruction
	sscanf(lines[i], "%s %s %s",inst , regOne, reg ); //Read instruction, number, and register
	//	printf("%s %s\n",regOne,"This is just the initial");
	//	printf("%s %c\n", "regOne[0] is ",regOne[0]);
	
	if (isdigit(regOne[0]) || regOne[0] == '-' ){//if we have a number instead of reg as first argument
	  // printf("regOne[0] is a digit!\n");
	  num = atoi(regOne);
	  //	  printf("%s %d\n","num =", num);
	  if (reg[0] == 'a'){
	    ax = num;
	  }
	  else if (reg[0] == 'b'){
	    bx = num;
	  }
	  else if (reg[0] == 'c'){
	    cx = num;
	  }
	  else if (reg[0] == 'd'){
	    dx = num;
	  }
	}
      
	else {// (isdigit(regOne[0]) ==0){ //else if we mov a reg to another reg
	//sscanf(lines[i], "%s %s %s", inst, regOne, reg);
	  // printf("regOne[0] is NOT a digit!\n");
	if (regOne[0] == 'a'){ // If we're moving ax
	  if (reg[0] == 'a'){
	    ax = ax;
	  }
	  else if(reg[0] == 'b'){
	    bx = ax;
	  }
	  else if (reg[0] == 'c'){
	    cx = ax;
	  }
	  else if (reg[0] == 'd'){
	    dx = ax;
	  }
	}
	    
	else if (regOne[0] == 'b'){// else if we're moving bx
	  if (reg[0] == 'a'){
	    ax = bx;
	  }
	  else if (reg[0] == 'b'){
	    bx = bx;
	  }
	  else if (reg[0] == 'c'){
	    cx = bx;
	  }
	  else if (reg[0] == 'd'){
	    dx = bx;
	  }
	}
	 
	else if (regOne[0] == 'c'){// else if we're moving cx
	  if (reg[0] == 'a'){
	    ax = cx;
	  }
	  else if (reg[0] == 'b'){
	    bx = cx;
	  }
	  else if (reg[0] == 'c'){
	    cx = cx;
	  }
	  else if (reg[0] == 'd'){
	    dx = cx;
	  }
	}
	
	else if (regOne[0] == 'd'){//else if we're moving dx
	  if (reg[0] == 'a'){
	    ax = dx;
	  }
	  else if (reg[0] == 'b'){
	    bx = dx;
	  }
	  else if (reg[0] == 'c'){
	    cx = dx;
	  }
	  else if (reg[0] == 'd'){
	    dx = dx;
	  }
	}
      }
    } // end mov

    else if (lines[i][0] == 'p'){//print instruction
	sscanf(lines[i], "%s %s",inst , regOne);

	if(isdigit(regOne[0])  || regOne[0] == '-'){//if we print a number for some reason
	  num=atoi(regOne);
	  printf("%hi",num);
	}
      
	else{// if(isdigit(regOne[0])==0){//else if we print a reg
	
	  if (lines[i][6] =='a'){
	    printf("%hi",ax);
	  }
	  else if(lines[i][6] =='b'){
	    printf("%hi",bx);
	  }
	  else if(lines[i][6] =='c'){
	    printf("%hi",cx);
	  }
	  else if(lines[i][6] =='d'){
	    printf("%hi",dx);
	  }
	}
    }//end print

   else if (lines[i][0] == 'a'){//add instruction
     sscanf(lines[i], "%s %s %s", inst, regOne, reg);

     if (isdigit(regOne[0])  || regOne[0] == '-'){
       num = atoi(regOne);
       if (reg[0] == 'a'){
	 ax += num;
       }
       else if (reg[0] == 'b'){
	 bx += num;
       }
       else if (reg[0] == 'c'){
	 cx += num;
       }
       else if (reg[0] == 'd'){
	 dx +=num;
       }
     }

     else{
       if (regOne[0] == 'a'){//else if we're adding dx
	  if (reg[0] == 'a'){
	    ax +=ax;
	  }
	  else if (reg[0] == 'b'){
	    bx += ax;
	  }
	  else if (reg[0] == 'c'){
	    cx += ax;
	  }
	  else if (reg[0] == 'd'){
	    dx += ax;
	  }
       }
       else  if (regOne[0] == 'b'){//else if we're adding dx
	 if (reg[0] == 'a'){
	   ax += bx;
	 }
	 else if (reg[0] == 'b'){
	   bx += bx;
	 }
	 else if (reg[0] == 'c'){
	   cx += bx;
	 }
	 else if (reg[0] == 'd'){
	   dx += bx;
	 }
       }
       else  if (regOne[0] == 'c'){//else if we're adding cx
	 if (reg[0] == 'a'){
	   ax += cx;
	 }
	 else if (reg[0] == 'b'){
	   bx += cx;
	 }
	 else if (reg[0] == 'c'){
	   cx += cx;
	 }
	 else if (reg[0] == 'd'){
	   dx += cx;
	 }
       }
       else  if (regOne[0] == 'd'){//else if we're adding dx
	 if (reg[0] == 'a'){
	   ax += dx;
	 }
	 else if (reg[0] == 'b'){
	   bx += dx;
	 }
	 else if (reg[0] == 'c'){
	   cx += dx;
	 }
	 else if (reg[0] == 'd'){
	   dx += dx;
	 }
       }
     }//end notdigit
   }//end add

   else if(lines[i][0] == 's'){//subtract instruction
    sscanf(lines[i], "%s %s %s", inst, regOne, reg);

       if (isdigit(regOne[0]) || regOne[0] == '-' ){
	 num = atoi(regOne);
	 if (reg[0] == 'a'){
	   ax -= num;
	 }
	 else if (reg[0] == 'b'){
	   bx -= num;
	 }
	 else if (reg[0] == 'c'){
	   cx -= num;
	 }
	 else if (reg[0] == 'd'){
	   dx -= num;
	 }
       }

       else{
	 if (regOne[0] == 'a'){//else if we're adding dx
	   if (reg[0] == 'a'){
	     ax -=ax;
	   }
	   else if (reg[0] == 'b'){
	     bx -= ax;
	   }
	   else if (reg[0] == 'c'){
	     cx -= ax;
	   }
	   else if (reg[0] == 'd'){
	     dx -= ax;
	   }
	 }
	 else  if (regOne[0] == 'b'){//else if we're adding dx
	   if (reg[0] == 'a'){
	     ax -= bx;
	   }
	   else if (reg[0] == 'b'){
	     bx -= bx;
	   }
	   else if (reg[0] == 'c'){
	     cx -= bx;
	   }
	   else if (reg[0] == 'd'){
	     dx -= bx;
	   }
	 }
	 else  if (regOne[0] == 'c'){//else if we're adding cx
	   if (reg[0] == 'a'){
	     ax -= cx;
	   }
	   else if (reg[0] == 'b'){
	     bx -= cx;
	   }
	   else if (reg[0] == 'c'){
	     cx -= cx;
	   }
	   else if (reg[0] == 'd'){
	     dx -= cx;
	   }
	 }
	 else  if (regOne[0] == 'd'){//else if we're adding dx
	   if (reg[0] == 'a'){
	     ax -= dx;
	   }
	   else if (reg[0] == 'b'){
	     bx -= dx;
	   }
	   else if (reg[0] == 'c'){
	     cx -= dx;
	   }
	   else if (reg[0] == 'd'){
	     dx -= dx;
	   }
	 }
       }//end notdigit
   }//end subtract
  

    
   else if (lines[i][0] == 'm' && lines[i][1] == 'u'){//multiply instruction
     sscanf(lines[i], "%s %s %s", inst, regOne, reg);

     if (isdigit(regOne[0]) || regOne[0] == '-' ){
       num = atoi(regOne);
       if (reg[0] == 'a'){
	 ax *= num;
       }
       else if (reg[0] == 'b'){
	 bx *= num;
       }
       else if (reg[0] == 'c'){
	 cx *= num;
       }
       else if (reg[0] == 'd'){
	 dx *=num;
       }
     }

     else{
       if (regOne[0] == 'a'){//else if we're adding dx
	 if (reg[0] == 'a'){
	   ax *=ax;
	 }
	 else if (reg[0] == 'b'){
	   bx *= ax;
	 }
	 else if (reg[0] == 'c'){
	   cx *= ax;
	 }
	 else if (reg[0] == 'd'){
	   dx *= ax;
	 }
       }
       else  if (regOne[0] == 'b'){//else if we're adding dx
	 if (reg[0] == 'a'){
	   ax *= bx;
	 }
	 else if (reg[0] == 'b'){
	   bx *= bx;
	 }
	 else if (reg[0] == 'c'){
	   cx *= bx;
	 }
	 else if (reg[0] == 'd'){
	   dx *= bx;
	 }
       }
       else  if (regOne[0] == 'c'){//else if we're adding cx
	 if (reg[0] == 'a'){
	   ax *= cx;
	 }
	 else if (reg[0] == 'b'){
	   bx *= cx;
	 }
	 else if (reg[0] == 'c'){
	   cx *= cx;
	 }
	 else if (reg[0] == 'd'){
	   dx *= cx;
	 }
       }
       else  if (regOne[0] == 'd'){//else if we're adding dx
	 if (reg[0] == 'a'){
	   ax *= dx;
	 }
	 else if (reg[0] == 'b'){
	   bx *= dx;
	 }
	 else if (reg[0] == 'c'){
	   cx *= dx;
	 }
	 else if (reg[0] == 'd'){
	   dx *= dx;
	 }
       }
     }//end notDigit
   }//end multiply

   else if(lines[i][0] == 'd'){//divide instruction
       sscanf(lines[i], "%s %s %s", inst, regOne, reg);

       if (isdigit(regOne[0]) || regOne[0] == '-'){
	 num = atoi(regOne);
	 if (reg[0] == 'a'){
	   ax = num/ax;
	 }
	 else if (reg[0] == 'b'){
	   bx = num/bx;
	 }
	 else if (reg[0] == 'c'){
	   cx = num/cx;
	 }
	 else if (reg[0] == 'd'){
	   dx =num/dx;
	 }
       }
       //y=x/y
       else{
	 if (regOne[0] == 'a'){//else if we're adding dx
	   if (reg[0] == 'a'){
	     ax =ax/ax;
	   }
	   else if (reg[0] == 'b'){
	     bx = ax/bx;
	   }
	   else if (reg[0] == 'c'){
	     cx = ax/cx;
	   }
	   else if (reg[0] == 'd'){
	     dx = ax/dx;
	   }
	 }
	 else  if (regOne[0] == 'b'){//else if we're adding dx
	   if (reg[0] == 'a'){
	     ax = bx/ax;
	   }
	   else if (reg[0] == 'b'){
	     bx = bx/bx;
	   }
	   else if (reg[0] == 'c'){
	     cx = bx/cx;
	   }
	   else if (reg[0] == 'd'){
	     dx = bx/dx;
	   }
	 }
	 else  if (regOne[0] == 'c'){//else if we're adding cx
	   if (reg[0] == 'a'){
	     ax = cx/ax;
	   }
	   else if (reg[0] == 'b'){
	     bx = cx/bx;
	   }
	   else if (reg[0] == 'c'){
	     cx = cx/cx;
	   }
	   else if (reg[0] == 'd'){
	     dx = cx/dx;
	   }
	 }
	 else  if (regOne[0] == 'd'){//else if we're adding dx
	   if (reg[0] == 'a'){
	     ax = dx/ax;
	   }
	   else if (reg[0] == 'b'){
	     bx = dx/bx;
	   }
	   else if (reg[0] == 'c'){
	     cx = dx/cx;
	   }
	   else if (reg[0] == 'd'){
	     dx = dx/dx;
	   }
	 }
       }//end notdigit
   }//end divide

   else if (lines[i][0] == 'j' && lines[i][1] == 'm' && lines[i][2] == 'p'){//jmp condition
     sscanf(lines[i],"%s %d",inst,&index);
      i = index -1;
     //continue;
   }
    
   else if (lines[i][0] == 'j' && lines[i][1] == 'e'){//je (jump if equal) condition
     sscanf(lines[i],"%s %d %s %s",inst,&index,regOne,reg);


     if ( (isdigit(regOne[0]) || regOne[0] == '-') && (isdigit(reg[0]) || reg[0] == '-') ){
       num = atoi(regOne);
       if (num == atoi(reg)){
	 //continue;
	 i = index-1;
       }
     }
     
     
     else if (isdigit(regOne[0]) || regOne[0] == '-'){
       num = atoi(regOne);

       if(reg[0] == 'a'){
	 if (num == ax){
	      i = index-1;
	   //continue;
	 }
       }
       else if (reg[0] =='b'){
	 if (num == bx){
	    i = index-1;
	   //continue;
	 }
       }
       else if (reg[0] == 'c'){
	 if (num == cx){
	   	   i = index-1;
	   //continue;
	 }
       }
       else if (reg[0] == 'd'){
	 if (num == dx){
	    i = index-1;
	   //continue;
	 }
       }
     }


     else if (isdigit(reg[0]) || reg[0] == '-'){
       num = atoi(reg);

       if(regOne[0] == 'a'){
	 if (ax == num){
	   i = index-1;
	   //continue;
	 }
       }
       else if (regOne[0] =='b'){
	 if (bx == num){
	    i = index-1;
	   //continue;
	 }
       }
       else if (regOne[0] == 'c'){
	 if (cx == num){
	   i = index-1;
	   //continue;
	 }
       }
       else if (regOne[0] == 'd'){
	 if (dx == num){
	    i = index-1;
	   //continue;
	 }
       }
     } //end digit
     


     

     else{
       if (regOne[0] == 'a'){

	 if(reg[0] == 'a'){
	   if (ax == ax){
	      i = index-1;
	     //continue;
	   }
	 }
	 else if (reg[0] =='b'){
	   if (ax == bx){
	      i = index-1;
	     //continue;
	   }
	 }
	 else if (reg[0] == 'c'){
	   if (ax == cx){
	      i = index-1;
	     //continue;
	   }
	 }
	 else if (reg[0] == 'd'){
	   if (ax == dx){
	      i = index-1;
	     //continue;
	   }
	 }
       }

       else if (regOne[0] == 'b'){

	 if(reg[0] == 'a'){
	   if (bx == ax){
	     i = index-1;
	     //continue;
	   }
	 }
	 else if (reg[0] =='b'){
	   if (bx == bx){
	     i = index-1;
	     //continue;
	   }
	 }
	 else if (reg[0] == 'c'){
	   if (bx == cx){
	      i = index-1;
	     //continue;
	   }
	 }
	 else if (reg[0] == 'd'){
	   if (bx == dx){
	      i = index-1;
	     //continue;
	   }
	 }
       }

       else if (regOne[0] == 'c'){

	 if(reg[0] == 'a'){
	   if (cx == ax){
	      i = index-1;
	     //continue;
	   }
	 }
	 else if (reg[0] =='b'){
	   if (cx == bx){
	      i = index-1;
	     //continue;
	   }
	 }
	 else if (reg[0] == 'c'){
	   if (cx == cx){
	      i = index-1;
	     //continue;
	   }
	 }
	 else if (reg[0] == 'd'){
	   if (cx == dx){
	      i = index-1;
	     //continue;
	   }
	 }
       }


       else if (regOne[0] == 'd'){

	 if(reg[0] == 'a'){
	   if (dx == ax){
	      i = index-1;
	     //continue;
	   }
	 }
	 else if (reg[0] =='b'){
	   if (dx == bx){
	      i = index-1;
	     //continue;
	   }
	 }
	 else if (reg[0] == 'c'){
	   if (dx == cx){
	      i = index-1;
	     //continue;
	   }
	 }
	 else if (reg[0] == 'd'){
	   if (dx == dx){
	      i = index-1;
	     //continue;
	   }
	 }
       }
     }//end notdigit
   }//end je




     
   else if (lines[i][0] == 'j' && lines[i][1] == 'n' && lines[i][2] == 'e'){//jne (jump if not equal) condition
     sscanf(lines[i],"%s %d %s %s",inst,&index,regOne,reg);

     if ( (isdigit(regOne[0]) || regOne[0] == '-') && (isdigit(reg[0]) || reg[0] == '-')){
       num = atoi(regOne);
	   if (num != atoi(reg)){
	     //continue;
	     i = index-1;
	   }
     }
     
     
     else if (isdigit(regOne[0]) || regOne[0] == '-'){
       num = atoi(regOne);

       if(reg[0] == 'a'){
	 if (num != ax){
	    i = index-1;
	   //continue;
	 }
       }
       else if (reg[0] =='b'){
	 if (num != bx){
	    i = index-1;
	   //continue;
	 }
       }
       else if (reg[0] == 'c'){
	 if (num != cx){
	    i = index-1;
	   //continue;
	 }
       }
       else if (reg[0] == 'd'){
	 if (num != dx){
	   i = index-1;
	   //continue;
	 }
       }
     } //end digit



     else if (isdigit(reg[0]) || reg[0] == '-'){
       num = atoi(reg);

       if(regOne[0] == 'a'){
	 if (ax != num){
	   i = index-1;
	   //continue;
	 }
       }
       else if (regOne[0] =='b'){
	 if (bx != num){
	    i = index-1;
	   //continue;
	 }
       }
       else if (regOne[0] == 'c'){
	 if (cx != num){
	   i = index-1;
	   //continue;
	 }
       }
       else if (regOne[0] == 'd'){
	 if (dx != num){
	    i = index-1;
	   //continue;
	 }
       }
     } //end digit
   






     

     else{
       if (regOne[0] == 'a'){

	 if(reg[0] == 'a'){
	   if (ax != ax){
	      i = index-1;
	     //continue;
	   }
	 }
	 else if (reg[0] =='b'){
	   if (ax != bx){
	      i = index-1;
	     //continue;
	   }
	 }
	 else if (reg[0] == 'c'){
	   if (ax != cx){
	      i = index-1;
	     //continue;
	   }
	 }
	 else if (reg[0] == 'd'){
	   if (ax != dx){
	      i = index-1;
	     //continue;
	   }
	 }
       }

       else if (regOne[0] == 'b'){

	 if(reg[0] == 'a'){
	   if (bx != ax){
	      i = index-1;
	     //continue;
	   }
	 }
	 else if (reg[0] =='b'){
	   if (bx != bx){
	      i = index-1;
	     //continue;
	   }
	 }
	 else if (reg[0] == 'c'){
	   if (bx != cx){
	      i = index-1;
	     //continue;
	   }
	 }
	 else if (reg[0] == 'd'){
	   if (bx != dx){	
	     i = index-1;
	     //continue;
	   }
	 }
       }

       if (regOne[0] == 'c'){

	 if(reg[0] == 'a'){
	   if (cx != ax){
	     i = index-1;
	     //continue;
	   }
	 }
	 else if (reg[0] =='b'){
	   if (cx != bx){
	      i = index-1;
	     //continue;
	   }
	 }
	 else if (reg[0] == 'c'){
	   if (cx != cx){
	     i = index-1;
	     // continue;
	   }
	 }
	 else if (reg[0] == 'd'){
	   if (cx != dx){
	    i = index-1;
	     // continue;
	   }
	 }
       }

       else if (regOne[0] == 'd'){

	 if(reg[0] == 'a'){
	   if (dx != ax){
	      i = index-1;
	     //continue;
	   }
	 }
	 else if (reg[0] =='b'){
	   if (dx != bx){
	     i = index-1;
	     //continue;
	   }
	 }
	 else if (reg[0] == 'c'){
	   if (dx != cx){
	      i = index-1;
	     //continue;
	   }
	 }
	 else if (reg[0] == 'd'){
	   if (dx != dx){
	     i = index-1;
	     //continue;
	   }
	 }
       }
     }//end notdigit
   }//end jne


       
   else if (lines[i][0] == 'j' && lines[i][1] == 'g' && lines[i][2] != 'e'){//jg (jump if greater) condition
     sscanf(lines[i],"%s %d %s %s",inst,&index,regOne,reg);

     if ( (isdigit(regOne[0]) || regOne[0] == '-') && (isdigit(reg[0]) || reg[0] == '-') ){
       num = atoi(regOne);
       if (num > atoi(reg)){
	 //continue;
	 i = index-1;
       }
     }
       
    else if (isdigit(regOne[0]) || regOne[0] == '-'){
       num = atoi(regOne);

       if(reg[0] == 'a'){
	 if (num > ax){
	    i = index-1;
	   //continue;
	 }
       }
       else if (reg[0] =='b'){
	 if (num > bx){
	    i = index-1;
	   //continue;
	 }
       }
       else if (reg[0] == 'c'){
	 if (num > cx){
	    i = index-1;
	   //continue;
	 }
       }
       else if (reg[0] == 'd'){
	 if (num > dx){
	    i = index-1;
	   // continue;
	 }
       }
     } //end digit


    else if (isdigit(reg[0]) || reg[0] == '-'){
      num = atoi(reg);

      if(regOne[0] == 'a'){
	if (ax > num){
	  i = index-1;
	  //continue;
	}
      }
      else if (regOne[0] =='b'){
	if (bx > num){
	   i = index-1;
	  //continue;
	}
      }
      else if (regOne[0] == 'c'){
	if (cx > num){
	  i = index-1;
	  //continue;
	}
      }
      else if (regOne[0] == 'd'){
	if (dx > num){
	   i = index-1;
	  //continue;
	}
      }
    } //end digit
     

     
   
     else{
       if (regOne[0] == 'a'){

	 if(reg[0] == 'a'){
	   if (ax > ax){
	      i = index-1;
	     //continue;
	   }
	 }
	 else if (reg[0] =='b'){
	   if (ax > bx){
	     i = index-1;
	     //continue;
	   }
	 }
	 else if (reg[0] == 'c'){
	   if (ax > cx){
	      i = index-1;
	     //continue;
	   }
	 }
	 else if (reg[0] == 'd'){
	   if (ax > dx){
	     i = index-1;
	     //continue;
	   }
	 }
       }

       else  if (regOne[0] == 'b'){

	 if(reg[0] == 'a'){
	   if (bx > ax){
	     i = index-1;
	     //continue;
	   }
	 }
	 else if (reg[0] =='b'){
	   if (bx > bx){
	     i = index-1;
	     //continue;
	   }
	 }
	 else if (reg[0] == 'c'){
	   if (bx > cx){
	     i = index-1;
	     //continue;
	   }
	 }
	 else if (reg[0] == 'd'){
	   if (bx > dx){
	     i = index-1;
	     //continue;
	   }
	 }
       }

       else  if (regOne[0] == 'c'){

	 if(reg[0] == 'a'){
	   if (cx  > ax){
	     i = index-1;
	     //continue;
	   }
	 }
	 else if (reg[0] =='b'){
	   if (cx > bx){
	     i = index-1;
	     //continue;
	   }
	 }
	 else if (reg[0] == 'c'){
	   if (cx > cx){
	      i = index-1;
	     //continue;
	   }
	 }
	 else if (reg[0] == 'd'){
	   if (cx > dx){
	     i = index-1;
	     //continue;
	   }
	 }
       }

       else  if (regOne[0] == 'd'){

	 if(reg[0] == 'a'){
	   if (dx > ax){
	      i = index-1;
	     //continue;
	   }
	 }
	 else if (reg[0] =='b'){
	   if (dx > bx){
	      i = index-1;
	     //continue;
	   }
	 }
	 else if (reg[0] == 'c'){
	   if (dx > cx){
	      i = index-1;
	     //continue;
	   }
	 }
	 else if (reg[0] == 'd'){
	   if (dx > dx){
	     i = index-1;
	     // continue;
	   }
	 }
       }
     }//end notdigit
   }//end jg


    
   else if (lines[i][0] == 'j' && lines[i][1] == 'g' && lines[i][2] == 'e'){//jge (jump if gr or eq) condition
     sscanf(lines[i],"%s %d %s %s",inst,&index,regOne,reg);

     if ( (isdigit(regOne[0]) || regOne[0] == '-') && (isdigit(reg[0]) || reg[0] == '-') ){
       num = atoi(regOne);
       if (num >= atoi(reg)){
	 i = index-1;
	 //continue;
       }
     }

     
    else if (isdigit(regOne[0]) || regOne[0] == '-'){
       num = atoi(regOne);

       if(reg[0] == 'a'){
	 if (num >= ax){
	   i = index-1;
	   //continue;
	 }
       }
       else if (reg[0] =='b'){
	 if (num >= bx){
	    i = index-1;
	   //continue;
	 }
       }
       else if (reg[0] == 'c'){
	 if (num >= cx){
	    i = index-1;
	   //continue;
	 }
       }
       else if (reg[0] == 'd'){
	 if (num >= dx){
	   i = index-1;
	   // continue;
	 }
       }
     } //end digit

    else if (isdigit(reg[0]) || reg[0] == '-'){
      num = atoi(reg);

      if(regOne[0] == 'a'){
	if (ax >= num){
	  i = index-1;
	  //continue;
	}
      }
      else if (regOne[0] =='b'){
	if (bx >= num){
	   i = index-1;
	  //continue;
	}
      }
      else if (regOne[0] == 'c'){
	if (cx >= num){
	  i = index-1;
	  //continue;
	}
      }
      else if (regOne[0] == 'd'){
	if (dx >= num){
	  i = index-1;
	  //continue;
	}
      }
    } //end digit
   

     

     
     else{
       if (regOne[0] == 'a'){

	 if(reg[0] == 'a'){
	   if (ax >= ax){
	      i = index-1;
	     //continue;
	   }
	 }
	 else if (reg[0] =='b'){
	   if (ax >= bx){
	      i = index-1;
	     //continue;
	   }
	 }
	 else if (reg[0] == 'c'){
	   if (ax >= cx){
	      i = index-1;
	     //continue;
	   }
	 }
	 else if (reg[0] == 'd'){
	   if (ax >= dx){
	      i = index-1;
	     //continue;
	   }
	 }
       }

       else if (regOne[0] == 'b'){

	   if(reg[0] == 'a'){
	     if (bx >= ax){
	        i = index-1;
	       //continue;
	     }
	   }
	   else if (reg[0] =='b'){
	     if (bx >= bx){
	        i = index-1;
	       //continue;
	     }
	   }
	   else if (reg[0] == 'c'){
	     if (bx >= cx){
	        i = index-1;
	       //continue;
	     }
	   }
	   else if (reg[0] == 'd'){
	     if (bx >= dx){
	        i = index-1;
	       //  continue;
	     }
	   }
       }

       else if (regOne[0] == 'c'){

	 if(reg[0] == 'a'){
	   if (cx >= ax){
	     i = index-1;
	     //continue;
	   }
	 }
	 else if (reg[0] =='b'){
	   if (cx >= bx){
	      i = index-1;
	     //continue;
	   }
	 }
	 else if (reg[0] == 'c'){
	   if (cx >= cx){
	     i = index-1;
	     //continue;
	   }
	 }
	 else if (reg[0] == 'd'){
	   if (cx >= dx){
	      i = index-1;
	     //continue;
	   }
	 }
       }

       else if (regOne[0] == 'd'){

	 if(reg[0] == 'a'){
	   if (dx >= ax){
	     i = index-1;
	     //continue;
	   }
	 }
	 else if (reg[0] =='b'){
	   if (dx >= bx){
	     i = index-1;
	     //continue;
	   }
	 }
	 else if (reg[0] == 'c'){
	   if (dx >= cx){
	     i = index-1;
	     //continue;
	   }
	 }
	 else if (reg[0] == 'd'){
	   if (dx >= dx){
	      i = index-1;
	     //continue;
	   }
	 }
       }
     }//end notdigit
   }//end jge



    
   else if (lines[i][0] == 'j' && lines[i][1] == 'l' && lines[i][2] != 'e'){//jl (jump if less than) condition
     sscanf(lines[i],"%s %d %s %s",inst,&index,regOne,reg);

     if( (isdigit(regOne[0]) || regOne[0] == '-') && (isdigit(reg[0]) || reg[0] == '-') ){
       num = atoi(regOne);
	 if (num < atoi(reg)){
	   i = index-1;
	   //continue;
	 }
     }

      
      
     else if (isdigit(regOne[0]) || regOne[0] == '-') {
       num = atoi(regOne);
       
       if(reg[0] == 'a'){
	 if (num < ax){
	   i = index-1;
	   //continue;
	 }
       }
       else if (reg[0] =='b'){
	 if (num < bx){
	    i = index-1;
	   //continue;
	 }
       }
       else if (reg[0] == 'c'){
	 if (num < cx){
	    i = index-1;
	   //continue;
	 }
       }
       else if (reg[0] == 'd'){
	 if (num < dx){
	    i = index-1;
	   //continue;
	 }
       }
     } //end digit


     
     else if(isdigit(reg[0]) || reg[0] == '-'){
       num = atoi(reg);
       
       if(regOne[0] == 'a'){
	 if (ax < num){
	   i = index-1;
	   //continue;
	 }
       }
       else if (regOne[0] =='b'){
	 if (bx < num){
	    i = index-1;
	   // continue;
	 }
       }
       else if (regOne[0] == 'c'){
	 if (cx < num){
	    i = index-1;
	   // continue;
	 }
       }
       else if (regOne[0] == 'd'){
	 if (dx < num){
	    i = index-1;
	   //continue;
	 }
       }
     } //now it can ONLY be reg, reg


     else{
   
          if (regOne[0] == 'a'){

	 if(reg[0] == 'a'){
	   if (ax < ax){
	      i = index-1;
	     //continue;
	   }
	 }
	 else if (reg[0] =='b'){
	   if (ax < bx){
	      i = index-1;
	     //continue;
	   }
	 }
	 else if (reg[0] == 'c'){
	   if (ax < cx){
	      i = index-1;
	     //continue;
	   }
	 }
	 else if (reg[0] == 'd'){
	   if (ax < dx){
	      i = index-1;
	     //  continue;
	   }
	 }
       }


       else if (regOne[0] == 'b'){

	 if(reg[0] == 'a'){
	   if (bx < ax){
	      i = index-1;
	     //continue;
	   }
	 }
	 else if (reg[0] =='b'){
	   if (bx < bx){
	      i = index-1;
	      //continue;
	   }
	 }
	 else if (reg[0] == 'c'){
	   if (bx < cx){
	      i = index-1;
	     //continue;
	   }
	 }
	 else if (reg[0] == 'd'){
	   if (bx < dx){
	     i = index-1;
	     //continue;
	   }
	 }
       }

       else  if (regOne[0] == 'c'){

	 if(reg[0] == 'a'){
	   if (cx < ax){
	      i = index-1;
	     //continue;
	   }
	 }
	 else if (reg[0] =='b'){
	   if (cx < bx){
	     i = index-1;
	     //continue;
	   }
	 }
	 else if (reg[0] == 'c'){
	   if (cx < cx){
	      i = index-1;
	     //continue;
	   }
	 }
	 else if (reg[0] == 'd'){
	   if (cx < dx){
	      i = index-1;
	     //continue;
	   }
	 }
       }

       else  if (regOne[0] == 'd'){

	 if(reg[0] == 'a'){
	   if (dx < ax){
	      i = index-1;
	     //continue;
	   }
	 }
	 else if (reg[0] =='b'){
	   if (dx < bx){
	     i = index-1;
	     //continue;
	   }
	 }
	 else if (reg[0] == 'c'){
	   if (dx < cx){
	     i = index-1;
	     //continue;
	   }
	 }
	 else if (reg[0] == 'd'){
	   if (dx < dx){
	     i = index-1;
	     //continue;
	   }
	 }
       }
     }//end notdigit
   }//end jl
    

     
   else if (lines[i][0] == 'j' && lines[i][1] == 'l' && lines[i][2] == 'e'){//jle (jump if less or eq) condition
     sscanf(lines[i],"%s %d %s %s",inst,&index,regOne,reg);
     //printf("made it into jle\n");

     if ((isdigit(regOne[0]) || regOne[0] == '-') && (isdigit(reg[0]) || reg[0] == '-') ){
       // printf("made it into two digits\n");
       num = atoi(regOne);
       if (num <= atoi(reg)){
	 i = index-1;
	 //continue;
       }
     
       // printf("not two digits\n");
     }
     else if (isdigit(regOne[0]) || regOne[0] == '-'){
       //printf("made it to check for regOne as digit and reg as register\n");
       num = atoi(regOne);

       if(reg[0] == 'a'){
	 if (num <= ax){
	   i = index-1;
	   //continue;
	 }
       }
       else if (reg[0] =='b'){
	 if (num <= bx){
	    i = index-1;
	   //continue;
	 }
       }
       else if (reg[0] == 'c'){
	 if (num <= cx){
	   i = index-1;
	   //continue;
	 }
       }
       else if (reg[0] == 'd'){
	 if (num <= dx){
	   i = index-1;
	   // continue;
	 }
       }
      //end digit
       //printf("not regOne digit and reg as register\n");
     }
     else if (isdigit(reg[0]) || reg[0] == '-'){
       
       
       //printf("about to check for regOne as register and reg as digit\n");
       num = atoi(reg);

       // printf("%s\n", regOne);
       // printf("%hi\n", num);
       
       if(regOne[0] == 'a'){
	 if (ax <= num){
	   i = index-1;
	   //continue;
	 }
       }
       else if (regOne[0] =='b'){
	 if (bx <= num){
	    i = index-1;
	   //continue;
	 }
       }
       else if (regOne[0] == 'c'){
	 if (cx <= num){
	   i = index-1;
	   //continue;
	 }
       }
       else if (regOne[0] == 'd'){
	 if (dx <= num){
	   i = index-1;
	   // continue;
	 }
       }
      //end digit
       //printf("not regOne as register and reg as digit\n");
     }
     
     else{
       // printf("about to check for two regs\n");
       if (regOne[0] == 'a'){

	 if(reg[0] == 'a'){
	   if (ax <= ax){
	      i = index-1;
	      // continue;
	   }
	 }
	 else if (reg[0] =='b'){
	   if (ax <= bx){
	     i = index-1;
	     // continue;
	   }
	 }
	 else if (reg[0] == 'c'){
	   if (ax <= cx){
	     i = index-1;
	     // continue;
	   }
	 }
	 else if (reg[0] == 'd'){
	   if (ax <= dx){
	     i = index-1;
	     //continue;
	   }
	 }
       }


       else if (regOne[0] == 'b'){

	 if(reg[0] == 'a'){
	   if (bx <= ax){
	     i = index-1;
	     // continue;
	   }
	 }
	 else if (reg[0] =='b'){
	   if (bx <= bx){
	     i = index-1;
	     //continue;
	   }
	 }
	 else if (reg[0] == 'c'){
	   if (bx <= cx){
	     i = index-1;
	     //continue;
	   }
	 }
	 else if (reg[0] == 'd'){
	   if (bx <= dx){
	     i = index-1;
	     //continue;
	   }
	 }
       }

       else  if (regOne[0] == 'c'){

	 if(reg[0] == 'a'){
	   if (cx <= ax){
	     i = index-1;
	     //continue;
	   }
	 }
	 else if (reg[0] =='b'){
	   if (cx <= bx){
	     i = index-1;
	     //continue;
	   }
	 }
	 else if (reg[0] == 'c'){
	   if (cx <= cx){
	     i = index-1;
	    //continue;
	   }
	 }
	 else if (reg[0] == 'd'){
	   if (cx <= dx){
	     i = index-1;
	     //continue;
	   }
	 }
       }

       else if (regOne[0] == 'd'){

	 if(reg[0] == 'a'){
	   if (dx <= ax){
	     i = index-1;
	     //continue;
	   }
	 }
	 else if (reg[0] =='b'){
	   if (dx <= bx){
	     i = index-1;
	     //continue;
	   }
	 }
	 else if (reg[0] == 'c'){
	   if (dx <= cx){
	     i = index-1;
	     //continue;
	   }
	 }
	 else if (reg[0] == 'd'){
	   if (dx <= dx){
	     i = index-1;
	     // continue;
	   }
	 }
       }
       //       printf("not two regs... lol\n");
     }//end notdigit
   }//end jle
  
    
  }//end loop 

  
  fclose(ass);
  return 0;
}
