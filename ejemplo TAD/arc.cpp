#include "arch.h"

main()
{
const int pacific_sea = AREA;
double    acres, sq_miles, sq_feet, sq_inches;

printf("\nLas conversiones marinas a area");
printf("de %d kilometros cuadrados.\n",pacific_sea); 
sq_miles = SQ_MILES_PER_SQ_KILOMETER * pacific_sea;
sq_feet = SQ_FEET_PER_SQ_MILE * pacific_sea;
sq_inches = SQ_INCHES_PER_SQ_FOOT * pacific_sea;
acres = ACRES_PER_SQ_MILE  * pacific_sea;
printf("En otras unidads de medida, estas son:\n\n");
printf("%22.7e acres \n");
printf("%22.7e  millas cuadradas\n",sq_miles);
printf("%22.7e  pies cuadrados\n",sq_feet);
printf("%22.7e  pulgadas cuadradas\n",sq_inches);

getch();
return 0;
}
