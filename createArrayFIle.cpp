#include <iostream>
#include <fstream>
#include <algorithm>
#include <stdlib.h>

unsigned short int ARRAYSIZE = 10000;

void swap(unsigned short int i, unsigned short int j, unsigned short int *Numbers){
    int temporary = Numbers[i];
    Numbers[i] = Numbers[j];
    Numbers[j] = temporary;
}



void nearlySorted(unsigned short int *Numbers, unsigned short int i){
    const unsigned short int K = 50; //hoeveelheid nummers dat gemixt word bij nearly sorted. (hoe hoger de K, hoe minder gesorteerd)

    //zet 10000 nummers in het array
    for(i = 0; i < ARRAYSIZE; i++){
        Numbers[i]= i + 1;
    }

    std::ofstream File;
    std::string nearlySortedFile = "C:\\Programming\\algoritmes\\nearlySorted.txt"; // verander dit naar het pad waarin uw file staat
    File.open(nearlySortedFile.c_str()); //het bestand waar de random lijst in komt te staan.

    //shuffle alle nummers in het array "Numbers"
	
	for (int k = 0; k < K; k++){
		short int i = rand() % ARRAYSIZE;
		short int j = rand() % ARRAYSIZE;
		swap(i, j, Numbers);
	}

    
    for(i = 0; i < ARRAYSIZE; i++) {
        File << Numbers[i] << "\n"; // zet het random array in het bestand.
        std::cout << Numbers[i] << "\n"; // print het op het console scherm (optioneel)
    }
    File.close();
}

void reverseSorted(unsigned short int *Numbers, unsigned short int i){
    //zet 10000 nummers in het array
    for(i = ARRAYSIZE; i > 0; i--){
        Numbers[i]= i;
    }

    std::ofstream File;
    std::string reverseSortedFile = "C:\\Programming\\algoritmes\\reverseSorted.txt"; // verander dit naar het pad waarin uw file staat
    File.open(reverseSortedFile.c_str());

    for(i = ARRAYSIZE; i > 0; i--) {
        File << Numbers[i] << "\n";
        std::cout << Numbers[i] << "\n";
    }

    File.close();
}

void randomSorted(unsigned short int *Numbers, unsigned short int i){
    //zet 10000 nummers in het array
    for(i = 0; i < ARRAYSIZE; i++){
        Numbers[i]= i + 1;
    }

    std::ofstream File;
    std::string randomSortedFile = "C:\\Programming\\algoritmes\\randomSorted.txt"; // verander dit naar het pad waarin uw file staat
    File.open(randomSortedFile.c_str()); //het bestand waar de random lijst in komt te staan.

    //shuffle alle nummers in het array "Numbers"
    std::random_shuffle(Numbers, Numbers + ARRAYSIZE);

    
    for(i = 0; i < ARRAYSIZE; i++) {
        File << Numbers[i] << "\n"; // zet het random array in het bestand.
        std::cout << Numbers[i] << "\n"; // print het op het console scherm (optioneel)
    }
    
    File.close();
}


int main(){
    unsigned short int Numbers[ARRAYSIZE], i;

    nearlySorted(Numbers, i); 
    std::cout << "nearly sorted finished . . .\n";
    reverseSorted(Numbers, i);
    std::cout << "reverse sorted finished . . .\n";
    randomSorted(Numbers, i);
    std::cout << "random sorted finished . . .\n";

    std::cout << "Done\n";

    return 0;
}