#include "employee.h"
const float IMPOTCA = 0.15;
const float IMPOTQC = 0.15;

Employee::Employee(std::string nom, int matricule) 
{
    if (matricule < 10000 || matricule>99999)
    {
        std::cout << "Erreur! Le matricule doit etre entre 10000 et 99999." << std::endl;
    }
    this->nom = nom;
    this->matricule = matricule;
}
int Employee::getMatricule()
{
    return matricule;
}
std::string Employee::getNom() 
{
    return nom;
}
Employee::~Employee() {};
int Employee::menu()
{
      int choix = 0;
      std::cout << " -----MENU----- " << std::endl;
      std::cout << " 1.Ajouter un(e) employe(e) syndique(e)." << std::endl;
      std::cout << " 2.Ajouter un(e) employe(e) contractuel(le)." << std::endl;
      std::cout << " 3.Ajouter un(e) employe(e) ponctuel(le)." << std::endl;
      std::cout << " 4.Afficher le resultat de la paie pour les employe(e)s entre(e)s." << std::endl;
      std::cout << " 5.Enlever un(e) employe(e)." << std::endl;
      std::cout << " 6.Quitter le logiciel." << std::endl;
      std::cin >> choix;
       return choix;
}
void Employee::afficher(Employee* empl[], int index)
{
    float sommePaieBrute = 0;
    for (int i = 0; i < index; i++)       
    {       
        std::cout << empl[i]->getNom() << " " << empl[i]->getMatricule() << std::endl;
        std::cout << " Paie brute de " << empl[i]->calculerPaie() << " $" << std::endl;      
        std::cout << " Impots CA de " << empl[i]->calculerPaie() * IMPOTCA << " $" << std::endl;       
        std::cout << " Impots QC de " << empl[i]->calculerPaie() * IMPOTQC << " $" << std::endl;       
        std::cout << " Paie nette de " << empl[i]->calculerPaie() * (1 - IMPOTCA - IMPOTQC) << " $" << std::endl;
        sommePaieBrute+= empl[i]->calculerPaie();
    }
        std::cout << "" << std::endl;
        std::cout << "Totaux" << std::endl;
        std::cout << " Montants totaux verses de " << sommePaieBrute << " $" << std::endl;
        std::cout << " Impots a transferer CA de " << sommePaieBrute*IMPOTCA << " $" << std::endl;
        std::cout << " Impots a transferer QC de " << sommePaieBrute * IMPOTQC << " $" << std::endl;
}
void  Employee::supp(Employee* empl1[], int index1)
{
    int le_matricule;
    if (index1 == 0)
    {
        std::cout << "Il n'y a aucun employe." << std::endl;
    }
    else
    {
        std::cout << "Veuilez saisir le matricule:" << std::endl;

      do
        {
            std::cin >> le_matricule;
            if (le_matricule< (empl1[0]->getMatricule()) || le_matricule>(empl1[index1 - 1]->getMatricule()))
            {
                std::cout << "Le numero de matricule est invalide:" << std::endl;
                std::cout << "Veuillez le saisir de nouveau:" << std::endl;
            }
        } while (le_matricule< empl1[0]->getMatricule() || le_matricule>empl1[index1 - 1]->getMatricule());
         for (int i = 0; i < index1; i++) 
         {
            if (empl1[i]->getMatricule() == le_matricule)
            {
                delete empl1[i];
                empl1[i] = NULL;
                for (int j = i; j < index1 - 1; j++)
                {
                    empl1[j] = empl1[j + 1];
                }
                i = index1;
            }
         }
         empl1[index1 - 1] = nullptr;
    }
}
