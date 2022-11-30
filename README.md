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
  git clone https://github.com/Socketlike/starship-config
  ```
- Linux:
  - Execute `make curved` or `make powerline` or `make sharp`
  - Edit your shell's rc script and set the `STARSHIP_CONFIG` variable to
    `$HOME/.config/starship/linux-std.toml` or  
    `$HOME/.config/starship/linux-fast.toml`.
- Windows:
  - Copy `windows-std.toml` to `C:\Users\(your user)\starship\`
  - Set the `STARSHIP_CONFIG` environment variable to `C:\Users\(your user)\starship\windows-std.toml`
- MacOS:
  - Copy `macos-std.toml` to `$HOME/starship`
  - Set the `STARSHIP_CONFIG` environment variable to `$HOME/starship/macos-std.toml`

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
