#ifndef JEU_H
#define JEU_H
#include<string>
#include"carte.h"
#include"tas.h"
#include<vector>
#include<ctime>
#include<cstdlib>


class jeu
{
    public:
       jeu();
        void deplacer(int a,int b,int k);
        void distribuer( std::vector<carte> t,int l);
        void afficherZone1();
        void afficherZone2();
        bool estBloque();
        bool estVideZone2();
        void permuterJeu();
        int  getVerifP();
        int  getVerifA();
        ~jeu();
        int  getScore();
        void ajoutScore(long int c,int k);

    private:

        tas zone1[4];
        tas zone2[2][6];
        int verifPermute; // to check whether the switchover has taken place or not
        int verifAction; // to check if the requested action is performed or not
        int score ;



};

#endif // JEU_H

