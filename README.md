# 🎮 cub3D

![Made with C](https://img.shields.io/badge/Made%20with-C-blue?logo=c)  
![42 Project](https://img.shields.io/badge/42-Project-black?logo=42)

## 🧠 Project Overview

*cub3D* is a graphics/game engine project from **42 School**.  
The goal is to build a simple **raycasting engine** (inspired by Wolfenstein 3D) that lets a user navigate inside a 3D maze based on a 2D map.

You will parse a `.cub` scene file that describes textures, colors, and the map layout. Then your program must render the world in **first-person view**, allowing movement, rotation, and optionally bonus features (sprites, minimap, etc.).

---

## 🚀 How to Run

### ✅ Requirements

- Unix-like environment (Linux, macOS, or WSL)  
- A working **MiniLibX** (graphics library)  
- `gcc` or `clang` compiler  
- `make`

### ⚙️ Installation & Compilation

git clone https://github.com/ndabboussi/cub3d.git
cd cub3d
make
# For bonus features	
make bonus

### ▶️ Usage		
./cub3D path/to/map.cub	

./cub3D maps/map1.cub	
./cub3D_bonus maps/map1.cub	

---

## 🔑 Key Challenges & Requirements	
| Feature / Challenge            | What it requires / why it’s tricky                                                                        |
| ------------------------------ | --------------------------------------------------------------------------------------------------------- |
| **Parsing the `.cub` file**    | Read texture paths, floor/ceiling colors, map definition, validate correctness.                           |
| **Map validation**             | Ensure the map is closed (surrounded by walls), exactly one spawn point, no invalid characters.           |
| **Raycasting & DDA algorithm** | Cast a ray per vertical slice, detect wall intersections (horizontal & vertical), select the closest hit. |
| **Projection & rendering**     | Compute wall heights, texture mapping, floor/ceiling coloring.                                            |
| **Movement & rotation**        | Move forward/back, strafe left/right, rotate view (arrow keys or mouse), with collision detection.        |
| **Bonus features**             | Sprites, minimap, doors, more complex interactions, mouse look, etc.                                      |
| **Memory & error management**  | Free all allocated memory, handle errors cleanly (invalid maps, wrong textures, etc.).                    |

---

## 📚 Resources & References

- 42 Docs : cub3d project details & raycasting guidance ([harm-smits.github.io](https://harm-smits.github.io/42docs/projects/cub3d))
- Raycasting tutorials (Lodev, others)
- MiniLibX documentation & usage examples
- https://www.youtube.com/watch?v=gYRrGTC7GtA&list=PLCWsH9Tj9oWyDM4W43VMj5yo2PdyYMGst
- https://reactive.so/post/42-a-comprehensive-guide-to-cub3d/

---

## ✨ Why This Project Matters

This project gives you hands-on experience with:

- Low-level graphics programming  
- Geometry, vectors, trigonometry  
- Real-time rendering (converting a 2D map into a 3D view)  
- Handling user input, collision detection, performance constraints  
- Designing robust parsers and error handling  

---

## 🎮 Controls (Typical)

- `W` / `S` : Move forward / backward  
- `A` / `D` : Strafe left / right  
- Arrow Left / Arrow Right (or mouse) : Rotate view  
- `ESC` or window close : Exit program  

---

## 🗺 Example Map File Format (`.cub`)

NO ./textures/north.xpm  
SO ./textures/south.xpm  
WE ./textures/west.xpm  
EA ./textures/east.xpm  
F 220,100,0  
C 225,30,0  

111111111111  
100000000001  
101100000101  
100N00000001  
111111111111  

- NO, SO, WE, EA = wall texture file paths
- F = RGB color for the floor	
- C = RGB color for the ceiling
- The map: 1 = wall, 0 = empty, N/S/E/W = player start and orientation	
