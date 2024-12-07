# 42 so_long

**so_long** is a 2D game where the player navigates a map to collect items and escape. The game features basic movement mechanics and graphical display, and is built using the **MiniLibX** graphics library. The project allows the user to move a character, collect items, and escape via an exit while avoiding obstacles.

## Project Overview

In **so_long**, the player controls a character that must collect all collectibles on the map before reaching the exit. The movement is controlled using the keyboard arrow keys. The game is based on a map described in a `.ber` file, with a set of rules that define walls, collectibles, free spaces, and the player's starting position. The game runs in a window and uses the **MiniLibX** library for rendering.

### Key Features
- **2D Game View**: Top-down or profile view of the game map.
- **Collectibles and Exit**: The player needs to collect all items and reach the exit.
- **Map Validation**: The map is validated for correct structure (rectangular shape, proper wall configuration, unique exit, and starting position).
- **Graphics**: Uses MiniLibX to render the game map and player movement.
- **Smooth Window Management**: The game window remains responsive even when changing windows or minimizing.

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
- `C`: Collectible item.
- `E`: Exit.
- `P`: Player's starting position.

A valid map must adhere to these rules:
- Contains exactly one exit (`E`), at least one collectible (`C`), and one player position (`P`).
- The map must be rectangular.
- The map must be surrounded by walls (`1`).
- There should be no duplicate `P` or `E` characters.
- The map must be parseable according to these rules, and if any misconfiguration occurs, the game will display an error message and exit.

Example of a valid map:
```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

Example of another valid map:
```
1111111111111111111111111111111111
1E0000000000000C00000C000000000001
1010010100100000101001000000010101
1010010010101010001001000000010101
1P0000000C00C0000000000000000000C1
1111111111111111111111111111111111
```

## Compilation and Execution
  
### Steps to Compile:

1. **Clone the repository**:
   ```bash
   git clone https://github.com/PabloXOC/42_so_long.git so_long
   cd so_long
   ```

2. **Makefile**:
   The project includes a `Makefile` that handles compilation. To build the game, simply run:
   ```bash
   make
   ```

3. **Run the Game**:
   To run the game, execute the following command, passing the map `.ber` file as an argument:
   ```bash
   ./so_long map.ber
   ```

4. **Clean Build**:
   To clean up the project files, use the following command:
   ```bash
   make clean
   ```

5. **Remove All Build Files**:
   To fully clean the project, including compiled files:
   ```bash
   make fclean
   ```

6. **Rebuild**:
   To rebuild the project after cleaning:
   ```bash
   make re
   ```

## External Libraries and Functions

The following external libraries and functions are used in this project:
- **MiniLibX**: For graphics rendering and window management.
- **Standard C Libraries**: For system calls like `open`, `close`, `read`, `write`, and memory management with `malloc`, `free`.
- **Mathematics Library**: For math-related functions (compilation with `-lm`).
- **ft_printf**: Custom implementation of `printf` for formatted output (if required).

## Error Handling

If any issues occur with the map, such as:
- Invalid map format.
- Duplicates of `P` or `E`.
- Incorrect wall placement or broken paths.

The program will exit cleanly and display the following error message:
```
Error\n<specific error message>
```

## License

This project is intended for educational purposes as part of the **42** curriculum and **Piscine** at **42 Fundación Telefónica**. Feel free to explore the code, but note that it is not for commercial use.

---

Thank you for reviewing the **so_long** project! Feel free to open an issue for any clarifications or feedback.
```

### Key Features and Additions:
1. **Game Description**: Provides a clear overview of the game's mechanics, controls, and objectives.
2. **Map Structure**: Details the format of the `.ber` map, ensuring clarity about how the map should be structured.
3. **Compilation and Usage**: Instructions on how to compile and run the game, as well as how to clean and rebuild the project.
4. **Error Handling**: Describes how errors related to the map will be handled and displayed.
5. **External Libraries**: Lists the libraries used, including MiniLibX and custom implementations like `ft_printf`.

This README should give a comprehensive understanding of the **so_long** project while guiding users on how to compile, run, and interact with the game.
