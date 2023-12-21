#include "start.h"
#include "common.h"
#include "stop.h"
#include "stop_watch.h"
#include <stdio.h>

static void start_state_start(stop_watch *w);
static void start_state_stop(stop_watch *w);
static void start_state_tick(stop_watch *w);

const stop_watch_if start_state_if = {
    .start = start_state_start,
    .stop = start_state_stop,
    .tick = start_state_tick,
};

void start_state_start(stop_watch *w)
{
    SW_CATCH_NULL_AND_RETURN(w);
    printf("Entered start state. Clearinig ticks.\n\r");
    w->current_ticks = 0u;
    w->is_expired = false;
}

void start_state_stop(stop_watch *w)
{
    SW_CATCH_NULL_AND_RETURN(w);
    printf("Transitioning to stop state.\n\r");
    w->state_if = stop_state_if;
    w->state_if.stop(w);
}

void start_state_tick(stop_watch *w)
{
    SW_CATCH_NULL_AND_RETURN(w);
    w->current_ticks++;
    w->current_ticks = SW_MIN(w->current_ticks, w->timeout_ticks);
    printf("Ticking. Current ticks: %u\n\r", w->current_ticks);
    if (w->current_ticks >= w->timeout_ticks) {
        printf("Stopwatch expired.\n\r");
        w->is_expired = true;
        w->state_if.stop(w);
    }
}
