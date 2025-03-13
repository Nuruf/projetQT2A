#include "mainwindow.h"
#include "compagne.h"
#include "ui_mainwindow.h"
#include <QMessageBox> // Pour afficher des boîtes de dialogue

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Afficher les campagnes au démarrage
    Compagne c;
    c.afficherCampagnes(ui->tableView);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 🎯 Ajouter une nouvelle campagne
void MainWindow::on_pushButton_clicked()
{
    QString nom = ui->lineEdit_Nom->text();
    QDate dateDebut = ui->dateEdit_Debut->date();
    QDate dateFin = ui->dateEdit_Fi->date();
    int nbVaccines = ui->lineEdit_NbVaccines->text().toInt();
    int responsable = ui->lineEdit_Responsable->text().toInt();

    if (nom.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Le nom de la campagne est obligatoire.");
        return;
    }

    // Création d'une instance de Compagne et ajout à la base
    Compagne c (nom, dateDebut, dateFin, nbVaccines, responsable);
    if (c.ajouter()) {
        QMessageBox::information(this, "Succès", "Campagne ajoutée avec succès !");
        c.afficherCampagnes(ui->tableView);
    } else {
        QMessageBox::critical(this, "Erreur", "Impossible d'ajouter la campagne.");
    }
}

// 🎯 Supprimer une campagne via ID
void MainWindow::on_pushButton_2_clicked()
{
    QModelIndex index = ui->tableView->currentIndex();
    if (index.isValid()) {
        // Récupérer l'ID de la colonne 0 (ID)
        int id = ui->tableView->model()->data(index.sibling(index.row(), 0)).toInt();

        // Demander confirmation
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Confirmation", "Voulez-vous vraiment supprimer cette campagne ?",
                                      QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            Compagne compagne;
            if (compagne.supprimer(id)) {
                QMessageBox::information(this, "Succès", "Campagne supprimée.");
                compagne.afficherCampagnes(ui->tableView);
            } else {
                QMessageBox::critical(this, "Erreur", "Impossible de supprimer la campagne.");
            }
        }
    } else {
        QMessageBox::warning(this, "Aucune sélection", "Veuillez sélectionner une campagne.");
    }
}

// 🎯 Charger une campagne sélectionnée pour modification
void MainWindow::on_pushButton_3_clicked()
{
    QModelIndex index = ui->tableView->currentIndex();
    if (index.isValid()) {
        // Récupérer l'ID de la colonne 0 (ID)
        int id = ui->tableView->model()->data(index.sibling(index.row(), 0)).toInt();

        Compagne compagne;
        if (compagne.chargerParId(id)) {
            // Remplir les champs avec les données récupérées
            ui->lineEdit_Nom->setText(compagne.getNom());
            ui->dateEdit_Debut->setDate(compagne.getDateDebut());
            ui->dateEdit_Fi->setDate(compagne.getDateFin());
            ui->lineEdit_NbVaccines->setText(QString::number(compagne.getNbVaccines()));
            ui->lineEdit_Responsable->setText(QString::number(compagne.getResponsable()));

            // Stocker l'ID de la campagne sélectionnée pour modification
            ui->lineEdit_Nom->setProperty("idCampagne", id);
        } else {
            QMessageBox::critical(this, "Erreur", "Impossible de charger les données de la campagne.");
        }
    } else {
        QMessageBox::warning(this, "Aucune sélection", "Veuillez sélectionner une campagne.");
    }
}

// 🎯 Modifier une campagne existante
void MainWindow::on_pushButton_4_clicked()
{
    // Récupérer l'ID stocké lors du chargement
    QVariant idVariant = ui->lineEdit_Nom->property("idCampagne");
    if (!idVariant.isValid()) {
        QMessageBox::warning(this, "Erreur", "Veuillez d'abord sélectionner une campagne à modifier.");
        return;
    }

    int id = idVariant.toInt();
    QString nom = ui->lineEdit_Nom->text();
    QDate dateDebut = ui->dateEdit_Debut->date();
    QDate dateFin = ui->dateEdit_Fi->date();
    int nbVaccines = ui->lineEdit_NbVaccines->text().toInt();
    int responsable = ui->lineEdit_Responsable->text().toInt();

    if (nom.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Le nom de la campagne est obligatoire.");
        return;
    }

    // Modifier la campagne avec l'ID récupéré
    Compagne c(id, nom, dateDebut, dateFin, nbVaccines, responsable);
    if (c.modifier(id)) {
        QMessageBox::information(this, "Succès", "Campagne modifiée !");
        c.afficherCampagnes(ui->tableView);
    } else {
        QMessageBox::critical(this, "Erreur", "Impossible de modifier la campagne.");
    }
}
