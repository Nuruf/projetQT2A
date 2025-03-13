#include "compagne.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>

Compagne::Compagne() {}

Compagne::Compagne(QString nom, QDate dateDebut, QDate dateFin, int nbVaccines, int responsable) {
    this->nom = nom;
    this->dateDebut = dateDebut;
    this->dateFin = dateFin;
    this->nbVaccines = nbVaccines;
    this->responsable = responsable;
}
Compagne::Compagne(int id, QString nom, QDate dateDebut, QDate dateFin, int nbVaccines, int responsable) {
    this->id = id;
    this->nom = nom;
    this->dateDebut = dateDebut;
    this->dateFin = dateFin;
    this->nbVaccines = nbVaccines;
    this->responsable = responsable;
}


// Getter et Setter pour id
int Compagne::getId() const {
    return id;
}

void Compagne::setId(int id) {
    this->id = id;
}

// Getter et Setter pour nom
QString Compagne::getNom() const {
    return nom;
}

void Compagne::setNom(const QString &nom) {
    this->nom = nom;
}

// Getter et Setter pour dateDebut
QDate Compagne::getDateDebut() const {
    return dateDebut;
}

void Compagne::setDateDebut(const QDate &dateDebut) {
    this->dateDebut = dateDebut;
}

// Getter et Setter pour dateFin
QDate Compagne::getDateFin() const {
    return dateFin;
}

void Compagne::setDateFin(const QDate &dateFin) {
    this->dateFin = dateFin;
}

// Getter et Setter pour nbVaccines
int Compagne::getNbVaccines() const {
    return nbVaccines;
}

void Compagne::setNbVaccines(int nbVaccines) {
    this->nbVaccines = nbVaccines;
}

// Getter et Setter pour responsable
int Compagne::getResponsable() const {
    return responsable;
}

void Compagne::setResponsable(int responsable) {
    this->responsable = responsable;
}

bool Compagne::ajouter() {
    QSqlQuery query;
    query.prepare("INSERT INTO SPARKLAB.CAMPAGNE (NOM_CAMPAGNE, DATE_DEBUT, DATE_FIN, NOMBRE_PATIENTS_VACCINES, RESPONSABLE) "
                  "VALUES (:nom, TO_DATE(:dateDebut, 'YYYY-MM-DD'), TO_DATE(:dateFin, 'YYYY-MM-DD'), :nbVaccines, :responsable)");
    query.bindValue(":nom", nom);
    query.bindValue(":dateDebut", dateDebut.toString("yyyy-MM-dd"));
    query.bindValue(":dateFin", dateFin.toString("yyyy-MM-dd"));
    query.bindValue(":nbVaccines", nbVaccines);
    query.bindValue(":responsable", responsable);
    if (!query.exec()) {
        qDebug() << "Erreur lors de l'ajout de la campagne : " << query.lastError().text();
        return false;
    }
    return true;
}

void Compagne::afficherCampagnes(QTableView* tableView) {
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query("SELECT ID_CAMPAGNE, NOM_CAMPAGNE, DATE_DEBUT, DATE_FIN, NOMBRE_PATIENTS_VACCINES FROM SPARKLAB.CAMPAGNE");

    model->setQuery(query);

    model->setHeaderData(0, Qt::Horizontal, "ID");
    model->setHeaderData(1, Qt::Horizontal, "Nom de la campagne");
    model->setHeaderData(2, Qt::Horizontal, "Date de début");
    model->setHeaderData(3, Qt::Horizontal, "Date de fin");
    model->setHeaderData(4, Qt::Horizontal, "Patients vaccinés");

    if (model->lastError().isValid()) {
        qDebug() << "Erreur lors de la récupération des données : " << model->lastError().text();
    } else {
        tableView->setModel(model);
        tableView->resizeColumnsToContents();
    }
}

bool Compagne::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM SPARKLAB.CAMPAGNE WHERE ID_CAMPAGNE = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la suppression de la campagne : " << query.lastError().text();
        return false;
    } else {
        qDebug() << "Campagne supprimée avec succès!";
        return true;
    }
}

bool Compagne::chargerParId(int id)
{
    QSqlQuery query;
    query.prepare("SELECT ID_CAMPAGNE, NOM_CAMPAGNE, DATE_DEBUT, DATE_FIN, NOMBRE_PATIENTS_VACCINES, RESPONSABLE "
                  "FROM SPARKLAB.CAMPAGNE WHERE ID_CAMPAGNE = :id");
    query.bindValue(":id", id);

    if (query.exec()) {
        if (query.next()) {
            this->id = query.value("ID_CAMPAGNE").toInt();
            this->nom = query.value("NOM_CAMPAGNE").toString();
            this->dateDebut = query.value("DATE_DEBUT").toDate();
            this->dateFin = query.value("DATE_FIN").toDate();
            this->nbVaccines = query.value("NOMBRE_PATIENTS_VACCINES").toInt();
            this->responsable = query.value("RESPONSABLE").toInt();
            return true;
        }
    }
    qDebug() << "Erreur lors de la récupération des données de la campagne : " << query.lastError().text();
    return false;
}

bool Compagne::modifier(int id)
{
    QSqlQuery query;
    query.prepare("UPDATE SPARKLAB.CAMPAGNE "
                  "SET NOM_CAMPAGNE = :nom, "
                  "DATE_DEBUT = TO_DATE(:dateDebut, 'YYYY-MM-DD'), "
                  "DATE_FIN = TO_DATE(:dateFin, 'YYYY-MM-DD'), "
                  "NOMBRE_PATIENTS_VACCINES = :nbVaccines, "
                  "RESPONSABLE = :responsable "
                  "WHERE ID_CAMPAGNE = :id");
    query.bindValue(":id", id);
    query.bindValue(":nom", this->nom);
    query.bindValue(":dateDebut", this->dateDebut.toString("yyyy-MM-dd"));
    query.bindValue(":dateFin", this->dateFin.toString("yyyy-MM-dd"));
    query.bindValue(":nbVaccines", this->nbVaccines);
    query.bindValue(":responsable", this->responsable);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la modification de la campagne : " << query.lastError().text();
        return false;
    }
    qDebug() << "Campagne modifiée avec succès!";
    return true;
}
