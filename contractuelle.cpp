#include "contractuelle.h"
const float IMPOTCA = 0.15;
const float IMPOTQC = 0.15;

Contractuelle::Contractuelle(std::string nom, int matricule, int le_montant_contrat, int les_semaines) :Employee(nom, matricule)
{
    this->montant_contrat = le_montant_contrat;
    this->semaines = les_semaines;
}
float Contractuelle::calculerPaie() 
{
    float paie = (float)this->montant_contrat / (float)this->semaines;
    return paie;
}
Contractuelle* Contractuelle::ajouterContractuelle()
{
    std::string nom;
    int lematricule, montantContrat, nbsemaimes;
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
    std::cout << "Le montant du contrat:" << std::endl;
    std::cin >> montantContrat;
    std::cout << "Le nombre de semaines:" << std::endl;
    std::cin >> nbsemaimes;
    return new Contractuelle(nom, lematricule, montantContrat, nbsemaimes);
}
