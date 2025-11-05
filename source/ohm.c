#include <stdio.h>

int main() {
  printf("Application de la loi d'Ohm, calcul du courant.\n");
  printf("-----------------------------------------------\n\n");
  
  double resistor;
  printf("Résistance en Ohm : ");
  scanf("%lf", &resistor);

  if (resistor <= 0) { 
    printf("Erreur: valeur de résistance incorrecte !\n");
    return 1;
  }

  double voltage;
  printf("Tension en Volts : ");
  scanf("%lf", &voltage);
  
  printf("Le courant est de %g Ampères\n", voltage / resistor);
  return 0;
}