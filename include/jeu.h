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
        void distribuer( std::vector<carte> t);
        void afficherZone1();
        void afficherZone2();
        bool estBloque();
        bool estVideZone2();
        void permuterJeu();
        int  getVerifP();
        int  getVerifA();
        ~jeu();

    private:

        tas zone1[4];
        tas zone2[2][6];
        int verifPermute; // pour v�rifier si la permutation a eu lieu ou non
        int verifAction; // pour v�rifier si l'action demand�e est effectu�e ou pas



};

#endif // JEU_H

