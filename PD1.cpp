#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

 void wypel(int a[],int rozmiar){

    srand( time( NULL ) );
    for(int i=0; i<rozmiar; i++)
    {
        a[i]=rand()%25+1;
    }


 }

 void wyswi(int a[], int rozmiar){

    for (int i=0; i<rozmiar; i++)
    {
        cout << a[i] << " ";
    }

 }

 void sortowanie_babelkowe(int a[],int n)
{
	for(int i=0;i<n;i++)
		for(int j=1;j<n-i;j++) 
		if(a[j-1]>a[j])
			
			swap(a[j-1], a[j]);
}

int main()
{
    const int rozmiar = 12;
         int a[rozmiar];

    wypel(a, rozmiar);
    wyswi(a, rozmiar);
    sortowanie_babelkowe(a,rozmiar); 

    cout << "\n sortowanie babelkowe: ";
	
	
	for(int i=0;i<rozmiar;i++)
          cout<<a[i]<<" ";
    return 0;



    
}