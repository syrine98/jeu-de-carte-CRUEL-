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
    //zone1 doit etre initialement vide
    // zone2 doit etre initiaisé aléatoirement
    verifAction=0;
    verifPermute=0;
    score=0;
}
jeu::~jeu(){}
void jeu::deplacer(int a ,int b)
{
    verifAction=0;
  int c=0;
  if (a>10)
  {
      a=a-6;
      c=1;
   }
   a=a-5;

  if (b<5)
  {

      b=b-1;

      carte C= zone2[c][a].t.top();
       if (zone1[b].t.top().comparerCarte(zone2[c][a].t.top()))
        {

      zone1[b].t.push( zone2[c][a].t.top());
      zone2[c][a].t.pop();
      verifPermute=0;
      verifAction=1;
      score+=100;

      }

  }


if (b>10)
      {
          b=b-11;

          carte C=zone2[c][a].t.top();
           if (zone2[c][a].t.top().comparerCarte(zone2[1][b].t.top()))
        {

          zone2[1][b].t.push(zone2[c][a].t.top());
          zone2[c][a].t.pop();
          verifPermute=0;
          verifAction=1;
          score+=100;
        }
      }
if (b<11&&b>4)
        {
          b=b-5;

          carte C=zone2[c][a].t.top();
          if (zone2[c][a].t.top().comparerCarte(zone2[0][b].t.top()))
        {

          zone2[0][b].t.push(zone2[c][a].t.top());
          zone2[c][a].t.pop();
          verifPermute=0;
          verifAction=1;
          score+=100;
        }

        }
if (verifAction==0)
   {
       cout<<"WARNING:Bad move"<<endl;
       cout<<"this move is not allowed"<<endl;
   }







} // on aura besoin à une seule méthode deplacer

void jeu::afficherZone1()
{

        cout<<"  ------------------------------------------------------------------------ "<<endl;
        cout<<"|";
    for(int i=0;i<4;i++)
    {
        int x=zone1[i].t.top().getRang().size();
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
         int x=zone2[0][j].t.top().getRang().size();
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
         int x=zone2[1][j].t.top().getRang().size();
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
   zone1[0].t.push(carte14);
   zone1[1].t.push(carte1);
   zone1[2].t.push(carte40);
   zone1[3].t.push(carte27);
      int i(0),j(0),k(0),position,positionS;
   if (l!=1)
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
   if (l==1)
   {


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
    if (verifPermute==1)
        cout<<"you can not have new cards"<<endl;
    else
    {
        verifPermute=1;
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
    bool test1= true ; // test1 pour vérifier s'il ya encore des déplacements possibles de la zone2 vers la zone1
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
                         test1=false; // il y a encore des deplacement possible de la zone 2 vers la zone 1
                    }
                }
            }
        }
    }
    int a(0),b(0),k,l;

    if (test1==true)

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
bool jeu::estVideZone2()
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

int jeu::getVerifP()
{
    return verifPermute;
}
int jeu::getVerifA()
{
    return verifAction;
}
int jeu::getScore()
{
    return score;
}
void jeu::ajoutScore(long int c)
{
    c=c/300;
    int s(1000-c);
    score=score+s;


}


