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
  
    int x1, y1; // ?��X��  
  
    int x,y;  
  
    long start;  
  
//=======================================  
//?��??�O?��initialize  
//=======================================  
  
//�U���w??�Y�D����??  
class snake_position  
{  
public:  
  
    int x,y;      //x��ܦ�Ay��ܦC  
  
    snake_position(){};  
  
    void initialize(int &);//���Ъ�l��  
  
  
};  
  
snake_position position[(N-2)*(N-2)+1]; //�w??�Y�D��????�A��(N-2)*(N-2)?��?  
  
void snake_position::initialize(int &j)  
{  
        x = 1;  
  
        y = j;  
}  
  
  
//�U���w??�Y�D����??  
  
class snake_map  
{  
  
private:  
  
    char s[N][N];//�w??�Y�D��?�A�]�A?���C  
  
    int grade, length;  
  
    int gamespeed; //�e????�j  
  
    char direction; // ��l��?�U�A�V�k??  
  
    int head,tail;  
  
    int score;  
  
    bool gameauto;  
  
public:  
  
    snake_map(int h=4,int t=1,int l=4,char d=77,int s=0):length(l),direction(d),head(h),tail(t),score(s){}  
  
    void initialize();   //��l�ƨ�?  
  
    void show_game();  
  
    int updata_game();  
  
    void setpoint();  
  
    void getgrade();  
  
    void display();  
  
  
};  
  
//�w?��l�ƨ�?�A??�Y�D����???���l��  
  
void snake_map::initialize()  
{  
    int i,j;  
  
    for(i=1;i<=3;i++)  
  
        s[1][i] = '*';  
  
    s[1][4] = '#';  
  
    for(i=1;i<=N-2;i++)  
  
        for(j=1;j<=N-2;j++)  
  
            s[i][j]=' '; // ��l��?�Y�D��?��?�ťճ���  
  
    for(i=0;i<=N-1;i++)  
  
        s[0][i] = s[N-1][i] = '-'; //��l��?�Y�D��?�W�U?��  
  
    for(i=1;i<=N-2;i++)  
  
        s[i][0] = s[i][N-1] = '|'; //��l��?�Y�D��?���k?��  
}  
  
  
//============================================  
//?�X?�Y�D��?�H��  
  
void snake_map::show_game()  
  
{  
  
    system("cls"); // �M��  
  
    int i,j;  
  
    cout << endl;  
  
    for(i=0;i<N;i++)  
    {  
  
        cout << '\t';  
  
        for(j=0;j<N;j++)  
  
            cout<<s[i][j]<<' '; // ?�X?�Y�D��?  
  
        if(i==2) cout << "\t���šG" << grade;  
  
        if(i==6) cout << "\t�t�סG" << gamespeed;  
  
        if(i==10) cout << "\t�o���G" << score << "��" ;  
  
        if(i==14) cout << "\t�Ȱ��G���@�U�Ů�?" ;  
  
        if(i==18) cout << "\t�~��G���@�U�Ů�?" ;  
  
        cout<<endl;  
    }  
}  
  
