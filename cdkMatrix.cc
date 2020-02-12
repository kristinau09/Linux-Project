/*
 * Filename        cdkMatrix.cc
 * Description: file with main(), displays the matrix
 * 
 */
#include <iostream>
#include <map>
#include <ncurses.h>
#include "/scratch/perkins/include/cdk.h"
#include <string>
#include "binReader.h"
 

#define MATRIX_WIDTH 5
#define MATRIX_HEIGHT 3
#define BOX_WIDTH 20
#define MATRIX_NAME_STRING "Binary File Content"

using namespace std;

 
int main(){
  binParser();
  cbreak();
  WINDOW	*window;
  CDKSCREEN	*cdkscreen;
  CDKMATRIX *myMatrix;           // CDK Screen Matrix

  const char 		*rowTitles[MATRIX_WIDTH+1] = {"R0", "a", "b", "c","d","e"};
  const char 		*columnTitles[MATRIX_HEIGHT+1] = {"C0", "a", "b", "c"};
  int		boxWidths[MATRIX_WIDTH+1] = {BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH,BOX_WIDTH, BOX_WIDTH};
  int		boxTypes[MATRIX_WIDTH+1] = {vMIXED, vMIXED, vMIXED, vMIXED,vMIXED, vMIXED};

  // Initialize the Cdk screen.
   
  window = initscr();
  cdkscreen = initCDKScreen(window);

 // Start CDK Colors 
  initCDKColor();
 // Create the matrix.  Need to manually cast (const char**) to (char **)
  
  myMatrix = newCDKMatrix(cdkscreen, CENTER, CENTER, MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_WIDTH, MATRIX_HEIGHT,
			  MATRIX_NAME_STRING, (char **) rowTitles, (char **) columnTitles, boxWidths,
				     boxTypes, 1, 1, ' ', ROW, true, true, false);
  
   if (myMatrix ==NULL)
    {
      printf("Error creating Matrix\n");
      _exit(1);
    } 

  // Display the Matrix
  drawCDKMatrix(myMatrix, true);

  
   // Dipslay a message
   
  //setCDKMatrixCell(myMatrix, 2, 2, "Test Message");
  //drawCDKMatrix(myMatrix, true);    
  int mapIndex=1;
  for(int i=1;i<=MATRIX_WIDTH;i++)
  {
    for(int j=1;j<=MATRIX_HEIGHT;j++){
      if(!((j>2)&&(i>1))){
      const char * val=(binMap[mapIndex++]).c_str(); 
      setCDKMatrixCell(myMatrix, i, j, val );
      drawCDKMatrix(myMatrix, true);    
    }

    
    }
  }
  
  unsigned char inp;
  cin>>inp;

  endCDK();
  
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
