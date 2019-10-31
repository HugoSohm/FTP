<div align="center"><h1>FTP - Epitech 2019</h1>

[![Build Status](https://travis-ci.org/HugoSohm/FTP.svg?branch=master)](https://travis-ci.org/HugoSohm/FTP)

Le FTP est un projet de programmation réseau en C de 2 semaines

</div>

## Projet FTP

### Paramètres

Le ftp nécéssite 2 arguments pour fonctionner ainsi qu'un client

- Port
- Lieu d'exécution
- Telnet ou client local

## Installation et compilation

### Récupération du projet

Après avoir cloné le [répertoire](https://github.com/HugoSohm/FTP):

```
git clone https://github.com/HugoSohm/FTP
```

- Se rendre à la racine du projet :

```
$ cd FTP
```

- Vérifier que tout est à jour :

```
$ git checkout master
```

### Compilation du programme

- Compilation

```
$ make
```

- Re-compilation

```
$ make re
```

- Nettoyage

```
$ make fclean
```

## Exécution

### Lancement du programme

- Serveur
```
$ ./myftp 4242 .
```

- Client
```
$ telnet 127.0.0.1 4242
```
