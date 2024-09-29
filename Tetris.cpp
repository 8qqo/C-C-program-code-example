#include <iostream>
/*iostream是C++中用於資料的串流輸入與輸出的標頭檔，屬於C++標準程式函式庫的一部分。
iostream 為 Input/Output Stream 的縮寫，即是輸入/輸出流。「流」是一連串從I/O裝置讀寫的字元。*/ 
#include <string>//其中的string是以char作為模板參數的模板類別實例，把字串的記憶體管理責任由string負責而不是由編程者負責，大大減輕了C語言風格的字串的麻煩。 
#include <ctime>//包含此標頭可保證，透過使用 Standard C 程式庫標頭中的外部連結所宣告的名稱會在 std 命名空間中宣告。 
#include <cstdlib>//包含 C Standard 程式庫標頭 <stdlib.h> ，並將相關聯的名稱新增至 std 命名空間。 包含此標頭可確保在命名空間中宣告使用 C 標準程式庫標頭外部連結所宣告 std 的名稱。 
#include <windows.h>
/*
windows.h是在可在C和C++中使用的僅用於Windows的頭文件，其中包含所有Windows API中函數的聲明、
程式設計師常用的Windows宏和各種函數所要使用到的數據類型和子系統。它定義了大量可在C和C++中使用的適用於Windows的特定函數。
在源文件中添加windows.h頭文件並將其連結到對應的lib中，就可以將Win32 API包含到項目裡邊。假如你要使用***.dll中所包含的函數，
那麼你就應該將程序連結到***.lib中（在MinGW中，這個擴展將會變為***.dll.a）。一些頭文件不會與.dll 關聯，而與靜態庫關聯（例如scrnsave.h 需要scrnsave.lib）。
*/ 
#include <conio.h>/*conio.h是一個C標頭檔，用於MS-DOS C編譯器裡。此標頭檔宣告了數個有用的函數，提供程式設計者主控台的輸出入操作介面。大部份MS-DOS、Windows 3.x、Phar Lap、DOSX、OS/2或Win32的C編譯器都預設此標頭檔，並提供相關的函數。
用於UNIX及Linux的編譯器並不支援conio.h，因為它不屬於C標準函式庫（C Standard library）或POSIX的一部分。 */ 

using namespace std;//生成方塊 

int block00[4][4] = { { 10,0,0,0 },{ 1,1,1,1 },{ 0,0,0,0 },{ 0,0,0,0 } };
int block01[4][4] = { { 11,0,1,0 },{ 0,0,1,0 },{ 0,0,1,0 },{ 0,0,1,0 } };
int block02[4][4] = { { 12,0,0,0 },{ 0,0,0,0 },{ 1,1,1,0 },{ 0,1,0,0 } };
int block03[4][4] = { { 13,0,0,0 },{ 0,1,0,0 },{ 1,1,0,0 },{ 0,1,0,0 } };
int block04[4][4] = { { 14,0,0,0 },{ 0,0,0,0 },{ 0,1,0,0 },{ 1,1,1,0 } };
int block05[4][4] = { { 15,0,0,0 },{ 0,1,0,0 },{ 0,1,1,0 },{ 0,1,0,0 } };
int block06[4][4] = { { 16,0,0,0 },{ 0,0,0,0 },{ 1,1,1,0 },{ 1,0,0,0 } };
int block07[4][4] = { { 17,0,0,0 },{ 1,1,0,0 },{ 0,1,0,0 },{ 0,1,0,0 } };
int block08[4][4] = { { 18,0,0,0 },{ 0,0,0,0 },{ 0,0,1,0 },{ 1,1,1,0 } };
int block09[4][4] = { { 19,0,0,0 },{ 0,1,0,0 },{ 0,1,0,0 },{ 0,1,1,0 } };
int block10[4][4] = { { 20,0,0,0 },{ 0,0,0,0 },{ 1,1,1,0 },{ 0,0,1,0 } };
int block11[4][4] = { { 21,0,0,0 },{ 0,1,0,0 },{ 0,1,0,0 },{ 1,1,0,0 } };
int block12[4][4] = { { 22,0,0,0 },{ 0,0,0,0 },{ 1,0,0,0 },{ 1,1,1,0 } };
int block13[4][4] = { { 23,0,0,0 },{ 0,1,1,0 },{ 0,1,0,0 },{ 0,1,0,0 } };
int block14[4][4] = { { 24,0,0,0 },{ 0,0,0,0 },{ 0,1,1,0 },{ 1,1,0,0 } };
int block15[4][4] = { { 25,0,0,0 },{ 1,0,0,0 },{ 1,1,0,0 },{ 0,1,0,0 } };
int block16[4][4] = { { 26,0,0,0 },{ 0,0,0,0 },{ 1,1,0,0 },{ 0,1,1,0 } };
int block17[4][4] = { { 27,0,0,0 },{ 0,0,1,0 },{ 0,1,1,0 },{ 0,1,0,0 } };
int block18[4][4] = { { 28,0,0,0 },{ 0,0,0,0 },{ 1,1,0,0 },{ 1,1,0,0 } };

