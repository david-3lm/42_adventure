
This document provides an overview of the functions available in the MiniLibX library.

# Table of Contents 
- [Initialization](#initialization) 
- [Window Management](#window-management) 
- [Image Functions](#image-functions) 
- [Event Handling](#event-handling) 
- [Keyboard and Mouse Control](#keyboard-and-mouse-control) 
- [Screen Management](#screen-management)]]

## Initialization
```c
void *mlx_init()
```

> **Description:** Initializes the MiniLibX library. This function must be called before any other MiniLibX functions.  
> **Returns:**  
> - Pointer to the initialized library object, or `NULL` on failure.

## Window Management

```c
void *mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title)
```

> **Description:** Creates a new window.  
> **Parameters:**  
> - `mlx_ptr`: Pointer to the initialized MiniLibX object.  
> - `size_x`: Width of the window.  
> - `size_y`: Height of the window.  
> - `title`: Title of the window.  
> **Returns:**  
> - Pointer to the created window object, or `NULL` on failure.

```c 
int mlx_clear_window(void *mlx_ptr, void *win_ptr)
```

> **Description:** Clears the content of the window.  
> **Parameters:**  
> - `mlx_ptr`: Pointer to the initialized MiniLibX object.  
> - `win_ptr`: Pointer to the window to clear.  
> **Returns:**  
> - `int`: Status code indicating success or failure.

```c
int mlx_destroy_window(void *mlx_ptr, void *win_ptr)
```

> **Description:** Destroys the specified window.  
> **Parameters:**  
> - `mlx_ptr`: Pointer to the initialized MiniLibX object.  
> - `win_ptr`: Pointer to the window to destroy.  
> **Returns:**  
> - `int`: Status code indicating success or failure.

## Drawing Functions

```c
int mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color)
```

> **Description:** Draws a pixel on the window at the specified coordinates.  
> **Parameters:**  
> - `mlx_ptr`: Pointer to the initialized MiniLibX object.  
> - `win_ptr`: Pointer to the window.  
> - `x`: X coordinate of the pixel.  
> - `y`: Y coordinate of the pixel.  
> - `color`: Color of the pixel in `0x00RRGGBB` format.  
> **Returns:**  
> - `int`: Status code indicating success or failure.

```c
int mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string)
```

> **Description:** Displays a string on the window at the specified coordinates.  
> **Parameters:**  
> - `mlx_ptr`: Pointer to the initialized MiniLibX object.  
> - `win_ptr`: Pointer to the window.  
> - `x`: X coordinate of the string.  
> - `y`: Y coordinate of the string.  
> - `color`: Color of the string in `0x00RRGGBB` format.  
> - `string`: The string to display.  
> **Returns:**  
> - `int`: Status code indicating success or failure.

```c
void mlx_set_font(void *mlx_ptr, void *win_ptr, char *name)
```

> **Description:** Sets the font for displaying text on the window.  
> **Parameters:**  
> - `mlx_ptr`: Pointer to the initialized MiniLibX object.  
> - `win_ptr`: Pointer to the window.  
> - `name`: Name of the font to use.  
> **Returns:**  
> - `void`

## Image Functions

```c
void *mlx_new_image(void *mlx_ptr, int width, int height)
```

> **Description:** Creates a new image with the specified dimensions.  
> **Parameters:**  
> - `mlx_ptr`: Pointer to the initialized MiniLibX object.  
> - `width`: Width of the image.  
> - `height`: Height of the image.  
> **Returns:**  
> - Pointer to the created image object, or `NULL` on failure.

```c
char *mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian)
```

> **Description:** Gets the address of the image data and additional information.  
> **Parameters:**  
> - `img_ptr`: Pointer to the image object.  
> - `bits_per_pixel`: Pointer to an integer to store the number of bits per pixel.  
> - `size_line`: Pointer to an integer to store the size of each line in bytes.  
> - `endian`: Pointer to an integer to store the endianess (0 = little endian, 1 = big endian).  
> **Returns:**  
> - Pointer to the image data address.

```c
int mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y)
```

> **Description:** Displays an image in a window at the specified coordinates.  
> **Parameters:**  
> - `mlx_ptr`: Pointer to the initialized MiniLibX object.  
> - `win_ptr`: Pointer to the window.  
> - `img_ptr`: Pointer to the image to display.  
> - `x`: X coordinate to display the image.  
> - `y`: Y coordinate to display the image.  
> **Returns:**  
> - `int`: Status code indicating success or failure.

```c
void *mlx_xpm_to_image(void *mlx_ptr, char **xpm_data, int *width, int *height)
```

> **Description:** Converts XPM data to an image.  
> **Parameters:**  
> - `mlx_ptr`: Pointer to the initialized MiniLibX object.  
> - `xpm_data`: XPM data.  
> - `width`: Pointer to an integer to store the width of the image.  
> - `height`: Pointer to an integer to store the height of the image.  
> **Returns:**  
> - Pointer to the created image object, or `NULL` on failure.

```c
void *mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width, int *height)
```

> **Description:** Loads an XPM file and converts it to an image.  
> **Parameters:**  
> - `mlx_ptr`: Pointer to the initialized MiniLibX object.  
> - `filename`: Path to the XPM file.  
> - `width`: Pointer to an integer to store the width of the image.  
> - `height`: Pointer to an integer to store the height of the image.  
> **Returns:**  
> - Pointer to the created image object, or `NULL` on failure.

```c
int mlx_destroy_image(void *mlx_ptr, void *img_ptr)
```

> **Description:** Destroys the specified image.  
> **Parameters:**  
> - `mlx_ptr`: Pointer to the initialized MiniLibX object.  
> - `img_ptr`: Pointer to the image to destroy.  
> **Returns:**  
> - `int`: Status code indicating success or failure.

## Event Handling

```c
int mlx_mouse_hook(void *win_ptr, int (*funct_ptr)(), void *param)
```

> **Description:** Sets a function to be called when a mouse event occurs.  
> **Parameters:**  
> - `win_ptr`: Pointer to the window.  
> - `funct_ptr`: Pointer to the function to call.  
> - `param`: Pointer to a parameter passed to the function.  
> **Returns:**  
> - `int`: Status code indicating success or failure.

```c
int mlx_key_hook(void *win_ptr, int (*funct_ptr)(), void *param)
```

> **Description:** Sets a function to be called when a key event occurs.  
> **Parameters:**  
> - `win_ptr`: Pointer to the window.  
> - `funct_ptr`: Pointer to the function to call.  
> - `param`: Pointer to a parameter passed to the function.  
> **Returns:**  
> - `int`: Status code indicating success or failure.

```c
int mlx_expose_hook(void *win_ptr, int (*funct_ptr)(), void *param)
```

> **Description:** Sets a function to be called when the window is exposed.  
> **Parameters:**  
> - `win_ptr`: Pointer to the window.  
> - `funct_ptr`: Pointer to the function to call.  
> - `param`: Pointer to a parameter passed to the function.  
> **Returns:**  
> - `int`: Status code indicating success or failure.

```c
int mlx_loop_hook(void *mlx_ptr, int (*funct_ptr)(), void *param)
```

> **Description:** Sets a function to be called continuously during the loop.  
> **Parameters:**  
> - `mlx_ptr`: Pointer to the initialized MiniLibX object.  
> - `funct_ptr`: Pointer to the function to call.  
> - `param`: Pointer to a parameter passed to the function.  
> **Returns:**  
> - `int`: Status code indicating success or failure.

```c
int mlx_loop(void *mlx_ptr)
```

> **Description:** Starts the event loop, processing events until `mlx_loop_end()` is called.  
> **Parameters:**  
> - `mlx_ptr`: Pointer to the initialized MiniLibX object.  
> **Returns:**  
> - `int`: Status code indicating success or failure.

```c
int mlx_loop_end(void *mlx_ptr)
```

> **Description:** Ends the event loop, stopping the processing of events.  
> **Parameters:**  
> - `mlx_ptr`: Pointer to the initialized MiniLibX object.  
> **Returns:**  
> - `int`: Status code indicating success or failure.

## Screen Size

```c
int mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey)
```

> **Description:** Gets the size of the screen.  
> **Parameters:**  
> - `mlx_ptr`: Pointer to the initialized MiniLibX object.  
> - `sizex`: Pointer to an integer to store the screen width.  
> - `sizey`: Pointer to an integer to store the screen height.  
> **Returns:**  
> - `int`: Status code indicating success or failure.
