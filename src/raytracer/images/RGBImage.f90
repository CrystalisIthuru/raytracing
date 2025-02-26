module RGBImage

    implicit none
    private

    type :: RGBImage_T
        integer, dimension(:, :), allocatable :: image
        integer :: image_height
        integer :: image_width
    contains
        procedure, public :: writePPM => RGBImage_writePPM
        final :: destroy_RGBImage
    end type

    interface RGBImage_T
        module procedure new_RGBImage
    end interface RGBImage_T

    public RGBImage_T

contains

    function new_RGBImage(image_width, image_height) result(this)

        integer, intent(in) :: image_width
        integer, intent(in) :: image_height
        type(RGBImage_T) :: this

        allocate(this%image(image_height, image_width))
        this%image(:, :) = 0
        this%image_height = image_height
        this%image_width = image_width

    end function new_RGBImage

    subroutine destroy_RGBImage(this)

        type(RGBImage_T), intent(inout) :: this

        if(allocated(this%image)) then
            deallocate(this%image)
        end if
        
    end subroutine destroy_RGBImage

    subroutine RGBImage_writePPM(this, fp)

        class(RGBImage_T), intent(in) :: this
        character(*), intent(in) :: fp
        integer :: unit, i, j, r, g, b

        100 FORMAT(3I5) ! PPM Formatting

        open(newunit = unit, file = fp, status = "replace", action = "write")
        write(unit, "(A2)") "P3"
        write(unit, *) this%image_width, this%image_height
        write(unit, *) "255"

        do i = 1, this%image_height
            do j = 1, this%image_width
                r = RSHIFT(IAND(this%image(i, j), z'FF0000'), 16)
                g = RSHIFT(IAND(this%image(i, j), z'00FF00'), 8)
                b = RSHIFT(IAND(this%image(i, j), z'0000FF'), 0)
                write(unit, "(I3XI3XI3)", advance = "no") r, g, b
            end do
            write(unit, *) ""
        end do

        close(unit)

    end subroutine RGBImage_writePPM

end module RGBImage