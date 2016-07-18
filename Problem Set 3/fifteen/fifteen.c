#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define DIM_MIN 3
#define DIM_MAX 9

int board[DIM_MAX][DIM_MAX];
int d;

void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    FILE* file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    greet();
    init();

    while (true)
    {
        clear();
        draw();
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);
        if (won())
        {
            printf("If you're not a robot, you lost your time, but you succeed !\n");
            break;
        }
        printf("Tile to move: ");
        int tile = GetInt();
        if (tile == 0)
        {
            break;
        }
        fprintf(file, "%i\n", tile);
        fflush(file);
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }
        usleep(500000);
    }
    fclose(file);
    return 0;
}

void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}


void init(void)
{
    int tilesnumber = (d*d) - 1;
    for (int i = 0; i < d; i++)
        for (int j = 0; j < d; j++, tilesnumber--) board[i][j] = tilesnumber;
    if (d%2 == 0)
    {
        int tempboard = board[d-1][d-3];
        board[d-1][d-3] = board[d-1][d-2];
        board[d-1][d-2] = tempboard;
    }
}

void draw(void)
{
    for (int i = 0; i < d; i++)
    {
        if (i > 0) printf("\n");
        for (int j = 0; j < d; j++)
        {
            if (board[i][j] != 0) printf("%2d ", board[i][j]);
            else printf("\033[32;1m - \033[0m");
        }
    }
    printf("\n");
}

bool move(int tile)
{
    int x1, y1, x2, y2;
    for (int i = 0; i < d; i++) 
        for (int j = 0; j < d; j++)
        {
            if (board[i][j] == 0)
            {
               x1 = i;
               y1 = j;
            }
            else if (board[i][j] == tile)
            {
                x2 = i;
                y2 = j;
            }
        }
            
    if (((x1 == x2) && (abs(y1 - y2) == 1)) || ((y1 == y2) && (abs(x1 - x2) == 1)))
    {
        int oldboard = board[x1][y1];
        board[x1][y1] = board[x2][y2];
        board[x2][y2] = oldboard;
        return true;
    }
   return false;
}

bool won(void)
{
    for (int i = 0; i < d; i++)
        for (int j = 0; j < d; j++)
        {
            if (j == d-1) board[i][j+1] = board[i+1][0];
            if ((i == d-1) && (j == d-2)) break;
            if (board[i][j] > board[i][j+1]) return false;
            if (board[d-1][d-1] != 0) return false;
        }            
    return true;
}