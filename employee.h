#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__

#include <iostream>
#include <string>
class Employee {
protected:
    std::string nom;
    int matricule;
public:
    Employee();
    Employee(std::string nom, int matricule);
    virtual ~Employee();
    int getMatricule();
    std::string getNom();
    virtual float calculerPaie() = 0;
    static int menu();
    static void afficher(Employee* empl[], int index);
    static  void supp(Employee* empl1[], int index1);
};
#endif

