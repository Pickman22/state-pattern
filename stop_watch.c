#include "stop_watch.h"
#include "common.h"
#include "start.h"
#include "stop.h"

void stop_watch_init(stop_watch *w)
{
    SW_CATCH_NULL_AND_RETURN(w);

    *w = (stop_watch){
        .state_if = stop_state_if,
        .timeout_ticks = 0u,
        .current_ticks = 0u,
        .is_expired = false,
    };

    w->state_if.stop(w);
}

void stop_watch_start(stop_watch *w)
{
    SW_CATCH_NULL_AND_RETURN(w);
    w->state_if.start(w);
}

void stop_watch_stop(stop_watch *w)
{
    SW_CATCH_NULL_AND_RETURN(w);
    w->state_if.stop(w);
}

void stop_watch_tick(stop_watch *w)
{
    SW_CATCH_NULL_AND_RETURN(w);
    w->state_if.tick(w);
}

void stop_watch_set_timeout(stop_watch *w, uint32_t to)
{
    SW_CATCH_NULL_AND_RETURN(w);
    w->timeout_ticks = to;
}

bool stop_watch_is_expired(const stop_watch *w)
{
    SW_CATCH_NULL_AND_RETURN_VALUE(w, true);
    return w->is_expired;
}
