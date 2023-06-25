<center>
  <h1 align="center">starship-config</h1>
  <h4 align="center">🎨 My <a href="https://starship.rs">Starship</a> config</h4>
</center>

## Requirements

- [Any Nerd Font](https://www.nerdfonts.com/font-downloads) (I used JetBrains Mono Nerd Font for the screenshot)
- [Starship](https://starship.rs)

## Installation for Linux

- Clone the repository

  ```bash
  git clone https://github.com/Socketlike/starship-config
  ```

- Replace `Makefile`'s CXX variable with your C++ compiler of choice. Default is `clang++`.
- Execute `make curved` or `make powerline` or `make sharp`
- Edit your shell's rc script and set the `STARSHIP_CONFIG` variable to
  `$HOME/.config/starship/std.toml` or  
  `$HOME/.config/starship/fast.toml`.

## Installation for Windows (untested)

- Clone the repository
- Open a PowerShell window. Navigate to the cloned repository folder.
- Execute `.\build.ps1 curved` or `.\build.ps1 powerline` or `.\build.ps1 sharp`.
- Edit the `STARSHIP_CONFIG` environment variable to point to `%USERPROFILE%/starship/std.toml`.

## Installation for MacOS

No.

## Miscellaneous

You should disable Starship for TTYs if you're on Linux by replacing

```bash
eval "$(starship init bash)"
```

with

```bash
if [ -n "$DISPLAY" ] || [ -n "$WAYLAND_DISPLAY" ]; then
  eval "$(starship init bash)"
fi
```
