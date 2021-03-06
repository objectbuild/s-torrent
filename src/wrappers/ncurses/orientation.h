#ifndef ORIENTATION_GUARD
#define ORIENTATION_GUARD

#include <memory>

#include "window.h"
#include "element.h"

namespace ncurses
{
    // The Orientation interface is needed to make writing of orientation ( horizontal, vertical )
    // agnostic layouts possible
    // The naming scheme is actually quite simple:
    // The primary value represents the that most of the layouts computation will use
    //
    // for exapmle for Vertical:
    //      primary_coordinate: y
    //      primary_length: height
    class Orientation
    {
        public:
            Orientation () = default;

            virtual int get_primary_coordinate ( std::shared_ptr < Window > target ) const = 0;
            virtual int get_primary_coordinate ( std::shared_ptr < Window_dummy > target ) const = 0;
            virtual int get_secondary_coordinate ( std::shared_ptr < Window > target ) const = 0;
            virtual int get_secondary_coordinate ( std::shared_ptr < Window_dummy > target ) const = 0;

            virtual int get_primary_length ( std::shared_ptr < Window > target ) const = 0;
            virtual int get_primary_length ( std::shared_ptr < Window_dummy > target ) const = 0;
            virtual int get_secondary_length ( std::shared_ptr < Window > target ) const = 0;
            virtual int get_secondary_length ( std::shared_ptr < Window_dummy > target ) const = 0;

            virtual void set_primary_coordinate ( std::shared_ptr < Window_dummy > target, int value ) const = 0;
            virtual void set_secondary_coordinate ( std::shared_ptr < Window_dummy > target, int value ) const = 0;
            virtual void set_primary_length ( std::shared_ptr < Window_dummy > target, int value ) const = 0;
            virtual void set_secondary_length ( std::shared_ptr < Window_dummy > target, int value ) const = 0;

            virtual int get_prefered_length ( std::shared_ptr < Element > target ) const = 0;

            virtual ~Orientation () noexcept = default;
    };

    class Vertical : public Orientation
    {
        public:

            virtual int get_primary_coordinate ( std::shared_ptr < Window > target ) const
                { return target->get_y (); }
            virtual int get_primary_coordinate ( std::shared_ptr < Window_dummy > target ) const
                { return target->y; }
            virtual int get_secondary_coordinate ( std::shared_ptr < Window > target ) const
                { return target->get_x (); }
            virtual int get_secondary_coordinate ( std::shared_ptr < Window_dummy > target ) const
                { return target->x; }

            virtual int get_primary_length ( std::shared_ptr < Window > target ) const
                { return target->get_height (); }
            virtual int get_primary_length ( std::shared_ptr < Window_dummy > target ) const
                { return target->height; }
            virtual int get_secondary_length ( std::shared_ptr < Window > target ) const
                { return target->get_width (); }
            virtual int get_secondary_length ( std::shared_ptr < Window_dummy > target ) const
                { return target->width; }

            virtual void set_primary_coordinate ( std::shared_ptr < Window_dummy > target, int value ) const
                { target->y = value; }
            virtual void set_secondary_coordinate ( std::shared_ptr < Window_dummy > target, int value ) const
                { target->x = value; }
            virtual void set_primary_length ( std::shared_ptr < Window_dummy > target, int value ) const
                { target->height = value; }
            virtual void set_secondary_length ( std::shared_ptr < Window_dummy > target, int value ) const
                { target->width = value; }

            virtual int get_prefered_length ( std::shared_ptr < Element > target ) const
                { return target->get_prefered_height (); }

            virtual ~Vertical () noexcept = default;
    };

    class Horizontal : public Orientation
    {
        public:

            virtual int get_primary_coordinate ( std::shared_ptr < Window > target ) const
                { return target->get_x (); }
            virtual int get_primary_coordinate ( std::shared_ptr < Window_dummy > target ) const
                { return target->x; }
            virtual int get_secondary_coordinate ( std::shared_ptr < Window > target ) const
                { return target->get_y (); }
            virtual int get_secondary_coordinate ( std::shared_ptr < Window_dummy > target ) const
                { return target->y; }

            virtual int get_primary_length ( std::shared_ptr < Window > target ) const
                { return target->get_width (); }
            virtual int get_primary_length ( std::shared_ptr < Window_dummy > target ) const
                { return target->width; }
            virtual int get_secondary_length ( std::shared_ptr < Window > target ) const
                { return target->get_height (); }
            virtual int get_secondary_length ( std::shared_ptr < Window_dummy > target ) const
                { return target->height; }

            virtual void set_primary_coordinate ( std::shared_ptr < Window_dummy > target, int value ) const
                { target->x = value; }
            virtual void set_secondary_coordinate ( std::shared_ptr < Window_dummy > target, int value ) const
                { target->y = value; }
            virtual void set_primary_length ( std::shared_ptr < Window_dummy > target, int value ) const
                { target->width = value; }
            virtual void set_secondary_length ( std::shared_ptr < Window_dummy > target, int value ) const
                { target->height = value; }

            virtual int get_prefered_length ( std::shared_ptr < Element > target ) const
                { return target->get_prefered_width (); }

            virtual ~Horizontal () noexcept = default;
    };
}

#endif
