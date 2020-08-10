
#include "syndiquee.h"
const float IMPOTCA = 0.15;
const float IMPOTQC = 0.15;

Syndiquee::Syndiquee(std::string nom, int matricule, float taux_horaire, float nb_heures) :Employee(nom, matricule)
{
    this->taux_horaire = taux_horaire;
    this->nb_heures = nb_heures;
}
float Syndiquee::calculerPaie() 
{
    float paie = this->taux_horaire * this->nb_heures;
    return paie;
}
Syndiquee* Syndiquee::ajouterSyndiquee()
{
    std::string nom;
    int lematricule;
    float tauxHoraire, nbHeures;
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
    std::cout << "Le taux horaire:" << std::endl;
    std::cin >> tauxHoraire;
    std::cout << "Le nombre d'heures travaillées par semaine:" << std::endl;
    std::cin >> nbHeures;
    return new Syndiquee(nom, lematricule, tauxHoraire, nbHeures);
}

