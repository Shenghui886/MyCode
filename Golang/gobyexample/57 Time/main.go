/*
	Go offers extensive support for times and durations; here
	are some examples.
*/

package main

import (
	"fmt"
	"time"
)

func main() {
	p := fmt.Println

	/*
		We'll start by getting the current time.
	*/
	now := time.Now()
	p(now)

	/*
		Your can build a 'time' struct by providing the year, month,
		day, etc. Times are always associated with a 'Location', i.e.
		time zone.
	*/
	then := time.Date(
		2009, 11, 17, 20, 34, 58, 651387237, time.UTC,
	)
	p(then)

	/*
		You can extract the various components of the time value
		as expected.
	*/
	p(now.Year())
	p(now.Month())
	p(now.Day())
	p(now.Hour())
	p(now.Minute())
	p(now.Second())
	p(now.Nanosecond())
	p(now.Location())

	/*
		The Monday-Sunday 'Weekday' in also available.
	*/
	p(now.Weekday())

	/*
		These methods compare two times, testing if the first
		occurs before, after, or at the same time as the second,
		respectively.
	*/
	p(now.Before(then))
	p(now.After(then))
	p(now.Equal(then))

	/*
		The 'Sub' methods returns a 'Duration' representing the
		interval between two times.
	*/
	diff := now.Sub(then)
	p(diff)

	/*
		We can compute the length of the duration in various
		units.
	*/
	p(diff.Hours())
	p(diff.Minutes())
	p(diff.Seconds())
	p(diff.Nanoseconds())

	/*
		You can use 'Add' to advance a time by a given duration, or
		with a - to move backwards by a duration.
	*/
	p(then.Add(diff))
	p(now.Add(-diff))
}
