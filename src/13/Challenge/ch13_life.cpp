// C++ Code Challenges, LinkedIn Learning

// Challenge #13: Conway's Game of Life
// Write an application that runs Conway's Game of Life, the best-known cellular automaton.
// Do this for a 10x10 grid.
// The grid wraps around in all directions, like the Pac-Man world.

// Rules:
// Any live cell with fewer than two live neighbors dies, as if by underpopulation.
// Any live cell with two or three live neighbors lives on to the next generation.
// Any live cell with more than three live neighbors dies, as if by overpopulation.
// Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

#define N 10
#define M 10

bool isCellAlive(char cell)
{
    return cell == 'X' || cell == '_';
}

// if cell was dead and now dead '-'
// if cell was live, but now dead '_'
// if cell was dead, but now live 'x'
// if cell was live and now live 'X'
void doCellLive(char* cell, bool alive)
{
    if(*cell == 'X')
        *cell = !alive ? '_' : *cell;

        if(*cell == '-')
        *cell = alive ? 'x' : *cell;
}

void wrapIndex(int& i, int& j)
{
    if (i < 0)
        i += N;
    else if (i >= N)
        i -=N;

    if (j < 0)
        j += M;
    else if (j >= M)
        j -=M;
}

int countLiveNeighbours(char game[][M], int i, int j)
{
    int res = 0;
    int  im = i - 1;
    int ip = i+1;
    int  jm = j - 1;
    int jp = j+1;
    wrapIndex(im, jm);
    wrapIndex(ip, jp);
    res += isCellAlive(game[im][jm]);
    res += isCellAlive(game[im][j]);
    res += isCellAlive(game[im][jp]);
    res += isCellAlive(game[i][jm]);
    res += isCellAlive(game[i][jp]);
    res += isCellAlive(game[ip][jm]);
    res += isCellAlive(game[ip][j]);
    res += isCellAlive(game[ip][jp]);
    return res;
}

void generateNext(char game[][M])
{
    for (int i = 0; i < N; ++i)
    for (int j = 0; j < M; ++j)
    {
        int n = countLiveNeighbours(game, i, j);
        char* currentCell = &game[i][j];
        if(isCellAlive(*currentCell))
        {
            if( n < 2 || n > 3)
            doCellLive(currentCell, false);
        }
        else
        {
            if (3 == n)
            doCellLive(currentCell, true);
        }
    }

    for (int i = 0; i < N; ++i)
    for (int j = 0; j < M; ++j)
    {
        if(game[i][j] == 'x')
        game[i][j] = 'X';

        if(game[i][j] == '_')
        game[i][j] = '-';
    }
}

// Conway's Game of Life, main()
// Summary: This application is a simulation of Conway's game of life.
int main(){    
    // The game, initialized with a glider and a blinker.
    char game[N][M];  
    std::memset(game,'-',N*M); // Initialize game with dashes.

    // A glider     // - - - - - - - - - -
    game[1][1]='X'; // - X - - - - - - - -
    game[2][2]='X'; // - - X - - - - - - -
    game[3][0]='X'; // X X X - - - - - - -
    game[3][1]='X';
    game[3][2]='X';

    // A blinker    // - - - - - - - - - -
    game[3][6]='X'; // - - - - - - - - - -
    game[3][7]='X'; // - - - - - - - - - -
    game[3][8]='X'; // - - - - - - X X X -
    
    int generation = 0;
    std::string go_on;
    do{
        std::cout << "Generation #" << generation++ << "\n";
        for (auto &str : game){
            for (auto &ch : str)
                std::cout << " " << ch;
            std::cout << "\n";
        }
        std::cout << "\n";

        // Write your code here
        generateNext(game);
        
        std::cout << "Press Enter for the next generation, or type \"Exit\": " << std::flush;
        std::getline(std::cin,go_on);
        std::transform(go_on.begin(), go_on.end(), go_on.begin(), toupper);
        std::cout << "\n" << std::flush;
    }while(go_on.compare("EXIT")!=0);
    
    return 0;
}
