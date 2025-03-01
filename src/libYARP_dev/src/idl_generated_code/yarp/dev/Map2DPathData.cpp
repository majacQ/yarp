/*
 * SPDX-FileCopyrightText: 2006-2021 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: BSD-3-Clause
 */

// Autogenerated by Thrift Compiler (0.14.1-yarped)
//
// This is an automatically generated file.
// It could get re-generated if the ALLOW_IDL_GENERATION flag is on.

#include <yarp/dev/Map2DPathData.h>

namespace yarp::dev {

// Constructor with field values
Map2DPathData::Map2DPathData(const std::vector<yarp::dev::Nav2D::Map2DLocation>& waypoints,
                             const std::string& description) :
        WirePortable(),
        waypoints(waypoints),
        description(description)
{
}

// Read structure on a Wire
bool Map2DPathData::read(yarp::os::idl::WireReader& reader)
{
    if (!read_waypoints(reader)) {
        return false;
    }
    if (!read_description(reader)) {
        return false;
    }
    return !reader.isError();
}

// Read structure on a Connection
bool Map2DPathData::read(yarp::os::ConnectionReader& connection)
{
    yarp::os::idl::WireReader reader(connection);
    if (!reader.readListHeader(2)) {
        return false;
    }
    return read(reader);
}

// Write structure on a Wire
bool Map2DPathData::write(const yarp::os::idl::WireWriter& writer) const
{
    if (!write_waypoints(writer)) {
        return false;
    }
    if (!write_description(writer)) {
        return false;
    }
    return !writer.isError();
}

// Write structure on a Connection
bool Map2DPathData::write(yarp::os::ConnectionWriter& connection) const
{
    yarp::os::idl::WireWriter writer(connection);
    if (!writer.writeListHeader(2)) {
        return false;
    }
    return write(writer);
}

// Convert to a printable string
std::string Map2DPathData::toString() const
{
    yarp::os::Bottle b;
    b.read(*this);
    return b.toString();
}

// Editor: default constructor
Map2DPathData::Editor::Editor()
{
    group = 0;
    obj_owned = true;
    obj = new Map2DPathData;
    dirty_flags(false);
    yarp().setOwner(*this);
}

// Editor: constructor with base class
Map2DPathData::Editor::Editor(Map2DPathData& obj)
{
    group = 0;
    obj_owned = false;
    edit(obj, false);
    yarp().setOwner(*this);
}

// Editor: destructor
Map2DPathData::Editor::~Editor()
{
    if (obj_owned) {
        delete obj;
    }
}

// Editor: edit
bool Map2DPathData::Editor::edit(Map2DPathData& obj, bool dirty)
{
    if (obj_owned) {
        delete this->obj;
    }
    this->obj = &obj;
    obj_owned = false;
    dirty_flags(dirty);
    return true;
}

// Editor: validity check
bool Map2DPathData::Editor::isValid() const
{
    return obj != nullptr;
}

// Editor: state
Map2DPathData& Map2DPathData::Editor::state()
{
    return *obj;
}

// Editor: grouping begin
void Map2DPathData::Editor::start_editing()
{
    group++;
}

// Editor: grouping end
void Map2DPathData::Editor::stop_editing()
{
    group--;
    if (group == 0 && is_dirty) {
        communicate();
    }
}
// Editor: waypoints setter
void Map2DPathData::Editor::set_waypoints(const std::vector<yarp::dev::Nav2D::Map2DLocation>& waypoints)
{
    will_set_waypoints();
    obj->waypoints = waypoints;
    mark_dirty_waypoints();
    communicate();
    did_set_waypoints();
}

// Editor: waypoints setter (list)
void Map2DPathData::Editor::set_waypoints(size_t index, const yarp::dev::Nav2D::Map2DLocation& elem)
{
    will_set_waypoints();
    obj->waypoints[index] = elem;
    mark_dirty_waypoints();
    communicate();
    did_set_waypoints();
}

// Editor: waypoints getter
const std::vector<yarp::dev::Nav2D::Map2DLocation>& Map2DPathData::Editor::get_waypoints() const
{
    return obj->waypoints;
}

// Editor: waypoints will_set
bool Map2DPathData::Editor::will_set_waypoints()
{
    return true;
}

// Editor: waypoints did_set
bool Map2DPathData::Editor::did_set_waypoints()
{
    return true;
}

// Editor: description setter
void Map2DPathData::Editor::set_description(const std::string& description)
{
    will_set_description();
    obj->description = description;
    mark_dirty_description();
    communicate();
    did_set_description();
}

// Editor: description getter
const std::string& Map2DPathData::Editor::get_description() const
{
    return obj->description;
}

// Editor: description will_set
bool Map2DPathData::Editor::will_set_description()
{
    return true;
}

// Editor: description did_set
bool Map2DPathData::Editor::did_set_description()
{
    return true;
}

// Editor: clean
void Map2DPathData::Editor::clean()
{
    dirty_flags(false);
}

// Editor: read
bool Map2DPathData::Editor::read(yarp::os::ConnectionReader& connection)
{
    if (!isValid()) {
        return false;
    }
    yarp::os::idl::WireReader reader(connection);
    reader.expectAccept();
    if (!reader.readListHeader()) {
        return false;
    }
    int len = reader.getLength();
    if (len == 0) {
        yarp::os::idl::WireWriter writer(reader);
        if (writer.isNull()) {
            return true;
        }
        if (!writer.writeListHeader(1)) {
            return false;
        }
        writer.writeString("send: 'help' or 'patch (param1 val1) (param2 val2)'");
        return true;
    }
    std::string tag;
    if (!reader.readString(tag)) {
        return false;
    }
    if (tag == "help") {
        yarp::os::idl::WireWriter writer(reader);
        if (writer.isNull()) {
            return true;
        }
        if (!writer.writeListHeader(2)) {
            return false;
        }
        if (!writer.writeTag("many", 1, 0)) {
            return false;
        }
        if (reader.getLength() > 0) {
            std::string field;
            if (!reader.readString(field)) {
                return false;
            }
            if (field == "waypoints") {
                if (!writer.writeListHeader(2)) {
                    return false;
                }
                if (!writer.writeString("std::vector<yarp::dev::Nav2D::Map2DLocation> waypoints")) {
                    return false;
                }
                if (!writer.writeString("list of waypoints which define the path")) {
                    return false;
                }
            }
            if (field == "description") {
                if (!writer.writeListHeader(2)) {
                    return false;
                }
                if (!writer.writeString("std::string description")) {
                    return false;
                }
                if (!writer.writeString("user defined string")) {
                    return false;
                }
            }
        }
        if (!writer.writeListHeader(3)) {
            return false;
        }
        writer.writeString("*** Available fields:");
        writer.writeString("waypoints");
        writer.writeString("description");
        return true;
    }
    bool nested = true;
    bool have_act = false;
    if (tag != "patch") {
        if (((len - 1) % 2) != 0) {
            return false;
        }
        len = 1 + ((len - 1) / 2);
        nested = false;
        have_act = true;
    }
    for (int i = 1; i < len; ++i) {
        if (nested && !reader.readListHeader(3)) {
            return false;
        }
        std::string act;
        std::string key;
        if (have_act) {
            act = tag;
        } else if (!reader.readString(act)) {
            return false;
        }
        if (!reader.readString(key)) {
            return false;
        }
        if (key == "waypoints") {
            will_set_waypoints();
            if (!obj->nested_read_waypoints(reader)) {
                return false;
            }
            did_set_waypoints();
        } else if (key == "description") {
            will_set_description();
            if (!obj->nested_read_description(reader)) {
                return false;
            }
            did_set_description();
        } else {
            // would be useful to have a fallback here
        }
    }
    reader.accept();
    yarp::os::idl::WireWriter writer(reader);
    if (writer.isNull()) {
        return true;
    }
    writer.writeListHeader(1);
    writer.writeVocab32('o', 'k');
    return true;
}

// Editor: write
bool Map2DPathData::Editor::write(yarp::os::ConnectionWriter& connection) const
{
    if (!isValid()) {
        return false;
    }
    yarp::os::idl::WireWriter writer(connection);
    if (!writer.writeListHeader(dirty_count + 1)) {
        return false;
    }
    if (!writer.writeString("patch")) {
        return false;
    }
    if (is_dirty_waypoints) {
        if (!writer.writeListHeader(3)) {
            return false;
        }
        if (!writer.writeString("set")) {
            return false;
        }
        if (!writer.writeString("waypoints")) {
            return false;
        }
        if (!obj->nested_write_waypoints(writer)) {
            return false;
        }
    }
    if (is_dirty_description) {
        if (!writer.writeListHeader(3)) {
            return false;
        }
        if (!writer.writeString("set")) {
            return false;
        }
        if (!writer.writeString("description")) {
            return false;
        }
        if (!obj->nested_write_description(writer)) {
            return false;
        }
    }
    return !writer.isError();
}

// Editor: send if possible
void Map2DPathData::Editor::communicate()
{
    if (group != 0) {
        return;
    }
    if (yarp().canWrite()) {
        yarp().write(*this);
        clean();
    }
}

// Editor: mark dirty overall
void Map2DPathData::Editor::mark_dirty()
{
    is_dirty = true;
}

// Editor: waypoints mark_dirty
void Map2DPathData::Editor::mark_dirty_waypoints()
{
    if (is_dirty_waypoints) {
        return;
    }
    dirty_count++;
    is_dirty_waypoints = true;
    mark_dirty();
}

// Editor: description mark_dirty
void Map2DPathData::Editor::mark_dirty_description()
{
    if (is_dirty_description) {
        return;
    }
    dirty_count++;
    is_dirty_description = true;
    mark_dirty();
}

// Editor: dirty_flags
void Map2DPathData::Editor::dirty_flags(bool flag)
{
    is_dirty = flag;
    is_dirty_waypoints = flag;
    is_dirty_description = flag;
    dirty_count = flag ? 2 : 0;
}

// read waypoints field
bool Map2DPathData::read_waypoints(yarp::os::idl::WireReader& reader)
{
    if (reader.noMore()) {
        reader.fail();
        return false;
    }
    waypoints.clear();
    uint32_t _size0;
    yarp::os::idl::WireState _etype3;
    reader.readListBegin(_etype3, _size0);
    waypoints.resize(_size0);
    for (size_t _i4 = 0; _i4 < _size0; ++_i4) {
        if (reader.noMore()) {
            reader.fail();
            return false;
        }
        if (!reader.readNested(waypoints[_i4])) {
            reader.fail();
            return false;
        }
    }
    reader.readListEnd();
    return true;
}

// write waypoints field
bool Map2DPathData::write_waypoints(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeListBegin(BOTTLE_TAG_LIST, static_cast<uint32_t>(waypoints.size()))) {
        return false;
    }
    for (const auto& _item5 : waypoints) {
        if (!writer.writeNested(_item5)) {
            return false;
        }
    }
    if (!writer.writeListEnd()) {
        return false;
    }
    return true;
}

