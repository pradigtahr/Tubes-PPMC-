#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "struct.h"
#include "haversine.h"

int main(){
    double lat1 = 51.5007; // Koordinat lintang untuk titik pertama (dalam derajat)
    double lon1 = 0.1246;  // Koordinat bujur untuk titik pertama (dalam derajat)
    double lat2 = 40.6892; // Koordinat lintang untuk titik kedua (dalam derajat)
    double lon2 = 74.0445; // Koordinat bujur untuk titik kedua (dalam derajat)
    
    // Memanggil fungsi haversine untuk menghitung jarak antara dua titik
    double distance = haversine(lat1, lon1, lat2, lon2);
    
    // Menampilkan hasil jarak dalam kilometer
    printf("Jarak antara kedua titik adalah: %.2f KM\n", distance);

  
  return(0);
}
