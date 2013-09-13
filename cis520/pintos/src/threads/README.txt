Lucas Wagner
README for alarm-mega test creation

There are a few things I had to do to add the alarm-mega test.
I had to add alarm-mega to Make.tests under the Test names section.
I then add alarm-mega into the tests struct in tests.c along with a test_alarm_mega function reference.
After that, I externed test_alarm_mega in tests.h.
I then added implemented the function in alarm-wait.c.
