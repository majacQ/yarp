/*
 * SPDX-FileCopyrightText: 2006-2021 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: BSD-3-Clause
 */

// Autogenerated by Thrift Compiler (0.14.1-yarped)
//
// This is an automatically generated file.
// It could get re-generated if the ALLOW_IDL_GENERATION flag is on.

#ifndef YARP_THRIFT_GENERATOR_STRUCT_RETURN_GET_LOCATIONS_LIST_H
#define YARP_THRIFT_GENERATOR_STRUCT_RETURN_GET_LOCATIONS_LIST_H

#include <yarp/os/Wire.h>
#include <yarp/os/idl/WireTypes.h>

class return_get_locations_list :
        public yarp::os::idl::WirePortable
{
public:
    // Fields
    bool retval{false};
    std::vector<std::string> locations{};

    // Default constructor
    return_get_locations_list() = default;

    // Constructor with field values
    return_get_locations_list(const bool retval,
                              const std::vector<std::string>& locations);

    // Read structure on a Wire
    bool read(yarp::os::idl::WireReader& reader) override;

    // Read structure on a Connection
    bool read(yarp::os::ConnectionReader& connection) override;

    // Write structure on a Wire
    bool write(const yarp::os::idl::WireWriter& writer) const override;

    // Write structure on a Connection
    bool write(yarp::os::ConnectionWriter& connection) const override;

    // Convert to a printable string
    std::string toString() const;

    // If you want to serialize this class without nesting, use this helper
    typedef yarp::os::idl::Unwrapped<return_get_locations_list> unwrapped;

    class Editor :
            public yarp::os::Wire,
            public yarp::os::PortWriter
    {
    public:
        // Editor: default constructor
        Editor();

        // Editor: constructor with base class
        Editor(return_get_locations_list& obj);

        // Editor: destructor
        ~Editor() override;

        // Editor: Deleted constructors and operator=
        Editor(const Editor& rhs) = delete;
        Editor(Editor&& rhs) = delete;
        Editor& operator=(const Editor& rhs) = delete;
        Editor& operator=(Editor&& rhs) = delete;

        // Editor: edit
        bool edit(return_get_locations_list& obj, bool dirty = true);

        // Editor: validity check
        bool isValid() const;

        // Editor: state
        return_get_locations_list& state();

        // Editor: start editing
        void start_editing();

#ifndef YARP_NO_DEPRECATED // Since YARP 3.2
        YARP_DEPRECATED_MSG("Use start_editing() instead")
        void begin()
        {
            start_editing();
        }
#endif // YARP_NO_DEPRECATED

        // Editor: stop editing
        void stop_editing();

#ifndef YARP_NO_DEPRECATED // Since YARP 3.2
        YARP_DEPRECATED_MSG("Use stop_editing() instead")
        void end()
        {
            stop_editing();
        }
#endif // YARP_NO_DEPRECATED

        // Editor: retval field
        void set_retval(const bool retval);
        bool get_retval() const;
        virtual bool will_set_retval();
        virtual bool did_set_retval();

        // Editor: locations field
        void set_locations(const std::vector<std::string>& locations);
        void set_locations(size_t index, const std::string& elem);
        const std::vector<std::string>& get_locations() const;
        virtual bool will_set_locations();
        virtual bool did_set_locations();

        // Editor: clean
        void clean();

        // Editor: read
        bool read(yarp::os::ConnectionReader& connection) override;

        // Editor: write
        bool write(yarp::os::ConnectionWriter& connection) const override;

    private:
        // Editor: state
        return_get_locations_list* obj;
        bool obj_owned;
        int group;

        // Editor: dirty variables
        bool is_dirty;
        bool is_dirty_retval;
        bool is_dirty_locations;
        int dirty_count;

        // Editor: send if possible
        void communicate();

        // Editor: mark dirty overall
        void mark_dirty();

        // Editor: mark dirty single fields
        void mark_dirty_retval();
        void mark_dirty_locations();

        // Editor: dirty_flags
        void dirty_flags(bool flag);
    };

private:
    // read/write retval field
    bool read_retval(yarp::os::idl::WireReader& reader);
    bool write_retval(const yarp::os::idl::WireWriter& writer) const;
    bool nested_read_retval(yarp::os::idl::WireReader& reader);
    bool nested_write_retval(const yarp::os::idl::WireWriter& writer) const;

    // read/write locations field
    bool read_locations(yarp::os::idl::WireReader& reader);
    bool write_locations(const yarp::os::idl::WireWriter& writer) const;
    bool nested_read_locations(yarp::os::idl::WireReader& reader);
    bool nested_write_locations(const yarp::os::idl::WireWriter& writer) const;
};

#endif // YARP_THRIFT_GENERATOR_STRUCT_RETURN_GET_LOCATIONS_LIST_H
