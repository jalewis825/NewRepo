
#include <iostream>
#include <vector>
#include <limits>

const int size = 3;

enum class Player {none, a, b};
enum class Direction { top, bottom, left, right};

struct Cell {
	bool top = false;
	bool bottom = false;
	bool left = false;
	bool right = false;//initilizes each side of the cell to false (not played)
	Player owner = Player::none; //initilizes the owner of the cell to none.
};

//creates a vector of vectors to access each cell within the board
std::vector<std::vector<Cell>> board(size, std::vector<Cell>(size));
int playerAScore = 0;
int playerBScore = 0;
Player currentPlayer = Player::a;

void printRules() {
	std::cout << "Welcome to Dots & Boxes: Players take turns connecting the dots." << std::endl;
	std::cout << "When a player completes a box, they earn a point and take another turn." << std::endl;
	std::cout << "The game ends when all boxes are claimed, and the player with the most points wins!" << std::endl;
}

void makeBoard() {

	std::cout << std::endl;
	//print column numbers
	std::cout << "    ";
	for (int col = 1; col <= size; col++) {
		std::cout << col << "   ";
	}

	std::cout << std::endl;
	for (int row = 1; row <= size; row++) {

		//print dots & horizontal lines
		std::cout << "  ";
		for (int col = 0; col < size; col++) {
			std::cout << ".---";
		}
		std::cout << "." << std::endl;
		
		//print row numbers & vertical lines
		std::cout << row << " ";
		for (int col = 0; col < size; col++) {
			std::cout << "|   ";
		}
		std::cout << "|" << std::endl;
		}
	//print last row of dots & horizontal lines
	std::cout << "  ";
	for (int col = 0; col < size; col++) {
		std::cout << ".---";
	}
	std::cout << "." << std::endl;
	std::cout << std::endl;
}

bool isMoveValid(int row, int col, Direction direction) {
	//makes sure row and col designation provided by user with within range of the board size
	if (row < 0 || row > size || col < 0 || col > size) {
		return false;
	}

	//checks if side of the cell has already been claimed
	switch (direction) {
	case Direction::top: 
		return !board[row][col].top;
	case Direction::bottom:
		return !board[row][col].bottom;
	case Direction::left:
		return !board[row][col].left;
	case Direction::right:
		return !board[row][col].right;
	}
}

bool gameStatus() {
	int totalBoxes = size * size;
	return (playerAScore + playerBScore) < totalBoxes;
}

void gamePlay() {
	int row;
	int col;
	int direction;

	while (gameStatus()) {
		makeBoard();
		std::cout << "Player: " << (currentPlayer == Player::a ? 'a' : 'b') << "'s turn. Enter row, column, and direction (T/B/L/R): ";
		while (!(std::cin >> row >> col >> direction) || (direction != 'T' && direction !=
			'B' && direction != 'L' && direction != 'R') {
			std::cout << "Invalid move. Try again: ";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
}


int main() {
	printRules();
	gamePlay();
	gameStatus();
	return 0; 
}

/*AI: Used to help me get started with gamePlay(); I had printRules, makeBoard(), and the enums created, 
I just needed help with a jumping off point for game play. I was struggling with the user input part of game play.*/