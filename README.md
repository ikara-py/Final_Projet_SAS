Final Projet

Introduction :

Créez une application console qui permet de gérer un aéroport fictif et son parc d’avions.

L’application doit offrir la possibilité d’ajouter, modifier, supprimer et afficher les avions du parc, gérer les informations de l’aéroport, effectuer des recherches et appliquer des tris, tout en intégrant une fonction bonus de calcul d’un coefficient d’occupation du parc.
Contexte du projet :

L’application doit avoir un menu qui vous permet de :
1. Gestion des avions

Chaque avion est défini par une structure contenant :

    idAvion (int, unique, généré automatiquement)

    modele (string, ex : Boeing 737, Airbus A320)

    capacite (int, nombre de passagers maximum)

    statut (string : “Disponible”, “En maintenance”, “En vol”)

    dateEntree (structure Date : jour, mois, année)

Fonctionnalités :

    Ajouter un avion (ou plusieurs).

    Modifier un avion (modele, capacité, statut).

    Supprimer un avion.

    Afficher la liste des avions.

    Rechercher un avion (par id ou par modèle).

    Trier les avions (par capacité, par modèle alphabétique,).

2. Gestion de l’aéroport

Chaque aéroport est défini par une structure contenant :

    nom (string, ex : Casablanca Mohammed V)

    flotte (tableau d’avions)

    nbAvions (int, nombre total d’avions enregistrés dans l’aéroport)

Fonctionnalités :

    Initialiser un aéroport avec son nom.

    Afficher les informations de l’aéroport et de sa flotte.


3. Gestion des dates (Bonus)

Chaque date est définie par une structure contenant :

    jour (int)

    mois (int)

    annee (int)

Fonctionnalités :

    Associer une date d’entrée à chaque avion.

    Permettre un tri par date d’entrée dans le parc.

    Trier les avions par date d'entrée.

4. Fonction - Calcul du coefficient d’occupation du parc

Le coefficient d’occupation du parc est calculé ainsi :

Coeff Occupation = (Nombre d’avions disponibles / Nombre total d’avions) × 100

Fonctionnalités :

    Calculer le pourcentage d’avions disponibles dans l’aéroport.

    Afficher ce coefficient sous forme numérique.

5. Statistiques

    Nombre total d’avions dans le parc.

    Nombre d’avions par statut (“Disponible”, “En maintenance”, “En vol”).

    Capacité totale de la flotte.

    L'avion ayant la plus grande capacité et celui ayant la plus petite capacité.

Contraintes pédagogiques :

    Les étudiants doivent utiliser :

        des structures pour représenter les entités (Avion, Airport, Date).

        des tableaux (statiques ou dynamiques simples) pour stocker les collections.

    Après chaque opération, l’utilisateur retourne au menu principal.

    Implémenter des algorithmes de recherche et de tri adaptés (recherche séquentielle, tri par sélection, tri à bulles, etc.).


N.B : L’utilisateur doit retourner au menu principal après chaque opération