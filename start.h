#include "stop_watch.h"

extern const stop_watch_if start_state_if;

void start_state_start(stop_watch *w);
void start_state_stop(stop_watch *w);
void start_state_tick(stop_watch *w);
