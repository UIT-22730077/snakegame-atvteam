#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
#include <time.h>

using namespace std;

const int HEIGHT = 20;
const int WIDTH = 71;
int diem = 0;
int doKho = 0;
void gotoxy(int column, int line);
struct Point{
    int x,y;
};

class CONRAN{
public:
    struct Point A[100];
    struct Point moi;
    int doDai;
    int sleep = 300;
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

    void xoaDuoi(){
        if (A[doDai-1].x > 0 && A[doDai-1].x < WIDTH-1 && A[doDai-1].y > 0 && A[doDai-1].y < HEIGHT - 1){
            gotoxy(A[doDai-1].x, A[doDai-1].y);
            cout << " ";
        }
    }

    void diChuyen(int huong, int& temp){
        xoaDuoi();
        for(int i = doDai-1; i > 0; i--)
            A[i] = A[i-1];
        if(huong - temp == 2 || huong - temp == -2)
            huong = temp;
        if(huong==0) A[0].x = A[0].x + 2;
        if(huong==1) A[0].y = A[0].y + 1;
        if(huong==2) A[0].x = A[0].x - 2;
        if(huong==3) A[0].y = A[0].y - 1;
        temp = huong;
        veConRan();
    }

    bool kiemTraMoi(){
        for(int i = 0; i < doDai; i++)
            if(A[i].x == moi.x && A[i].y == moi.y)
                return true;
        if(moi.x == 0)
            return true;
        return false;
    }

    void taoMoi(){
        srand(time(0));
        do{
            moi.x = (rand() % ((WIDTH - 1) / 2)) * 2 ;
            moi.y = rand() % (HEIGHT - 2) + 1;
        }while(kiemTraMoi());
    }

    void veMoi(){
    gotoxy(moi.x, moi.y);
    cout << "O";
    }

    void anMoi(){
        if(A[0].x == moi.x && A[0].y == moi.y){
            doDai++;
            diem++;
            tangDoKho();
            taoMoi();
        }

    }

    void tangDoKho(){
        if(diem > 0 && diem%5 == 0 && doKho < 10){
            doKho++;
            sleep -= 20;
        }
    }

    bool kiemTraThua(){
        if(A[0].x == 0 || A[0].x == WIDTH-1 || A[0].y == 0 || A[0].y == HEIGHT-1)
            return true;
        for(int i = 1; i < doDai-1; i++)
            if(A[0].x == A[i].x && A[0].y == A[i].y)
            return true;
        if(doDai == (WIDTH-2)*(HEIGHT-2))
            return true;
        return false;
    }

    bool kiemtraThang(){
        if(doDai == (WIDTH-2)*(HEIGHT-2))
            return true;
        return false;
    }
};

class HIENTHI: public CONRAN{
public:
    void veKhungTroChoi(){
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

    void veKhungDiem(){
        for(int i = 0; i < WIDTH; i++){
            gotoxy(i, HEIGHT);
            cout << "=";
            gotoxy(i, HEIGHT+4);
            cout << "=";
        }
        gotoxy(WIDTH+2, 1);
        cout << "W - UP";
        gotoxy(WIDTH+2, 2);
        cout << "S - DOWN";
        gotoxy(WIDTH+2, 3);
        cout << "A - LEFT";
        gotoxy(WIDTH+2, 4);
        cout << "D - RIGHT";
        gotoxy(WIDTH+2, 6);
        cout << "P - PAUSE";
        gotoxy(WIDTH+2, 7);
        cout << "Q - QUIT";
        gotoxy(WIDTH-9, HEIGHT+5);
        cout << "@ATV-Team";
    }

    void xuatDiem(){
        gotoxy(2, HEIGHT+1);
        cout << "POINT: " << diem << "    LEVEL: " << doKho << "" << endl;
    }

    void tamDung(){
        gotoxy(25, HEIGHT+2);
        cout << "GAME PAUSE, PRESS ANY KEY TO RESUME" << endl;
        gotoxy(37, HEIGHT+3);
        cout << "PRESS Q TO QUIT";
    }

    void tiepTuc(){
        for(int i = 0; i < WIDTH; i++){
            gotoxy(i, HEIGHT+2);
            cout << " ";
            gotoxy(i, HEIGHT+3);
            cout << " ";
        }
    }

    void thoat(){
        gotoxy(32, HEIGHT+2);
        cout << "YOU LOSE!" << endl;
        Sleep(1000);
        gotoxy(0, HEIGHT+5);
    }

    void chucMung(){
        gotoxy(32, HEIGHT+2);
        cout << "YOU WIN!" << endl;
        Sleep(1000);
        gotoxy(0, HEIGHT+5);
    }
};

int main(){
    CONRAN r;
    HIENTHI h;
    int huong = 0;
    int prevHuong = 0;
    char t;
    h.veKhungTroChoi();
    h.veKhungDiem();
    r.veConRan();
    r.taoMoi();
    while(true){
        if(kbhit()){
            t = getch();
            t = tolower(t);
            if(t == 'a') huong = 2;
            if(t == 'w') huong = 3;
            if(t == 'd') huong = 0;
            if(t == 's') huong = 1;
            if(t == 'p'){
                h.tamDung();
                t = getch();
                h.tiepTuc();
                if(t == 'q'){
                    h.thoat();
                    break;
                }
            };
            if(t == 'q'){
                h.thoat();
                break;
            }
        }
        r.diChuyen(huong, prevHuong);
        r.veMoi();
        r.anMoi();
        h.xuatDiem();
        r.kiemTraThua();
        if(r.kiemTraThua() == true){
            h.thoat();
            break;
        }
        r.kiemtraThang();
        if(r.kiemtraThang() == true){
            h.chucMung();
            break;
        }
        Sleep(r.sleep);
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
