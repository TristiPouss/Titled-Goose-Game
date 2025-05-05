# Titled-Goose-Game

![Logo Title Goose Game](./Titled_Goose_Game_Cover_art.png)

## Auteurs

* Matéo GALIZZI
* Paul MAILLARD-SALIN
* Tristan de SAINT GILLES

## Répartition du travail

### Matéo :

* Textures
* Modélisation
* Placement des objets dans la scène
* Scène des dés

### Paul : 

* Modèle
* Contrôleur
* Portage Linux
* Modélisation de dés avec animation
* Animations du jeu
* Refonte de l'architecture du code

### Tristan :

* Modélisation
* Caméra
* Vue
* Lumières
* Matériaux

## Liste commentée des fichiers du zip

### Dossier `Src`
- **Jeu_Oie_test.cpp** : Fichier principal du projet. Contient l'initialisation de la scène 3D, la gestion des lumières et des événements claviers/souris.

#### Sous-dossier `model/`
- **Board.cc / Board.h** : 
  - Implémente et déclare la classe `Board`, qui représente le plateau de jeu.
  - Gère les cellules et les interactions entre les joueurs et le plateau.
- **Cell.cc / Cell.h** : 
  - Implémente et déclare la classe `Cell`, qui représente une case individuelle du plateau.
  - Peut inclure des propriétés comme le type de cellule ou des actions spécifiques.
- **Dice.cc / Dice.h** : 
  - Implémente et déclare la classe `Dice`, qui simule un dé pour le jeu.
- **Game.cc / Game.h** : 
  - Implémente et déclare la classe `Game`, qui gère la logique principale du jeu, comme les tours des joueurs et les règles.
- **Player.cc / Player.h** : 
  - Implémente et déclare la classe `Player`, qui représente un joueur dans le jeu, avec des propriétés comme le nom, la position, et l'état.

#### Sous-dossier `tests/`
- **CMakeLists.txt** : Fichier de configuration pour la compilation des tests.
- **unit_test.cc** : Contient des tests unitaires pour valider les fonctionnalités principales du projet.

#### Sous-dossier `View/`
##### Fichiers principaux
- **Colors.h** : Définit des constantes pour les couleurs utilisées dans la vue (par exemple, `white`, `grey`, `darkGrey`).
- **Settings.h** : Contient des paramètres globaux pour la vue, comme la résolution de la fenêtre, les options d'affichage, et les drapeaux pour les animations.

#### Sous-dossier `Camera/`
- **Camera.cpp / Camera.h** : 
  - Implémente et déclare la classe `Camera`, qui gère la position et l'orientation de la caméra dans la scène 3D.

#### Sous-dossier `Geometry/`
- **Furnitures.cpp / Furnitures.h** : 
  - Définit et implémente des objets géométriques spécifiques (par exemple, des meubles ou des éléments de décor).
- **Shapes.cpp / Shapes.h** : 
  - Contient des fonctions pour dessiner des formes géométriques de base (cube, cylindre, sphère, etc.).
- **Texture.cpp / Texture.h** : 
  - Gère les textures appliquées aux objets 3D.

## Liste commentée des classes développées

### Classes principales

- **Board** (fichiers `Board.cc / Board.h`) :
  - Représente le plateau de jeu.
  - Gère les cellules et les interactions entre les joueurs et le plateau.
  - Fournit des méthodes pour ajouter des joueurs, déplacer des joueurs, et accéder aux cellules.

- **Cell** (fichiers `Cell.cc / Cell.h`) :
  - Classe de base représentant une case du plateau.
  - Définie comme une classe virtuelle avec des dérivées spécifiques :
    - **GooseCell** : Représente une case "Oie" qui permet au joueur d'avancer.
    - **TrapCell** : Représente une case "Piège" qui bloque le joueur pour un certain nombre de tours.
    - **TeleportCell** : Représente une case "Téléportation" qui déplace le joueur vers une autre case.

