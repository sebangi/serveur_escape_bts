#ifndef ENIGME_H
#define ENIGME_H

#include <QString>
#include <vector>

class Enigme
{
public:
    Enigme( int id, QString nom, int temps, bool valide );


    QString nom() const;
    int temps() const;
    bool valide() const;
    int id() const;

private:
    int m_id;
    QString m_nom;
    int m_temps;
    bool m_valide;
};

typedef std::vector<Enigme> type_enigmes;

#endif // ENIGME_H
