#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>

using namespace std;
bool gameOver = false;
int x,y,fruitx,fruity;
enum eDirection {STOP = 0 , LEFT,RIGHT , DOWN, UP};
eDirection dir;
int height=20, width=30,score=0,tailn = 0;
int tailx[100],taily[100],tailtx[100],tailty[100];


void setUp(){
    gameOver = false;
    dir = STOP;
    x=width/2;
    y=height/2;
    fruitx =   rand()%width;
    fruity = rand()%height;
}
//this goto function works on the cursor flickering problem
void gotoxy(int,int);s

void draw(){
    gotoxy(0,0);
    int final = height;
    //system("cls");
    for(int i=0; i<=height; i++){

        if(i==0 || i == final){
            if(i==0)
            cout<<"Score : "<<score*10<<endl;
            for(int j = 0; j<width; j++){
                cout<<"#";
            }
            cout<<endl;
        }
        else if(i!=0){

            cout<<"#";
            for(int q = 1; q<width-1;q++){
                // int p=0;
                if(q==x && i == y){
                    cout<<"O";
                }
                else if(q==fruitx && i == fruity){
                    cout<<"f";
                }
                else{
                    bool printTail = false;
                  for(int t = 0; t < tailn; t++) {
            if(tailx[t] == q && taily[t] == i) {
                printTail = true;
                break;
            }
        }

        if(printTail)
            cout << "o";
        else
            cout << " ";


                }
            }
            cout<<"#"<<endl;

    }
    if(x==width ){
        x=1;
    }
    else if(x==0){
        x=width-1;
    }
    else if(y==0){
        y=height-1;
    }
    else if(y==height){
        y=1;
    }
}
}

void input(){
    if(_kbhit()){
        // char ch = ;
        switch (_getch()){
            case 'a':
                dir = LEFT;
                break;
            case 'w':
                dir = UP;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'q':
                gameOver = true;
                break;

        }

    }
    if(x==fruitx&&y==fruity){
        fruitx = rand()%(width-2)+1;
        fruity = rand()%(height-2)+1;
        score++;
        tailn++;
    }
}

void logic(){

    int prevX = tailx[0];
    int prevY = taily[0];

    int prev2X, prev2Y;

    tailx[0] = x;
    taily[0] = y;

    for(int i = 1; i < tailn; i++) {
        prev2X = tailx[i];
        prev2Y = taily[i];

        tailx[i] = prevX;
        taily[i] = prevY;

        prevX = prev2X;
        prevY = prev2Y;
        if(tailx[i]==x && taily[i]==y )
            gameOver = true;
    }

    // while (1){
        switch (dir){
        case LEFT:
            x--;
        break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        // case default:
        // break;

    // }
    }
}
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
int main(){
    setUp();
    srand(time(NULL));


    while(!gameOver){
            input();
            logic();
            draw();
            Sleep(10);
     }
     return 0;

}
