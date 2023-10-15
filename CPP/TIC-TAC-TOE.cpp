#include <iostream>
using namespace std;

int input;
char arr[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
bool ch = true;
void check()
{
    if (arr[0] == 'O' && arr[1] == 'O' && arr[2] == 'O' || arr[3] == 'O' && arr[4] == 'O' && arr[5] == 'O' || arr[6] == 'O' && arr[7] == 'O' && arr[8] == 'O' || arr[0] == 'O' && arr[4] == 'O' && arr[8] == 'O' || arr[2] == 'O' && arr[4] == 'O' && arr[8] == 'O' || arr[0] == 'O' && arr[3] == 'O' && arr[6] == 'O' || arr[1] == 'O' && arr[4] == 'O' && arr[7] == 'O' || arr[2] == 'O' && arr[5] == 'O' && arr[8] == 'O')
    {
        cout << "Player 2 win!!!\n";
         ch = false;
    }
    if (arr[0] == 'X' && arr[1] == 'X' && arr[2] == 'X' || arr[3] == 'X' && arr[4] == 'X' && arr[5] == 'X' || arr[6] == 'X' && arr[7] == 'X' && arr[8] == 'X' || arr[0] == 'X' && arr[4] == 'X' && arr[8] == 'X' || arr[2] == 'X' && arr[4] == 'X' && arr[8] == 'X' || arr[0] == 'X' && arr[3] == 'X' && arr[6] == 'X' || arr[1] == 'X' && arr[4] == 'X' && arr[7] == 'X' || arr[2] == 'X' && arr[5] == 'X' && arr[8] == 'X')
    {
        cout << "Player 1 win!!!\n";
         ch = false;
    }
    else
    {
         ch = true;
    }
}
void turn1()
{
    cout << "Player 1, it's your turn(X)";
    cin >> input;
    arr[input - 1] = 'X';
    for (int i = 0; i < 9;)
    {
        cout << "\t" << arr[i] << " | " << arr[i + 1] << " | " << arr[i + 2] << "\n";
        cout << "\t---------\n";
        i = i + 3;
    }
    check();
}
void turn2()
{
    cout << "Player 2, it's your turn(O)";
    cin >> input;
    arr[input - 1] = 'O';
    for (int i = 0; i < 9;)
    {
        cout << "\t" << arr[i] << " | " << arr[i + 1] << " | " << arr[i + 2] << "\n";
        cout << "\t---------\n";
        i = i + 3;
    }
    check();
}
void draw(){
        if(arr[0]!='1' && arr[1]!='2' && arr[2]!='3' && arr[3]!='4' && arr[4]!='5' && arr[5]!='6' && arr[6]!='7' && arr[7]!='8' && arr[8]!='9'){
            cout<<"Draw\n";
            ch=false;
        }
        else{
           cout<<"ongoing Match\n";
        }
}
int main()
{
    cout<<" ___________   _______   ________      __________       /\\           _________            ___________   ________   ________\n";
    cout<<"      |           |      |                 |           /  \\          |                         |        |      |   |\n";
    cout<<"      |           |      |         ___     |          /____\\         |             ____        |        |      |   |_______\n";
    cout<<"      |           |      |                 |         /      \\        |                         |        |      |   |\n";
    cout<<"      |        ___|___   |_______          |        /        \\       |________                 |        |______|   |_______\n\n\n";
    
    char con = 'y';
    while (con = 'y')
    {    
        char arr[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        for (int i = 0; i < 9;)
        {
            cout << "\t" << arr[i] << " | " << arr[i + 1] << " | " << arr[i + 2] << "\n";
            cout << "\t---------\n";
            i = i + 3;
        }
        cout << "first player's symbol : X\nSecond player's symbol : O\nEnter number corresponding to space\n";
        int input;
        while (true)
        {
            turn1();
            if (ch == false)
            {
                break;
            }
            draw();
            if (ch == false)
            {
                break;
            }
            turn2();
            if (ch == false)
            {
                break;
            }
            draw();
            if (ch == false)
            {
                break;
            }  
        }
        cout << "want to play again(y/n): ";
        cin >> con;
    }
    return 0;
}