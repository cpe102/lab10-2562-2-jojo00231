#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;

string cardNames[] = {"","A","2","3","4","5","6","7","8","9","10","J","Q","K"};
int cardScores[] = {0,1,2,3,4,5,6,7,8,9,10,10,10,10};

int drawCard(void){
	int i = rand()%13+1 ;
	return i ;
}

int calScore(int x,int y,int z){
	return x + y + z ;
}

int findYugiAction(int s){	
	int per ;
	if(s == 9) return 2; 
	else if(s < 6) return 1; 
	else{ if(s==6||s==7||s==8)
			per = rand()%100+1 ;
				if( per < 69) return 1;
				else return 2;
		}
}

void checkWinner(int p, int y){
	cout << "\n---------------------------------\n";
	if(p == y) cout <<   "|             Draw!!!           |"; // when p is equal to y
	else if(p > y) cout <<   "|         Player wins!!!        |"; // when p is greater than y
		 else if(p < y) cout <<   "|          Yugi wins!!!         |"; // when p is less than y
	cout << "\n---------------------------------\n";
}

int main(){	
	srand(time(0));
	int playerScore, yugiScore, playerAction, yugiAction;
	int playerCards[3] = {drawCard(), drawCard(), 0};
	
	
	
	cout << "---------ORE NO TURN, DRAW!!!------------\n";
	cout << "Your cards: " << cardNames[playerCards[0]] << " " << cardNames[playerCards[1]] << "\n";
	playerScore = calScore(cardScores[playerCards[0]],cardScores[playerCards[1]],cardScores[playerCards[2]])%10;
	cout << "Your score: " << playerScore << "\n";
	do{
		cout << "(1) Destiny draw (2) Stay, SELECT: ";
		cin >> playerAction;
	}while(playerAction != 1 && playerAction != 2);
	if(playerAction == 1){
		playerCards[2] = drawCard() ;
		cout << "Player draws the 3rd card!!!" << "\n";
		cout << "Your 3rd card: " << cardNames[playerCards[2]] << "\n";
		playerScore = calScore(cardScores[playerCards[0]],cardScores[playerCards[1]],cardScores[playerCards[2]])%10;
		cout << "Your new score: " << playerScore << "\n";
	}
	cout << "------------ Turn end -------------------\n\n";
	
	
	int yugiCards[3]= {drawCard(), drawCard(), 0};
	cout << "---------YUGI'S TURN, DRAW!!!------------\n";
	cout << "Yugi's cards: " << cardNames[yugiCards[0]] << " " << cardNames[yugiCards[1]] << "\n";
	yugiScore = calScore(cardScores[yugiCards[0]],cardScores[yugiCards[1]],cardScores[yugiCards[2]])%10;
	cout << "Yugi's score: " << yugiScore << "\n";
	yugiAction = findYugiAction(yugiScore);
	if(yugiAction == 1){
		cout << "Yugi draws the 3rd card!!!\n";
		yugiCards[2] = drawCard() ;
		cout << "Yugi's 3rd card: " << cardNames[yugiCards[2]]<< "\n";
		yugiScore = calScore(cardScores[yugiCards[0]],cardScores[yugiCards[1]],cardScores[yugiCards[2]])%10 ;
		cout << "Yugi's new score: " << yugiScore << "\n";
	}
	cout << "------------ Turn end -------------------\n";
	
	checkWinner(playerScore,yugiScore);
}