//?�J??��?  
void snake_map::getgrade()  
{  
    cin>>grade;  
  
    while( grade>7 || grade<1 )  
    {  
        cout <<" �п�J�Ʀr1-7��ܵ��šA��J��L�Ʀr�L�� "<< endl;  
  
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
  
//?�X��?�A�o����?�H��??  
  
void snake_map::display()  
{  
  
    cout << "\n\t\t\t\t���šG" << grade;  
  
    cout << "\n\n\n\t\t\t\t�t�סG" << gamespeed;  
  
    cout << "\n\n\n\t\t\t\t�o���G" << score << "��" ;  
  
}  
  
//?��?�ͦ�  
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
  
    //�p�G��?���U��??�W?��?�e????�j??��`?  
  
  
  
        if(gameover)  
        {  
  
            getch();  
  
            key = getch();  
        }  
  
        if(key == ' ')  
  
        {  
            while(getch()!=' '){};//?��??���O���Ů�??���A���Ů�???���\��A������?���]�A�ݭn��?�U�Ů�~��??�C?�O?bug�C  
        }  
  
        else  
  
            direction = key;  
  
        switch(direction)  
        {  
            case 72: x= position[head].x-1; y= position[head].y;break; // �V�W  
  
            case 80: x= position[head].x+1; y= position[head].y;break; // �V�U  
  
            case 75: x= position[head].x; y= position[head].y-1;break; // �V��  
  
            case 77: x= position[head].x; y= position[head].y+1; // �V�k  
  
        }  
  
        if(!(direction==72||direction==80||direction==75 ||direction==77))   // ��?�D��V?  
  
            gameover = 0;  
  
        else if(x==0 || x==N-1 ||y==0 || y==N-1)   // �I���پ�  
  
            gameover = 0;  
  
        else if(s[x][y]!=' '&&!(x==x1&&y==y1))    // �D�Y�I��D��  
  
            gameover = 0;  
  
        else if(x==x1 && y==y1)  
  
        { // �Y�̡A?�ץ[1  
  
            length ++;  
  
            if(length>=8 && gameauto)  
  
            {  
  
                length -= 8;  
  
                grade ++;  
  
                if(gamespeed>=200)  
  
                    gamespeed -= 200; // ��??�Y�D�e?�t��  
  
                else  
  
                    gamespeed = 100;  
  
            }  
  
            s[x][y]= '#';  //��s�D?  
  
            s[position[head].x][position[head].y] = '*'; //�Y�̦Z?����D???�D��  
  
            head = (head+1) % ( (N-2)*(N-2) );   //���D?��?  
  
            position[head].x = x;  
  
            position[head].y = y;  
  
            show_game();  
  
            gameover = 1;  
  
            score += grade*20;  //�[��  
  
            setpoint();   //?�ͦ�  
  
        }  
  
        else  
        { // ���Y��  
  
            s[position[tail].x][position[tail].y]=' ';//?�D���m��  
  
            tail= (tail+1) % ( (N-2) * (N-2) );//��s�D����?  
  
            s[position[head].x][position[head].y]='*';  //?�D?��?�D��  
  
            head= (head+1) % ( (N-2) * (N-2) );  
  
            position[head].x = x;  
  
            position[head].y = y;  
  
            s[position[head].x][position[head].y]='#'; //��s�D?  
  
            gameover = 1;  
  
        }  
    return gameover;  
  
}  
//====================================  
//�D�禡����  
//====================================  
int main()  
{  
    char ctn = 'y';  
  
    int nodead;  
  
    cout<<"\n\n\n\n\n\t\t\t �w��i�J�g�Y�D����	!"<<endl;//�w��ɭ�;  
  
    cout<<"\n\n\n\t\t\t �����N���W�}�l�C�C�C"<<endl;//�ǳƶ}�l;;  
  
    getch();  
  
    while( ctn=='y' )  
    {  
        system("cls"); // �M��  
  
        snake_map snake;  
  
        snake.initialize();  
  
        cout << "\n\n�п�J�Ʀr��ܯšG" << endl;  
  
        cout << "\n\n\n\t\t\t1.���Ť@�G�t�� 1000 \n\n\t\t\t2.���ŤG�G�t�� 800 \n\n\t\t\t3.���ŤT�G�t�� 600 ";  
  
        cout << "\n\n\t\t\t4.���ť|�G�t�� 400 \n\n\t\t\t5.���Ť��G�t�� 200 \n\n\t\t\t6.���Ť��G�t�� 100 \n\n\t\t\t7.�۰ʤɳt�Ҧ�" << endl;  
  
        snake.getgrade();//?����?  
  
        for(int i=1;i<=4;i++)  
        {  
            position[i].initialize(i);//��l�Ƨ���  
        }  
  
        snake.setpoint();  // ?�ͲĤ@?��  
  
        do  
        {  
            snake.show_game();  
  
            nodead = snake.updata_game();  
  
        }while(nodead);  
  
        system("cls"); //�M��  
  
  
  
        cout << "\n\n\n\t\t\t\tGameover�I\n\n"<<endl;  
  
        snake.display();//?�X��?/�o����?  
  
        cout << "\n\n\n\t\t    �O�_����~��C���H��J y �~��An �h�X" << endl;  
  
        cin >> ctn;  
  
    }  
  
    return 0;  
}  
