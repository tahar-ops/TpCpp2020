#include <iostream>
#include <string>
#include "employee.h"
#include "contractuelle.h"
#include "ponctuelle.h" 
#include "syndiquee.h"
const float IMPOTCA = 0.15  ;
const float IMPOTQC = 0.15;

int main()
{
    Employee* employes[250];
    int choix;
    int indice = 0;
    do
    {
        choix = Employee::menu();
        switch (choix)
        {
         case 1:
         {
             employes[indice] = Syndiquee::ajouterSyndiquee();
             indice++;
         }
            break;
         case 2:
         {
            employes[indice] = Contractuelle::ajouterContractuelle();
            indice++;
         }
              break;
         case 3:
         {
            employes[indice] = Ponctuelle::ajouterPonctuelle();
            indice++;
         }
              break;
         case 4:
         {
            Employee::afficher(employes, indice);
         }
              break;
         case 5: 
         {
            Employee::supp(employes, indice);
            if (indice > 0)
                indice--;
         }
              break;
         case 6:
         {
            for (int i = 0; i < indice; i++)
                delete employes[i];
            std::cout << "Vous avez quitte le logiciel avec succes!" << std::endl;
            exit(0);
         }
         break;
         default:
            std::cout << "Veuillez saisir un choix valide entre 1 et 6." << std::endl;
            choix = 1;
        }
    } while (choix >= 1 && choix <= 6);

}
