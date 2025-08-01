# ft\_printf - 42

## 📚 Description

`ft_printf` est un projet de l'école 42 qui consiste à recréer une version simplifiée de la fonction `printf` de la bibliothèque standard C. L’objectif est de comprendre le fonctionnement interne de cette fonction emblématique tout en respectant des contraintes strictes.

---

## 🔧 Fonction principale

```c
int ft_printf(const char *format, ...);
```

Cette fonction prend une chaîne de format ainsi qu’un nombre variable d’arguments, puis affiche les données formatées sur la sortie standard.

---

## ✅ Conversions gérées

* `%c` : caractère
* `%s` : chaîne de caractères
* `%p` : pointeur (adresse mémoire en hexadécimal)
* `%d` / `%i` : entier signé
* `%u` : entier non signé
* `%x` : entier hexadécimal (minuscule)
* `%X` : entier hexadécimal (majuscule)
* `%%` : symbole `%` littéral

---

## ⚙️ Fonctionnalités et structure du projet

* Utilisation de `va_list` pour gérer un nombre variable d’arguments
* Conversion d'entiers en chaînes (décimal, hexadécimal)
* Affichage via `write()`
* Retour du nombre total de caractères affichés
* Gestion de cas limites et comportement conforme à `printf`

---

## ⚙️ Compilation

| Commande      | Description                                  |
| ------------- | -------------------------------------------- |
| `make`        | Compile le projet et génère `libftprintf.a`  |
| `make clean`  | Supprime les fichiers objets (`.o`)          |
| `make fclean` | Supprime les fichiers objets et la librairie |
| `make re`     | Supprime tout et recompile entièrement       |

---

## 🖼️ Note du projet

<p align="center">
  <img width="199" height="169" alt="image" src="https://github.com/user-attachments/assets/3cb12a00-dc57-4f96-a6b9-66bbfe7cd7b8" />
</p>
---

## 🫐 Auteur

* Océane (ocviller)
* Projet réalisé à 42 Paris, 2025