- **Dice** (fichiers `Dice.cc / Dice.h`) :
  - Simule un dé pour le jeu.
  - Fournit des méthodes pour lancer le dé et obtenir une valeur aléatoire.

- **Game** (fichiers `Game.cc / Game.h`) :
  - Gère la logique principale du jeu, comme les tours des joueurs, les règles, et l'état du jeu.
  - Fournit des méthodes pour ajouter des joueurs, lancer le jeu, et gérer les tours.

- **Player** (fichiers `Player.cc / Player.h`) :
  - Représente un joueur dans le jeu.
  - Contient des propriétés comme le nom, la position sur le plateau, et l'état (par exemple, bloqué ou non).
  - Fournit des méthodes pour déplacer le joueur et gérer son état.

### Classes liées à la vue

- **Camera** (fichiers `Camera.cpp / Camera.h`) :
  - Gère la position et l'orientation de la caméra dans la scène 3D.

- **Settings** (fichier `Settings.h`) :
  - Contient les paramètres globaux pour la vue, comme la résolution de la fenêtre, les options d'affichage, et les drapeaux pour les animations.

### Classes liées à la géométrie

- **Furnitures** (fichiers `Furnitures.cpp / Furnitures.h`) :
  - Définit et implémente des objets géométriques spécifiques (par exemple, des meubles ou des éléments de décor).

- **Shapes** (fichiers `Shapes.cpp / Shapes.h`) :
  - Contient des fonctions pour dessiner des formes géométriques de base (cube, cylindre, sphère, etc.).

- **Texture** (fichiers `Texture.cpp / Texture.h`) :
  - Gère les textures appliquées aux objets 3D.

### Classes utilitaires

- **Image** :
  - Classe représentant une image, utilisée pour charger et manipuler les fichiers PNG.

- **PngFile** :
  - Classe pour la gestion des fichiers PNG, incluant le chargement et la sauvegarde.

## Description du sujet

Le projet **Titled-Goose-Game** est une implémentation d'un jeu inspiré du jeu de l'oie, avec des fonctionnalités comme des textures personnalisées, des animations de dés, et une compatibilité multiplateforme (Windows et Linux).

## Documentation d'utilisation

1. **Installation** :
   - Clonez le dépôt ou extrayez les fichiers du zip.
   - Assurez-vous que les dépendances nécessaires (comme les bibliothèques pour PNG) sont installées.

2. **Compilation** :
   - Sous Windows : Utilisez Visual Studio Code avec les configurations fournies.
   - Sous Linux : Utilisez `make` pour compiler le projet.

3. **Lancement** :
   - Exécutez le fichier binaire généré pour démarrer le jeu.

4. **Contrôles** :
   - Utilisez les touches du clavier pour interagir avec le jeu.
   - La souris peut être utilisée pour certaines actions spécifiques.

5. **Touches** :
   - 'Esc' : Quitter le jeu
   - 'n'   : Augmenter les facettes
   - 'N'   : Diminuer les facettes
   - 'k'   : Zoom +
   - 'K'   : Zoom -
   - 'Z, Q, S, D'   : Mouvements de camera
   - 'F'   : Mode plein écran 
   - 'b'   : Change la couleur de fond
   - 'c'   : Culling 
   - 'C'   : Changement de caméra perspective / Orthogonale (fonctionne mal) 
   - 'm'   : Affichage en fil de fer 
   - 'P'   : Mettre la caméra sur le joueur actuel 
   - 'O'   : Caméra sur les dés 
   - 'H'   : Affichage de l'aide 
   - 'V'   : Joue le tour
   - 'r'   : Réinitialise la partie
   - 'R'   : Réinitialisation du zoom, des rotations et des modifications de camera
   - 'F1 -> F4' : Lumières 0 à 3 activation/désactivation
   - 'F10' : Activation/désactivation de l'éclairage
   - 'T'   : Activation/désactivation des textures