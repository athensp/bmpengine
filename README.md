#bmpengine

###A library for editing 24-bit bitmap images.

##Get Started

Once you have the source code,
while in the bmpengine directory

###__Compilation__ (Makefile's parameters)

```
$make
```

###__Run__

```
$./bmpengine
```

###__Commands__

**Display a menu with the available commands**
```
$./bmpengine --help
```

**List the metadata of the chosen bitmap image(s)**
```
$./bmpengine -list img1.bmp img2.bmp ... imgn.bmp
```

**Horizontally flip the chosen bitmap image(s)**
```
$./bmpengine -hflip img1.bmp img2.bmp ... imgn.bmp
```

**Vertically flip the chosen bitmap image(s)**
```
$./bmpengine -vflip img1.bmp img2.bmp ... imgn.bmp
```

**Rotate by 90 degrees to the left the chosen bitmap image(s)**
```
$./bmpengine -left90 img1.bmp img2.bmp ... imgn.bmp
```

**Rotate by 90 degrees to the right the chosen bitmap image(s)**
```
$./bmpengine -right90 img1.bmp img2.bmp ... imgn.bmp
```

**Transform into grayscale the chosen bitmap image(s)**
```
$./bmpengine -gray img1.bmp img2.bmp ... imgn.bmp
```

###__Clean__ (Object files)
```
$make clean
```
