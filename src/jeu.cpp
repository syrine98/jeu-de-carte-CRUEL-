#include "jeu.h"
#include<string>
#include<vector>
#include"carte.h"
#include"tas.h"
#include <ctime>
#include <cstdlib>
#include<iostream>

using namespace std;
jeu::jeu()
{
    
    
    verifAction=0;//become 1 if the player make a move
    verifPermute=0;//become 1 if the player swap cards
    score=0;
}
jeu::~jeu(){}
void jeu::deplacer(int a ,int b,int k)//move a cards from the top of the stack a to yhe top of the stack b
{
    verifAction=0;//always null when the player try to move a card 
    //updating the positions a and b to the real positions in the two static vector zone1 and zone2
  int c=0;
  if (a>10)
  {
      a=a-6;
      c=1;
   }
   a=a-5;

  if (b<5)//moving a card from zone2 to zone1   
  {

      b=b-1;

      carte C= zone2[c][a].t.top();
      /*comparing cards if they have the same type and the card in the zone1 should be also higher rank with only one point
      for example if rank of the card in zone1 is 2 the rank of the card that the player want to move  should be  3 .
      Only in this condition the card will be moved */
       if (zone1[b].t.top().comparerCarte(zone2[c][a].t.top()))
        {

      zone1[b].t.push( zone2[c][a].t.top());
      zone2[c][a].t.pop();
      verifPermute=0;
      verifAction=1;//the card is moved
      score+=100;//adding 100 to the score after a good move
      

      }

  }

//moving a card in zone2
    /*comparing cards if they have the same type and the rank should be inferior for the card the player want to move 
      for example if rank of the moved card  is 5 the rank of the card on the destination stack should be 6.
      Only in this condition the card will be moved */
if (b>10)// destination stack is in the second row 
      {
          b=b-11;

          carte C=zone2[c][a].t.top();
           if (zone2[c][a].t.top().comparerCarte(zone2[1][b].t.top()))//comparing cards 
        {

          zone2[1][b].t.push(zone2[c][a].t.top());
          zone2[c][a].t.pop();
          verifPermute=0;
          verifAction=1;//the card is moved
          score+=100;//adding 100 to the score after a good move
          
        }
      }
if (b<11&&b>4)//destination stack is in the first row
        {
          b=b-5;

          carte C=zone2[c][a].t.top();
          if (zone2[c][a].t.top().comparerCarte(zone2[0][b].t.top()))
        {

          zone2[0][b].t.push(zone2[c][a].t.top());
          zone2[c][a].t.pop();
          verifPermute=0;
          verifAction=1;//the card is moved
          score+=100;//adding 100 to the score after a good move
        }

        }
if (verifAction==0)//the player make a bad move 
   {
       if (k==3)
       {
           score-=50;
       }
       cout<<"WARNING:Bad move"<<endl;
       cout<<"this move is not allowed"<<endl;
   }







}

