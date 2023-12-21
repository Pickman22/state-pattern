#include "stop_watch.h"
#include <stdio.h>

int main(void)
{
    stop_watch w;

    stop_watch_init(&w);
    stop_watch_set_timeout(&w, 10u);
    stop_watch_start(&w);

    while (!stop_watch_is_expired(&w)) {
        stop_watch_tick(&w);
    }

    /* Stop watch automatically transitions to stopped once expired.
     * Restart it. */
    stop_watch_start(&w);
    while (!stop_watch_is_expired(&w)) {
        stop_watch_tick(&w);
    }

    printf("Done.\n\r");
}
