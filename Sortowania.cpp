
//SOrtowanie babelkowe
#include <iostream>
using namespace std;

void bubble(int tab1[], int rozmiar) {
    for (int i = 0; i < rozmiar - 1; i++) {
        for (int j = 0; j < rozmiar - i - 1; j++) {
            if (tab1[j] > tab1[j + 1]) {    
                int temp = tab1[j]; //zmnienia meijscamy liczby jesli liczba 1 jeste mniejsza od liczby 2
                tab1[j] = tab1[j + 1];
                tab1[j + 1] = temp;}}}}

int main() {
    int rozmiar;
    cout << "Podaj ilosc liczb do posortowania: ";
    cin >> rozmiar;

    int tab2[rozmiar];
    cout << "Podaj " << rozmiar << " liczb do posortowania: ";
    for (int i = 0; i < rozmiar; i++) {
        cin >> tab2[i];
    }

    bubble(tab2, rozmiar);

    cout << "Posortowane liczby: ";
    for (int i = 0; i < rozmiar; i++) {
        cout << tab2[i] << " ";
    }

    return 0;
}

//Sortowanie koktajlowe//////////////////////////////////////////////



#include <iostream>
using namespace std;
// Funkcja do zamiany miejscami dwóch elementów
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// deklaracja funkcji sortowania
void koktajl(int tablica[], int n) {
    bool zamiana = true;
    int start = 0;
    int koniec = n - 1;

    while (zamiana) {
        zamiana = false;

        // Przejście do przodu
        for (int i = start; i < koniec; i++) {
            if (tablica[i] > tablica[i + 1]) {
                swap(tablica[i], tablica[i + 1]);
                zamiana = true;}}
            if (!zamiana) {
            break;}

        zamiana = false;
        koniec--;

        // Przejście do tyłu
        for (int i = koniec - 1; i >= start; i--) {
            if (tablica[i] > tablica[i + 1]) {
                swap(tablica[i], tablica[i + 1]);
                zamiana = true;}}
                start++;}}

int main() {
    int rozmiar;
    cout << "Podaj rozmiar tablicy: ";
    cin >> rozmiar;

    int tablica[rozmiar];
    cout << "Podaj " << rozmiar << " liczb do posortowania: ";
    for (int i = 0; i < rozmiar; i++) {
       cin >> tablica[i];}

    koktajl(tablica, rozmiar);

    cout << "Posortowana tablica: ";
    for (int i = 0; i < rozmiar; i++) {
        cout << tablica[i] << " ";}
    cout << endl;
    return 0;
}

//Sortowanie przez scalanie //////////////////////////////////////////////////////////////////////


#include <iostream>
using namespace std;

// Funkcja scalająca posortowane części tablicy
void scalanie(int tablica[], int lew, int srd, int praw) {
    int i, j, n;
    int n1 = srd - lew + 1;
    int n2 = praw - srd;

    // Tworzenie  tablic
    int L[n1], R[n2];

    // Kopiowanie danych do tablic
    for (i = 0; i < n1; i++) {
        L[i] = tablica[lew + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = tablica[srd + 1 + j];
    }

    // Scalanie tablic 
    i = 0;
    j = 0;
    n = lew;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            tablica[n] = L[i];
            i++;
        } else {
            tablica[n] = R[j];
            j++;
        }
        n++;
    }

    // Kopiowanie pozostałych elementów z L jeśli jakieś są
    while (i < n1) {
        tablica[n] = L[i];
        i++;
        n++;
    }

    // Kopiowanie pozostałych elementów z R jeśli jakieś są
    while (j < n2) {
        tablica[n] = R[j];
        j++;
        n++;
    }
}

// Funkcja sortująca przez scalanie
void scalaniesort(int tablica[], int lew, int praw) {
    if (lew < praw) {
        // Obliczenie środka tablicy
        int srd = lew + (praw - lew) / 2;

        // Sortowanie obu połówek tablicy
        scalaniesort(tablica, lew, srd);
        scalaniesort(tablica, srd + 1, praw);

        // Scalanie posortowanych połówek
        scalanie(tablica, lew, srd, praw);
    }
}

int main() {
    int rozmiar;
    cout << "Podaj rozmiar tablicy: ";
    cin >> rozmiar;

    int tablica[rozmiar];
    cout << "Podaj " << rozmiar << " liczb do posortowania: ";
    for (int i = 0; i < rozmiar; i++) {
       cin >> tablica[i];
    }

    scalaniesort(tablica, 0, rozmiar - 1);

    cout << "Posortowana tablica: ";
    for (int i = 0; i < rozmiar; i++) {
        cout << tablica[i] << " ";
    }
    cout << endl;

    return 0;
}

//Quick sort/////////////////////////////////////////////////////////////////////////////////////////////////////////////



#include <iostream>
using namespace std;

// Funkcja zamieniająca miejscami wartości
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Funkcja wybierająca element rozdzielający pivot i dzieląca tablicę
int pivot(int tablica[], int lewy, int prawy) {
    int pivot = tablica[prawy]; // Wybieramy ostatni element jako pivot
    int i = (lewy - 1); // Indeks elementu mniejszego od pivot

    for (int j = lewy; j <= prawy - 1; j++) {
        // Jeśli bieżący element jest mniejszy lub równy pivotowi
        if (tablica[j] <= pivot) {
            i++; // Inkrementujemy indeks mniejszych elementów
            swap(tablica[i], tablica[j]);
        }
    }
    swap(tablica[i + 1], tablica[prawy]);
    return (i + 1);
}

// Funkcja sortująca przez quicksort
void quicksort(int tablica[], int lewy, int prawy) {
    if (lewy < prawy) {
        // pivotIndex jest indeksem elementu, który jest już na właściwym miejscu
        int pivotIndex = pivot(tablica, lewy, prawy);

        //  sortujemy elementy przed i po pivotIndex
        quicksort(tablica, lewy, pivotIndex - 1);
        quicksort(tablica, pivotIndex + 1, prawy);
    }
}

int main() {
    int rozmiar;
    cout << "Podaj rozmiar tablicy: ";
    cin >> rozmiar;

    int tablica[rozmiar];
    cout << "Podaj " << rozmiar << " liczb do posortowania: ";
    for (int i = 0; i < rozmiar; i++) {
       cin >> tablica[i];
    }

    quicksort(tablica, 0, rozmiar - 1);

    cout << "Posortowana tablica: ";
    for (int i = 0; i < rozmiar; i++) {
        cout << tablica[i] << " ";
    }
    cout << endl;

    return 0;
}
/////Sortowanie przez wstawianie

#include <iostream>
using namespace std;
int main() {
    
    cout << "Nie umiem tego zrobic ¯\_(ツ)_/¯";

    return 0;
}