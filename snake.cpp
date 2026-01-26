#include <iostream>
#include "keyboard.h"
#include <unistd.h>
#include <cstdlib>
#include <ctime>

using namespace std;
bool gameOver = false;
int x,y,fruitx,fruity;
enum eDirection {STOP = 0 , LEFT,RIGHT , DOWN, UP};
eDirection dir;
int height=20, width=30,score=0;


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
            if(score>0 && y == i)
            width = width-score;
            for(int q = 1; q<width-1;q++){
                if(q==x && i == y){
                    for(int s=0;s<=score;s++)
                    cout<<"0";
                }
                else if(q==fruitx && i == fruity){
                    cout<<"f";
                }
                else
                cout<<" ";  
            }
            width=30;
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
    else if(y==width){
        y=1;
    }
}
}

void input(){
    if(kbhit()){
        // char ch = ;
        switch (getch_posix()){
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
    }
}

void logic(){
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

int main(){
    setUp();
    srand(time(NULL));

    init_keyboard();

    while(!gameOver){
            input();
            logic();
            draw();
            usleep(100000);
     }

}