#ifndef CARTE_H
#define CARTE_H
#include <string>

class carte
{
    public:
        carte ();
        carte(std::string a ,std:: string b,int t);
        carte(const carte& c); // constructeur de copie
        std::string getType();
        std::string getRang();
        int getRang2();
        void afficher();
        bool comparerCarte(carte);
        ~carte();
    private:
        std::string type;
        std::string rang;
        int rang2;
};

#endif // CARTE_H

