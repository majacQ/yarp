/*
 * SPDX-FileCopyrightText: 2006-2021 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: BSD-3-Clause
 */

// Autogenerated by Thrift Compiler (0.14.1-yarped)
//
// This is an automatically generated file.
// It could get re-generated if the ALLOW_IDL_GENERATION flag is on.

#include <return_get_estimated_poses.h>

// Default constructor
return_get_estimated_poses::return_get_estimated_poses() :
        WirePortable(),
        ret(false),
        poses()
{
}

// Constructor with field values
return_get_estimated_poses::return_get_estimated_poses(const bool ret,
                                                       const std::vector<yarp::dev::Nav2D::Map2DLocation>& poses) :
        WirePortable(),
        ret(ret),
        poses(poses)
{
}

// Read structure on a Wire
bool return_get_estimated_poses::read(yarp::os::idl::WireReader& reader)
{
    if (!read_ret(reader)) {
        return false;
    }
    if (!read_poses(reader)) {
        return false;
    }
    return !reader.isError();
}

// Read structure on a Connection
bool return_get_estimated_poses::read(yarp::os::ConnectionReader& connection)
{
    yarp::os::idl::WireReader reader(connection);
    if (!reader.readListHeader(2)) {
        return false;
    }
    return read(reader);
}

// Write structure on a Wire
bool return_get_estimated_poses::write(const yarp::os::idl::WireWriter& writer) const
{
    if (!write_ret(writer)) {
        return false;
    }
    if (!write_poses(writer)) {
        return false;
    }
    return !writer.isError();
}

// Write structure on a Connection
bool return_get_estimated_poses::write(yarp::os::ConnectionWriter& connection) const
{
    yarp::os::idl::WireWriter writer(connection);
    if (!writer.writeListHeader(2)) {
        return false;
    }
    return write(writer);
}

// Convert to a printable string
std::string return_get_estimated_poses::toString() const
{
    yarp::os::Bottle b;
    b.read(*this);
    return b.toString();
}

// Editor: default constructor
return_get_estimated_poses::Editor::Editor()
{
    group = 0;
    obj_owned = true;
    obj = new return_get_estimated_poses;
    dirty_flags(false);
    yarp().setOwner(*this);
}

// Editor: constructor with base class
return_get_estimated_poses::Editor::Editor(return_get_estimated_poses& obj)
{
    group = 0;
    obj_owned = false;
    edit(obj, false);
    yarp().setOwner(*this);
}

// Editor: destructor
return_get_estimated_poses::Editor::~Editor()
{
    if (obj_owned) {
        delete obj;
    }
}

// Editor: edit
bool return_get_estimated_poses::Editor::edit(return_get_estimated_poses& obj, bool dirty)
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
bool return_get_estimated_poses::Editor::isValid() const
{
    return obj != nullptr;
}

// Editor: state
return_get_estimated_poses& return_get_estimated_poses::Editor::state()
{
    return *obj;
}

// Editor: grouping begin
void return_get_estimated_poses::Editor::start_editing()
{
    group++;
}

// Editor: grouping end
void return_get_estimated_poses::Editor::stop_editing()
{
    group--;
    if (group == 0 && is_dirty) {
        communicate();
    }
}
// Editor: ret setter
void return_get_estimated_poses::Editor::set_ret(const bool ret)
{
    will_set_ret();
    obj->ret = ret;
    mark_dirty_ret();
    communicate();
    did_set_ret();
}

// Editor: ret getter
bool return_get_estimated_poses::Editor::get_ret() const
{
    return obj->ret;
}

// Editor: ret will_set
bool return_get_estimated_poses::Editor::will_set_ret()
{
    return true;
}

// Editor: ret did_set
bool return_get_estimated_poses::Editor::did_set_ret()
{
    return true;
}

// Editor: poses setter
void return_get_estimated_poses::Editor::set_poses(const std::vector<yarp::dev::Nav2D::Map2DLocation>& poses)
{
    will_set_poses();
    obj->poses = poses;
    mark_dirty_poses();
    communicate();
    did_set_poses();
}

// Editor: poses setter (list)
void return_get_estimated_poses::Editor::set_poses(size_t index, const yarp::dev::Nav2D::Map2DLocation& elem)
{
    will_set_poses();
    obj->poses[index] = elem;
    mark_dirty_poses();
    communicate();
    did_set_poses();
}

// Editor: poses getter
const std::vector<yarp::dev::Nav2D::Map2DLocation>& return_get_estimated_poses::Editor::get_poses() const
{
    return obj->poses;
}

// Editor: poses will_set
bool return_get_estimated_poses::Editor::will_set_poses()
{
    return true;
}

// Editor: poses did_set
bool return_get_estimated_poses::Editor::did_set_poses()
{
    return true;
}

// Editor: clean
void return_get_estimated_poses::Editor::clean()
{
    dirty_flags(false);
}

