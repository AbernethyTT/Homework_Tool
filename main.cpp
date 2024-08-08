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

int mouseclick(int x, int y)
{
  //input
    INPUT input;
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP; //put
    SetCursorPos(x, y);
    input.mi.dx = 0;            //x
    input.mi.dy = 0;            //y
    input.mi.mouseData = -0;     //up&down
    input.mi.dwExtraInfo = 0; 
    input.mi.time = 0;
    SendInput(1, &input, sizeof(INPUT));
    return 0;
}

int main()
{
    get_position();
    char chose;
    int i;
AS:
    cout << "Start enter '1'" << endl;
    cout << "Dont start ener '2'" << endl;
    cout << "Please enter '1' or '2' :";
    cin >> chose;
    if (chose == '1')
    {
        for (i = 1; i < 60; i++)
        {
            cout << "start" << i;
            mouseclick(1702, 873);//低
            mouseclick(66, 639);    //A
            mouseclick(1622, 844);//发
            mouseclick(1683, 137);//next
            mouseclick(899, 501);//yes
            mouseclick(1683, 137);//next
            Sleep(1); 
            //get_position();
            return 0;
        }
    }
    else if (chose == '2')
    {
        cout << "Don't start\n";
        return 0;
    }
    else
    {
        goto AS;
    }
}
//坐标66,639-->A
//1636,846-->发布评语
//672,135-->下一个