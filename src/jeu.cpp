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
    verifAction=0;
    verifPermute=0;
}
jeu::~jeu(){}
void jeu::deplacer(int a ,int b) // a representera le n° de la carte à deplacer, b le n° de tas ou on va placer la carte
{
    verifAction=0;
  int c=0;
  if (a>10)
  {
      a=a-6;
      c=1;
   }
   a=a-5;

  if (b<5) // lorsque le déplacement va s'effectuer de la zone 2 vars la zone 1
  {
      b=b-1;


      carte C= zone2[c][a].t.top();
       if (zone1[b].t.top().comparerCarte(zone2[c][a].t.top()))
        {

      zone1[b].t.push( zone2[c][a].t.top());
      zone2[c][a].t.pop();
      verifPermute=0;
      verifAction=1;

      }

  }

// deplacements dans la zone 2
if (b>10)
      {
          b=b-11;

          carte C=zone2[c][a].t.top();
           if (zone2[1][b].t.top().comparerCarte(zone2[c][a].t.top()))
        {

          zone2[1][b].t.push(zone2[c][a].t.top());
          zone2[c][a].t.pop();
          verifPermute=0;
          verifAction=1;
        }
      }
if (b<10&&b>4)
        {
          b=b-5;
          cout<<"im on"<<endl;
          carte C=zone2[c][a].t.top();
          if (zone2[0][b].t.top().comparerCarte(zone2[c][a].t.top()))
        {
          cout<<"im in"<<endl;
          zone2[0][b].t.push(zone2[c][a].t.top());
          zone2[c][a].t.pop();
          verifPermute=0;
          verifAction=1;
        }

        }
        if(verifAction==0)
        {
            cout<<"WARNING: incorrect move"<<endl;
        }

}


void jeu::afficherZone1()
{

        cout<<"  ------------------------------------------------------------------- "<<endl;
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
          if ((x==4)||(x==5))

        {
        cout<<i+1<<")";
        zone1[i].t.top().afficher();
        cout<<"  ";
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
          if ((x==4)||(x==5))

        {
        cout<<j+5<<")";
        zone2[0][j].t.top().afficher();
        cout<<"  ";
        }
    }
    cout<<" "<<endl<<"|";

    for (int j=0; j<6; j++)
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
          if ((x==4)||(x==5))

        {
        cout<<j+11<<")";
        zone2[1][j].t.top().afficher();
        cout<<" ";
        }


    }
    cout<<"  "<<endl;
    cout<<"  -------------------------------------------------------------------  "<<endl;

}


void jeu::distribuer(std::vector<carte> tableau)
{
    carte carte1("As","CO",1),carte14("As","PI",1),carte27("As","CA",1),carte40("As","TR",1);
   zone1[0].t.push(carte14); // remplisaage de la zone1 par des As
   zone1[1].t.push(carte1);
   zone1[2].t.push(carte40);
   zone1[3].t.push(carte27);

   int i(0),j(0),k(0),position;

   do // kenet while mn ghir do
   {
       position=rand()%tableau.size(); // générer une position aléatoire dans le tableau
       zone2[k][j].t.push(tableau[position]); //ajouter la carte se trouvant dans cette position aux tas de la zone 2
       tableau.erase(tableau.begin()+position); // supprimer cette carte du tableau
       i=i+1;
       if (i==4) // nombre max que peut contenir un tas de la zone 2
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
   while (tableau.size()!=0) ;


}


void jeu::permuterJeu()
{
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
bool jeu::estBloque()
{
     bool test1= true ; // test1 pour vérifier s'il ya encore des déplacements possibles de la zone2 vers la zone1
    bool test2=true ; // test2 pour vérifier s'il ya encore des déplacements possibles au sein de la zone2
    for (int c=0;c<4;c++)
    {
        for (int i=0;i<2;i++)
        {
            for (int j=0;j<6;j++)
            {
                if ((zone1[c].t.top().comparerCarte(zone2[i][j].t.top())&&(zone1[c].t.top().getType()).compare(zone2[i][j].t.top().getType())==0))
                {
                    test1=false; // il y a encore des deplacement possible de la zone 2 vers la zone 1
                }
            }
        }
    }
    int a=0; int b=0;
    do
    {
    do
    {
        for (int i=0; i<2;i++)


        {
            for(int j=0;j<6;j++)
            {
                if((zone2[i][j].t.top().comparerCarte(zone2[a][b].t.top())&&(zone2[i][j].t.top().getType()).compare(zone2[a][b].t.top().getType())==0))
                {
                    test2=false;
                }
            }
        }
        b++;
    }
    while( b>=6);
    a++;
    }
    while(a>=2);
    return(test1 && test2);
}

bool jeu::estVideZone2()
{
    bool test=true ;
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<6;j++)
        {
            if (!zone2[i][j].t.empty())
            {
                test=false ;
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