void jeu::afficherZone1()
{

        cout<<"  ------------------------------------------------------------------------ "<<endl;
        cout<<"|";
    for(int i=0;i<4;i++)
    {
        int x=zone1[i].t.top().getRang().size();//getting the size of the rank so we can print cards with equal space
        if (x==1)

        {
        cout<<i+1<<")";
        zone1[i].t.top().afficher();
        cout<<"      ";
        }
         if (x==2)

        {
        cout<<i+1<<")";
        zone1[i].t.top().afficher();
        cout<<"     ";
        }

        if (x==3)

        {
        cout<<i+1<<")";
        zone1[i].t.top().afficher();
        cout<<"    ";
        }
          if (x==5)

        {
        cout<<i+1<<")";
        zone1[i].t.top().afficher();
        cout<<"  ";
        }
        if (x==4)

        {
        cout<<i+1<<")";
        zone1[i].t.top().afficher();
        cout<<"   ";
        }
    }
    cout<<"  "<<endl;
    cout<<"|"<<endl;
}
void jeu::afficherZone2()
{
    cout<<"|";

    for (int j=0; j<6; j++)
    {

        if (!(zone2[0][j].t.empty()))
        {
         int x=zone2[0][j].t.top().getRang().size();//getting the size of the rank so we can print cards with equal space
         if (x==1)

        {
        cout<<j+5<<")";
        zone2[0][j].t.top().afficher();
        cout<<"      ";
        }
         if (x==2)

        {
        cout<<j+5<<")";
        zone2[0][j].t.top().afficher();
        cout<<"     ";
        }

        if (x==3)

        {
        cout<<j+5<<")";
        zone2[0][j].t.top().afficher();
        cout<<"    ";
        }
          if (x==5)

        {
        cout<<j+5<<")";
        zone2[0][j].t.top().afficher();
        cout<<"  ";
        }
         if (x==4)

        {
        cout<<j+5<<")";
        zone2[0][j].t.top().afficher();
        cout<<"   ";
        }
    }
}
    cout<<" "<<endl<<"|";

    for (int j=0; j<6; j++)
    {


        if (!(zone2[1][j].t.empty()))
        {
         int x=zone2[1][j].t.top().getRang().size();//getting the size of the rank so we can print cards with equal space
         if (x==1)

        {
        cout<<j+11<<")";
        zone2[1][j].t.top().afficher();
        cout<<"     ";
        }
         if (x==2)

        {
        cout<<j+11<<")";
        zone2[1][j].t.top().afficher();
        cout<<"    ";
        }

        if (x==3)

        {
        cout<<j+11<<")";
        zone2[1][j].t.top().afficher();
        cout<<"   ";
        }
          if (x==5)

        {
        cout<<j+11<<")";
        zone2[1][j].t.top().afficher();
        cout<<" ";
        }
        if (x==4)

        {
        cout<<j+11<<")";
        zone2[1][j].t.top().afficher();
        cout<<"  ";
        }

    }
    }
    cout<<"  "<<endl;
    cout<<"  ------------------------------------------------------------------------  "<<endl;

}


void jeu::distribuer(vector<carte> tableau,int l)
{
    carte carte1("AS","CO",1),carte14("AS","TR",1),carte27("AS","CA",1),carte40("AS","PI",1);
    //put 4 AS in zone1 
   zone1[0].t.push(carte14);
   zone1[1].t.push(carte1);
   zone1[2].t.push(carte40);
   zone1[3].t.push(carte27);
      int i(0),j(0),k(0),position,positionS;
   if (l!=1)//distribute randomly four cards in each stack 
   {
       while (tableau.size()!=0)
   {
       position=rand()%tableau.size();
       zone2[k][j].t.push(tableau[position]);
       tableau.erase(tableau.begin()+position);
       i=i+1;
       if (i==4)
       {
           i=0;
           j=j+1;

       }
       if (j==6)

       {
          j=j-6;
          k=1;
       }



   }
   }
   if (l==1)//the level 1 so the cards on the top of each stack in zone 2 are choosen from the begining so the player can make moves easily
   {

         //the cards with rank 2 are separated from other cards 
        carte carte2("2","CO",2),carte15("2","TR",2),carte28("2","CA",2),carte41("2","PI",2);
        tableau.erase(tableau.begin()+0);
        tableau.erase(tableau.begin()+11);
        tableau.erase(tableau.begin()+22);
        tableau.erase(tableau.begin()+33);

        vector<carte> tab;
        tab.push_back(carte2);
        tab.push_back(carte15);
        tab.push_back(carte28);
        tab.push_back(carte41);
       //8 other cards where each 2 cards have same type and two successive ranks
        for(int m=0;m<4;m++)
        {

            position=rand()%tableau.size();
            tab.push_back(tableau[position]);
            if (tableau[position].getRang2()!=13)
            {
            tab.push_back(tableau[position+1]);
            tableau.erase(tableau.begin()+position);
            tableau.erase(tableau.begin()+position);
            }
            if (tableau[position].getRang2()==13)
            {
            tab.push_back(tableau[position-1]);
            tableau.erase(tableau.begin()+position);
            tableau.erase(tableau.begin()+position-1);
            }

        }
       //distrubute randomly 3 cards in each stack in zone 2
       while (tableau.size()!=0)
       {

           position=rand()%tableau.size();
           zone2[k][j].t.push(tableau[position]);
           tableau.erase(tableau.begin()+position);
           i=i+1;
           if (i==3)
              {
                   i=0;
                   j=j+1;

              }
           if (j==6)

              {
                   j=j-6;
                   k=1;
              }
       }
       i=0;
       j=0;
       k=0;
       //distribute a card in the top of each stack in zone2
       while (tab.size()!=0)
       {

           positionS=rand()%tab.size();
           zone2[k][j].t.push(tab[positionS]);
           tab.erase(tab.begin()+positionS);
           j=j+1;
           if (j==6)

              {
                   j=j-6;
                   k=1;
              }
       }


      }



}


