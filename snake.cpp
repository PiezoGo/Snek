#include <iostream>
#include "keyboard.h"
#include <unistd.h>

using namespace std;
bool gameOver = false;
int x,y,fruitx,fruity;
enum eDirection {STOP = 0 , LEFT,RIGHT , DOWN, UP};
eDirection dir;
int height=30, width=30;


void setUp(){
    gameOver = false;
    dir = STOP;
    x=width/2;
    y=height/2;
    fruitx =   rand()%width;
    fruity = rand()%height;
}


void draw(){
    int final = height;
    system("clear");
    for(int i=0; i<=height; i++){
        if(i==0 || i == final){
            for(int j = 0; j<width; j++){
                cout<<"#";
            }
            cout<<endl;
        }
        else if(i!=0){
            cout<<"#";
            for(int q = 1; q<width-1;q++){
                if(q==x && i == y){
                    cout<<"0";
                }
                else if(q==fruitx && i == fruity){
                    cout<<"f";
                }
                else
                cout<<" ";  
            }
            cout<<"#"<<endl;            
    }
}
}

void input(){
    if(kbhit()){
        char ch = getch_posix();
        switch (ch){
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
}

void logic(){
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
    }
}

int main(){
    setUp();
    while(!gameOver){
            input();
            logic();
            draw();
            usleep(100000);
    }
}