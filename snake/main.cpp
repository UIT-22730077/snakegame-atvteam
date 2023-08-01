#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
<<<<<<< Updated upstream
=======
#include <time.h>;

>>>>>>> Stashed changes
using namespace std;
void gotoxy( int column, int line );
struct Point{
    int x,y;
};
class CONRAN{
public:
    struct Point A[100];
<<<<<<< Updated upstream
    int DoDai;
=======
    struct Point moi;
    int doDai;
>>>>>>> Stashed changes
    CONRAN(){
        DoDai = 3;
        A[0].x = 10; A[0].y = 10;
        A[1].x = 11; A[1].y = 10;
        A[2].x = 12; A[2].y = 10;
    }
    void Ve(){
        for (int i = 0; i < DoDai; i++){
            gotoxy(A[i].x,A[i].y);
            cout<<"X";
        }
    }
    void DiChuyen(int Huong, int& temp){
        for (int i = DoDai-1; i>0;i--)
            A[i] = A[i-1];
        if(Huong - temp == 2 || Huong - temp == -2)
            Huong = temp;
        if (Huong==0) A[0].x = A[0].x + 1;
        if (Huong==1) A[0].y = A[0].y + 1;
        if (Huong==2) A[0].x = A[0].x - 1;
        if (Huong==3) A[0].y = A[0].y - 1;
        temp = Huong;
    }

    bool kiemTraMoi(){
        for(int i = 0; i < doDai; i++)
            if(A[i].x == moi.x && A[i].y == moi.y)
                return true;
        return false;
    }

    void taoMoi(){
        srand(time(0));
        do{
            moi.x = rand() % (WIDTH - 2) + 1;
            moi.y = rand() % (HEIGHT - 2) + 1;
        }while(kiemTraMoi());
    }

    void veMoi(){
    gotoxy(moi.x, moi.y);
    cout << "O";
    }
};

int main()
{
    CONRAN r;
    int Huong = 0;
    int Huong_temp = 0;
    char t;
<<<<<<< Updated upstream

    while (1){
        if (kbhit()){
=======
    r.veKhung();
    r.veConRan();
    r.taoMoi();
    while(1){
        if(kbhit()){
>>>>>>> Stashed changes
            t = getch();
            t = tolower(t);
            if(t=='a') Huong = 2;
            if(t=='w') Huong = 3;
            if(t=='d') Huong = 0;
            if(t=='s') Huong = 1;
            if(t == 'q') break;
        }
<<<<<<< Updated upstream
        system("cls");
        r.Ve();
        r.DiChuyen(Huong);
=======
        r.xoaDuoi();
        r.diChuyen(huong, prevHuong);
        r.veConRan();
        r.veMoi();
>>>>>>> Stashed changes
        Sleep(300);
    }
    return 0;
}


void gotoxy( int column, int line )
  {
  COORD coord;
  coord.X = column;
  coord.Y = line;
  SetConsoleCursorPosition(
    GetStdHandle( STD_OUTPUT_HANDLE ),
    coord
    );
  }