// read (nested) waypoints field
bool Map2DPathData::nested_read_waypoints(yarp::os::idl::WireReader& reader)
{
    if (reader.noMore()) {
        reader.fail();
        return false;
    }
    waypoints.clear();
    uint32_t _size6;
    yarp::os::idl::WireState _etype9;
    reader.readListBegin(_etype9, _size6);
    waypoints.resize(_size6);
    for (size_t _i10 = 0; _i10 < _size6; ++_i10) {
        if (reader.noMore()) {
            reader.fail();
            return false;
        }
        if (!reader.readNested(waypoints[_i10])) {
            reader.fail();
            return false;
        }
    }
    reader.readListEnd();
    return true;
}

// write (nested) waypoints field
bool Map2DPathData::nested_write_waypoints(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeListBegin(BOTTLE_TAG_LIST, static_cast<uint32_t>(waypoints.size()))) {
        return false;
    }
    for (const auto& _item11 : waypoints) {
        if (!writer.writeNested(_item11)) {
            return false;
        }
    }
    if (!writer.writeListEnd()) {
        return false;
    }
    return true;
}

// read description field
bool Map2DPathData::read_description(yarp::os::idl::WireReader& reader)
{
    if (reader.noMore()) {
        reader.fail();
        return false;
    }
    if (!reader.readString(description)) {
        reader.fail();
        return false;
    }
    return true;
}

// write description field
bool Map2DPathData::write_description(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeString(description)) {
        return false;
    }
    return true;
}

// read (nested) description field
bool Map2DPathData::nested_read_description(yarp::os::idl::WireReader& reader)
{
    if (reader.noMore()) {
        reader.fail();
        return false;
    }
    if (!reader.readString(description)) {
        reader.fail();
        return false;
    }
    return true;
}

// write (nested) description field
bool Map2DPathData::nested_write_description(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeString(description)) {
        return false;
    }
    return true;
}

} // namespace yarp::dev
