# cub3d

Raycasting

- https://harm-smits.github.io/42docs/projects/cub3d
- https://www.youtube.com/watch?v=gYRrGTC7GtA&list=PLCWsH9Tj9oWyDM4W43VMj5yo2PdyYMGst
- https://reactive.so/post/42-a-comprehensive-guide-to-cub3d/

To do Nina :
	Gérer les erreurs correctement avec des messages clairs.

GESTION DES PORTES

Parsing
	Ajouter une texture specifique pour les portes
	Reconnaitre le charactere D et vcerifier s'il est entoure de murs et pas sur le bord de la map
(ou bien considerer qu'une porte en bords de map ne s'ouvre pas)

Implémenter leS PORTES
	Calculer une distance minimum a laquelle le player doit se tenir de la porte pour l''ouvrir
	Mis en place de reception du sugnall "H" pour ouvrir la porte
	Tranformer le P ou 0 pour permettre le passage
	Possibilite de refermer la porte

Option :  transfert de la texture de la porte a l'interieur du passage cree pour donner l'illusion qu'elle est ouverte


PIERRE 
	- color prend pas tous les cas en compte : map/invalid_map/wrong_color_2.cub
	- si le fichier est vide, renvoyer "empty file" : en testant avec map/invalid_map/vide.cub on renvoie "Check_config_complete: Missing texture path"

NINA 
	- si la map est vide on devrait direct renvoyer une erreur, pas celle du player
	- map/invalid_map/wrong_border.cub fonctionne pas
