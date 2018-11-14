#ifndef BDDINTERFACE_H
#define BDDINTERFACE_H

#include <QSqlDatabase>
#include "entete/enigme.h"

class BddInterface
{
private:
    BddInterface();

public:
    ~BddInterface();

public:
    static BddInterface* instance();

    bool connexionEtablie() const;
    type_enigmes get_enigmes() const;

private:
    /** \brief Pointeur sur l'instance singleton AfficheurInterface. */
    static BddInterface* m_instance;

    QSqlDatabase m_db;
};

#endif // BDDINTERFACE_H
