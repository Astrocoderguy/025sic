#ifndef DEVICES_TIMER_H
#define DEVICES_TIMER_H

#include <list.h>
#include <round.h>
#include <stdint.h>

#define ENTRY_TO_THREAD(entry) (list_entry( entry, struct thread, alarm_elem ))

/* Number of timer interrupts per second. */
#define TIMER_FREQ 100

void timer_init (void);
void timer_calibrate (void);

int64_t timer_ticks (void);
int64_t timer_elapsed (int64_t);

/* Sleep and yield the CPU to other threads. */
void timer_sleep (int64_t ticks);
void timer_msleep (int64_t milliseconds);
void timer_usleep (int64_t microseconds);
void timer_nsleep (int64_t nanoseconds);

/* Busy waits. */
void timer_mdelay (int64_t milliseconds);
void timer_udelay (int64_t microseconds);
void timer_ndelay (int64_t nanoseconds);

void timer_print_stats (void);

/* Thread wait compare */
bool compare_thread_wait(const struct list_elem *t1, const struct list_elem *t2, void* aux);

#endif /* devices/timer.h */
