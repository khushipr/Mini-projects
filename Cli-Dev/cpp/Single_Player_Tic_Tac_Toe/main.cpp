#include <iostream>
#include "brain.h"

using namespace std;

int main()
{
    char Game[3][3] {{'.','.','.'},{'.','.','.'},{'.','.','.'}};
    char cpu_symbol;
    char player_symbol;
    int position_cpu=0;
    int position_player=0;

    display(Game);

    // SELECT SYMBOL USER
    {
        cout << endl <<"Welcome To " << "Tic Tac Toe " << "Game" << endl;

        choose_symbol_again:

        cout << "Choose Your Symbol Player (O / X) : ";
        cin >> player_symbol;

        // CHECK CORRECT INPUT
        {
            if(player_symbol == 'o' || player_symbol == '0' || player_symbol == 'O')
            {
                player_symbol = 'o';
                cpu_symbol = 'x';
            }
            else if(player_symbol == 'x'||player_symbol == 'X'||player_symbol == '+')
            {   
                player_symbol = 'x';
                cpu_symbol = 'o';
            }
            else
            {
                cout << "Choose Your Symbol Again ..." << endl;
                goto choose_symbol_again;
            }
        }
        
    }

    // SET NUMBERS 1,2,...
    {
        int c = 49;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                Game[i][j] = c++;
    }

    display(Game);


    // Turns
    {
        for(int turn=0;turn<4;turn++)
        {
            // CPU Turn
            {
                // Turn 1
                if(turn == 0)
                {
                    Game[2][2] = cpu_symbol;
                    position_cpu = 9;
                }

                //Turn 2
                else if(turn == 1)
                {
                    if(position_player != 5)
                    {
                        if( position_player == 7 || position_player == 8 || position_player == 2 || position_player == 1 )
                        {
                            Game[0][2] = cpu_symbol;
                            position_cpu = 3;
                        }

                        else if( position_player == 6 || position_player == 3 || position_player == 4 )
                        {
                                Game[2][0] = cpu_symbol;
                                position_cpu = 7;
                        }

                    }
                    else
                    {
                        Game[0][0] = cpu_symbol;
                        position_cpu = 1;
                    }
                    
                }
                
                //Turn 3
                else if( turn == 2)
                {
                    int temp_position_cpu = position_cpu;
                    position_cpu = if_win(Game,(position_cpu-1)/3,(position_cpu-1)%3,cpu_symbol);

                    if(position_cpu != 0)
                        Game[(position_cpu - 1) / 3][(position_cpu - 1) % 3] = cpu_symbol;
                    
                    else
                    {
                        position_cpu = if_win(Game,(position_player-1)/3,(position_player-1) % 3,player_symbol);
                    
                        if(position_cpu != 0)
                            Game[(position_cpu - 1) / 3][(position_cpu - 1) % 3] = cpu_symbol;

                        else
                        {

                            if(temp_position_cpu == 3 && ( Game[2][0] == player_symbol || Game[2][1] == player_symbol) )
                                position_cpu = 1;
                            
                            else if( temp_position_cpu == 3 && ( Game[0][0] == player_symbol || Game[0][1] == player_symbol))
                                    position_cpu = 7;
                            
                            else if( temp_position_cpu == 7 && ( Game[0][2] == player_symbol || Game[1][2] == player_symbol ) )
                                position_cpu = 1;
                            
                            else if(temp_position_cpu == 7 && Game[1][0] == player_symbol )
                                position_cpu = 3;

                            Game[(position_cpu - 1) / 3][(position_cpu - 1) % 3] = cpu_symbol;
                            
                        }
                    }  
                }

                //Turn 4
                else if( turn == 3 )
                {
                    position_cpu = if_win(Game,(position_cpu-1)/3,(position_cpu-1)%3,cpu_symbol);

                    if(position_cpu != 0)
                        Game[(position_cpu - 1) / 3][(position_cpu - 1) % 3] = cpu_symbol;
                    
                    else
                    {
                        position_cpu = if_win(Game,(position_player-1)/3,(position_player-1) % 3,player_symbol);
                    
                        if(position_cpu != 0)
                            Game[(position_cpu - 1) / 3][(position_cpu - 1) % 3] = cpu_symbol;
                    }
                }
                
                display(Game);
                 
                // CHECK FOR WIN 
                if(check_win(Game,(position_cpu -1) /3,(position_cpu -1) %3))
                {
                    cout << "CPU Wins ..." << endl;
                    return 0;
                }
            }

            // PLAYER TURN
            {
                choose_position_again:
                cout << "Enter The Position Where You Want to Mark Your Symbol : ";
                cin >> position_player;

                if(position_player <= 0 && position_player >= 9)
                {
                    cout << "No Such Position Exist ..." << endl;
                    cout << "Try Again Below ..." << endl ;
                    goto choose_position_again;
                }

                else if( Game [(position_player - 1) / 3] [(position_player - 1) % 3] == player_symbol || Game[(position_player - 1) / 3][(position_player - 1) % 3] == cpu_symbol )
                {
                    display(Game);
                    cout << "The Position " << position_player << " is Occupied ...\nTry Again Below...\n";
                    goto choose_position_again;
                }
                
                else
                    Game[(position_player - 1) / 3][(position_player - 1) % 3] = player_symbol;

                display(Game);

                // CHECK FOR WIN
                if(check_win(Game,(position_player -1) /3,(position_player -1) %3))
                {    
                    cout << "Congo Player Wins !!!" << endl;
                    return 0;
                }
            }
        }

        //LAST TURN AUTOMATIC
        {
            for(int i=0;i<3;i++)
            {
                for(int j=0;j<3;j++)
                {
                    if(Game[i][j] <= 58)
                    {
                        Game[i][j] = cpu_symbol;
                        display(Game);
                        if(check_win(Game,i,j))
                        {
                            cout << "CPU Wins !!!" << endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }

    cout << "Its A Draw !!\nYou actually played well !!" << endl;
    return 0;

}