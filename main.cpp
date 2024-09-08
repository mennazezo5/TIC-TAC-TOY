#include <iostream>
#include<fstream>
#include<time.h>
#include"funy.h"
using namespace std;

int main()
{
char sign='y';
while(sign!='n'){
    initialization();
    Game();
    cout<< "\nDo you want to play again? (y/n): \n";
    cin>>sign;
    initialization();}
    return 0;
}
