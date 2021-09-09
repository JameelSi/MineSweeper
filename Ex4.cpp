#include <iostream> 
#include <stdlib.h> 
#include <time.h> 
#include <string>  
using namespace std; 
#define COLS 5
#define ROWS 6
/*QUESTION 1*/
void getCharMat(char mat[][COLS]){
    srand (time(NULL));
    int random;
    for (int i = 0; i < ROWS; i++)
       for (int j = 0; j < COLS; j++) {
            random = (rand() % 2);
            if(random==1)
                mat[i][j]='.';
            else
                mat[i][j]='*';
        }
}

void printCharMat(char mat[][COLS]){
    for (int i = 0; i < ROWS; i++)
       for (int j = 0; j < COLS; j++)
           // Prints ' ' if j != n-1 else prints '\n'
           cout << mat[i][j] << " \n"[j == COLS-1];
    cout << "\n";

}
bool isIn(int i, int j){
    if(i>=0 && i<ROWS && j>=0 && j<COLS)
        return true;
    return false;
}
int num_of_neighbors(char mat[][COLS], int i, int j) {
    if(!isIn(i,j))
        return -1;
    int counter=0;
    // checking above
    if(isIn(i-1,j))
        if(mat[i-1][j]=='*')
            counter++;
    // checking below 
    if(isIn(i+1,j))
        if(mat[i+1][j]=='*')
            counter++;
    // checking right 
    if(isIn(i,j+1))
        if(mat[i][j+1]=='*')
            counter++;
    //checking left 
    if(isIn(i,j-1))
        if(mat[i][j-1]=='*')
            counter++;
    // checking diagonals 
    if(isIn(i-1,j-1))
        if(mat[i-1][j-1]=='*')
            counter++;
    // checking diagonals 
    if(isIn(i+1,j+1))
        if(mat[i+1][j+1]=='*')
            counter++;
    // checking diagonals 
    if(isIn(i-1,j+1))
        if(mat[i-1][j+1]=='*')
            counter++;
    // checking diagonals 
    if(isIn(i+1,j-1))
        if(mat[i+1][j-1]=='*')
            counter++;
    return counter;
}
void Game(char mat[][COLS]){
    for (int i = 0; i < ROWS; i++)
       for (int j = 0; j < COLS; j++)
            // print the num of neighbours if the cell contains a dot
            if(mat[i][j]=='.')
                cout << num_of_neighbors(mat,i,j)<< " \n"[j == COLS-1];
            // else print the star as is
            else
                cout << mat[i][j] << " \n"[j == COLS-1];
               
}
/***************************/
/*QuESTION 2*/
string diff(string a, string b){
    int alen=a.length();
    int blen=b.length();
    string str="";
    char x;
    for(int i=0;i<alen;i++){
        for(int j=0;j<blen;j++){
            if(a[i]==b[j])
                break;
            else if(j==blen-1)
                str+=a[i];
                
        }
    }
    cout << str<<"\n";
    return str;
    
}
/***************************/
/*QUESTION 3*/
bool is_number(string s) {
    for(int i=0; i<s.length();i++)
        if(!(s[i]>='0' && s[i]<='9' || s[i] ==' '))
        return false;
        
    return true;
}

/**************************/
int main(){

    cout<<"Menu:"<<"\n"<<"Press:"<<"\n"<<"0.  For exit"<<"\n"<<"1.	Game  MinesWeeper."<<"\n"<<"2.	Display different string"<<"\n"<<"3.	is_number"<<"\n \n"<<"Enter your choice:";
    int choice;
    cin >> choice;
    while(choice!=0){
        if(choice==1){
            char array[ROWS][COLS];
            getCharMat(array);
            cout<< "THIS IS YOUR GAME !!"<<"\n";
            printCharMat(array);
            Game(array);
        }
        else if(choice==2){
            string a;
            string b;
            cout << "Please enter the first String: ";
            cin >> a;
            cout << "Please enter the second String: ";
            cin >> b;            
            diff(a,b);

        }
        else if(choice==3){
            string check;
            cout << "Please enter the String : ";
            cin >> check;
            is_number(check)==1?cout<<"True"<<"\n":cout<<"False"<<"\n";
        }
        else 
            cout << "Wrong input";
            cout<<"Menu:"<<"\n"<<"Press:"<<"\n"<<"0.  For exit"<<"\n"<<"1.	Game  MinesWeeper."<<"\n"<<"2.	Display different string"<<"\n"<<"3.	is_number"<<"\n \n"<<"Enter your choice:";
            cin >> choice;

    }
    return 0; 
} 