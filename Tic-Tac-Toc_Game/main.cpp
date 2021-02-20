/*Goal: Practice creating classes and functions. 
**Create a program that allows two users to 
**play a 4x4 tic-tac-toe game. 
*/

#include "ClassFunctions.cpp"




int main()
{
    Game gameBoard;
    string nameX;
    string nameO;
    
    int tieGame = 0;
    char gameWinner = '?';
    int numTurns = 0;
    
    //get the names of the players
    GetUserName(nameX , nameO);
    
    //the game is played for 8 turns maximum
    while(numTurns < 8)
    {
        //print a board that has the postions numbered
		PrintTheBoard(gameBoard);
        //ask player x where they want to put an 'x'
		PrintUserPrompt(nameX , 'x');
        //check that the input is a valid position and that
        //it has not already been taken
        CheckResponse(gameBoard , 'x');
        //check to see if player 'x' has four in a row somewhere on the board
        gameWinner = gameBoard.determineWinner();
        
        //if player 'x' has won, end the game
		if(gameWinner !='?')
		{
			PrintTheBoard(gameBoard);
			WriteTheBoard(gameBoard);
			printGameWinner(gameBoard , nameX , nameO);
			break;
		}
        
		//Now do the same for player 'o'
        //print a board that has the postions numbered
		PrintTheBoard(gameBoard);
		//ask player x where they want to put an 'o'
		PrintUserPrompt(nameX , 'o');
		//check that the input is a valid position and that
        //it has not already been taken
        CheckResponse(gameBoard , 'o');
        //check to see if player 'x' has four in a row somewhere on the board
        gameWinner = gameBoard.determineWinner();
		
		if(gameWinner != '?')
		{
			PrintTheBoard(gameBoard);
			WriteTheBoard(gameBoard);
			printGameWinner(gameBoard , nameX , nameO);
			break;
		}
		numTurns++;
		
	}
	
	if(numTurns >= 8)
		cout<<"Game Tie.\n";
    
    return 0;
}


