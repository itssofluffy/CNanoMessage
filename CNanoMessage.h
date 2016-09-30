/*
    CNanoMessage.h

    Copyright (c) 2016 Stephen Whittle  All rights reserved.

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation
    the rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom
    the Software is furnished to do so, subject to the following conditions:
    The above copyright notice and this permission notice shall be included
    in all copies or substantial portions of the Software.
    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
    THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
    IN THE SOFTWARE.
*/

#include <nanomsg/nn.h>

// protocols
#include <nanomsg/pair.h>
#include <nanomsg/reqrep.h>
#include <nanomsg/pubsub.h>
#include <nanomsg/survey.h>
#include <nanomsg/pipeline.h>
#include <nanomsg/bus.h>

// transport mechanisms
#include <nanomsg/inproc.h>
#include <nanomsg/ipc.h>
#include <nanomsg/tcp.h>
#include <nanomsg/ws.h>

// The following #if...#else...#endif's are used to valid and redefine some
// required #defines, these where originally defined as complex macros in
// the above header files and so can be evaluated but not passed by the preprocessor.
#if NN_PROTO_PAIR == 1
#    if NN_PAIR == 16
#        define NN_PAIR 16
#    else
#        error "NN_PAIR is undefined or is a different value than expected."
#    endif
#else
#    error "NN_PROTO_PAIR is undefined or is a different value than expected."
#endif

#if NN_PROTO_PUBSUB == 2
#    if NN_PUB == 32
#        define NN_PUB 32
#    else
#        error "NN_PUB is undefined or is a different value than expected."
#    endif
#    if NN_SUB == 33
#        define NN_SUB 33
#    else
#        error "NN_SUB is undefined or is a different value than expected."
#    endif
#else
#    error "NN_PROTO_PUBSUB is undefined or is a different value than expected."
#endif

#if NN_PROTO_REQREP == 3
#    if NN_REQ == 48
#        define NN_REQ 48
#    else
#        error "NN_REQ is undefined or is a different value than expected."
#    endif
#    if NN_REP == 49
#        define NN_REP 49
#    else
#        error "NN_REP is undefined or is a different value than expected."
#    endif
#else
#    error "NN_PROTO_REQREP is undefined or is a different value than expected."
#endif

#if NN_PROTO_PIPELINE == 5
#    if NN_PUSH == 80
#        define NN_PUSH 80
#    else
#        error "NN_PUSH is undefined or is a different value than expected."
#    endif
#    if NN_PULL == 81
#        define NN_PULL 81
#    else
#        error "NN_PULL is undefined or is a different value than expected."
#    endif
#else
#    error "NN_PROTO_PIPELINE is undefined or is a different value than expected."
#endif

#if NN_PROTO_SURVEY == 6
#    if NN_SURVEYOR == 98
#        define NN_SURVEYOR 98
#    else
#        error "NN_SURVEYOR is undefined or is a different value than expected."
#    endif
#    if NN_RESPONDENT == 99
#        define NN_RESPONDENT 99
#    else
#        error "NN_RESPONDENT is undefined or is a different value than expected."
#    endif
#else
#    error "NN_PROTO_SURVEY is undefined or is a different value than expected."
#endif

#if NN_PROTO_BUS == 7
#    if NN_BUS == 112
#        define NN_BUS 112
#    else
#        error "NN_BUS is undefined or is a different value than expected."
#    endif
#else
#    error "NN_PROTO_BUS is undefined or is a different value than expected."
#endif
