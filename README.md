# Cub3D

This project is a 3D game created using the ray-casting technique, inspired by the classic game Wolfenstein 3D. The goal is to render a 3D perspective from a 2D map. The project is written in C and uses the MiniLibX library for graphics.

## Features

*   **Map Parsing**: The program can parse a `.cub` file which describes the map layout, textures for the walls, and colors for the floor and ceiling.
*   **Ray-casting Engine**: A ray-casting engine is implemented to render the 3D view from the player's perspective.
*   **Player Movement**: The player can move forward, backward, left, and right, and can rotate the camera.
*   **Texture Mapping**: Walls are rendered with textures provided in the map file.

## How to Compile

To compile the project, simply run the `make` command in the root directory of the project.
```bash
make
```

## How to Run

After compilation, you can run the game by providing a map file as an argument. An example map is provided in the `maps` directory.

```bash
./cub3D maps/map.cub
```

## Contact

*   **42 Login**: ihhadjal
*   **Email**: ihhadjal@student.42nice.fr
