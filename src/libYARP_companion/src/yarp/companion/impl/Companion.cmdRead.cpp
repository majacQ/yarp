/*
 * SPDX-FileCopyrightText: 2006-2021 Istituto Italiano di Tecnologia (IIT)
 * SPDX-FileCopyrightText: 2006-2010 RobotCub Consortium
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <yarp/companion/impl/Companion.h>
#include <yarp/companion/impl/BottleReader.h>
#include <yarp/os/ContactStyle.h>
#include <yarp/os/Network.h>
#include <yarp/os/LogStream.h>

#include <cstring>

using yarp::companion::impl::Companion;
using yarp::companion::impl::BottleReader;
using yarp::os::ContactStyle;
using yarp::os::NetworkBase;


/**
 * Create a port to read Bottles and prints them to standard input.
 * It assumes the Bottles consist of an integer followed by a string.
 * The integer indicates whether the "end-of-file" has been reached.
 * The string is what gets printed.
 * @param name the name which which to register the port
 * @param src name of a port to connect from, if any
 * @param showEnvelope set to true if you want envelope information shown
 * @param trim number of characters of the string that should be printed
 * @return 0 on success, non-zero on failure
 */
int Companion::read(const char *name, const char *src, Companion::showEnvelopeEnum showEnvelope, bool justOnce, int trim)
{
    Companion::installHandler();
    BottleReader reader;
    applyArgs(reader.core);
    reader.open(name, showEnvelope, justOnce, trim);
    if (src != nullptr) {
        ContactStyle style;
        style.quiet = false;
        style.verboseOnSuccess = false;
        NetworkBase::connect(src, reader.getName(), style);
    }
    reader.wait();
    reader.close();
    return 0;
}



int Companion::cmdRead(int argc, char *argv[])
{
    if (argc<1) {
        yCError(COMPANION, "Usage:");
        yCError(COMPANION, "  yarp read <port> [remote port] [envelope] [trim [length]] [once]");
        return 1;
    }

    const char *name = argv[0];
    const char *src = nullptr;
    showEnvelopeEnum showEnvelope = showEnvelopeEnum::do_not_show;
    size_t trim = -1;
    bool justOnce = false;
    bool envelopeInline = true;
    while (argc>1) {
        if (strcmp(argv[1], "envelope") == 0) {
            showEnvelope = showEnvelopeEnum::show_inline;
        } else if (strcmp(argv[1], "envelope2") == 0) {
            showEnvelope = showEnvelopeEnum::show_two_lines;
        } else if (strcmp(argv[1], "trim") == 0) {
            argc--;
            argv++;
            if (argc > 1) {
                trim = atoi(argv[1]);
            } else {
                static constexpr int default_trim = 80;
                trim = default_trim;
            }
        }
        else if (strcmp(argv[1], "once") == 0) {
            justOnce = true;
        }
        else {
            src = argv[1];
        }
        argc--;
        argv++;
    }

    //the following check prevents opening as local port a port which is already registered (and active) on the yarp nameserver
    bool e = NetworkBase::exists(name, true);
    if (e)
    {
        yCError(COMPANION) << "Port"<< name << "already exists! Do you mean yarp read ..."<< name <<"?";
        return 1;
    }
    return read(name, src, showEnvelope, justOnce, trim);
}
