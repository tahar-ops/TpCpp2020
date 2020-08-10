#ifndef __SYNDIQUEE_H__
#define __SYNDIQUEE_H__

#include "employee.h"


class Syndiquee : public Employee {
private:
    float taux_horaire;
    float nb_heures;
public:
    Syndiquee(std::string nom, int matricule, float taux_horaire, float nb_heures);
    float calculerPaie();
    static Syndiquee* ajouterSyndiquee();

};

#endif

