#ifndef __CONTRACTUELLE_H__
#define __CONTRACTUELLE_H__
#include "employee.h"


class Contractuelle : public Employee {
private:
    int montant_contrat;
    int semaines;
public:
    Contractuelle(std::string nom, int matricule, int le_montant_contrat, int les_semaines);
    float calculerPaie();
    static Contractuelle* ajouterContractuelle();
};
#endif
