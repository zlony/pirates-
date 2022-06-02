#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

constexpr int FIELD_WIDTH = 10; 
constexpr int FIELD_HEIGHT = 10;

int g_treasureX;
int g_treasureY;

int g_pirateX = 0, 
int g_pirateY = 0;

void Init();
void Greeting();
void MainLoop();

void MoveLeft();
void MoveRight();
void MoveUp();
void MoveDown();

bool CheckWin();

int main() {

	Init();

	Greeting();	

	MainLoop();

	system("pause");
	return 0;
}

void MoveLeft() {
	g_pirateX--;
	if (g_pirateX < 0) {
		g_pirateX = FIELD_WIDTH;
	}
}
void MoveRight() {
	g_pirateX++;
	if (g_pirateX > FIELD_WIDTH) {
		g_pirateX = 0;
	}
}
void MoveUp() {
	g_pirateY++;
	if (g_pirateY > FIELD_HEIGHT) {
		g_pirateY = 0;
	}
}
void MoveDown() {
	g_pirateY--;
	if (g_pirateY < 0) {
		g_pirateY = FIELD_HEIGHT;
	}
}

void MainLoop() {
	char inputDirections;


	bool isGameRunning = true;

	while (isGameRunning)
	{
		cout << "Choose your direction: ";
		cin >> inputDirections;

		switch (inputDirections)
		{
		case 'w':
		{
			MoveUp();//pirateY = (10 + pirateY) % 10;
			break;
		}
		case 'a':
		{
			MoveLeft();
			break;
		}
		case 's':
		{
			MoveDown();
			break;
		}
		case 'd':
		{
			MoveRight();
			break;
		}
		case 'q':
		{
			cout << "Are you tired? Understand. See you." << endl;
			isGameRunning = false;
			continue;
		}
		default:
			break;
		}

		cout << endl << ", your are at [" << g_pirateX << ", " << g_pirateY << "]" << endl;

		isGameRunning = !CheckWin();
		}

	}

bool CheckWin() {
	if (g_treasureX == g_pirateX && g_treasureY == g_pirateY) {
		cout << "You've found the treasure!" << endl;
		return true;
	}
	else {
		cout << "Not here, looser" << endl;
		cout << "Treasure is here: " << g_treasureX << ", " << g_treasureY << endl;
	}
	return false;
}

void Init() {
	//srand(unsigned(std::time(0)));

	g_treasureX = rand() % FIELD_WIDTH;
	g_treasureY = rand() % FIELD_HEIGHT;
}

void Greeting() {
	std::string pirateName;

	cout << "Hello, stranger! What is your name? : ";
	cin >> pirateName;

	cout << "Welcome on island, " << pirateName << endl;
	cout << "You can walk around using 'W', 'S', 'A', 'D' keys\n";

	cout << "Treasure is here: " << g_treasureX << ", " << g_treasureY << endl;

}

