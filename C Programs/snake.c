#include <stdio.h>
#include <conio.h>
#include <windows.h>

int i, j, height = 20, width = 20;
int gameover, score, tailX[100], tailY[100];
int x, y, fruitX, fruitY, flag;

// Function to generate the initial position of the fruit
void setup()
{
    gameover = 0;

    // Initialize the head position of the snake
    x = height / 2;
    y = width / 2;

generate_fruit:
    // Generate the initial position of the fruit
    fruitX = rand() % 20;
    if (fruitX == 0)
        goto generate_fruit;
generate_fruit_y:
    fruitY = rand() % 20;
    if (fruitY == 0)
        goto generate_fruit_y;

    score = 0;
}

// Function to draw the board
void draw()
{
    system("cls");
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            if (i == 0 || i == width - 1
                || j == 0 || j == height - 1)
            {
                printf("#");
            }
            else
            {
                if (i == x && j == y)
                    printf("0");
                else if (i == fruitX && j == fruitY)
                    printf("*");
                else
                {
                    int print = 0;
                    for (int k = 0; k < score; k++)
                    {
                        if (i == tailX[k] && j == tailY[k])
                        {
                            printf("o");
                            print = 1;
                        }
                    }
                    if (print == 0)
                        printf(" ");
                }
            }
        }
        printf("\n");
    }
    printf("Score: %d", score);
    printf("\n");
    printf("Press X to quit the game");
}

// Function to take input
void input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            flag = 1;
            break;
        case 's':
            flag = 2;
            break;
        case 'd':
            flag = 3;
            break;
        case 'w':
            flag = 4;
            break;
        case 'x':
            gameover = 1;
            break;
        }
    }
}

// Function for logic behind each movement
void logic()
{
    Sleep(0.01);
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < score; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (flag)
    {
    case 1:
        y--;
        break;
    case 2:
        x++;
        break;
    case 3:
        y++;
        break;
    case 4:
        x--;
        break;
    default:
        break;
    }

    if (x < 0 || x > height
        || y < 0 || y > width)
        gameover = 1;

    for (int i = 0; i < score; i++)
    {
        if (tailX[i] == x && tailY[i] == y)
            gameover = 1;
    }

    if (x == fruitX && y == fruitY)
    {
    generate_fruit_x:
        fruitX = rand() % 20;
        if (fruitX == 0)
            goto generate_fruit_x;
    generate_fruit_y:
        fruitY = rand() % 20;
        if (fruitY == 0)
            goto generate_fruit_y;
        score++;
    }
}

int main()
{
    int m, n;

    // Generate initial setup
    setup();

    // Until the game is not over
    while (!gameover)
    {

        // Function Call
        draw();
        input();
        logic();
    }
    return 0;
}
