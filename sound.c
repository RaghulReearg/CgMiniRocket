#include<stdio.h>
#include<iostream>
using namespace std;
#include<windows.h>
#include<mmsystem.h>
int main(){
    PlaySound(TEXT("sound.wav"),NULL,SND_SYNC);
}
