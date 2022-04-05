#include<iostream>

using namespace std;


// this function will be used to print the
// state of the board

void print_board(char board[][7]){
for(int i = 0; i<6; i++){
        cout<<"     ";
    for(int j=0; j<7; j++){
        cout<<board[i][j]<<" ";
    }
    cout<<endl;
}
  cout<<endl<<endl;
return ;
}

// this function will check that
// board is full or not

bool is_full(char board[][7]){
      for(int i = 0; i < 6; i++){
        for(int j = 0; j < 7; j++){
            // if we found any cell containing '0'
            // than that will indicate that
            // we still left some (one) move to be
            // played
            if(board[i][j] == '0') return false;
        }
      }
        return true;
}


// this is a helper function for the function
// check_winner used to check the winner

int check(char board[][7], int i, int j, char x){
        // checking 4 consecutive same character horizontally
        // this variable will keep the count of
        // consecutive character
        int cnt = 0;
        for(int k = j; k < 7; k++){
            if(board[i][k] == x) cnt++;
            else break;
        }
        // if this count is greater than or equal to 4
        // than it we will return 1, indicating that the current player
        // wins the match

        if(cnt >= 4) return 1;

        // checking 4 consecutive same character vertically

        // doing the same process as above
        cnt = 0;

        for(int k = i; k < 6; k++){
            if(board[k][i] == x) cnt++;
            else break;
        }

        if(cnt >= 4) return 1;

        // checking 4 consecutive same character diagonally
        cnt = 0;
        for(int k = i, l = j; k < 6 && l < 7; k++, j++){
            if(board[k][l] == x) cnt++;
            else break;
        }

        if(cnt >= 4) return 1;

        // checking 4 consecutive same character Anti - diagonally
        cnt = 0;
        for(int k = i, l = j; k >= 0 && l >= 0; k--, j--){
            if(board[k][l] == x) cnt++;
            else break;
        }

        if(cnt >= 4) return 1;

        // if none of the above if statement executes than it will
        // suggests that no player has won the match after this move
        // so we will return 0

        return 0;

}

// this function will check that which player wins the match
// after playing one move for any instance

int check_winner(char board[][7]){
    // the idea is simple, we will just iterate on the board
    // if we found character 'b' or 'r', than
    // we will call the helper function 'check' to check
    // that this player ('r', 'b') wins or not?

    // if we found any winner than we will return 1
    // else we will return 0

      for(int i = 0; i < 6; i++){
        for(int j = 0; j < 7; j++){
            if(board[i][j] == 'b') {

                int winner = check(board, i, j, board[i][j]);
                if(winner == 1) return 1;
            }
            if(board[i][j] == 'r'){
                int winner = check(board, i, j, board[i][j]);
                if(winner == 1) return 2;
            }
        }
      }
      return 0;
}

// this function will place a piece and report that
// weather the board is full or not

int place_peices(char board[][7], int turn_move, bool player_turn){
      // is_full function will check that weather
      // the board is full or not
      // if it is we will return -1

      bool flag = is_full(board);
      if(flag) return -1;
      for(int i =5; i>= 0; i--){
        // if we found an empty place in the choosen column
        // than we will place the piece on that column

        if(board[i][turn_move] == '0'){
                   if(player_turn){
                      board[i][turn_move] = 'b';
                   }
                   else board[i][turn_move] = 'r';
                   break;
        }
      }
      // this variable will store the value return by the
      // function check_winner and at the end we will
      // return that

      int result = check_winner(board);
      return result;
}



int main(){

// taking the name of the player as the input
// and greeting them

cout<<"---------------------CONNECT 4-----------------------"<<endl<<endl;
string name1, name2;
cout<<"Please Enter the Name of Player 1 "<<endl;
cout<<"Please Enter the Name of Player 2 "<<endl;
cin>>name1>>name2;

// these variable will store the count of wins both the player
// will make while playing
int count1 = 0, count2 = 0;

cout<<"*****************WELCOME IN THE GAME*****************"<<endl<<endl;

// this loop will run while the users don't enter 'N'

while(1){

// in every round we will start with
// fresh board

char board[6][7];

// initializing the board with values
// zero

for(int i =0; i<6; i++){
    for(int j=0; j<7; j++){
        board[i][j] = '0';
    }
}

// this variable will track the turn
// of players, if it is true than its player 1's
// turn else its player 2's turn

bool player_turn = true;

cout<<"**********BOARD**********"<<endl<<endl;
// before starting the game we should print the board
print_board(board);
cout<<endl;


while(1){


// this variable is used to input the column
// number entered the player
int turn_move;

// this variable will store the result
// -1 -> if match drawn (board is full)
// 0 ->  if no one wins after playing the move
// 1 -> if player 1 wins
// 2 -> if player 2 wins

int result;

if(player_turn){
    // taking input the move played by the player 1

    cout<<"Player 1 Move : ";
    cin>>turn_move;

    // storing the result to use in future

    result = place_peices(board, turn_move - 1, player_turn);

    // toggling the moves

    player_turn = false;
}

else{
    // taking input the move played by the player 1

    cout<<"Player 2 Move : ";
    cin>>turn_move;

    // storing the result to use in future

    result = place_peices(board, turn_move - 1, player_turn);

    // toggling the moves

    player_turn = true;
}

// all actions will be made on the basis of
// value stored by the variable result as
// mentioned above

if(result == 1) {
    print_board(board);
    cout<<"*******WINNER : PLAYER 1******"<<endl<<endl;
    count1++;
    break;
}

if(result == 2) {
        print_board(board);
    cout<<"*******WINNER : PLAYER 2******"<<endl<<endl;
    count2++;
    break;
}

if(result == 0){
    print_board(board);
    continue;
}

if(result < 0){
    print_board(board);
    cout<<"*******MATCH DRAWN*******"<<endl;
    break;
}

}

cout<<endl;

// asking player to continue the game,
// if player entered N than we will end the
// session, else new game will start

cout<<"Play Agian (Y/N) ?"<<endl;
char ch;
cin>>ch;

if(ch == 'Y') continue;

else {
    // printing the win count of
    // each player and greeting them
    cout<<endl;
    cout<<"*****WIN COUNT*****"<<endl;
    cout<<"Player 1     Player 2"<<endl;
    cout<<"   "<<count1<<"            "<<count2<<endl;
    cout<<"Thanks for Playing!!!"<<endl;
    cout<<"\nExiting..."<<endl;
    break;
}
}

return 0;
}
