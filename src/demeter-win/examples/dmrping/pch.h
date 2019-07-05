#pragma once
#ifndef PCH_H
#define PCH_H

// TODO: add headers that you want to pre-compile here

#define LOG_SGES(_sges, _count)                                             \
    do {                                                                    \
        char tbuf[256];                                                     \
        for (int ii = 0; ii < _count; ii++) {                               \
            int n = Utils::sge_to_string(tbuf, sizeof(tbuf), *(_sges+ii));  \
            LOG("%s", tbuf);                                                \
        }                                                                   \
    } while(false)


#endif //PCH_H
