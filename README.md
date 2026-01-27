# 🐍 Console Snake Game (C++)

A simple cross-platform terminal Snake game built using C++.😃
The project demonstrates real-time keyboard input handling, game loop logic, and dynamic snake tail movement.

## ✨ Features

Real-time WASD controls
Snake tail growth system
Random fruit generation
Score tracking

Screen wrapping (snake reappears on opposite side)

## Cross-platform support (Linux😃, macOS, Windows(coming soon))
🎮 Controls
Key	Action
- W	Move Up
- A	Move Left
- S	Move Down
- D	Move Right
- Q	Quit Game
📂 Files
- snake.cpp     → Main game logic  (for linux and MacOS)

- keyboard.h   → Keyboard interface  (for linux and MacOS)

- keyboard.cpp → Cross-platform input handling  (for linux and MacOS)

- SnekinWIN32.cpp → Cross-platform input handling  (WINDOWS Users)

- try.exe → simple run this file

## ⚙ Compilation
### Linux / macOS
//Make sure g++ is installed in your system using the command
```bash
g++ --version
```
//then now do 
```bash
g++ snake.cpp keyboard.cpp -o snake

./snake
```
## 🛠 How It Works

The game runs in a continuous loop that:
Reads keyboard input
Updates snake movement and tail
Draws the game board

Applies a short delay for smooth gameplay

When the snake eats a fruit, the score increases and the tail grows.

## 🚀 Future Improvements
haaa I don't think so.😃😃

👨‍💻 Author

Michael Ochieng'
PiezoGo