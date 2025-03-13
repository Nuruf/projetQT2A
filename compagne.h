#ifndef COMPAGNE_H
#define COMPAGNE_H

#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>

class Compagne
{
public:
    // 🔥 Constructeurs
    Compagne();  // Constructeur par défaut
    Compagne(int id, QString nom, QDate dateDebut, QDate dateFin, int nbVaccines, int responsable);
    Compagne(QString nom, QDate dateDebut, QDate dateFin, int nbVaccines, int responsable);

    // 🛠️ Destructeur
    ~Compagne() {}

    // 📝 Méthodes CRUD
    bool ajouter();
    bool supprimer(int id);
    bool modifier(int id);
    bool chargerParId(int id);

    // 📊 Affichage
    void afficherCampagnes(QTableView* tableView);

    // 🏷️ Getters
    int getId() const;
    QString getNom() const;
    QDate getDateDebut() const;
    QDate getDateFin() const;
    int getNbVaccines() const;
    int getResponsable() const;

    // ✍️ Setters
    void setId(int id);
    void setNom(const QString &nom);
    void setDateDebut(const QDate &dateDebut);
    void setDateFin(const QDate &dateFin);
    void setNbVaccines(int nbVaccines);
    void setResponsable(int responsable);

private:
    int id;
    QString nom;
    QDate dateDebut;
    QDate dateFin;
    int nbVaccines;
    int responsable;
};

#endif // COMPAGNE_H
