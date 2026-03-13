*This project has been created as part of the 42 curriculum by mcrenn.*

# 🌀 Fract'ol

## 📄 Description:
The objective of fractol is to display a fractal (Mandelbrot or Julia) based on user input in the terminal.

### Qu'est ce qu'une fractale ?
A fractal is an “infinitely fragmented” geometric object whose details can be observed at any arbitrarily chosen scale.

### Qu'est ce que Mandelbrot ?
The Mandelbrot set is the set of complex numbers *c* for which the sequence is defined by the formula:

```math
Z_{n+1} = z^2_n + c
```

### Qu'est ce que Julia ?
Julia acts within the Mandelbrot set based on cx and cy.

## 📏 Instructions:
In order to launch the program correctly, you must first clone [the repository](https://github.com/ManoPotame/42-fract-ol)
```bash
	git clone https://github.com/ManoPotame/42-fract-ol
```

Next, use the `make` command to compile the entire pipex program and [libft](https://github.com/ManoPotame/Libft) library.
```bash
	make all
```

After that you can diaplay julia or mandelbrot. To do this, you'll have to execute `./fractol` and the name of the fractal you want to diaplay.
```bash
	# Display mandelbrot
	./fractol mandelbrot

	# Diaplay julia / NOTE: you have to type cx and cy after julia to make the function work
	./fractol julia 0.285 0.01
```

## 📚 Ressources:
- The [guide](https://medium.com/@leogaudin/fract-ol-creating-graphically-beautiful-fractals-6664b6b045b5) i follow to start fractol.
- The documentation of [macrolibx](https://macrolibx.kbz8.me/guides/getting_started/).
- The [formula](https://henry.codes/writing/how-to-map-a-number-between-two-ranges/) I use to remap.
- The [wiki](https://en.wikipedia.org/wiki/Julia_set) of julia set.
- And my 42 mates !
