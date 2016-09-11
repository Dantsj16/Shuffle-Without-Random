#include <iostream>
#include <string>
using namespace std;
typedef unsigned long ug;
string num[] = {"TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE","TEN","JACK","QUEEN","KING","ACE"};
string typ[] = {"CLUBS", "SPADES", "DIAMONDS","HEARTS" };
struct Card {
	string type;
	string number;
};
class Cards
{
public:
	Cards () :n(1)
	{
		for (int i = 0; i < 52; i++)
		{
			CardPtr[i].type = typ[i / 13];
			CardPtr[i].number = num[i % 13];
		}
	}
	void getCards() {
		for (int i = 0; i < 52; i++)
		{
			cout << CardPtr[i].type << " " << CardPtr[i].number << endl;
		}
	}
	void shuffleCards()  {
		for (int j = 0; j < 10; j++)
		{
			for (int i = 0; i < 52; i++)
			{
				string tempstringnumber = CardPtr[i].number;
				string tempstringtype = CardPtr[i].type;
				n = n * 16807 % 2147483647;
				CardPtr[i].type = CardPtr[n % 52].type;
				CardPtr[i].number = CardPtr[n % 52].number;
				CardPtr[n % 52].type = tempstringtype;
				CardPtr[n % 52].number = tempstringnumber;
			}
		}
	}
	~Cards()
	{
		delete[] CardPtr;
	}
private:
	Card *CardPtr = new Card[52];
	ug n;
};
int main() {
	Cards myCards;
	myCards.shuffleCards();
	myCards.getCards();
	int x;
	cin >> x;
}