

#include<stdio.h>
#include<iostream>
using namespace std;
#include<windows.h>
#include<mmsystem.h>
int sound(){
    PlaySound(TEXT("rocket.wav"),NULL,SND_SYNC);
    return 0;
}
