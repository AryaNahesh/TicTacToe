#include <stdbool.h>
#include <stdio.h>

void printBoard(char board[3][3]);
bool haveWon(char board[3][3], char player);

int main() {
  char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
  char player = 'X';
  bool gameOver = false;
  int row, col;

  while (!gameOver) {
    printBoard(board);
    printf("Player %c enter: ", player);
    scanf("%d %d", &row, &col);
    printf("\n");

    if (board[row][col] == ' ') {
      board[row][col] = player;
      gameOver = haveWon(board, player);
      if (gameOver) {
        printf("Player %c has won!\n", player);
      } else {
        player = (player == 'X') ? 'O' : 'X';
      }
    } else {
      printf("Invalid move. Try again!\n");
    }
  }

  printBoard(board);

  return 0;
}

void printBoard(char board[3][3]) {
  for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 3; col++) {
      printf("%c | ", board[row][col]);
    }
    printf("\n");
  }
}

bool haveWon(char board[3][3], char player) {
  // check the rows
  for (int row = 0; row < 3; row++) {
    if (board[row][0] == player && board[row][1] == player &&
        board[row][2] == player) {
      return true;
    }
  }

  // check the columns
  for (int col = 0; col < 3; col++) {
    if (board[0][col] == player && board[1][col] == player &&
        board[2][col] == player) {
      return true;
    }
  }

  // check the diagonals
  if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
    return true;
  }

  if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
    return true;
  }

  return false;
}
