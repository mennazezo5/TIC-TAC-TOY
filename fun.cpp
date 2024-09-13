#include <iostream>
#include<fstream>
#include<time.h>
#include <ctime>
#include <sstream>
#include<string>
#include<vector>
using namespace std;

char mark;
int pl=1;
char s[10];
int End=1;
int NOG=1;
void initialization(){
    char w='0';
for(int i=0;i<10;i++){
    s[i]=w;
w++;}
pl=1;
}
void saveResults(int p) {
    ofstream file("score.csv", ios::app);
    if (file.is_open()) {
        if(p==1){file<<"game "<<NOG<<":,WIN!"<<"\n";}
        else{file<<"game "<<NOG<<":, LOSE!"<<"\n";}}
         else {
        cout << "Unable to open file";}
         string currentBoard="";
    for (int i = 1; i < 10; i++) {
        currentBoard += s[i];
        if((i-1)%3==1||(i-1)%3==0){
                 currentBoard += '|';}
        if ((i-1) % 3 == 2) currentBoard += '\n';
    }
           ofstream filee("board.csv", ios::app);
           if (file.is_open()) {
           filee<<NOG<<endl;
           filee<<currentBoard;}
           filee.close();
        file.close();

        NOG++;
}
void clearResults() {
    NOG=1;
    ofstream file("score.csv", ios::trunc);
    ofstream filee("board.csv", ios::trunc);
    if (file.is_open()) {cout << "History cleared.\n";
        file.close();}
    else {cout << "Unable to open file";}
}
void showResults() {
    ifstream file("score.csv");
    char car;
    int gameCount = 0;
    int wins = 0, losses = 0;
    if (file.is_open()) {
        while (file.get(car)) {
                if(car==','){continue;}
                else{
                        cout << car;
                         if (car == 'W') wins++;
            else if (car == 'L') losses++;
                        }
                        }
        file.close();
          cout << "Total: " << wins << " win(s), " << losses << " lose(s)\n";}
        else {cout << "Unable to open file";}
}
void Win(char j){
if (j=='X'){pl=1; saveResults(pl);}
else{pl=2; saveResults(pl);}
    cout<<"\a \a CONGRATULATIONS player  "<<pl<<"  WINS!\n";
}
void representGame(char gameID) {
ifstream fi("board.csv");
char ch;
while(fi.get(ch)){
    if(ch==gameID){
        for(int i=0;i<19;i++){
                fi.get(ch);
            cout<<ch;
        }
        break;
    }
}
fi.close();

}
int check(){
     if (End==0) {return -2;}
     else{
         if(s[1]==s[2]&&s[2]==s[3]){return 1;}
    else if(s[4]==s[5]&&s[5]==s[6]){return 1;}
    else if(s[7]==s[8]&&s[8]==s[9]){return 1;}
    else if(s[1]==s[4]&&s[4]==s[7]){return 1;}
    else if(s[2]==s[5]&&s[5]==s[8]){return 1;}
    else if(s[3]==s[6]&&s[6]==s[9]){return 1;}
    else if(s[1]==s[5]&&s[5]==s[9]){return 1;}
    else if(s[3]==s[5]&&s[5]==s[7]){return 1;}
    else if(s[1]!='1'&&s[2]!='2'&&s[3]!='3'
            &&s[4]!='4'&&s[5]!='5'&&s[6]!='6'
            &&s[7]!='7'&&s[8]!='8'&&s[9]!='9')
                {return 0;}else{return -1;}
                }
}
void board(){
    system("cls");
    cout<<"\n\n      tic tac toe game \n\n";
    cout<<"        player 1 (X) - player 2 (o)"<<endl<<endl<<endl;
//drawing board
//cout<<"             |   |   "<<endl;
    cout<<"           "<<s[1]<<" | "<<s[2]<<" | "<<s[3]<<endl;
    cout<<"          ___|___|___"<<endl;
//cout<<"             |   |   "<<endl;
    cout<<"           "<<s[4]<<" | "<<s[5]<<" | "<<s[6]<<endl;
    cout<<"          ___|___|___"<<endl;
//cout<<"             |   |   "<<endl;
    cout<<"           "<<s[7]<<" | "<<s[8]<<" | "<<s[9]<<endl;
    cout<<"             |   |   "<<endl<<endl;

cout << "Enter [0] to end game or continue \n";


}
void Game(){
    int cho;
    do
    {   board();

         pl=(pl%2)?1:2;
        cout<<"        player "<<pl<<"  enter the num:";
        if (pl==1){cin>>cho;}
        else
        {
            do{
            srand(time(NULL));
         cho=rand()%9;}
         while(cho==0);
        }
        mark=(pl==1)?'X':'o';
        if(cho==1&&s[1]=='1'){s[1]=mark;}
        else if(cho==2&&s[2]=='2'){s[2]=mark;}
      else if(cho==3&&s[3]=='3'){s[3]=mark;}
      else if(cho==4&&s[4]=='4'){s[4]=mark;}
     else if(cho==5&&s[5]=='5'){s[5]=mark;}
      else if(cho==6&&s[6]=='6'){s[6]=mark;}
       else if(cho==7&&s[7]=='7'){s[7]=mark;}
      else if(cho==8&&s[8]=='8'){s[8]=mark;}
       else if(cho==9&&s[9]=='9'){s[9]=mark;}
       else if (cho == 0) {End=0; }
        else
        {
            cout<<"invalid move";
            pl--;
        }
        pl++;
    }

    while(check()==-1);
    for(int i=0;i<1;i++){
    if(End==0){
        break;
    }
    else{
     board();
    if(check()==1){Win(mark);}
     else{initialization();
           Game();}}}

}
void showMenu() {
    int choice;
    while (End!=0) {
        cout << "\nChoose an option:\n";
        cout << "[1]: New Game\n";
        cout << "[2]: History\n";
        cin >> choice;
        if (choice == 1) {
            initialization();
            Game();
        }  else if (choice == 2) {
            cout << "\nHistory:\n";
            showResults();
            cout << "\nEnter game ID to represent it or 0 to exit history: ";
            char gameID;
            cin >> gameID;
            if (gameID != '0') {
                representGame(gameID);
            }
            else{clearResults();
                    break;}
            cout << "\nControls:\n";
            cout << "[1]: New Game\n";
            cout << "[10]: Clear History\n";
            cin >> choice;
            if (choice == 1) {
                    initialization();
               Game();
            } else if (choice == 10) {
                clearResults();
            }
            }
         else {
            cout << "Invalid choice. Try again.\n";
        }
    }
    clearResults();
}

