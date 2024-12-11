# 42 so_long

![image](https://github.com/user-attachments/assets/8b892f03-e06f-4710-8637-bcf609d2ab6c)


**so_long** is a 2D game where the player navigates a map to collect items and escape. The game features basic movement mechanics and graphical display, and is built using the **MiniLibX** graphics library. The project allows the user to move a character, collect items, and escape via an exit while avoiding obstacles. I have used pokemon characters, sprites and tiles to make my preoject.

## Project Overview

In **so_long**, the player controls a character that must collect all collectibles on the map before reaching the exit in the minimum amount of moves. The movement is controlled using the keyboard arrow keys. The game is based on a map described in a `.ber` file, with a set of rules that define walls, collectibles, free spaces, and the player's starting position. The game runs in a window and uses the **MiniLibX** library for rendering.

### Key Features
- **2D Game View**: Top-down or profile view of the game map.
- **Collectibles and Exit**: The player needs to collect all pokeballs and reach the exit.
- **Map Validation**: The map is validated for correct structure (rectangular shape, proper wall configuration, unique exit, and starting position).
- **Graphics**: Uses MiniLibX to render the game map and player movement.

## Gameplay

- **Objective**: Collect every collectible (`C`) on the map and reach the exit (`E`) while avoiding walls (`1`).
- **Controls**:
  - Use arrow keys to move the character up, down, left, and right.
  - The game displays the number of movements in the terminal at every move.
  - Press **ESC** to exit the game.
  - Click the close button on the window to quit.

## Map Format

The map is provided as a `.ber` file, which contains a grid representing walls, free spaces, collectibles, and the player’s starting position. The map is constructed with the following characters:
- `0`: Empty space (free space).
- `1`: Wall (impassable).
- `C`: Collectible item (pokeball).
- `E`: Exit (Stairs).
- `P`: Player's starting position.

A valid map must adhere to these rules:
- Contains exactly one exit, at least one collectible, and one player position.
- The map must be rectangular.
- The map must be surrounded by walls.
- There should be no duplicate `P` or `E` characters.

If any issues occur with the map the program will exit cleanly and display and Error message.

Example of a valid map:
```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

Under /maps there are a few different maps. For testing purposes some are valid and some are not. They are clearly named so it should be easy to tell what problem each of the incorrect maps have.

## Compilation Instructions

Before compiling the project, ensure you have all the necessary dependencies installed on your system:

### Dependencies:
1. **MiniLibX**:
   - MiniLibX is a lightweight graphics library used in the 42 curriculum.
   - On Linux you will need to install `libglfw3` and `libglfw3-dev` to support MiniLibX. Use the following commands:

       ```bash
       sudo apt-get update
       sudo apt-get install libglfw3 libglfw3-dev
       ```

2. **Mathematics Library**:
   - Ensure your compiler links the math library (`-lm`) during the build process.


Once all dependencies are installed, compile the project using the `make` command:

```bash
make
```

This will generate the game executable.

### Running the Game:

To run the game, execute the generated binary with a valid `.ber` map file:

```bash
./so_long path/to/map.ber
```

### Cleaning Up
Use the following commands for cleanup:

- `make clean`: Remove object files.
- `make fclean`: Remove object files and the compiled library.
- `make re`: Rebuild the library from scratch.

## Bonus Part

For the bonus part of **so_long**, I implemented the following extra features to enhance the game:

### Features
1. **Enemy Patrols**
   - I added patrolling Charmander enemies (M) to the game. If the player collides with a Charmander while navigating the map, the game ends, and the player loses.
2. **Sprite Animation**
   - To make the game more dynamic, I incorporated sprite animation for the player character. Instead of a static character, the player now looks in the direction it is walking.
   - This adds a more polished look and feel to the game, making the movement more interactive.
3. **Movement Count Display**
   - Instead of displaying the player's movement count in the terminal, I added an on-screen display that shows the number of movements directly in the game window.
   - This helps keep the player informed without having to switch to the terminal, enhancing the user experience.

### Compilation
Follow the same instructions, but using 
```bash
make bonus
```
to compile and using the executable 
```bash
./so_long_bonus path/to/map.ber
```
