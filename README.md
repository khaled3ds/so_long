# so_long

A simple 2D game built with MiniLibX where the player must collect all items and reach the exit.

## Description

so_long is a small 2D game where you navigate through a map, collect all collectibles, and escape through the exit. The game validates maps for proper structure, ensures there's a valid path to complete the level, and tracks your moves as you play.

## Features

- **Map validation**: Ensures maps are rectangular, properly walled, and contain exactly one player and one exit
- **Path finding**: Validates that all collectibles and the exit are reachable using flood fill algorithm
- **Smooth controls**: Movement with WASD or arrow keys
- **Move counter**: Displays the number of moves in the terminal
- **Pixel art textures**: Beautiful 64x64 XPM sprites for all game elements
- **Clean exit handling**: Proper cleanup of MLX resources on ESC or window close

## Textures

The game includes custom pixel art textures (64x64 pixels each):
- `wall.xpm` - Stone brick walls
- `floor.xpm` - Grass floor tiles
- `player.xpm` - Character sprite
- `collect.xpm` - Collectible coin/item
- `exit.xpm` - Blue portal exit

All textures must be placed in a `textures/` directory.

## Map Format

Maps must be in `.ber` format with the following rules:

- **Rectangular shape**: All rows must have the same length
- **Surrounded by walls** (`1`)
- **Must contain**:
  - Exactly **one player** (`P`)
  - Exactly **one exit** (`E`)
  - At least **one collectible** (`C`)
- **Valid characters**: `0` (floor), `1` (wall), `P` (player), `E` (exit), `C` (collectible)

### Example Map

```
1111111
1P00001
1000001
1011111
100E0C1
1111111
```

## Installation

```bash
# Clone the repository
cd so_long

# Build the project
make
```

## Usage

```bash
./so_long maps/map.ber
```

### Controls

- **W / ↑**: Move up
- **A / ←**: Move left
- **S / ↓**: Move down
- **D / →**: Move right
- **ESC**: Exit game

## Project Structure

```
.
├── main.c              # Entry point and game initialization
├── validation.c        # Map validation (rectangle, walls, entities)
├── valid_char.c        # Character validation
├── path.c              # Pathfinding and flood fill algorithm
├── readmap.c           # Map file reading
├── image.c             # Image loading and rendering
├── move_player.c       # Player movement logic
├── click.c             # Keyboard input handling
├── initializer.c       # MLX initialization
├── rows_and_columns.c  # Map dimension helpers
├── get_next_line.c     # Line reading utility
├── ft_split.c          # String splitting utility
├── free_all.c          # Memory cleanup
├── so_long.h           # Header file
├── Makefile            # Build configuration
└── textures/           # XPM texture files
    ├── wall.xpm
    ├── floor.xpm
    ├── player.xpm
    ├── collect.xpm
    └── exit.xpm
```

## How It Works

1. **Map Loading**: Reads the `.ber` file and parses it into a 2D array
2. **Validation**: Checks map structure, walls, entity counts, and valid characters
3. **Pathfinding**: Uses flood fill to verify all collectibles and exit are reachable
4. **Game Loop**: 
   - Renders the map with textures
   - Listens for keyboard input
   - Updates player position and collectible count
   - Tracks moves and displays count
   - Ends when player reaches exit after collecting all items

## Error Handling

The program handles various error cases:
- Wrong number of arguments
- Invalid file extension (must be `.ber`)
- File reading errors
- Invalid map structure
- Unreachable collectibles or exit
- MLX initialization failures

All errors output `Error\n` to stderr.

## Requirements

- **MiniLibX**: Graphics library (included in `mlx/` directory)
- **X11**: Required for Linux
- **cc**: C compiler with `-Wall -Wextra -Werror` flags

## Compilation

The Makefile includes:
- `make`: Build the executable
- `make clean`: Remove object files
- `make fclean`: Remove object files and executable
- `make re`: Rebuild everything

## License

This project is part of the 42 school curriculum.

## Author

kadas (kadas@student.42.fr)
