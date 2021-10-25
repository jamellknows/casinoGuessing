#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
void rules();
int main()
{
    string playerName;
    int balance;
    int bettingAmount;
    int dice;
    char choice;
    int guess;
    srand(time(0));
    cout <<"\n\t\t=======WELCOME TO CASINO WORLD=======\n\n";
    cout <<"\n\nWhat's your Name : ";
    getline(cin, playerName);
    cout <<"\n\nEnter the starting balance to play a game:  £";
    cin >> balance;
    do{
        system("clear");
        rules();
        cout << "\n\nYour current balance is £" << balance << "\n";
        do{
            cout << " Hey, " << playerName <<", enter your amount to bet: £";
            cin >> bettingAmount;
            if(bettingAmount > balance){
                cout <<"Betting amount can not be greater than your current balance!\n"
                << "\nRe-enter your betting amount";

            }
        }while(bettingAmount > balance);
        do{
            cout << "Guess any betting number between 1 & 10: ";
            cin >> guess;
            if(guess <= 0 || guess > 10){
                cout << "\nNumber should be between 1 to 10\n"
                <<"Re-enter your number:\n";
            }
        }while(guess <=0 || guess > 10);
        dice = rand()%10 + 1;
        if(guess==dice)
        {
            cout << "\nCongratulations!! You have won £" << bettingAmount*10;
            balance = balance + bettingAmount*10;
        }else{
            cout <<"Better luck next time! You lost £" <<bettingAmount <<"\n";
            balance = balance - bettingAmount;
        }
        cout << "\nThe winning number was: " <<dice <<"\n";
        cout <<"\n"<<playerName<<", you have a balance of £"<<balance<<"\n";
        if(balance ==0){
            cout << "You have no money to play";
            break;
        }
        cout<< "\n\n-->Do you want to play again (y/n)?";
        cin>>choice;

    }while(choice == 'Y' || choice == 'y');
    cout <<"\n\n\n";
    cout << "\n\nThanks for playing the game. Your balance is £" << balance <<"\n\n";
    return 0;
}

void rules()
{
    system("clear");
    cout << "\t\t=====CASINO GUSSING GAME RULES======\n";
    cout << "\t1. Choose a number between 1 to 10\n";
    cout << "\t2. Winner gets 10 times the money of a bet\n";
    cout << "\t3. Wrong bet, and you lose the amount you bet \n\n";
}