#include <windows.h>
#include <iostream>
#include <iomanip>
#include<stdlib.h>
#include<time.h>
using namespace std;

void get_position()
{//get m sp
    CONSOLE_CURSOR_INFO info = { 1, 0 };	
    HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = { 0, 0 };
    POINT pt = { 0, 0 };
    SetConsoleCursorInfo(hand, &info);
    int t = 100;
    while (1) {
        SetConsoleCursorPosition(hand, coord);
        GetCursorPos(&pt);							//get xy
        cout << "当前坐标：" << pt.x << ',' << pt.y << setw(10) << "\0" << endl;

        cout << "程序将在" << t / 10 << "s后继续 " << endl;;
        Sleep(100);
        if (t == 0) { break; }
        t = t - 1;

    }
}

int mouseclickxy(int x, int y)
{
  //input
    INPUT input;
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP; //put
    SetCursorPos(x, y);
    input.mi.dx = 0;            //x
    input.mi.dy = 0;            //y
    input.mi.mouseData = 0;     //up&down
    input.mi.dwExtraInfo = 0; 
    input.mi.time = 0;
    SendInput(1, &input, sizeof(INPUT));
    return 0;
}

int main()
{
    int a;

    for (a=1;a<15;a++)
    {
        keybd_event(VK_LBUTTON, (BYTE)0, 0, 0);
        mouseclickxy(1703, 836);//低1/2
        keybd_event(VK_LBUTTON, (BYTE)0, KEYEVENTF_KEYUP, 0);


        mouseclickxy(66, 639);    //A

        mouseclickxy(1622, 844);//发
        Sleep(20);
        mouseclickxy(1683, 137);//next

        mouseclickxy(899, 501);//yes
    }
    return 0;
}
//坐标66,639-->A
//1636,846-->发布评语
//672,135-->下一个
//mouseclick(1702, 832);//低1
        //mouseclick(66, 639);    //A
        //mouseclick(37, 685);//评语
       // keybd_event('A', (BYTE)0, 0, 0);
        //keybd_event('A', (BYTE)0, KEYEVENTF_KEYUP, 0);
        //mouseclick(37, 685);//评语
//mouseclick(899, 501,-900);//yes
        //mouseclick(1683, 137);//next
 //get_position();
