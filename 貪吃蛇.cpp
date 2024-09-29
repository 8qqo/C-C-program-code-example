#include <windows.h>  
#include <stdlib.h>  
#include <conio.h>  
#include <time.h>  
#include <cstring>  
#include <cstdio>  
#include <iostream>  
#define  N 22  
using namespace std;  
  
    int gameover;  
  
    int x1, y1; // ?机出米  
  
    int x,y;  
  
    long start;  
  
//=======================================  
//?的??与?用initialize  
//=======================================  
  
//下面定??吃蛇的坐??  
class snake_position  
{  
public:  
  
    int x,y;      //x表示行，y表示列  
  
    snake_position(){};  
  
    void initialize(int &);//坐標初始化  
  
  
};  
  
snake_position position[(N-2)*(N-2)+1]; //定??吃蛇坐????，有(N-2)*(N-2)?坐?  
  
void snake_position::initialize(int &j)  
{  
        x = 1;  
  
        y = j;  
}  
  
  
//下面定??吃蛇的棋??  
  
class snake_map  
{  
  
private:  
  
    char s[N][N];//定??吃蛇棋?，包括?壁。  
  
    int grade, length;  
  
    int gamespeed; //前????隔  
  
    char direction; // 初始情?下，向右??  
  
    int head,tail;  
  
    int score;  
  
    bool gameauto;  
  
public:  
  
    snake_map(int h=4,int t=1,int l=4,char d=77,int s=0):length(l),direction(d),head(h),tail(t),score(s){}  
  
    void initialize();   //初始化函?  
  
    void show_game();  
  
    int updata_game();  
  
    void setpoint();  
  
    void getgrade();  
  
    void display();  
  
  
};  
  
//定?初始化函?，??吃蛇的棋???行初始化  
  
void snake_map::initialize()  
{  
    int i,j;  
  
    for(i=1;i<=3;i++)  
  
        s[1][i] = '*';  
  
    s[1][4] = '#';  
  
    for(i=1;i<=N-2;i++)  
  
        for(j=1;j<=N-2;j++)  
  
            s[i][j]=' '; // 初始化?吃蛇棋?中?空白部分  
  
    for(i=0;i<=N-1;i++)  
  
        s[0][i] = s[N-1][i] = '-'; //初始化?吃蛇棋?上下?壁  
  
    for(i=1;i<=N-2;i++)  
  
        s[i][0] = s[i][N-1] = '|'; //初始化?吃蛇棋?左右?壁  
}  
  
  
//============================================  
//?出?吃蛇棋?信息  
  
void snake_map::show_game()  
  
{  
  
    system("cls"); // 清屏  
  
    int i,j;  
  
    cout << endl;  
  
    for(i=0;i<N;i++)  
    {  
  
        cout << '\t';  
  
        for(j=0;j<N;j++)  
  
            cout<<s[i][j]<<' '; // ?出?吃蛇棋?  
  
        if(i==2) cout << "\t等級：" << grade;  
  
        if(i==6) cout << "\t速度：" << gamespeed;  
  
        if(i==10) cout << "\t得分：" << score << "分" ;  
  
        if(i==14) cout << "\t暫停：按一下空格?" ;  
  
        if(i==18) cout << "\t繼續：按一下空格?" ;  
  
        cout<<endl;  
    }  
}  
  
//?入??等?  
void snake_map::getgrade()  
{  
    cin>>grade;  
  
    while( grade>7 || grade<1 )  
    {  
        cout <<" 請輸入數字1-7選擇等級，輸入其他數字無效 "<< endl;  
  
        cin >> grade;  
    }  
    switch(grade)  
    {  
        case 1: gamespeed = 1000;gameauto = 0;break;  
  
        case 2: gamespeed = 800;gameauto = 0;break;  
  
        case 3: gamespeed = 600;gameauto = 0;break;  
  
        case 4: gamespeed = 400;gameauto = 0;break;  
  
        case 5: gamespeed = 200;gameauto = 0;break;  
  
        case 6: gamespeed = 100;gameauto = 0;break;  
  
        case 7: grade = 1;gamespeed = 1000;gameauto = 1;break;  
  
    }  
  
}  
  
//?出等?，得分情?以及??  
  
void snake_map::display()  
{  
  
    cout << "\n\t\t\t\t等級：" << grade;  
  
    cout << "\n\n\n\t\t\t\t速度：" << gamespeed;  
  
    cout << "\n\n\n\t\t\t\t得分：" << score << "分" ;  
  
}  
  
//?机?生米  
void snake_map::setpoint()  
{  
    srand(time(0));  
  
    do  
    {  
  
        x1 = rand() % (N-2) + 1;  
  
        y1 = rand() % (N-2) + 1;  
  
    }while(s[x1][y1]!=' ');  
  
    s[x1][y1]='*';  
}  
  
