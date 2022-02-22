//TIC TAC TOE
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

//CHECK VERTICALLY
/*

 1 | 2 | 3 |   147
 4 | 5 | 6 |   258
 7 | 8 | 9 |   369

*/


//CHECK HORIZONTALLY
/*

 1  2  3    123 
=========  
 4  5  6    456
=========  
 7  8  9    789 
    

*/
//CHECK DIOGANALLY
/*
   159  357     
*/

string board[9] = {"1","2","3","4","5","6","7","8","9"};
void ChangeBoard(int a,string terima){
   board[a] = terima;
}
bool checkHorizontally(){
   bool check = false;
   for(int i = 0;i < 9; i += 3){
      check = board[i] == board[i + 1] && board[i] == board[i + 2] ;
      if(check == true) break;
   } 
return check;

}

bool checkVertically(){
   bool check1 = false;
   for(int i = 0; i < 3;i++){
      check1 = board[i] == board[i + 3] && board[i] == board[i + 6];
      if(check1 == true) break;
   }
   return check1;
}
bool checkDiagonally(){
   return (board[0] == board[4] && board[0] == board[8]) || (board[2] == board[4] && board[2] == board[6]) ;
   
}
bool CheckAll(){
   return checkVertically() || checkHorizontally() || checkDiagonally();
}
void Display(){
   int time = 0;
   while(time < 9){
   for(int i =0;i < 3;i++){
      if(i < 2)cout<<"     |";   
      else cout<<"      ";
   }
   cout<<"\n";
   for(int i =0;i < 3;i++){
      if(i < 2)cout<<"  "<<board[time]<<"  |";
      else cout<<"  "<<board[time]<<"   ";
      time++;
   }
   cout<<"\n";
   for(int i =0;i < 3;i++){
      if(i < 2)cout<<"_____|";   
      else cout<<"______";
   } 
   cout<<"\n";
      }
}
int main(){
   int turn = 0;  
   while(turn < 10 && !CheckAll()){
   string jalan,a;
   int spot;
   system("cls");
   cout<<"=====+ TIC TAC TOE +=====\n";
   cout<<"PLAYER 1 [X]          PLAYER 2 [O]\n\n";
   //TO DISPLAY THE BOARD
   Display();
   if(turn % 2 == 0){a = "PLAYER 1 \nPICK A SPOT : ";jalan = "X";}
   else {a = "PLAYER 2 \nPICK A SPOT : ";jalan = "O";}
   if(turn < 9){cout<<a;cin>>spot;}
   spot += -1;
   ChangeBoard(spot,jalan);
   turn++;
   }
   system("cls");
   Display();
   string message;
   bool winner = CheckAll();
   //NO WINNER MEANS CheckAll is false !
   if(winner == false){
      message = "NO WINNER";  
   }
   else{
      if((turn - 1) % 2 == 0){
         message = "PLAYER 1 IS THE WINNER";
      }
      else {
         message = "PLAYER 2 IS THE WINNER";
      }
   }
   cout<<message;

return 0;
}
