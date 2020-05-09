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
        void deplacer(int a,int b);
        void distribuer( std::vector<carte> t,int k);
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
        int verifPermute; // pour vérifier si la permutation a eu lieu ou non
        int verifAction; // pour vérifier si l'action demandée est effectuée ou pas
        int score ;



};

#endif // JEU_H

