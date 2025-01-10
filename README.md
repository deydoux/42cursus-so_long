<div align="center">
  <img src="https://github.com/user-attachments/assets/0f5ed192-2ade-49d0-a641-10ab14d722ea">
  <h1>so_long</h1>
  <p>This project is a small 2D game with minilibx. You'll learn about textures, sprites and tiles.</p>
</div>

## About the project
This project is part of the 42 curriculum and focuses on creating a simple 2D game using the MinilibX graphics library. The main objectives include:
- Working with textures, sprites, and basic game elements
- Handling keyboard events for player movement
- Implementing basic game mechanics (collecting items, reaching exit)
- Managing window events and proper game closure
- Reading and validating map files
- Understanding basic game development concepts

[Gameplay.webm](https://github.com/user-attachments/assets/b890ce5c-cc26-4f51-bc2e-6d91a50e971d)

### Key Requirements
- The player must collect all collectibles before reaching the exit
- The game must be viewed from a 2D perspective (top-down or profile)
- The player must be able to move in 4 directions: up, down, left, right
- The player cannot move through walls
- Number of movements must be displayed in the shell
- Must use MinilibX for graphics rendering
- Map must be constructed with 5+1 components:
  - Walls (1)
  - Collectibles (C)
  - Exit (E)
  - Starting position (P)
  - Empty spaces (0)
  - **Bonus enemy:** Rake (R)

**Map example**
<img align="right" height="192" width="192" src="https://github.com/user-attachments/assets/842945b4-bff6-4388-ab26-e2df36808b2a">
```
11111
1C1P1
10001
1E1R1
11111
```

### Bonus features
- Animated sprites
- Enemies
- Movement count display

### Skills Learned
- Graphics programming fundamentals
- Event handling in a graphical environment
- Game logic implementation
- Memory management
- File parsing and error handling

## Getting started
### Requirements
**For Linux**
```bash
sudo apt-get install gcc libbsd-dev libxext-dev make xorg
```

**For macOS**
```bash
brew install xquartz
reboot
```

### Build and run
```bash
make
./so_long_bonus maps/maze10.ber
```
*You can replace `maps/maze10.ber` by any `.ber` file.*

## Credits
<img align="right" src="https://github.com/user-attachments/assets/e3a1b843-a0ac-46f7-9cfb-6b7e81369aac">

- [42](https://42.fr/)
- [MinilibX](https://github.com/42Paris/minilibx-linux)

### Sprites
- [TUNIC GBC by MintFerret](https://mintferret.itch.io/tunicdemake)
- [Sprout Lands - UI Pack by Cup Nooble](https://cupnooble.itch.io/sprout-lands-ui-pack)
