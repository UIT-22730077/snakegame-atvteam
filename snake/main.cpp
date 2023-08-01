#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <conio.h>

using namespace std;

const int HEIGHT = 20;
const int WIDTH = 70;
void gotoxy(int column, int line);
struct Point{
    int x,y;
};

class CONRAN{
public:
    struct Point A[100];
    int doDai;
    CONRAN(){
        doDai = 3;
        A[0].x = 10; A[0].y = 10;
        A[1].x = 11; A[1].y = 10;
        A[2].x = 12; A[2].y = 10;
    }

    void veConRan(){
        gotoxy(A[0].x, A[0].y);
        cout << "O";
        for(int i = 1; i < doDai-1; i++){
            gotoxy(A[i].x, A[i].y);
            cout << "X";
        }
        gotoxy(A[doDai-1].x, A[doDai-1].y);
        cout << "+";
    }

    void diChuyen(int huong, int& temp){
        for(int i = doDai-1; i > 0; i--)
            A[i] = A[i-1];
        if(huong - temp == 2 || huong - temp == -2)
            huong = temp;
        if(huong==0) A[0].x = A[0].x + 1;
        if(huong==1) A[0].y = A[0].y + 1;
        if(huong==2) A[0].x = A[0].x - 1;
        if(huong==3) A[0].y = A[0].y - 1;
        temp = huong;
    }

    void veKhung(){
        for(int i = 0; i < WIDTH; i++){
            gotoxy(i, 0);
            cout << "#";
            gotoxy(i, HEIGHT - 1);
            cout << "#";
        }
        for(int i = 1; i < HEIGHT - 1; i++){
            gotoxy(0, i);
            cout << "#";
            gotoxy(WIDTH - 1, i);
            cout << "#";
        }
    }

    void xoaDuoi(){
        gotoxy(A[doDai-1].x, A[doDai-1].y);
        cout << " ";
    }
};

int main()
{
    CONRAN r;
    int huong = 0;
    int prevHuong = 0;
    char t;
    r.veKhung();
    r.veConRan();
    while(1){
        if(kbhit()){
            t = getch();
            t = tolower(t);
            if(t=='a') huong = 2;
            if(t=='w') huong = 3;
            if(t=='d') huong = 0;
            if(t=='s') huong = 1;
            if(t == 'q') break;
        }
        r.xoaDuoi();
        r.diChuyen(huong, prevHuong);
        r.veConRan();
        Sleep(300);
    }
    return 0;
}


void gotoxy(int column, int line)
  {
  COORD coord;
  coord.X = column;
  coord.Y = line;
  SetConsoleCursorPosition(
    GetStdHandle(STD_OUTPUT_HANDLE),
    coord
    );
  }
