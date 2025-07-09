# cub3d

Raycasting

- https://harm-smits.github.io/42docs/projects/cub3d
- https://www.youtube.com/watch?v=gYRrGTC7GtA&list=PLCWsH9Tj9oWyDM4W43VMj5yo2PdyYMGst
- https://reactive.so/post/42-a-comprehensive-guide-to-cub3d/

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