// Editor: read
bool return_get_estimated_poses::Editor::read(yarp::os::ConnectionReader& connection)
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
            if (field == "ret") {
                if (!writer.writeListHeader(1)) {
                    return false;
                }
                if (!writer.writeString("bool ret")) {
                    return false;
                }
            }
            if (field == "poses") {
                if (!writer.writeListHeader(1)) {
                    return false;
                }
                if (!writer.writeString("std::vector<yarp::dev::Nav2D::Map2DLocation> poses")) {
                    return false;
                }
            }
        }
        if (!writer.writeListHeader(3)) {
            return false;
        }
        writer.writeString("*** Available fields:");
        writer.writeString("ret");
        writer.writeString("poses");
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
        if (key == "ret") {
            will_set_ret();
            if (!obj->nested_read_ret(reader)) {
                return false;
            }
            did_set_ret();
        } else if (key == "poses") {
            will_set_poses();
            if (!obj->nested_read_poses(reader)) {
                return false;
            }
            did_set_poses();
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
bool return_get_estimated_poses::Editor::write(yarp::os::ConnectionWriter& connection) const
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
    if (is_dirty_ret) {
        if (!writer.writeListHeader(3)) {
            return false;
        }
        if (!writer.writeString("set")) {
            return false;
        }
        if (!writer.writeString("ret")) {
            return false;
        }
        if (!obj->nested_write_ret(writer)) {
            return false;
        }
    }
    if (is_dirty_poses) {
        if (!writer.writeListHeader(3)) {
            return false;
        }
        if (!writer.writeString("set")) {
            return false;
        }
        if (!writer.writeString("poses")) {
            return false;
        }
        if (!obj->nested_write_poses(writer)) {
            return false;
        }
    }
    return !writer.isError();
}

// Editor: send if possible
void return_get_estimated_poses::Editor::communicate()
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
void return_get_estimated_poses::Editor::mark_dirty()
{
    is_dirty = true;
}

// Editor: ret mark_dirty
void return_get_estimated_poses::Editor::mark_dirty_ret()
{
    if (is_dirty_ret) {
        return;
    }
    dirty_count++;
    is_dirty_ret = true;
    mark_dirty();
}

// Editor: poses mark_dirty
void return_get_estimated_poses::Editor::mark_dirty_poses()
{
    if (is_dirty_poses) {
        return;
    }
    dirty_count++;
    is_dirty_poses = true;
    mark_dirty();
}

// Editor: dirty_flags
void return_get_estimated_poses::Editor::dirty_flags(bool flag)
{
    is_dirty = flag;
    is_dirty_ret = flag;
    is_dirty_poses = flag;
    dirty_count = flag ? 2 : 0;
}

// read ret field
bool return_get_estimated_poses::read_ret(yarp::os::idl::WireReader& reader)
{
    if (!reader.readBool(ret)) {
        ret = 0;
    }
    return true;
}

// write ret field
bool return_get_estimated_poses::write_ret(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeBool(ret)) {
        return false;
    }
    return true;
}

// read (nested) ret field
bool return_get_estimated_poses::nested_read_ret(yarp::os::idl::WireReader& reader)
{
    if (!reader.readBool(ret)) {
        ret = 0;
    }
    return true;
}

// write (nested) ret field
bool return_get_estimated_poses::nested_write_ret(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeBool(ret)) {
        return false;
    }
    return true;
}

// read poses field
bool return_get_estimated_poses::read_poses(yarp::os::idl::WireReader& reader)
{
    poses.clear();
    uint32_t _size4;
    yarp::os::idl::WireState _etype7;
    reader.readListBegin(_etype7, _size4);
    poses.resize(_size4);
    for (size_t _i8 = 0; _i8 < _size4; ++_i8) {
        if (!reader.readNested(poses[_i8])) {
            reader.fail();
            return false;
        }
    }
    reader.readListEnd();
    return true;
}

// write poses field
bool return_get_estimated_poses::write_poses(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeListBegin(BOTTLE_TAG_LIST, static_cast<uint32_t>(poses.size()))) {
        return false;
    }
    for (const auto& _item9 : poses) {
        if (!writer.writeNested(_item9)) {
            return false;
        }
    }
    if (!writer.writeListEnd()) {
        return false;
    }
    return true;
}

// read (nested) poses field
bool return_get_estimated_poses::nested_read_poses(yarp::os::idl::WireReader& reader)
{
    poses.clear();
    uint32_t _size10;
    yarp::os::idl::WireState _etype13;
    reader.readListBegin(_etype13, _size10);
    poses.resize(_size10);
    for (size_t _i14 = 0; _i14 < _size10; ++_i14) {
        if (!reader.readNested(poses[_i14])) {
            reader.fail();
            return false;
        }
    }
    reader.readListEnd();
    return true;
}

// write (nested) poses field
bool return_get_estimated_poses::nested_write_poses(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeListBegin(BOTTLE_TAG_LIST, static_cast<uint32_t>(poses.size()))) {
        return false;
    }
    for (const auto& _item15 : poses) {
        if (!writer.writeNested(_item15)) {
            return false;
        }
    }
    if (!writer.writeListEnd()) {
        return false;
    }
    return true;
}
