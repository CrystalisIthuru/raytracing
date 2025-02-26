program hello

    use RGBImage

    implicit none

    type(RGBImage_T) :: simple_image;

    simple_image = RGBImage_T(3, 2)
    simple_image%image(1, 1) = int(z'FF0000')
    simple_image%image(1, 2) = int(z'00FF00')
    simple_image%image(1, 3) = int(z'0000FF')
    simple_image%image(2, 1) = int(z'FFFF00')
    simple_image%image(2, 2) = int(z'FFFFFF')
    call simple_image%writePPM("out.ppm")

end program hello