void initialWindow(HANDLE hOut);//初始化窗口
void initialPrint(HANDLE hOut);//初始化界面
void gotoXY(HANDLE hOut, int x, int y);//移動光標 
void roundBlock(HANDLE hOut, int block[4][4]);//隨機生成方塊並打印到下一個方塊位置
bool collisionDetection(int block[4][4], int map[21][12], int x, int y);//檢測碰撞
void printBlock(HANDLE hOut, int block[4][4], int x, int y);//打印方塊 
void clearBlock(HANDLE hOut, int block[4][4], int x, int y);//消除方塊
void myLeft(HANDLE hOut, int block[4][4], int map[21][12], int x, int &y);//左移
void myRight(HANDLE hOut, int block[4][4], int map[21][12], int x, int &y);//右移
void myUp(HANDLE hOut, int block[4][4], int map[21][12], int x, int &y);//順時針旋轉90度
int myDown(HANDLE hOut, int block[4][4], int map[21][12], int &x, int y);//加速下落
void myStop(HANDLE hOut, int block[4][4]);//遊戲暫停
void gameOver(HANDLE hOut, int block[4][4], int map[21][12]);//遊戲結束
void eliminateRow(HANDLE hOut, int map[21][12], int &val, int &fraction, int &checkpoint);//判斷是否能消行并更新分值

int main()
{
    int map[21][12];//地圖大小 
    int blockA[4][4];//候選區的方塊 
    int blockB[4][4];//下落中的方塊 
    int positionX, positionY;//方塊左上角的坐標 
    bool check;//檢查方塊還能不能下落
    char key;//用來存儲按鍵 
    int val;//用來控制下落速度
    int fraction;//用來存儲得分
    int checkpoint;//用來存儲關卡
    int times;
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//獲取標准輸出設備訊號 
    initialWindow(hOut);
initial:
    gotoXY(hOut, 0, 0);
    initialPrint(hOut);
    check = true;
    val = 50;
    fraction = 0;
    checkpoint = 1;
    times = val;
    for (int i = 0; i < 20; ++i)
    {
        for (int j = 1; j < 11; ++j)
        {
            map[i][j] = 0;
        }
    }
    for (int i = 0; i < 20; ++i)
    {
        map[i][0] = map[i][11] = 1;
    }
    for (int i = 0; i < 12; ++i)
    {
        map[20][i] = 1;
    }

    srand((unsigned)time(NULL));
    roundBlock(hOut, blockA);
    while (true)
    {
        if (check)
        {
            eliminateRow(hOut, map, val, fraction, checkpoint);
            check = false;
            positionX = -3;
            positionY = 4;
            if (collisionDetection(blockA, map, positionX, positionY))
            {
                for (int i = 0; i < 4; ++i)
                {
                    for (int j = 0; j < 4; ++j)
                    {
                        blockB[i][j] = blockA[i][j];
                    }
                }
                roundBlock(hOut, blockA);
            }
            else
            {
                gameOver(hOut, blockA, map);
                goto initial;
            }
        }
        printBlock(hOut, blockB, positionX, positionY);
        if (_kbhit())
        {
            key = _getch();
            switch (key)
            {
            case 72:
                myUp(hOut, blockB, map, positionX, positionY);
                break;
            case 75:
                myLeft(hOut, blockB, map, positionX, positionY);
                break;
            case 77:
                myRight(hOut, blockB, map, positionX, positionY);
                break;
            case 80:
                switch (myDown(hOut, blockB, map, positionX, positionY))
                {
                case 0:
                    check = false;
                    break;
                case 1:
                    check = true;
                    break;
                case 2:
                    gameOver(hOut, blockB, map);
                    goto initial;
                default:
                    break;
                }
                break;
            case 32:
                myStop(hOut, blockA);
                break;
            case 27:
                exit(0);
            default:
                break;
            }
        }
        Sleep(20);
        if (0 == --times)
        {
            switch (myDown(hOut, blockB, map, positionX, positionY))
            {
            case 0:
                check = false;
                break;
            case 1:
                check = true;
                break;
            case 2:
                gameOver(hOut, blockB, map);
                goto initial;
            default:
                break;
            }
            times = val;
        }
    }
    cin.get();
    return 0;
}

