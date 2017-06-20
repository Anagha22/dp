#include <iostream>
#include<string.h>
using namespace std;

int main() {

    char text[]="bacbabababacaca";
    char pat[]="ababaca";
    int pre[7];
    int textlen=strlen(text);
    int patlen=strlen(pat);
    int patctr=0,textctr=0;
    int i=1,j=0;
    pre[0]=0;

    if(i<patlen) {

        if(pat[i]==pat[j]) {        //matches
            pre[i]=j+1;
            i++;
            j++;
        }
        else {                      //mismatch
            if(j==0) {              //case1: j=0
                pre[i]=0;
                i++;
            }
            else                        //case2: j>0
                j=pre[j-1];
        }
    }

    while(textctr<textlen) {

        while(text[textctr]&&text[textctr]==pat[patctr]) {
            textctr++;
            patctr++;

        }
        if(patctr=patlen) {
            cout<<"pattern found"<<endl;
            return 0;
        }
        if(patctr==0)
            textctr++;
        else
            patctr=pre[patctr-1];
    }
    cout<<"not found"<<endl;




    return 0;
}

