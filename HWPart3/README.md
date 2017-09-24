Author: Jacob Claytor

The included is my work for part 2 of Homework 1. I received help from Erik Horowitz with the objectCounter variable.
I also had to include "time.h" to use srand(time(NULL)) so I wouldn't get the same random number every time I called my
removeRandom function. The current time to run driver.cpp can take a few seconds depending on the values I get for rand(). 
I set it up so it would keep trying to get a random number whose element value did not equal 0. Otherwise, calling removeRandom()
multiple times in a row would not work, or if I had already deleted something from the collection.