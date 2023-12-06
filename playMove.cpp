#include "GameState.h"
#include "globals.h"


#include <iostream>
using namespace std;

bool validPos (int row, int col){

  if (row < 0 || row > boardSize){
    return false;
  } else if (col < 0 || col > boardSize){
    return false;
  }

  return true;
}

void playMove(GameState& game_state) {    // validity check in main not here
  
  int player;
  int row;
  int col = game_state.get_selectedColumn();

  if (game_state.get_turn()){        //Set player to colors turn
    player = R;    
  } else {
    player = Y;
  }

  for (int x = 0 ; x < boardSize; x++){     //Does not account for out of bounds column or full column

    if (game_state.get_gameBoard(x, game_state.get_selectedColumn()) == Empty){
    
      game_state.set_gameBoard(x, game_state.get_selectedColumn(), player);
      row = x;
      x = boardSize;

    }
  }

  int dirx [4] = {0, 1, 1, 1};
  int diry [4] = {1, 1, 0, -1};

  for (int x = 0; x < 4; x++){    // move through dir arrays indicating different directions while loops check positive and negative direcctions in order from placed piece and
                                  // counts how many are in a row then checks next row
    int count = 1;
    int n = 1;

    while (validPos(row + n*diry[x], col + n*dirx[x]) && game_state.get_gameBoard(row + n*diry[x], col + n*dirx[x]) == player){        

      count++;
      n++;

    }

    n = -1;

    while (validPos(row + n*diry[x], col + n*dirx[x]) && game_state.get_gameBoard(row + n*diry[x], col + n*dirx[x]) == player){

      count++;
      n--;

    }

    if (count >= 4){

      game_state.set_winner(player);
      game_state.set_gameOver(true);             //Figure out game over 
      x = 4;

    }
  }


  


  if (game_state.get_turn()){        // swith turn
    game_state.set_turn(false);
  } else {
    game_state.set_turn(true);
  }

  game_state.set_moveValid(false);   //move valid default false
}