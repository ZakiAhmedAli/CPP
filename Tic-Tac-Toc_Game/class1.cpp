/*The Class header file for main.cpp*/
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>

using namespace std;

class Game
{
private:
		char  position[16];
		char winner;
public:
	Game();
	char *GetPosition(void);
	int  SetPosition(int GridNum , int User);
	char checkRows();	
	char checkColumns();
	char checkDiagonals();
	char determineWinner();
	
};//end of class


/*default constructor to set position to default symbol*/
Game::Game()
{
	//sets the board to blanks and the winner to 'z'
	winner='?';
	for(char p=0 ; p<16 ;p++)
	{
		position[p] = '_';
	}
}
/*function to return position in board*/
char* Game::GetPosition(void)
{
	return position;
}
int Game:: SetPosition(int GridNum , int User)
{
	
	if(position[GridNum] == '_')
	{
		position[GridNum] = User;
		return 0;
	}
	else
	{
		//means That position is taken;
		return -1;
	}
	return 0;
}
char Game:: checkRows()
{
	//check the rows for a winner
   int rows 	  = 0;
   int counter    = 0;
   int fourInRowX = 0;
   int fourInRowO = 0;

   for(rows =0 ; rows <16 ; rows+=4)
   {
	   for(counter =0 ;counter<4 ; counter++)
	   {
		   if(position[rows+counter] == 'x')
				fourInRowX++;
		   if(position[rows+counter] == 'o')
				fourInRowO++;
	   }
	   
	   if(fourInRowX == 4)
	   {
		   winner = 'x';
		   return winner;
	   }
	   if(fourInRowO == 4)
	   {
		   winner ='o';
		   return winner;
	   }
	   fourInRowO =0;
	   fourInRowX =0;
	   
   }//end for loop

  return '?';
}
char Game:: checkColumns()
{
   int column 	  	 = 0;
   int counter    	 = 0;
   int fourInColumnX = 0;
   int fourInColumnO = 0;
   
   for(column =0 ;column<16 ; column+=4)
   {
	   for(counter =0 ;counter<4 ; counter++)
	   {
		   if(position[counter + column] == 'x')
			   fourInColumnX++;
		   
		   if(position[counter +column] == 'o')
			   fourInColumnO++;
		}   
		 
		if(fourInColumnX == 4)
		{
		  winner = 'x';
		  return winner;			  
		}
		if(fourInColumnO == 4)
		{
		  winner = 'o';
		  return winner;			  
		}
	
		fourInColumnO =0;
		fourInColumnX =0;
   }

  return '?';
}

char Game:: checkDiagonals()
{
	//check the diagonals for a winner
	int  counter=0;
    int  fourInRowX = 0;
    int  fourInRowO = 0;
	
	//check left to right diagonal
	for(counter =0 ; counter<16 ; counter+=5)
	{
		if(position[counter] == 'x')
			fourInRowX++;
		
		if(position[counter] == 'o')
			fourInRowO++;			
	}
	
	//check right to left diagonal
	if(fourInRowX !=4 and fourInRowO !=4)
	{
		for(int i=3 ; i<15 ; i=i+3)
		{
			if(position[i] == 'x')
				fourInRowX++;
			
			if(position[i] == 'o')
				fourInRowO++;
		}
	}
	if(fourInRowX == 4)
	{
		winner ='x';
		//return winner;
	}	
	if(fourInRowO == 4)
	{
		winner ='o';
		//return winner;
	}
	
	fourInRowX =0;
	fourInRowO =0;
	
  return winner;	
}
char Game:: determineWinner()
{
	char checkWinner ='?';
	
	checkWinner = checkRows();
	
	if(checkWinner =='?')
		checkWinner = checkColumns();
	
	if(checkWinner)
		checkWinner = checkDiagonals();
	
	return checkWinner;
}