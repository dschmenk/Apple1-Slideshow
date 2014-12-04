Apple1-Slideshow
================

ASCII art slideshow for Apple 1 (as seen on most Apple 1 auctions)

Build Process
-------------

The build process isn't automated, so you have to run the cross assembler by hand. The assembler used is the xa 6502 assembler:

http://www.floodgap.com/retrotech/xa/

Many Linux distros will have the xa65 package available.

Once installed, build the binary with:
```
xa slideshow.a65
```
A binary, a.o65, will be produced. This can by massaged into the Apple 1 monitor format by compiling and running:
```
bintomon 280 a.o65 > slideshow.mon
```
The starting address is $280 (in 6502 hex nomenclature, 0x280 in C syntax). The resultant file, slideshow.mon, can be pasted into an emulator or copied to a real Apple 1, clone, or replica if you have the keyboard/serial port adapter.

Creating Other Artwork
----------------------

To use different artwork, You have to go through a bit of a process to get the artwork into a compatible format. Using a program like PhotoShop or The Gimp, change the image to 8 bit greyscale, then resize the image to 40x23 pixels. Save it is a net PBM file (.pbm). Convert the PBM to a RLE format with the converter:
```
pbmtorle < image.pbm > image.rle
```

You have to edit the source code to use the appropriate rle file and give it a caption. The caption string is prepended with the length, so make sure it matches. When you rebuild the binary, the resultant file has to be 3456 bytes or less, assuming you want it to run on a minimal 4K Apple 1. If you have more contiguous memory, then you can fill 'er up.

Viewing RLE ASCII Artwork
-------------------------

You can view the converted ASCII artwork in your terminal by running:
```
dumprle image.rle
```

Dave...
