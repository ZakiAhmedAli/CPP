/*
**Goal: Practice creating classes and functions. 
**Create a program that allows two users to 
**play a 4x4 tic-tac-toe game. 
*/

#include <fstream>
#include "class1.cpp"
/****************Functions prototypes ******************************/
	void CheckResponse(Game&  , char );                       
/*														           */
	void GetUserName(string & , string &);                         
/*														           */
	void PrintBlankBoard();                                        
/*														           */
	void PrintTheBoard(Game);                                      
/*														           */
	void WriteTheBoard(Game);                                      
/*														           */
	void PrintUserPrompt(string nameIn, char letter);              
/*														           */
	void printGameWinner(Game boardIn, string nameX, string nameO);
/*														           */
int  GetUserResponse();
/*******************************************************************/


using namespace std;

//get the chosen user position, check that it is an integer
//check that it is between 0 and 15 inclusive													           
int  GetUserResponse()
{
	int Position =-1;
	cout<<"Enter an integer between 0 : 15:";
	cin>>Position;
	
	while(Position < 0 or Position > 15 or !cin)
	{
		cin.clear();
		
		std::cout<<"That's not a valid position\nEnter an integer between 0 : 15 : ";
		
		cin.clear();
		
		std::cin>>Position;
	}
	return Position;
}//end of function


//check that the position selected is not already selected
void CheckResponse(Game &BoardIn , char Input)
{
	int Position;
	int UserIn;

	do
	{
		Position = GetUserResponse();
		UserIn   = BoardIn.SetPosition(Position , Input);
		if(UserIn == -1)
		{
			cout<<"This Position is taken.";
		}		
	}while(Position == -1);

}                       
	//get the user names													           
void GetUserName(string &UserX , string &UserO)
{
	//get the user names
    std::cout<< "Name of user to be 'x' :";
    std::cin >>UserX;
    std::cout<< "Name of user to be 'o' :";
    std::cin >>UserO;
}                         
													           
void PrintBlankBoard()
{
	for(int i=0 ; i<16 ; i++)
	{
		cout<<"|"<<i;
		if(i<=9)
			cout<<" ";
		if(i % 4 == 3)
			cout<<"|\n";
	}
	cout<<"\n";
}                                      
													           
void PrintTheBoard(Game BoardIn)
{
	//print the board with player moves
	PrintBlankBoard();
	
	for(int i=0 ; i<16 ; i++)
	{
		std::cout<<"|"<<BoardIn.GetPosition()[i];
		if(i % 4 == 3)
			std::cout<<"|\n";
	}
	cout<<"\n";
}                                      

//print the board with player moves													           
void WriteTheBoard(Game BoardIn)
{
	for(int i=0; i<16 ;i++)
	{
		std::cout<<"|"<<BoardIn.GetPosition()[i];
		
		if(i %4 == 3)
			std::cout<<"|\n";
	}
	cout<<"\n";
}   
												           
void PrintUserPrompt(string nameIn, char letter)
{
	//prompt for user input
    std::cout<<nameIn<<"\nwhere would you like to place an "<<letter<<"?:";	
}  
													           
void printGameWinner(Game boardIn, string nameX, string nameO)
{
	char winner;
	
	winner = boardIn.determineWinner();
	if(winner == 'x')
		cout<<"Congrats "<<nameX<<" you won!\n\n";
	
	if(winner == 'o')
		cout<<"Congrats "<<nameO<<" you won!\n\n";
}
