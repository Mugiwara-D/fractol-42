# Fractol

Un explorateur de fractales ecrit en C avec MinilibX.

## Fractales Disponibles

- **Mandelbrot** - L'ensemble de Mandelbrot classique
- **Julia** - Ensemble de Julia avec 6 presets
- **Burning Ship** - La fractale Burning Ship

## Compilation

```bash
make
```

## Utilisation

```bash
./fractol mandelbrot          # ou ./fractol m
./fractol julia [0-5]         # ou ./fractol j [0-5]
./fractol burning_ship        # ou ./fractol b
```

## Controles

| Touche | Action |
|--------|--------|
| Molette souris | Zoom avant/arriere |
| Fleches | Deplacer la vue |
| C | Changer la palette de couleurs |
| +/- | Ajuster les parametres Julia |
| Clic gauche | Definir la constante Julia (Julia uniquement) |
| ESC | Quitter |

## Prerequis

- Linux avec X11
- Compilateur GCC
