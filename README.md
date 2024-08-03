# FDF

## Overview

**FDF** is a project that involves creating a wireframe model representation of a 3D landscape by linking various points (x, y, z) using line segments (edges). This project will help you understand and implement graphical rendering using the MiniLibX library, alongside other essential functions.

## Summary

This project is about representing a landscape as a 3D wireframe model.

## Mandatory Part

### Program Name
`fdf`

### Turn-in Files
- `Makefile`
- `*.h`
- `*.c`

### Makefile Targets
- `NAME`
- `all`
- `clean`
- `fclean`
- `re`

### Arguments
- A file in `.fdf` format

### External Functions
- `open`, `close`, `read`, `write`
- `malloc`, `free`
- `perror`, `strerror`
- `exit`
- All functions of the math library (`-lm` compiler option)
- All functions of the MiniLibX
- `ft_printf` and any equivalent YOU coded

### Libft Authorization
Libft is authorized for this project.

### Description
This project involves creating a simple wireframe model representation of a 3D landscape by linking various points (x, y, z) using line segments (edges).

#### Requirements
- Use the MiniLibX library, either the version available on the school machines or by installing it from its sources.
- Provide a Makefile that compiles your source files without relinking.
- Global variables are forbidden.

### Rendering
- Represent the model in isometric projection.
- The coordinates of the landscape are stored in a `.fdf` file passed as a parameter to your program.
- Each number in the file represents a point in space:
  - The horizontal position corresponds to its axis.
  - The vertical position corresponds to its ordinate.
  - The value corresponds to its altitude.

### Graphic Management
- Display the image in a window.
- Ensure smooth window management (e.g., changing to another window, minimizing).
- Pressing ESC should close the window and quit the program cleanly.
- Clicking on the cross on the window’s frame should close the window and quit the program cleanly.
- Use the images of the MiniLibX.

### Example Files
Download the binary file `fdf` and the example file `42.fdf` from the project intranet page (inside `fdf.zip`).

## Bonus Part

### Bonus Features
You can earn extra points by implementing the following features:
- Include one extra projection (such as parallel or conic).
- Zoom in and out.
- Translate your model.
- Rotate your model.
- Add one more bonus of your choice.

## Installation

Clone the repository and navigate to the project directory:

```sh
git clone https://github.com/aabderrafie/fdf_42.git
cd fdf
```

### Installing MiniLibX
Follow the instructions provided in the MiniLibX repository to install it:

```sh
git clone https://github.com/42Paris/minilibx-linux.git
cd minilibx-linux
make
```

For more detailed information on using the MiniLibX library, please refer to the [MiniLibX Documentation](https://harm-smits.github.io/42docs/libs/minilibx).

### Compiling the Project

Compile the project using the Makefile:

```sh
make
```

## Usage

Run the program with a `.fdf` file as an argument:

```sh
./fdf example.fdf
```

### Example

```sh
./fdf 42.fdf
```

## Contributing

Contributions are welcome! Feel free to open issues or submit pull requests.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Acknowledgements

Special thanks to the 42 Network and all the peer reviewers who helped make this project a success.
