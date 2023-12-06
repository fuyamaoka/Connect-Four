#include <iostream>
#include <string>
using namespace std;

#include "GameState.h"
#include "globals.h"

int main() {

  const int numOfRounds = 3;
  GameState game_state[numOfRounds];

  int col;
  int round = 0;
  int rScore = 0;
  int yScore = 0;

  cout << "Game " << round+1 << endl;

  while (!game_state[round].get_gameOver()) {

    cout << "Enter column to place piece: ";
    cin >> col;
 
    if( cin.eof() ) {
      cerr << endl << "Game ended by user." << endl ;
      exit( 0 ) ;
    }
    if( cin.fail() ) {
      cin.clear() ;
      cin.ignore( 1000, '\n' ) ;
      col = -1;
    }

    while (col < 0 || col >= boardSize || game_state[round].get_gameBoard(boardSize - 1, col) != Empty){

      cout << "Invalid column!" << endl;
      cout << "Enter column to place piece: ";
      cin >> col;

    }
    
    cout << "column chosen: " << col << endl;

    game_state[round].set_selectedColumn(col);

    for (int y = 0; y < boardSize; y++){
      
      if (game_state[round].get_gameBoard(y, col) == Empty){

        game_state[round].set_selectedRow(y);
        y = boardSize;

      }
    }

    playMove(game_state[round]);


    for (int y = boardSize - 1; y >= 0; y--){
      
      for (int x = 0; x < boardSize; x++){
        
        if (game_state[round].get_gameBoard(y, x) == 1){
          cout << "R";
        } else if (game_state[round].get_gameBoard(y, x) == -1){
          cout << "Y";
        } else {
          cout << "_";
        }
      }

      cout << "\n";

    }

    cout << endl;

    // Check if a player won this round

    if (game_state[round].get_gameOver()){

      if (game_state[round].get_turn()){

        yScore++;
        cout << "Y won this round!" << endl;

      } else {

        rScore++;
        cout << "R won this round!" << endl;

      }

      round++;

      if (round < 3 && (yScore != 2 && rScore != 2)){
     
      cout << "Game " << round+1 << endl;

    }

    }

    // Check if a player won this match

    if (round == 3 || yScore == 2 || rScore == 2){

      if (rScore == 2){

        cout << "R won the match!";

      } else {

        cout << "Y won the match!";

      }

      return 0;
    }
  }
}
  
