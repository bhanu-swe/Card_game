#include <iostream>
#include <ctime>
#include <string>
using namespace std;

class Number
{
    public:
     
    int num1, num2, sum, extracard;
  
};

void card1 (int num1, int num2, int num3, int sum);
void card2 (int num1, int num2, int sum);
bool playagain (char x, int money);
int winnerfunction (int cardplayer1, int cardplayer2);
int declarewinner (int winner, int decision, int bet);


int
main ()
{
  srand (time (NULL));
  string name;
  int bet, decision, winner, prize;
  char play;
  bool logic = true;
  int money = 100000;
  cout << "-------------------------" << endl;
  cout << "Game start now" << endl;

  cout << " Enter your Name: " << endl;
  getline (cin, name);

  cout << "\nHI!" << name << endl;
  cout << "---------------------------------" << endl;
  cout << "WELCOME TO VIRTUAL BACCARAT TABLE" << endl;
  cout << "---------------------------------" << endl;

  while (logic != false)
    {
      cout << "current Balance, Coins" << money << endl;
      cout << "1-cardplayer1 \n 2-cardplayer2\n";
      cout << "chose your bet" << endl;
      while (!(cin >> decision) || (decision < 1 || decision > 2))
	{
	  cin.clear ();
	  cout << "\n" << "Choose your bet ";
	  cout << "\n" << "1-cardplayer1 \n 2-cardplayer2\n";
	}


      do
	{
	  cout << "Place your bet,coins: ";
	  cin >> bet;
	}
      while (bet > money);

      cout << "\n-------------------------\n";
      cout << "        -cardplayer1-\n";
      cout << "\n-------------------------\n";

      struct Number player1;
      player1.num1 = rand () % 10 + 1;
      player1.num2 = rand () % 10 + 1;
      player1.sum = (player1.num1 + player1.num2) % 10;

      if (player1.sum != 9 && player1.sum != 8)
	{
	  player1.extracard = rand () % 10 + 1;
	  player1.sum += player1.extracard;
	  player1.sum = player1.sum % 10;
	  card1 (player1.num1, player1.num2, player1.extracard, player1.sum);
	}
      else
	{
	  card2 (player1.num1, player1.num2, player1.sum);
	}

      cout << "\n-------------------------\n";
      cout << "        -cardplayer2-\n";
      cout << "\n-------------------------\n";

      struct Number player2;
      player2.num1 = rand () % 10 + 1;
      player2.num2 = rand () % 10 + 1;
      player2.sum = (player2.num1 + player2.num2) % 10;

      if (player2.sum != 9 && player2.sum != 8)
	{
	  player2.extracard = rand () % 10 + 1;
	  player2.sum += player2.extracard;
	  player2.sum = player2.sum % 10;
	  card1 (player2.num1, player2.num2, player2.extracard, player2.sum);
	}
      else
	{
	  card2 (player2.num1, player2.num2, player2.sum);
	}

      winner = winnerfunction (player1.sum, player2.sum);

      prize = declarewinner (winner, decision, bet);

      money += prize;

      cout << "Current Money, Coins " << money << "\n\n";

      cout << "Play again? Y/N ";

      cin >> play;
      logic = playagain (play, money);

    }

  return 0;
}

void
card1 (int num1, int num2, int num3, int sum)
{
  cout << "---------\n";
  cout << "|      |\n";
  cout << "|   " << sum << "   |\n";
  cout << "|      |\n";
  cout << "---------\n";

  cout << "First Card " << num1 << "\n";
  cout << "Second card" << num2 << "\n";
  cout << "Extra card " << num3;

}

void
card2 (int num1, int num2, int sum)
{
  cout << "---------\n";
  cout << "|      |\n";
  cout << "|   " << sum << "  |\n";
  cout << "|      |\n";
  cout << "---------\n";

  cout << "First Card " << num1 << "\n";
  cout << "Second card" << num2 << "\n";

}

bool
playagain (char x, int money)
{

  if (money > 0)
    {

      if (x == 'Y' || x == 'y')
	{

	  return true;
	}
      else if (x == 'N' || x == 'n')
	{

	  cout << "THANK YOU FOR PLAYING!";
	  return false;
	}
    }
  else
    {

      cout << "Insufficient fund!";
      return false;
    }
  return false;

}


int
winnerfunction (int bankerCard, int playerCard)
{
  //function to determine nearest number to 9
  //returns 1,2,3 depending on condiiton met

  std::cout << "\n==================================\n";
  if (bankerCard > playerCard)
    {

      cout << "\nCardplayer1 WIN, ";
      return 1;
    }
  else if (bankerCard < playerCard)
    {

      cout << "\nCardplayer2 WIN, ";
      return 2;

    }
  cout << "\nDRAW, ";
  return 3;

}


int
declarewinner (int winner, int decision, int bet)
{

  if (winner == decision)
    {

      //win pays the bet
      cout << "YOU WIN!\n";
      return bet;
    }
  if (winner == 3)
    {

      //draw
      cout << "Tie Game!" << std::endl;
      return 0;
    }
  else
    {

      cout << "YOU LOSE!\n";
      bet *= -1;
      return bet;
    }

}
