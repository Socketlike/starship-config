#!/bin/bash

make
mkdir -p $HOME/.config/starship
cp {detectlang,detectdistro,minimal.toml} $HOME/.config/starship
