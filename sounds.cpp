

#include<iostream>
using namespace std;
#include<windows.h>
#include<mmsystem.h>
int main(){
    PlaySound(TEXT("rocket.WAV"),NULL,SND_SYNC);
}
