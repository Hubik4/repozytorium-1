////wyszukiwanie liniowe

#include <iostream>
using namespace std;
int funkcja(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;  // Znaleziono element, zwracamy indeks
        }
    }
    return -1;  // Element nie został znaleziony
}

int main() {
    int numbers[] = {1, 2, 3, 4, 5, 6, 10};
    int key;
    int n = sizeof(numbers) / sizeof(numbers[0]);
    cout << "Podaj liczbę do znalezienia: ";
    cin >> key;

    int index = funkcja(numbers, n, key);
    if (index != -1) {
        cout << "Znaleziono " << key << " na indeksie " << index << endl;
    } else {
        cout << "Nie znaleziono " << key << " w tablicy" << endl;
    }

    return 0;
}

/////////////////////////////////////// z wartownikiem//////////////////
#include <iostream>
using namespace std;
int funkcja(int arr[], int n, int key) {
    arr[n] = key;  // Dodanie wartownika na końcu tablicy
    int i = 0;
    while (arr[i] != key) {
        i++;
    }
    if (i < n) {
        return i;  //  zwracamy indeks
    } else {
        return -1;  // Element nie został znaleziony
    }
}

int main() {
    int numbers[] = {1, 2, 3, 4, 5, 6, 10};
    int key;
    int n = sizeof(numbers) / sizeof(numbers[0]);
    cout << "Podaj liczbę do znalezienia: ";
    cin >> key;

    int index = funkcja(numbers, n, key);
    if (index != -1) {
        cout << " liczba " << key << " znajduje sie na indeksie " << index << endl;
    } else {
    cout << "Nie znaleziono " << key << " w tablicy" << endl;
    }

    return 0;
}
/////////////////////// skokowe////////////////////////////

#include <iostream>
#include <cmath>
using namespace std;
int jumpSearch(int arr[], int n, int key) {
    int step = sqrt(n);  // Rozmiar kroku
    int prev = 0;

    while (arr[std::min(step, n)-1] < key) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) {
            return -1;  }}

    while (arr[prev] < key) {
        prev++;
        if (prev == min(step, n)) {
            return -1;  }}

    if (arr[prev] == key) {
        return prev;  }

    return -1;  
}

int main() {
    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int key;
    int n = sizeof(numbers) / sizeof(numbers[0]);
    cout << "Podaj liczbę do znalezienia: ";
    cin >> key;

    int index = jumpSearch(numbers, n, key);
    if (index != -1) {
        cout << "liczba " << key << "  jest na indeksie " << index << endl;
    } else {
        cout << "Nie znaleziono " << key << " w tablicy" << endl;
    }

 
   return 0;
}



/////////////////binarne///////////////////

#include <iostream>
using namespace std;
int main() {
    
    cout << "Nie umiem tego zrobic ¯\_(ツ)_/¯";

    return 0;
}

/////////////////interpolacyjne ///////////

#include <iostream>
using namespace std;
int main() {
    
    cout << "Nie umiem tego zrobic ¯\_(ツ)_/¯";

    return 0;
}
