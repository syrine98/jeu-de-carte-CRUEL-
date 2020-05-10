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
string carte::getRang()//getter of rang
{
    return(rang);
}
string carte::getType()//getter of type
{
    return(type);
}
int carte::getRang2()//getter of rang2
{

 return(rang2);

}
void carte::afficher()//print card
{
    cout<<rang<<"-"<<type;
}
bool carte::comparerCarte(carte c) // true if the card passed in parameters is larger than the object card and has the same type
{
    int x=rang2+1;
    int y=type.compare(c.getType()); // to compare the two types of cards
    bool test=((c.getRang2()==x)&&(y==0));
        return test;
}

