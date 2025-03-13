#include "connection.h"
#include <QSqlError>
#include <QDebug>

Connection::Connection()
{
}

bool Connection::createconnect()
{
    bool test = false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("source_sparklab"); // Nom de la source de données
    db.setUserName("system"); // Nom d'utilisateur
    db.setPassword("ahmed"); // Mot de passe

    if (db.open()) {
        test = true;
        qDebug() << "Connexion réussie!";
    } else {
        // Afficher l'erreur si la connexion échoue
        qDebug() << "Erreur de connexion:" << db.lastError().text();
    }

    return test;
}
