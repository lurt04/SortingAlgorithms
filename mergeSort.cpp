#include <iostream>
#include <algorithm>
#include <fstream>
#include <chrono>
/* verander unsigned short integer naar auto of long, in het geval dat het array groter is dan 65,535. in ons geval gebeurt dit niet, dus houden we int aan. */


unsigned short int ARRAYSIZE = 10000;

/*combineer de arrays tot een groter array.*/
void merge(unsigned short int *array, unsigned short int begin, unsigned short int middle, unsigned short int end) {
	short int temporary[end - begin + 1];

	unsigned short int i = begin, j = middle + 1, k = 0;
	/* kijk of het array aan de linkerkant kleiner is dan het array aan de rechterkant, zo ja: zet hem dan in een tijdelijk array, zo niet: zet de rechter in het tijdelijke array */
	while(i <= middle && j <= end) {
		if(array[i] <= array[j]) {
			temporary[k] = array[i];
			k += 1; i += 1;
		}
		else {
			temporary[k] = array[j];
			k += 1; j += 1;
		}
	}
	/* in het geval dat alle cijfers uit het rechter array samengevoegd zijn, zet de overige getallen er dan achter in het tijdelijke array. ditzelfde geld voor andersom. */
	while(i <= middle) {
		temporary[k] = array[i];
		k += 1; i += 1;
	}

	while(j <= end) {
		temporary[k] = array[j];
		k += 1; j += 1;
	}
	/* verplaats alle cijfers uit het tijdelijke array, naar het "echte" array. */
	for(i = begin; i <= end; i += 1) {
		array[i] = temporary[i - begin];
	}
}

/* maak het array steeds kleiner, zodat je de individuele indexes later kan vergelijken. */
void mergeSort(unsigned short int *array, unsigned short int begin, unsigned short int end){

	if(begin < end) {
		unsigned short int middle = (begin + end) / 2;
		mergeSort(array, begin, middle);
		mergeSort(array, middle+1, end);
		merge(array, begin, middle, end);
	}
}
 
/* print het array */ 
void printArray(unsigned short int *array, unsigned short int arrayLength)
{
    for (int i = 0; i <= arrayLength; i++){
        std::cout << array[i] << " ";
	}
	std::cout << "\n";
	
}

void error(){
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.clear();
	std::cout << "Oops, that input is invalid.  Please try again.\n";
	std::abort();
}

/* maak het array */
void createArray(unsigned short int *array, unsigned short int arrayLength){
	std::cout << "choose your preferred list to sort: \t(1) randomly sorted, \n\t\t\t\t\t(2) reverse sorted, \n\t\t\t\t\t(3) nearly sorted . . . ";
	unsigned short int selectedList;
	std::cin >> selectedList;	
	//voorkom dat de gebruiker een verkeerde getal invoert.
	if (selectedList < 0 || selectedList > 3 || std::cin.fail()){
		error();
	}

	else {std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');}

	std::ifstream File;

	if (selectedList == 1) { // zet het random bestand in het array.
		std::string textFile = "C:\\Programming\\algoritmes\\randomSorted.txt";
		File.open(textFile.c_str());
		std::cout << "Randomly sorted selected. \n";
	}

	else if(selectedList == 2) { // zet het omgekeerd gesorteerde bestand in het array.
		std::string textFile = "C:\\Programming\\algoritmes\\reverseSorted.txt";
		File.open(textFile.c_str());
		std::cout << "Reverse sorted selected. \n";
	}

	else if(selectedList == 3) { // zet het "nearly sorted" bestand in het array.
		std::string textFile = "C:\\Programming\\algoritmes\\nearlySorted.txt";
		File.open(textFile.c_str());
		std::cout << "Nearly sorted selected. \n";
	}



	if (File.is_open()){
		for(int i = 0; i < arrayLength; i++){
			File >> array[i];
		}

		File.close();
	}

	else {
		std::cerr << "Can't currently find the requested list file " << std::endl;
	}
}


int main() {

	unsigned short int array[ARRAYSIZE];
	unsigned short int arrayLength{sizeof(array)/ sizeof(array[0])}; 
	unsigned short int begin = 0; //in het geval dat je b.v.b. de eerste 10 indexes niet wilt sorteren, verander je deze waarde naar 10.
	unsigned short int end = arrayLength;

	createArray(array, arrayLength);
	auto startTime = std::chrono::high_resolution_clock::now();
	mergeSort(array, begin, end);
	printArray(array, arrayLength);

	auto stopTime = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stopTime - startTime);
	std::cout << "Time taken by function: " << duration.count() << " milliseconds" << std::endl;

	system("pause");
	system("cls");
}