void initialWindow(HANDLE hOut)
{
    SetConsoleTitle("俄羅斯方塊");
    COORD size = { 80, 25 };
    SetConsoleScreenBufferSize(hOut, size);
    SMALL_RECT rc = { 0, 0, 79, 24 };
    SetConsoleWindowInfo(hOut, true, &rc);
    CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
    SetConsoleCursorInfo(hOut, &cursor_info);
}

void initialPrint(HANDLE hOut)
{
    SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    for (int i = 0; i < 20; ++i)
    {
        cout << "■                     ■☆                       ☆" << endl;
    }
    gotoXY(hOut, 26, 0);
    cout << "☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆";
    gotoXY(hOut, 0, 20);
    cout << "■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■ ■☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆";
    gotoXY(hOut, 26, 1);
    cout << "分    數     ";
    gotoXY(hOut, 26, 2);
    cout << "關    卡     ";
    gotoXY(hOut, 26, 4);
    cout << "下個方塊";
    gotoXY(hOut, 26, 9);
    cout << "操作方法";
    gotoXY(hOut, 30, 11);
    cout << "↑：旋轉 ↓：速降";
    gotoXY(hOut, 30, 12);
    cout << "→：右移 ←：左移";
    gotoXY(hOut, 30, 13);
    cout << "空格鍵：開始/暫停";
    gotoXY(hOut, 30, 14);
    cout << "Esc 鍵：退出";
    gotoXY(hOut, 26, 16);
    cout << "關    卡";
    gotoXY(hOut, 30, 18);
    cout << "俄羅斯方塊V1.0";
  
}

void gotoXY(HANDLE hOut, int x, int y)
{
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(hOut, pos);
}

void roundBlock(HANDLE hOut, int block[4][4])
{
    clearBlock(hOut, block, 5, 15);
    switch (rand() % 19)
    {
    case 0:
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                block[i][j] = block00[i][j];
            }
        }
        break;
    case 1:
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                block[i][j] = block01[i][j];
            }
        }
        break;
    case 2:
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                block[i][j] = block02[i][j];
            }
        }
        break;
    case 3:
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                block[i][j] = block03[i][j];
            }
        }
        break;
    case 4:
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                block[i][j] = block04[i][j];
            }
        }
        break;
    case 5:
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                block[i][j] = block05[i][j];
            }
        }
        break;
    case 6:
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                block[i][j] = block06[i][j];
            }
        }
        break;
    case 7:
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                block[i][j] = block07[i][j];
            }
        }
        break;
    case 8:
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                block[i][j] = block08[i][j];
            }
        }
        break;
    case 9:
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                block[i][j] = block09[i][j];
            }
        }
        break;
    case 10:
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                block[i][j] = block10[i][j];
            }
        }
        break;
    case 11:
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                block[i][j] = block11[i][j];
            }
        }
        break;
    case 12:
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                block[i][j] = block12[i][j];
            }
        }
        break;
    case 13:
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                block[i][j] = block13[i][j];
            }
        }
        break;
    case 14:
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                block[i][j] = block14[i][j];
            }
        }
        break;
    case 15:
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                block[i][j] = block15[i][j];
            }
        }
        break;
    case 16:
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                block[i][j] = block16[i][j];
            }
        }
        break;
    case 17:
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                block[i][j] = block17[i][j];
            }
        }
        break;
    case 18:
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                block[i][j] = block18[i][j];
            }
        }
        break;
    default:
        break;
    }
    printBlock(hOut, block, 5, 15);
}

