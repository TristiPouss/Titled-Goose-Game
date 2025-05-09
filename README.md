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
* README

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
- **Jeu_Oie_test.cpp** : Fichier principal du projet. Contient l'initialisation de la scène 3D, les contrôles clavier et les appels au controller.

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
- **CMakeLists.txt** : 
  - Fichier de configuration pour la compilation des tests.
- **unit_test.cc** : 
  - Contient des tests unitaires pour valider les fonctionnalités du model.

#### Sous-dossier `View/`
- **Colors.h** : 
  - Définit des constantes pour les couleurs utilisées dans la vue (par exemple, `white`, `grey`, `darkGrey`).
- **Settings.h** : 
  - Contient des paramètres globaux pour la vue, comme la résolution de la fenêtre, les options d'affichage, et les drapeaux pour les animations.
- **Light.cpp / Light.h** : 
  - Implémente les différentes lumières utilisées dans le jeu.
  - Elles simulent plusieurs heures de la journée.
- **Materials.cpp / Materials.h** : 
  - Implémente les différents matériaux utilisés comme `WallMaterial`, `WoodMaterial`.
- **SceneSettings.h** : 
  - Définit des constantes pour la construction de la scène.
- **View.cpp / View.h** : 
  - Gère l'entièreté de la vue. La construction des différentes scènes (`MainScene` et `DiceScene`) ainsi que leurs animations (déplacement des pions et animations des dés).

#### Sous-sous-dossier `Camera/`
- **Camera.cpp / Camera.h** : 
  - Implémente et déclare la classe `Camera`, qui gère la position et l'orientation des différentes caméras dans la scène 3D.
  - On a une camera libre qui peut se déplacer, une camera qui suit le joueur actif et une camera vue du dessus.

#### Sous-sous-dossier `Geometry/`
- **Furnitures.cpp / Furnitures.h** : 
  - Définit et implémente des objets spécifiques (des meubles ou des éléments de décor).
  - Leurs tailles, leur nombre de facettes et leurs textures sont variables.
- **Shapes.cpp / Shapes.h** : 
  - Contient des fonctions pour dessiner des formes géométriques de base (cube, cylindre, sphère, etc.).
  - Leurs tailles et leurs nombres de facettes sont variables.
- **Texture.cpp / Texture.h** : 
  - Gère les textures appliquées aux objets 3D.

#### Sous-dossier `controller/`
- **Controller.cpp / Controller.h** : 
  - Gère l'interaction entre le modèle, la vue, et l'utilisateur.
  - Initialisation du jeu, gestion des tours des joueurs, et mise à jour de l'affichage.


## Description du sujet

Le projet **Titled-Goose-Game** est une implémentation d'un jeu inspiré du jeu de l'oie, avec des fonctionnalités comme des textures personnalisées, des animations de dés, et une compatibilité multiplateforme (Windows et Linux).

## Utilisation

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