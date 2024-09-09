#include <iostream>
#include<fstream>
#include<time.h>

using namespace std;

char mark;
int pl=1;
char s[10];
int End=1;
void initialization(){
    char w='0';
for(int i=0;i<10;i++){
    s[i]=w;
w++;}
pl=1;
}
void saveResults(int p){
   static int NOG=1;
 fstream file;
    file.open("score.csv",ios::app);
    if(p==1){file<<"game "<<NOG<<":,"<<"WINS!\n";}
    else{file<<"game "<<NOG<<":, "<<"LOSE\n";}
    NOG++;
}
void clearResults() {
    ofstream file("score.csv", ios::trunc);
    if (file.is_open()) {cout << "History cleared.\n";
        file.close();}
    else {cout << "Unable to open file";}
}
void showResults() {
    ifstream file("score.csv");
    char car;
    if (file.is_open()) {
        while (file.get(car)) {
                if(car==','){continue;}
                else{
                        cout << car;}}
        file.close();}
        else {cout << "Unable to open file";}
}
void Win(char j){
if (j=='X'){pl=1;}
else{pl=2;}

    cout<<"\a \a CONGRATULATIONS player  "<<pl<<"  WINS!\n";
     saveResults(pl);
    // showResults();
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
        {srand(time(NULL));
         cho=rand()%9;
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
        cout << "Choose an option:\n";
        cout << "[1]: New Game\n";
        cout << "[2]: History\n";
        cin >> choice;
        if (choice == 1) {
            initialization();
            Game();
        } else if (choice == 2) {
            cout << "History:\n";
            showResults();
            cout << "Controls:\n";
            cout << "[1]: New Game\n";
            cout << "[10]: Clear History\n";
            cin >> choice;
            if (choice == 1) {
                initialization();
                Game();
            } else if (choice == 10) {
                clearResults();
            }
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }
}

