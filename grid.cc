#include <iostream>
#include "grid.h"

using namespace std;


Grid::Grid() {
  td = nullptr;
}

Grid::~Grid() { 
  if(td){
    delete td;
  }
}

void Grid::clearGrid() {
  theGrid.clear();
}

bool Grid::isWon() const { 
  return won; 
}

void Grid::init(int n) {
  if(td){
    clearGrid();
    delete td;
  }
  theGrid.resize(n);
  td = new TextDisplay(n);
  gridSize = n;
  for(int r = 0; r < gridSize; r++){
    for(int c = 0; c < gridSize; c++){
      Cell temp;
      temp.setCoords(r,c);
      theGrid[r].emplace_back(temp);
    }
  }

  for(int r = 0; r < gridSize; r++){
    for(int c = 0; c < gridSize; c++){
      if(r + 1 < gridSize){
        theGrid[r][c].attach(&theGrid[r + 1][c]);
      }
      if(r - 1 >= 0){
        theGrid[r][c].attach(&theGrid[r - 1][c]);
      }
      if(c + 1 < gridSize){
        theGrid[r][c].attach(&theGrid[r][c + 1]);
      }
      if(c - 1 >= 0){
        theGrid[r][c].attach(&theGrid[r][c - 1]);
      }
      theGrid[r][c].attach(td);
    }
  }
}

void Grid::turnOn(int r, int c) {
  theGrid[r][c].setOn();
}

void Grid::toggle(int r, int c) {
  theGrid[r][c].toggle();
  bool w = true;
  for(int r = 0; r < gridSize; r++){
    for(int c = 0; c < gridSize; c++){
      if(theGrid[r][c].getState()){
        w = false;
        break;
      }
    }
    if(w == false){
      break;
    }
  }
  won = w;
}


ostream &operator<<(ostream &out, const Grid &g) {
  out << *g.td;
  return out;
}

void Grid::printCells() const {
  for(int r = 0; r < gridSize; r++){
    for(int c = 0; c < gridSize; c++){
      std::cout << theGrid[r][c].getName() << ": " << theGrid[r][c].getObserverNames() << std::endl;
    }
  }
}

