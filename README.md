# cub3d

Raycasting

- https://harm-smits.github.io/42docs/projects/cub3d
- https://www.youtube.com/watch?v=gYRrGTC7GtA&list=PLCWsH9Tj9oWyDM4W43VMj5yo2PdyYMGst
- https://reactive.so/post/42-a-comprehensive-guide-to-cub3d/

Parsing de la Map

	OK - Fichier .cub au bon format et avec les bonnes autorisations.

	Format des textures.

	Couleurs de sol et de plafond.

	OK - Validité des caractères (0, 1, N, S, E, W, etc.).

	OK - Fermeture de la map avec un système de flood fill.

	Gérer les erreurs correctement avec des messages clairs.

Initialiser la MinilibX

	OK - Créer une fenêtre.

	Charger les textures 

Gestion des Événements

	OK - Gestion de la fermeture de la fenêtre.

	OK - Gestion propre de l'ESC et des touches directionnelles.

	OK - Libération de la mémoire.

Implémenter le Raycasting

	Calculer les distances aux murs à chaque "rayon" projeté.

	Dessiner les murs en vertical slice.

	Gérer les textures correctement sur les murs.

Afficher le Sol et le Plafond

	Soit en remplissant simplement de couleur.

	Soit via des textures (bonus).

Gestion des Mouvements

	Avancer, reculer.

	Rotation gauche/droite.
