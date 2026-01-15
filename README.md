# Fractol

A fractal explorer written in C using MinilibX.

## Fractals Available

- **Mandelbrot** - The classic Mandelbrot set
- **Julia** - Julia set with 6 presets
- **Burning Ship** - The Burning Ship fractal

## Compilation

```bash
make
```

## Usage

```bash
./fractol mandelbrot          # or ./fractol m
./fractol julia [0-5]         # or ./fractol j [0-5]
./fractol burning_ship        # or ./fractol b
```

## Controls

| Key | Action |
|-----|--------|
| Mouse Wheel | Zoom in/out |
| Arrow Keys | Move view |
| C | Change color palette |
| +/- | Adjust Julia parameters |
| Left Click | Set Julia constant (Julia only) |
| ESC | Exit |

## Requirements

- Linux with X11
- GCC compiler