bool collisionDetection(int block[4][4], int map[21][12], int x, int y)
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (x + i >= 0 && y + j >= 0 && map[x + i][y + j] == 1 && block[i][j] == 1)
            {
                return false;
            }
        }
    }
    return true;
}

void printBlock(HANDLE hOut, int block[4][4], int x, int y)
{
    switch (block[0][0])
    {
    case 10:
    case 11:
        SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);//SetConsoleTextAttribute為專門控制顏色的函數 
        break;
    case 12:
    case 13:
    case 14:
    case 15:
        SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        break;
    case 16:
    case 17:
    case 18:
    case 19:
        SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        break;
    case 20:
    case 21:
    case 22:
    case 23:
        SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        break;
    case 24:
    case 25:
        SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        break;
    case 26:
    case 27:
        SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        break;
    case 28:
        SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
        break;
    default:
        break;
    }
    for (int i = 0; i < 4; ++i)
    {
        if (i + x >= 0)
        {
            for (int j = 0; j < 4; ++j)
            {
                if (block[i][j] == 1)
                {
					
                    gotoXY(hOut, 2 * (y + j), x + i);
                    cout <<"■";
                }
            }
        }
    }
}

void clearBlock(HANDLE hOut, int block[4][4], int x, int y)
{
    for (int i = 0; i < 4; ++i)
    {
        if (i + x >= 0)
        {
            for (int j = 0; j < 4; ++j)
            {
                if (block[i][j] == 1)
                {
                    gotoXY(hOut, 2 * (y + j), x + i);
                    cout << "  ";
                }
            }
        }
    }
}

void gameOver(HANDLE hOut, int block[4][4], int map[21][12])
{
    SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
    gotoXY(hOut, 9, 8);
    cout << "GAME OVER";
    gotoXY(hOut, 8, 9);
    cout << "空格鍵：重來";
    gotoXY(hOut, 8, 10);
    cout << "ESC鍵：退出";
    char key;
    while (true)
    {
        key = _getch();
        if (key == 32)
        {
            return;
        }
        if (key == 27)
        {
            exit(0);
        }
    }
}

int myDown(HANDLE hOut, int block[4][4], int map[21][12], int &x, int y)
{
    if (collisionDetection(block, map, x + 1, y))
    {
        clearBlock(hOut, block, x, y);
        ++x;
        return 0;
    }
    if (x < 0)
    {
        return 2;
    }
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (block[i][j] == 1)
            {
                map[x + i][y + j] = 1;
                //SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
                gotoXY(hOut, 2 * (y + j), x + i);
                cout << "■";
            }
        }
    }
    return 1;
}

void myLeft(HANDLE hOut, int block[4][4], int map[21][12], int x, int &y)//左移 
{
    if (collisionDetection(block, map, x, y - 1))
    {
        clearBlock(hOut, block, x, y);
        --y;
    }
}

void myRight(HANDLE hOut, int block[4][4], int map[21][12], int x, int &y)//右移 
{
    if (collisionDetection(block, map, x, y + 1))
    {
        clearBlock(hOut, block, x, y);
        ++y;
    }
}

