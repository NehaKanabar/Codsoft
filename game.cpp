#include <iostream>
using namespace std;

char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

void show_board();
void get_X_player_choice();
void get_O_player_choice();
int count_board(char symbol);
char check_winner();
void player_vs_player();

int main()
{
    player_vs_player();
    return 0;
}

void player_vs_player()
{
    string X_playername, O_playername;
    cout << "enter X player name: ";
    cin >> X_playername;
    cout << "enter O player name: ";
    cin >> O_playername;

    while (true)
    {
        system("cls");
        show_board();
        if (count_board('X') == count_board('O'))
        {
            cout << X_playername << "'s Turn." << endl;
            get_X_player_choice();
        }
        else
        {
            cout << O_playername << "'s Turn." << endl;
            get_O_player_choice();
        }

        char winner = check_winner();
        if (winner == 'X')
        {
            system("cls");
            show_board();
            cout << X_playername << " won the game" << endl;
            break;
        }
        else if (winner == 'O')
        {
            system("cls");
            show_board();
            cout << O_playername << " won the game" << endl;
            break;
        }
        else if (winner == 'D')
        {
            cout << "game is draw" << endl;
            break;
        }
    }
}

void get_X_player_choice()
{
    while (true)
    {
        cout << "select your position (1-9): ";
        int choice;
        cin >> choice;
        choice--;
        if (choice < 0 || choice > 8)
        {
            cout << "please select your choice from (1-9)" << endl;
        }
        else if (board[choice] != ' ')
        {
            cout << "please select an empty position" << endl;
        }
        else
        {
            board[choice] = 'X';
            break;
        }
    }
}

void get_O_player_choice()
{
    while (true)
    {
        cout << "select your position (1-9): ";
        int choice;
        cin >> choice;
        choice--;
        if (choice < 0 || choice > 8)
        {
            cout << "please select your choice from (1-9)" << endl;
        }
        else if (board[choice] != ' ')
        {
            cout << "please select an empty position" << endl;
        }
        else
        {
            board[choice] = 'O';
            break;
        }
    }
}

int count_board(char symbol)
{
    int total = 0;
    for (int i = 0; i < 9; i++)
    {
        if (board[i] == symbol)
        {
            total += 1;
        }
    }
    return total;
}

char check_winner()
{
    // Check horizontally
    if (board[0] == board[1] && board[1] == board[2] && board[0] != ' ')
    {
        return board[0];
    }
    if (board[3] == board[4] && board[4] == board[5] && board[3] != ' ')
    {
        return board[3];
    }
    if (board[6] == board[7] && board[7] == board[8] && board[6] != ' ')
    {
        return board[6];
    }
    // Check vertically
    if (board[0] == board[3] && board[3] == board[6] && board[0] != ' ')
    {
        return board[0];
    }
    if (board[1] == board[4] && board[4] == board[7] && board[1] != ' ')
    {
        return board[1];
    }
    if (board[2] == board[5] && board[5] == board[8] && board[2] != ' ')
    {
        return board[2];
    }
    // Check diagonally
    if (board[0] == board[4] && board[4] == board[8] && board[0] != ' ')
    {
        return board[0];
    }
    if (board[2] == board[4] && board[4] == board[6] && board[2] != ' ')
    {
        return board[2];
    }
    // No winner yet
    if (count_board(' ') == 0)
    {
        return 'D'; // Draw
    }
    else
    {
        return ' '; // No winner yet
    }
}

void show_board()
{
    cout << "   " << "    |   " << "    |   " << endl;
    cout << "   " << board[0] << "   |   " << board[1] << "   |   " << board[2] << endl;
    cout << "   " << "    |   " << "    |   " << endl;
    cout << "-------------------------" << endl;
    cout << "   " << "    |   " << "    |   " << endl;
    cout << "   " << board[3] << "   |   " << board[4] << "   |   " << board[5] << endl;
    cout << "   " << "    |   " << "    |   " << endl;
    cout << "-------------------------" << endl;
    cout << "   " << "    |   " << "    |   " << endl;
    cout << "   " << board[6] << "   |   " << board[7] << "   |   " << board[8] << endl;
    cout << "   " << "    |   " << "    |   " << endl;
}
