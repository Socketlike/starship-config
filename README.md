<center>
  <h1 align="center">starship-config</h1>
  <h4 align="center">🎨 My <a href="https://starship.rs">Starship</a> config</h4>
</center>

## Preview
![image1](https://i.imgur.com/EPSpWOw.png)

## Requirements
- [JetBrains Mono Nerd Font](https://www.nerdfonts.com/font-downloads)
- [Starship](https://starship.rs)

## Installation
- Clone the repository
  
  ```bash
  git clone https://github.com/Abstructor/starship-config
  ```
- Copy `minimal.toml` (+ `detectdistro` and `detectlang` if you use Linux) to...
  - `/home/(username)/.config/starship` (Linux & MacOS)
  - `C:/Users/(username)/starship` (Windows)
- Set the STARSHIP_CONFIG environment variable to...
  - `/home/(username)/.config/starship/minimal.toml` (Linux & MacOS)
  - `C:/Users/(username)/starship/minimal.toml` (Windows)

## Miscellaneous
You should disable Starship for TTYs if you're on Linux by replacing
```bash
eval "$(starship init bash)"
```  
with  
```bash
if [ -n "$DISPLAY" ]; then
eval "$(starship init bash)"
fi
```
