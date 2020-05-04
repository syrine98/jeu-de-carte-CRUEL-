#include <iostream>
#include "carte.h"
#include "tas.h"
#include "jeu.h"
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    srand(time(0)); // pour la distribution aléatoire
    cout << "welcome in the game! " << endl;
    //initialisation de 52 cartes
    carte carte1("As","CO",1),carte2("2","CO",2),carte3("3","CO",3),carte4("4","CO",4),carte5("5","CO",5),carte6("6","CO",6),carte7("7","CO",7),carte8("8","CO",8);
    carte carte9("9","CO",9),carte10("10","CO",10),carte11("Valet","CO",11),carte12("Dame","CO",12),carte13("Roi","CO",13),carte14("As","PI",1),carte15("2","PI",2);
    carte carte16("3","PI",3),carte17("4","PI",4),carte18("5","PI",5),carte19("6","PI",6),carte20("7","PI",7),carte21("8","PI",8),carte22("9","PI",9),carte23("10","PI",10);
    carte carte24("Valet","PI",11),carte25("Dame","PI",12),carte26("Roi","PI",13),carte27("As","CA",1),carte28("2","CA",2),carte29("3","CA",3),carte30("4","CA",4);
    carte carte31("5","CA",5),carte32("6","CA",6),carte33("7","CA",7),carte34("8","CA",8),carte35("9","CA",9),carte36("10","CA",10),carte37("Valet","CA",11);
    carte carte38("Dame","CA",12),carte39("Roi","CA",13),carte40("As","TR",1),carte41("2","TR",2),carte42("3","TR",3),carte43("4","TR",4),carte44("5","TR",5);
    carte carte45("6","TR",6),carte46("7","TR",7),carte47("8","TR",8),carte48("9","TR",9),carte49("10","TR",10),carte50("Valet","TR",11),carte51("Dame","TR",12),carte52("Roi","TR",13);
    vector <carte> tableau ;
for (int i=0 ;i<=48 ;i++) // remplissage du tableau par 48 cartes
{
tableau.push_back(carte2);
tableau.push_back(carte3);
tableau.push_back(carte4);
tableau.push_back(carte5);
tableau.push_back(carte6);
tableau.push_back(carte7);
tableau.push_back(carte8);
tableau.push_back(carte9);
tableau.push_back(carte10);
tableau.push_back(carte11);
tableau.push_back(carte12);
tableau.push_back(carte13);
tableau.push_back(carte15);
tableau.push_back(carte16);
tableau.push_back(carte17);
tableau.push_back(carte18);
tableau.push_back(carte19);
tableau.push_back(carte20);
tableau.push_back(carte21);
tableau.push_back(carte22);
tableau.push_back(carte23);
tableau.push_back(carte24);
tableau.push_back(carte25);
tableau.push_back(carte26);
tableau.push_back(carte28);
tableau.push_back(carte29);
tableau.push_back(carte30);
tableau.push_back(carte31);
tableau.push_back(carte32);
tableau.push_back(carte33);
tableau.push_back(carte34);
tableau.push_back(carte35);
tableau.push_back(carte36);
tableau.push_back(carte37);
tableau.push_back(carte38);
tableau.push_back(carte39);
tableau.push_back(carte41);
tableau.push_back(carte42);
tableau.push_back(carte43);
tableau.push_back(carte44);
tableau.push_back(carte45);
tableau.push_back(carte46);
tableau.push_back(carte47);
tableau.push_back(carte48);
tableau.push_back(carte49);
tableau.push_back(carte50);
tableau.push_back(carte51);
tableau.push_back(carte52);
}


    int i,j,a,b;
    cout<<"do you want to start a new game? click 1 if you want"<<endl;
     cin>>i;
     if (i==1)
     {

         jeu newGame;
         newGame.distribuer(tableau);
         newGame.afficherZone1();
         newGame.afficherZone2();
         bool test=true;
        while(test)
         {
             if ((newGame.getVerifP()==1)&&(newGame.estBloque())) // permutation effectuée et la zone2 est bloquée
             {
                 cout<<"GAME OVER"<<endl;
                 test=false;

             }
             cout<<"if you want to move a card click 1"<<endl<<"if you want to have new cards click 2"<<endl;
             cin>>j;
             if (j==1) // si on veut déplacer une carte
             {



                     do
                   {
                   cout<<"enter the number of tas from where you want to move card"<<endl;
                   cin>>a; // 4<= a <= 16
                   }
                   while ((a>16)||(a<4));
                    do
                   {
                   cout<<"enter the number of tas where you want to place card"<<endl;
                   cin>>b; // 0<b<=16
                   }
                   while((b>16)||(b<0));

                   newGame.deplacer(a,b);


             }
              if (j==2) // donner des nouvelles cartes: effectuer la permutation
              {
                  newGame.permuterJeu();

              }

               if (newGame.estVideZone2())
               {
                   cout<<"You won"<<endl;
                   break;
               }

               newGame.afficherZone1();
               newGame.afficherZone2();




         }






     }
    return 0;
}


