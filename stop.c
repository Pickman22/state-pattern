#include "stop.h"
#include "common.h"
#include "start.h"
#include "stop_watch.h"
#include <stdio.h>

const stop_watch_if stop_state_if = {
    .start = stop_state_start,
    .stop = stop_state_stop,
    .tick = stop_state_tick,
};

void stop_state_start(stop_watch *w)
{
    SW_CATCH_NULL_AND_RETURN(w);
    printf("Transitioning to started state.\n\r");
    w->state_if = start_state_if;
    w->state_if.start(w);
}

void stop_state_stop(stop_watch *w)
{
    SW_CATCH_NULL_AND_RETURN(w);
    printf("Entered stopped state.\n\r");
    w->current_ticks = 0u;
}

void stop_state_tick(stop_watch *w)
{
    SW_CATCH_NULL_AND_RETURN(w);
    printf("Stopped state does not tick!\n\r");
}
