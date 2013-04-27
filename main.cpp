/* 
 * File:   main.cpp
 * Author: red
 *
 * Created on September 18, 2012, 12:44 AM
 */


#include <cstdlib>
#include <stdio.h>
#include <iostream>
//#include <gtk-2.0/gtk/gtk.h>
 #include <ddk/usb.h> //usb configuration


#include "rs232.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    long a;
    unsigned char byte[]="g0 x12.34 y34.22 z45.466";
    char t[2]="s";
    unsigned char gelen[11];
    int sonuc,i,deger,sayici;
    unsigned int port;
    
    
    printf("bu program rs232 seri port durumunu gösterir\n");
    cin >> port;
    deger=OpenComport(port,9600);
    if(deger==1) return 1;
    
 /* struct sysinfo bilgi;
    a=bilgi.uptime;
    printf("%ld\n",a);
    printf("basliyor\n"); */

    while(1){
       cin >> byte;
        sayici=0;
                while(1){
                sonuc=SendByte(port,byte[sayici]);
                sayici++;
                if(byte[sayici]=='\0') break;
                }
        if(sonuc==1) printf("veri yollanamadı!yonetici oldugunuzdan emin olun");
        else if(sonuc==0) printf("veri yollandı\n");
        cin >> byte;
        if(byte) break;
        }
    CloseComport(port);

    return 0;
}

