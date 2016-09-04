#include <stdio.h>
#include "fargeskrift.h"

const int max = 7;

//skriver ut fargene
int main(){
	farge_printf(7, 0, "svart  \n");
	farge_printf(7, 1, "rød    \n");
	farge_printf(7, 2, "grønn  \n");
	farge_printf(7, 3, "orange \n");
	farge_printf(7, 4, "blå    \n");
	farge_printf(7, 5, "lilla  \n");
	farge_printf(7, 6, "lyseblå\n");
	farge_printf(0, 7, "hvit   \n");
}

