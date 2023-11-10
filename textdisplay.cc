#include <iostream>
#include "textdisplay.h"
#include "subject.h"
#include "observer.h"
#include "cell.h"

using namespace std;

TextDisplay::TextDisplay(int n) : gridSize{n} {
  theDisplay = vector<vector<char>> (gridSize, vector<char> (gridSize, '.'));
}

void TextDisplay::notify(Cell &whoNotified) {
  if (whoNotified.getState()){
    theDisplay[whoNotified.getRow()][whoNotified.getCol()] = 'X';
  }else{
    theDisplay[whoNotified.getRow()][whoNotified.getCol()] = '.';
  }
  
}

TextDisplay::~TextDisplay() {
  for (int i = 0; i < gridSize; i++){
    theDisplay[i].clear();
  }
  theDisplay.clear();
}

SubscriptionType TextDisplay::subType() const {
  return SubscriptionType::All;
}

std::string TextDisplay::getName() const {
  return "TD";
}

ostream &operator<<(ostream &out, const TextDisplay &td) {
  for (int r = 0; r < td.gridSize; r++){
    for (int c = 0; c < td.gridSize; c++){
      out << (td.theDisplay[r][c]);
    }
    out << endl;
  }
  return out;
}