void jeu::permuterJeu()
{
    if (verifPermute==1)//the player can't swap cards two times without making changes 
        cout<<"you can not have new cards"<<endl;
    else
    {
        verifPermute=1;
        //swap the two cards in the top of each stack in zone2
        for (int i=0;i<2;i++)
        {
          for(int j=0;j<6;j++)
          {
              if(zone2[i][j].t.size()>=2)
              {
                   zone2[i][j].permuter();
              }
          }
        }
    }
}
bool jeu::estBloque()
{
    bool test1= true ;
    /*check if there is a possible move from the zone1 to the zone 2 by comparing cards in the top of  zone2 stacks to the cards 
    in the the top of zone1 stacks*/
    for (int c=0;c<4;c++)
    {
        if (test1==false)
                break;
        for (int i=0;i<2;i++)
        {
            if (test1==false)
                break;
            for (int j=0;j<6;j++)
            {
                if (!(zone2[i][j].t.empty()))
                {
                    if (zone1[c].t.top().comparerCarte(zone2[i][j].t.top()))
                    {
                         test1=false; // there are still posssibilities
                    }
                }
            }
        }
    }
    int a(0),b(0),k,l;
    
     /*check if there is a possible move in the zone 2 by comparing cards in the top of each  stack in zone2  to the cards 
    in the the top of zone2  stacks with higher rank*/
    if (test1==true)//we don't have to check if we have a possible move yet

       {
           for (int i=0; i<11;i++)
        {
            k=i;
            if (i>5)
            {
                k=i-6;
                a=1;
            }
            if (test1==false)
              break;


            for(int j=i+1;j<12;j++)
            {
                l=j;
                if (j>5)
                    {
                       l=j-6;
                       b=1;
                    }
                if ((!(zone2[a][k].t.empty()))&&(!(zone2[b][l].t.empty())))
                {
                    if ((zone2[a][k].t.top().comparerCarte(zone2[b][l].t.top()))||(zone2[b][l].t.top().comparerCarte(zone2[a][k].t.top())))
                    {
                       test1=false;
                       break;
                    }
                }
            }
        }
       }

    return(test1);
}
bool jeu::estVideZone2()//verifying if zone2 is empty so the player win and we finish the game
{
    bool test=true ;
    for(int i=0;i<2;i++)
    {
        if (test==false)
            break;
        for(int j=0;j<6;j++)
        {
            if (!zone2[i][j].t.empty())
            {
                test=false ;
                break;
            }
        }
    }
    return(test);
}

int jeu::getVerifP()//getter of verifPermute
{
    return verifPermute;
}
int jeu::getVerifA()//getter of verifAction
{
    return verifAction;
}
int jeu::getScore()//getter of score
{
    return score;
}
void jeu::ajoutScore(long int c,int k)//updating score in the end of game 
{
    c=c/300;
    int s;
    if (k!=3)
    {
        s=4000-(c*100);
    }
    else
    {
        s=4000-(c*200);
    }
    
    score=score+s;


}


