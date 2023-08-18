#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
    string name;
    static int score;
    char input;
    int guess;
    cout<<"enter your name:"<<endl;
    getline(cin,name);
    do
    {
        if(input=='y' || input=='Y')
        srand(0);
        int number=rand()%100+1;
        cout<<"enter any number in between 1 to 100"<<endl;
        cin>>guess;
        if(guess==number)
        {
            cout<<"Congratulations "<<name;
            cout<<" you guessed exact number!!"<<endl;
            score++;
        }
        else if(guess>number)
        {
            cout<<"please guess lower number"<<endl;
        }
        else if(guess<number)
        {
            cout<<"please guess higher number"<<endl;
        }
        cout<<"do you wanna play again? if yes than enter Y/y otherwise enter N/n"<<endl;
        cin>>input;
       
    } while (input!='n' && input!='N');
    cout<<"your score is:"<<score<<endl;
    cout<<"Game end"<<endl;
    cout<<"hope you enjoyed it"<<endl;

    return 0;
}