void myUp(HANDLE hOut, int block[4][4], int map[21][12], int x, int &y)//旋轉 
{
    switch (block[0][0])
    {
    case 10:
        if (collisionDetection(block01, map, x, y))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block01[i][j];
                }
            }
        }
        break;
    case 11:
        if (collisionDetection(block00, map, x, y))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block00[i][j];
                }
            }
        }
        else if (collisionDetection(block00, map, x, y - 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block00[i][j];
                }
            }
            --y;
        }
        else if (collisionDetection(block00, map, x, y + 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block00[i][j];
                }
            }
            ++y;
        }
        else if (collisionDetection(block00, map, x, y - 2))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block00[i][j];
                }
            }
            y = y - 2;
        }
        else if (collisionDetection(block00, map, x, y + 2))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block00[i][j];
                }
            }
            y = y + 2;
        }
        break;
    case 12:
        if (collisionDetection(block03, map, x, y))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block03[i][j];
                }
            }
        }
        else if (collisionDetection(block03, map, x, y - 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block03[i][j];
                }
            }
            --y;
        }
        else if (collisionDetection(block03, map, x, y + 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block03[i][j];
                }
            }
            ++y;
        }
        break;
    case 13:
        if (collisionDetection(block04, map, x, y))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block04[i][j];
                }
            }
        }
        else if (collisionDetection(block04, map, x, y - 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block04[i][j];
                }
            }
            --y;
        }
        else if (collisionDetection(block04, map, x, y + 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block04[i][j];
                }
            }
            ++y;
        }
        break;
    case 14:
        if (collisionDetection(block05, map, x, y))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block05[i][j];
                }
            }
        }
        else if (collisionDetection(block05, map, x, y - 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block05[i][j];
                }
            }
            --y;
        }
        else if (collisionDetection(block05, map, x, y + 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block05[i][j];
                }
            }
            ++y;
        }
        break;
    case 15:
        if (collisionDetection(block02, map, x, y))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block02[i][j];
                }
            }
        }
        else if (collisionDetection(block02, map, x, y - 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block02[i][j];
                }
            }
            --y;
        }
        else if (collisionDetection(block02, map, x, y + 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block02[i][j];
                }
            }
            ++y;
        }
        break;

    case 16:
        if (collisionDetection(block07, map, x, y))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block07[i][j];
                }
            }
        }
        else if (collisionDetection(block07, map, x, y - 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block07[i][j];
                }
            }
            --y;
        }
        else if (collisionDetection(block07, map, x, y + 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block07[i][j];
                }
            }
            ++y;
        }
        break;
    case 17:
        if (collisionDetection(block08, map, x, y))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block08[i][j];
                }
            }
        }
        else if (collisionDetection(block08, map, x, y - 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block08[i][j];
                }
            }
            --y;
        }
        else if (collisionDetection(block08, map, x, y + 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block08[i][j];
                }
            }
            ++y;
        }
        break;
    case 18:
        if (collisionDetection(block09, map, x, y))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block09[i][j];
                }
            }
        }
        else if (collisionDetection(block09, map, x, y - 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block09[i][j];
                }
            }
            --y;
        }
        else if (collisionDetection(block09, map, x, y + 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block09[i][j];
                }
            }
            ++y;
        }
        break;
    case 19:
        if (collisionDetection(block06, map, x, y))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block06[i][j];
                }
            }
        }
        else if (collisionDetection(block06, map, x, y - 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block06[i][j];
                }
            }
            --y;
        }
        else if (collisionDetection(block06, map, x, y + 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block06[i][j];
                }
            }
            ++y;
        }
        break;
    case 20:
        if (collisionDetection(block11, map, x, y))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block11[i][j];
                }
            }
        }
        else if (collisionDetection(block11, map, x, y - 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block11[i][j];
                }
            }
            --y;
        }
        else if (collisionDetection(block11, map, x, y + 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block11[i][j];
                }
            }
            ++y;
        }
        break;
    case 21:
        if (collisionDetection(block12, map, x, y))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block12[i][j];
                }
            }
        }
        else if (collisionDetection(block12, map, x, y - 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block12[i][j];
                }
            }
            --y;
        }
        else if (collisionDetection(block12, map, x, y + 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block12[i][j];
                }
            }
            ++y;
        }
        break;
    case 22:
        if (collisionDetection(block13, map, x, y))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block13[i][j];
                }
            }
        }
        else if (collisionDetection(block13, map, x, y - 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block13[i][j];
                }
            }
            --y;
        }
        else if (collisionDetection(block13, map, x, y + 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block13[i][j];
                }
            }
            ++y;
        }
        break;
    case 23:
        if (collisionDetection(block10, map, x, y))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block10[i][j];
                }
            }
        }
        else if (collisionDetection(block10, map, x, y - 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block10[i][j];
                }
            }
            --y;
        }
        else if (collisionDetection(block10, map, x, y + 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block10[i][j];
                }
            }
            ++y;
        }
        break;
    case 24:
        if (collisionDetection(block15, map, x, y))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block15[i][j];
                }
            }
        }
        else if (collisionDetection(block15, map, x, y - 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block15[i][j];
                }
            }
            --y;
        }
        else if (collisionDetection(block15, map, x, y + 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block15[i][j];
                }
            }
            ++y;
        }
        break;
    case 25:
        if (collisionDetection(block14, map, x, y))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block14[i][j];
                }
            }
        }
        else if (collisionDetection(block14, map, x, y - 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block14[i][j];
                }
            }
            --y;
        }
        else if (collisionDetection(block14, map, x, y + 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block14[i][j];
                }
            }
            ++y;
        }
        break;
    case 26:
        if (collisionDetection(block17, map, x, y))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block17[i][j];
                }
            }
        }
        else if (collisionDetection(block17, map, x, y - 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block17[i][j];
                }
            }
            --y;
        }
        else if (collisionDetection(block17, map, x, y + 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block17[i][j];
                }
            }
            ++y;
        }
        break;
    case 27:
        if (collisionDetection(block16, map, x, y))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block16[i][j];
                }
            }
        }
        else if (collisionDetection(block16, map, x, y - 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block16[i][j];
                }
            }
            --y;
        }
        else if (collisionDetection(block16, map, x, y + 1))
        {
            clearBlock(hOut, block, x, y);
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    block[i][j] = block16[i][j];
                }
            }
            ++y;
        }
        break;
    default:
        break;
    }
}

