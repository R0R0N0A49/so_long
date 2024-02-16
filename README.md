# Projet so_long



## Installation :
   ### Puis le télécharger :

	git clone https://github.com/R0R0N0A49/so_long.git
   #### Et prendre les musiques dans :
 
   - https://drive.google.com/drive/folders/1qOMKi_4CQb3IF_HhrlMU_n8KQNKTZBOF?usp=drive_link
   - Mettre le dossier 'music' dans le dossier 'so_long'.

   ### Puis pour le lancer :

   > (Ouvrir un terminal dans le dossier 'so_long')
> 
   > (remplacer "nom_de_map" par une carte présente dans le dossier map)


   #### Pour le tout premier lancement :

 
	make first && make && ./so_long map/< nom_de_map >


   #### Pour les autres fois :


	./so_long map/< nom_de_map >

## les touches :

| Action  | touche_1 | touche_2       |
| :-----: |:--------:| :-------------:|
|         |          |                |
| Droite  |   D      |  Flèche droite |
| Gauche  |   A      |  Flèche gauche |
| Haut    |   W      |  Flèche haute  |
| Bas     |   S      |  Flèche basse  |
| Quitter |   Q      |  ESC           |

## Pour créer une carte :


**- Crée un fichier ".ber" dans le dossier "map".**

**- Crée une carte avec les caractères suivants :**
 
   - 1 est un mur.
   - 0 est un endroit où le joueur peut se déplacer.
   - E est la sortie.
   - P est la position de départ du joueur.
   - C est un objet que le joueur doit ramasser.

**- Avec les critères suivants**
 
   - La carte doit être entourée de murs.
   - Il ne doit pas y avoir de ligne plus grande que les autres. Si la carte est créée sur Visual Studio, il doit y avoir un retour à la ligne à la fin.
   - Il doit y avoir seulement une position de départ et une sortie.
   - Il doit y avoir au moins un objet à collecter.

## affichage :

![img](/asset/img_Readme.jpg)

**en bas de l'écran, il y a un compteur de mouvements (entouré en bleu)**

**et un compteur de collectibles (entouré en rouge)**

## realise a 42_Angouleme
