/*
	Matrice di Vigenere
	Programmato da Carlo Zambaldo 5CS
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <iostream>
using namespace std;
 
#define n 26
#define k 50
 
int main(){
    int i=0, j=0;
    char A[n][n], chiave[k], frase[k*k];
     
    // Inizializzo la matrice frase
    cout<<"Inizializzo il programma.";
    for(int i=0; i<strlen(frase); i++){
        frase[i]=' ';
    }
    cout<<" Fine."<<endl;
         
    // Inserisco una stringa da crittografare
    cout<<"Inserire la frase da crittografare: ";
    gets(frase);
 
     
    // Disegno la matrice di Vigenere
    cout<<"Inizializzo la matrice.";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            A[i][j]=(j+i)%26+'A';
             
        }       
    }
    cout<<" Fine."<<endl;
    cout<<"Inserire chiave di cifratura: ";
    cin>>chiave;
     
    // Riempio chiave[k] con la parola inserita
    int H = strlen(chiave);
    for(int i=H; i<k; i++){
        chiave[i]=chiave[i%H];
    }
    for(i=0;i<k;i++)
        if(chiave[i]>'Z')
            chiave[i]-=32;
    cout<<"Chiave salvata."<<endl<<endl;
    puts(chiave);
     
    i=0;
    // Modifico la matrice frase
    int L=strlen(frase);
    do{
        if (frase[i]<'A'){
        for(int j=i;j<L;j++)
        frase[j]=frase[j+1];
        L--;frase[L]=' ';}
        else i++;
    } while (i<L);
  
    // Porto tutte le lettere in maiuscolo
    for(i=0;i<L;i++)
        if(frase[i]>'Z')
            frase[i]-=32;
                 
    cout<<"\nFrase corretta: ";
    puts(frase);
     
    // Encription
    char critto[k];
    for (i=0; i<L; i++)
        critto[i]=A[chiave[i]-'A'][frase[i]-'A'];
    cout<<"Frase encriptata:";
    puts(critto);
     
    char decritto[k];
    for (i=0; i<L; i++)
        for(int h=0; h<n; h++)
            if(A[chiave[i]-'A'][h]==critto[i])
                decritto[i]=h+'A';
    cout<<"Frase decrittata:";
    puts(decritto);
     
    bool F = strcmp(decritto,critto);
    cout<<endl<<endl<<"AUTOCHECK: ";
    
    if(F==0) cout<<"FALSE."<<endl;
    else cout<<"TRUE."<<endl;
         
	cout<<endl;
    system("PAUSE");
    return 0;
}
	
	
