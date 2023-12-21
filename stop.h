#include "stop_watch.h"

extern const stop_watch_if stop_state_if;

void stop_state_start(stop_watch *w);
void stop_state_stop(stop_watch *w);
void stop_state_tick(stop_watch *w);
