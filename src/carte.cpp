#include "carte.h"
#include<string>
#include <iostream>
using namespace std;

carte::carte()
{
    //constructeur


}
carte::~carte()
{
    //destructeur
}
carte::carte(string a,string b,int t)
{
    type=b;
    rang=a;
    rang2=t;
}
carte::carte(const carte& c)
{
    type=c.type;
    rang=c.rang;
    rang2=c.rang2;
}
string carte::getRang()
{
    return(rang);
}
string carte::getType()
{
    return(type);
}
int carte::getRang2()
{

 return(rang2);

}
void carte::afficher()
{
    cout<<rang<<"-"<<type;
}
bool carte::comparerCarte(carte c) // true si la carte passée en paramètres est plus grande que la carte objet
{
    int x=rang2+1;
    int y=type.compare(c.getType()); // pour comparer les deux types de cartes
    bool test=((c.getRang2()==x)&&(y==0));
        return test;
}

