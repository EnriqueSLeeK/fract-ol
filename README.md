# fract-ol
A simple fractal renderer written in C

## Compiling
```
make
```

## Usage

For mandelbrot
```
./fractol mandelbrot
```

For julia
```
./fractol julia <img> <real>
```

For burning ship
```
./fractol burning
```
key | Behaviour
----|------------
esc | terminate the renderer
W   | move up
A   | move right
S   | move down
D   | move left
Q   | change color
E   | change color (2)
Z   | increase iteration
X   | decrease iteration
wheel up   | zoom in relative to the mouse
wheel down | zoom out relative to the mouse

## Images
<p align="center">
  <a href="https://en.wikipedia.org/wiki/Julia_set">
  <img src = "https://github.com/EnriqueSLeeK/fract-ol/blob/main/img/julia.png">
  </a>
  <img src = "https://github.com/EnriqueSLeeK/fract-ol/blob/main/img/ship.png">
  <img src = "https://github.com/EnriqueSLeeK/fract-ol/blob/main/img/mandel.png">
 </p>
