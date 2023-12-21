#ifndef STOP_WATCH_H
#define STOP_WATCH_H

#include <stdbool.h>
#include <stdint.h>

struct stop_watch_s;

typedef void (*stop_watch_start_if)(struct stop_watch_s *w);
typedef void (*stop_watch_stop_if)(struct stop_watch_s *w);
typedef void (*stop_watch_tick_if)(struct stop_watch_s *w);

typedef struct
{
    stop_watch_stop_if stop;
    stop_watch_start_if start;
    stop_watch_tick_if tick;
} stop_watch_if;

typedef struct stop_watch_s
{
    bool is_expired;
    uint32_t timeout_ticks;
    uint32_t current_ticks;
    stop_watch_if state_if;
} stop_watch;

void stop_watch_start(stop_watch *w);
void stop_watch_init(stop_watch *w);
void stop_watch_stop(stop_watch *w);
void stop_watch_tick(stop_watch *w);
void stop_watch_set_timeout(stop_watch *w, uint32_t to);
bool stop_watch_is_expired(const stop_watch *w);

#endif
