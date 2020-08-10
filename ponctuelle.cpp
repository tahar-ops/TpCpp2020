
#include "ponctuelle.h"
const float IMPOTCA = 0.15;
const float IMPOTQC = 0.15;
Ponctuelle::Ponctuelle(std::string nom, int matricule, float montant_unique) :Employee(nom, matricule)
{
    this->montant_unique = montant_unique;
}
float Ponctuelle::calculerPaie()
{
    float paie = this->montant_unique;
    return paie;
}
Ponctuelle* Ponctuelle::ajouterPonctuelle()
{
    std::string nom;
    int lematricule, montant_unique;
    std::cout << "Veuillez saisir le nom:" << std::endl;
    std::cin >> nom;
    std::cout << "Le matricule:" << std::endl;
    do 
    {
         std::cin >> lematricule;
         if (lematricule < 10000 || lematricule>99999)
        {
            std::cout << "Le matricule doit être entre 10000 et 99999." << std::endl;
            std::cout << "Veuillez saisir de nouveau le matricule:" << std::endl;
        }
    } while (lematricule < 10000 || lematricule>99999);
    std::cout << "Le montant unique:" << std::endl;
    std::cin >> montant_unique;
    return new Ponctuelle(nom, lematricule, montant_unique);
}