void myStop(HANDLE hOut, int block[4][4])//暫停 
{
    clearBlock(hOut, block, 5, 15);
    SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
    gotoXY(hOut, 30, 7);
    cout << "遊戲暫停";
    char key;
    while (true)
    {
        key = _getch();
        if (key == 32)
        {
            gotoXY(hOut, 30, 7);
            cout << "        ";
            printBlock(hOut, block, 5, 15);
            return;
        }
        if (key == 27)
        {
            exit(0);
        }
    }
}

void eliminateRow(HANDLE hOut, int map[21][12], int &val, int &fraction, int &checkpoint)//消除行 
{
    //SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_INTENSITY );
    for (int i = 19; i >= 0; --i)
    {
        int x = 0;
        for (int j = 1; j < 11; ++j)
        {
            x += map[i][j];
        }
        if (x == 10)
        {
            fraction += 100;
            if (val > 1 && fraction / 1000 + 1 != checkpoint)
            {
                checkpoint = fraction / 1000 + 1;
                val -= 5;
            }
            for (int m = i; m > 0; --m)
            {
                for (int n = 1; n < 11; ++n)
                {
                    map[m][n] = map[m - 1][n];
                    gotoXY(hOut, 2 * n, m);
                    if (map[m][n] == 1)
                    {
                    	
                        cout <<  "■";
                    }
                    else
                    {
                        cout << "  ";
                    }
                }
            }
            ++i;
        }
    }
    gotoXY(hOut, 36, 1);
    cout << fraction;
    gotoXY(hOut, 36, 2);
    cout << checkpoint;
}
