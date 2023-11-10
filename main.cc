#include <iostream>
#include <string>
#include "grid.h"

using namespace std;

int main() {
  cin.exceptions(ios::eofbit|ios::failbit);
  string cmd, aux;
  Grid g;
  int moves = 0;
  bool startGame = false;

  while (true) {
    try {
      cin >> cmd;
      if (cmd == "new") {
        int n;
        cin >> n;
        g.init(n);
        startGame = false;
      }
      else if (cmd == "init") {
        int r = 0, c = 0;
        cin >> r >> c;
        while (r != -1 && c != -1){
          g.turnOn(r,c);
          cin >> r >> c;
        }
        cout << g;
      }
      else if ( cmd == "neighbours" ) {
        g.printCells();
      }
      else if (cmd == "game") {
        cin >> moves;
        startGame = true;
        if (moves == 1){
          std::cout << "1 move left" << std::endl;
        }else{
          std::cout << moves << " moves left" << std::endl;
        }
      }
      else if (cmd == "switch") {
        int r = 0, c = 0;
        try{
          cin >> r >> c;
        }
        catch(ios::failure &) {
          break;
        }
        moves -= 1;
        g.toggle(r,c);
        if (moves == 1){
          std::cout << g << "1 move left" << std::endl;
        }else{
          std::cout << g << moves << " moves left" << std::endl;
        }
        if (g.isWon() == true){
          std::cout << "Won" << std::endl;
        }else if (moves == 0 && startGame){
          std::cout << "Lost" << std::endl;
        }
      }  
    }
    catch (ios::failure &) {
      break;
    }
  }
}
