#include "GameState.h"
#include "globals.h"

#include <iostream>
using namespace std;

GameState :: GameState(){

    selectedRow = 0;
    selectedColumn = 0;
    moveValid = true;
    gameOver = false;
    turn = true;
    winner = Empty;

    for (int y = 0; y < boardSize; y++) {

        for (int x = 0; x < boardSize; x++) {

            gameBoard[x][y] = Empty;
        
        }
    }
}

int GameState :: get_selectedRow(){
    return selectedRow; 
}

int GameState :: get_selectedColumn(){
    return selectedColumn;
}

void GameState :: set_selectedRow(int value){

    if (value >= 0 && value < boardSize){
        selectedRow = value;
    } 

    return;
}

void GameState :: set_selectedColumn(int value){

    if (value >= 0 && value < boardSize){
        selectedColumn = value;
    } 

    return;
}

bool GameState :: get_moveValid(){
    return moveValid;
}

void GameState :: set_moveValid(bool value){
    moveValid = value;
}

bool GameState :: get_gameOver(){
    return gameOver;
}

void GameState :: set_gameOver(bool value){
    gameOver = value;
}

bool GameState :: get_turn(){
    return turn;
}

void GameState :: set_turn(bool value){
    turn = value;
}

int GameState :: get_winner(){
    return winner;
}

void GameState :: set_winner(int value){
    winner = value;
}

int GameState :: get_gameBoard(int row, int col){

    if (row < 0 || row >= boardSize){
        return Empty;
    }

    if (col < 0 || col >= boardSize){
        return Empty;
    }

    return gameBoard[row][col];
}

void GameState :: set_gameBoard(int row, int col, int value){

    if (row < 0 || row >= boardSize){
        return;
    }

    if (col < 0 || col >= boardSize){
        return;
    }

    if (value != 1 && value != -1 && value != 0){
        return;
    }

    gameBoard[row][col] = value;

    return;
}