#include<iostream>

using namespace std;

void display(const char game[][3])
{
    system("cls");


    for(int i=0;i<3;i++)
    {
        cout << "     |     |     " << endl;
        for(int j=0;j<3;j++)
        {
            if(game[i][j] == 'x')
                cout << "  " << game[i][j] << "  |";

            else if(game[i][j] == 'o')
                cout << "  " << game[i][j] << "  |";

            else
                cout << "  " << game[i][j] << "  |";
            
        }
        cout << "\b \n";
        cout << "     |     |     " << endl;
        if(i < 2)
            cout << "=================" << endl;
    }
}


bool check_win(char play[][3],int i,int j)
{
    if( play[i][0] == play[i][1] && play[i][1] == play[i][2] )
        return true;
    else if( play[0][j] == play[1][j] && play[1][j] == play[2][j] )
        return true;
    else if( play[0][0] == play[1][1] && play[0][0] == play[2][2] )
        return true;
    else if( play[1][1] == play[0][2] && play[2][0] == play[1][1] )
        return true;
    else
        return false;
    
}

int if_win(char play[][3],int i, int j, char player_sign)
{
    // CHECK IN ROW
    {
        if(play[i][0] == play[i][1] && play[i][2] == 51 + 3*i && play[i][0] == player_sign )
            return 3*(i+1) ;
        else if( play[i][0] == play[i][2] && play[i][1] == 50 + 3*i && play[i][0] == player_sign )
            return 3*i + 2;
        else if( play[i][1] == play[i][2] && play[i][0] == 49 + 3*i && play[i][1] == player_sign )
            return 3*i + 1;
    }

    //CHECK IN COLUMN
    {
        if( play[0][j] == play[1][j] && play[2][j] <=58 && play[0][j] == player_sign )
            return j+7;
        else if( play[1][j] == play[2][j] && play[0][j] <=58 && play[1][j] == player_sign )
            return j+1;
        else if( play[0][j] == play[2][j] && play[1][j] <=58 && play[0][j] == player_sign )
            return j+4;
    }

    //CHECK IN SIDE DIAGONAL
    {
        if( play[0][2] == play[1][1] && play[2][0] <= 58 && play[0][2] == player_sign )
            return 7;

        else if( play[0][2] == play[2][0] && play[1][1] <= 58 && play[0][2] == player_sign )
            return 5;
        
        else if( play[2][0] == play[1][1] && play[0][2] <= 58 && play[1][1] == player_sign )
        {
            return 3;
        }
    }

    //CHECK IN MAIN DIAGONAL
    {
        if(play[0][0] == play[2][2] && play[1][1] == 53 && play[0][2] == player_sign )
            return 5;
    }

    return 0;
}