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
    srand(time(0)); 
    cout << "welcome in the game! " << endl;
    //initialization de 52 cartes
    carte carte1("As","CO",1),carte2("2","CO",2),carte3("3","CO",3),carte4("4","CO",4),carte5("5","CO",5),carte6("6","CO",6),carte7("7","CO",7),carte8("8","CO",8);
    carte carte9("9","CO",9),carte10("10","CO",10),carte11("Valet","CO",11),carte12("Dame","CO",12),carte13("Roi","CO",13),carte14("As","PI",1),carte15("2","PI",2);
    carte carte16("3","PI",3),carte17("4","PI",4),carte18("5","PI",5),carte19("6","PI",6),carte20("7","PI",7),carte21("8","PI",8),carte22("9","PI",9),carte23("10","PI",10);
    carte carte24("Valet","PI",11),carte25("Dame","PI",12),carte26("Roi","PI",13),carte27("As","CA",1),carte28("2","CA",2),carte29("3","CA",3),carte30("4","CA",4);
    carte carte31("5","CA",5),carte32("6","CA",6),carte33("7","CA",7),carte34("8","CA",8),carte35("9","CA",9),carte36("10","CA",10),carte37("Valet","CA",11);
    carte carte38("Dame","CA",12),carte39("Roi","CA",13),carte40("As","TR",1),carte41("2","TR",2),carte42("3","TR",3),carte43("4","TR",4),carte44("5","TR",5);
    carte carte45("6","TR",6),carte46("7","TR",7),carte47("8","TR",8),carte48("9","TR",9),carte49("10","TR",10),carte50("Valet","TR",11),carte51("Dame","TR",12),carte52("Roi","TR",13);
    vector <carte> tableau ;
 // filling the vector with 48 cards

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



    int i,j,k,a,b;
    //the player choose to start the game 
    cout<<"do you want to start a new game? click 1 if you want"<<endl;
     cin>>i;

     if (i==1)
     {

         jeu newGame;//starting the game
         long int startTime,endTime,elapsedTime;
         startTime=time(0);
         //the player choose the level
         do
         {
             cout<<"choose level, click 1 if you want the beginner, 2 for the medium, 3 for the hard"<<endl;
             cin>>k;
         }
         while ((k!=1)&&(k!=2)&&(k!=3));

         newGame.distribuer(tableau,k);//distribute cards
         newGame.afficherZone1();//print cards in the two areas
         newGame.afficherZone2();
         bool test=true;
        while(test)
         {
            
             if (((newGame.getVerifP()==1)&&(newGame.estBloque()))||((k==3)&&(elapsedTime>1800)))//the game ended if it's blocked after having new cards or passed the limited timr for level 3
             {
                 
                 cout<<"GAME OVER"<<endl;
                 //adding points to score 
                 if ((k!=3)||((k==3)&&(!(elapsedTime>1800))))
                 {
                     newGame.ajoutScore(elapsedTime,k);
                 }
                 if ((k==3)&&((elapsedTime>1800)))
                 {
                     newGame.ajoutScore(elapsedTime+2500,k);
                 }
                 
                 cout<<"score:"<<newGame.getScore()<<endl;//print score
                 cout<<"playing time:"<<elapsedTime<<" s"<<endl;//print the playing time
                 break;


             }
             cout<<"if you want to move a card click 1"<<endl<<"if you want to have new cards click 2"<<endl;
             cin>>j;
             if (j==1)
             {



                     do
                   {
                   cout<<"enter the number of tas from where you want to move card"<<endl;
                   cin>>a;
                   }
                   while ((a>16)||(a<4));
                    do
                   {
                   cout<<"enter the number of tas where you want to place card"<<endl;
                   cin>>b;
                   }
                   while((b>16)||(b<0));

                   newGame.deplacer(a,b,k);//moving cards from stack a to stack b if it's possible


             }
              if ((j==2) && newGame.estBloque()==true)
              {
                  newGame.permuterJeu();

              }
              else if ((j==2) && newGame.estBloque()==false)
              {
                  cout<<"there are still possibilities"<<endl;

              }

               if (newGame.estVideZone2())
               {
                   cout<<"You won"<<endl;
                   newGame.ajoutScore(elapsedTime,k);
                   cout<<"score:"<<newGame.getScore()<<endl;
                   cout<<"playing time:"<<elapsedTime<<" s"<<endl;
                   break;
               }

               newGame.afficherZone1();
               newGame.afficherZone2();
               endTime=time(0);
               elapsedTime=endTime-startTime;





         }






     }


    return 0;
}