char key;  
  
int snake_map::updata_game()  
{  
    gameover = 1;  
  
    key = direction;  
  
    start = clock();  
  
    while((gameover=(clock()-start<=gamespeed))&&!kbhit());  
  
    //如果有?按下或??超?自?前????隔??止循?  
  
  
  
        if(gameover)  
        {  
  
            getch();  
  
            key = getch();  
        }  
  
        if(key == ' ')  
  
        {  
            while(getch()!=' '){};//?里??的是按空格??停，按空格???的功能，但不知?何原因，需要按?下空格才能??。?是?bug。  
        }  
  
        else  
  
            direction = key;  
  
        switch(direction)  
        {  
            case 72: x= position[head].x-1; y= position[head].y;break; // 向上  
  
            case 80: x= position[head].x+1; y= position[head].y;break; // 向下  
  
            case 75: x= position[head].x; y= position[head].y-1;break; // 向左  
  
            case 77: x= position[head].x; y= position[head].y+1; // 向右  
  
        }  
  
        if(!(direction==72||direction==80||direction==75 ||direction==77))   // 按?非方向?  
  
            gameover = 0;  
  
        else if(x==0 || x==N-1 ||y==0 || y==N-1)   // 碰到墻壁  
  
            gameover = 0;  
  
        else if(s[x][y]!=' '&&!(x==x1&&y==y1))    // 蛇頭碰到蛇身  
  
            gameover = 0;  
  
        else if(x==x1 && y==y1)  
  
        { // 吃米，?度加1  
  
            length ++;  
  
            if(length>=8 && gameauto)  
  
            {  
  
                length -= 8;  
  
                grade ++;  
  
                if(gamespeed>=200)  
  
                    gamespeed -= 200; // 改??吃蛇前?速度  
  
                else  
  
                    gamespeed = 100;  
  
            }  
  
            s[x][y]= '#';  //更新蛇?  
  
            s[position[head].x][position[head].y] = '*'; //吃米后?原先蛇???蛇身  
  
            head = (head+1) % ( (N-2)*(N-2) );   //取蛇?坐?  
  
            position[head].x = x;  
  
            position[head].y = y;  
  
            show_game();  
  
            gameover = 1;  
  
            score += grade*20;  //加分  
  
            setpoint();   //?生米  
  
        }  
  
        else  
        { // 不吃米  
  
            s[position[tail].x][position[tail].y]=' ';//?蛇尾置空  
  
            tail= (tail+1) % ( (N-2) * (N-2) );//更新蛇尾坐?  
  
            s[position[head].x][position[head].y]='*';  //?蛇?更?蛇身  
  
            head= (head+1) % ( (N-2) * (N-2) );  
  
            position[head].x = x;  
  
            position[head].y = y;  
  
            s[position[head].x][position[head].y]='#'; //更新蛇?  
  
            gameover = 1;  
  
        }  
    return gameover;  
  
}  
//====================================  
//主函式部分  
//====================================  
int main()  
{  
    char ctn = 'y';  
  
    int nodead;  
  
    cout<<"\n\n\n\n\n\t\t\t 歡迎進入貪吃蛇游戲	!"<<endl;//歡迎界面;  
  
    cout<<"\n\n\n\t\t\t 按任意馬上開始。。。"<<endl;//準備開始;;  
  
    getch();  
  
    while( ctn=='y' )  
    {  
        system("cls"); // 清屏  
  
        snake_map snake;  
  
        snake.initialize();  
  
        cout << "\n\n請輸入數字選擇級：" << endl;  
  
        cout << "\n\n\n\t\t\t1.等級一：速度 1000 \n\n\t\t\t2.等級二：速度 800 \n\n\t\t\t3.等級三：速度 600 ";  
  
        cout << "\n\n\t\t\t4.等級四：速度 400 \n\n\t\t\t5.等級五：速度 200 \n\n\t\t\t6.等級六：速度 100 \n\n\t\t\t7.自動升速模式" << endl;  
  
        snake.getgrade();//?取等?  
  
        for(int i=1;i<=4;i++)  
        {  
            position[i].initialize(i);//初始化坐標  
        }  
  
        snake.setpoint();  // ?生第一?米  
  
        do  
        {  
            snake.show_game();  
  
            nodead = snake.updata_game();  
  
        }while(nodead);  
  
        system("cls"); //清屏  
  
  
  
        cout << "\n\n\n\t\t\t\tGameover！\n\n"<<endl;  
  
        snake.display();//?出等?/得分情?  
  
        cout << "\n\n\n\t\t    是否選擇繼續遊戲？輸入 y 繼續，n 退出" << endl;  
  
        cin >> ctn;  
  
    }  
  
    return 0;  
}  
