#include <stdio.h>
#include <math.h>
#include "transytivien.h"

int knoblauchbauern(int t)
{
  if(t == 0){
    return 400;
  }
  else{
    return floor((3 * knoblauchbauern(t-1)) / 2) - floor(7 * werwoelfe(t-1) / 4);
  }
}

int vampire(int t)
{
  if(t == 0){
    return 50;
  }
  else{
    return floor(6 * vampire(t-1) / 5) - floor(knoblauchbauern(t-1) / 400);
  }
}

int werwoelfe(int t)
{
  if(t == 0){
    return 75;
  }
  else{
    return floor(5 * werwoelfe(t-1) / 4) - floor(vampire(t-1) / 8);
  }
}

int geister(int t)
{
  int geist_innen = 0;
  for(int i = 1; i <= t; i++){
    if(i <= 26)
    {
      geist_innen += floor(7 * werwoelfe(i-1) / 4);
    }
  }
  printf("Anzahl Geist_innen nach %d Jahren: %d\n", t, geist_innen);
  return geist_innen;
}

// t* = 26 (Jahre)
// geister(t*) = 34351

/*
int main(){
  for(int i = 0; i <= 30; i++){
    geister(i);
  }
  return 0;
}
*/
