#include<iostream>
using namespace std;

int recursionMystery9(int x, int y){
    if(x<0)
        return -recursionMystery9(-x,y);
    else if(y<0)
        return -recursionMystery9(x,-y);
    else if(x==0 && y==0)
        return 0;
    else
        return 100*recursionMystery9(x/10,y/10)+10*(x%10)+y%10;
}

int main(){
    cout<<recursionMystery9(12,49);
    return 0;
}
