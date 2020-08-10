#ifndef __PONCTUELLE_H__
#define __PONCTUELLE_H__

#include "employee.h"


class Ponctuelle : public Employee {
private:
    float montant_unique;
public:
    Ponctuelle(std::string nom, int matricule, float montant_unique);
    float calculerPaie();
    static Ponctuelle* ajouterPonctuelle();
};

#endif

