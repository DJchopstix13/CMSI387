CSI: Process
=======

Use long-running invocations (i.e., huge numbers) of the `thread-java` and/or `thread-posix` sample programs to do the following on at least two operating systems chosen from Linux, Mac OS X, and Microsoft Windows. The chosen two can be different for each task, depending on what is possible or easy for each operating system:

1. Invoke the long-running program, send it to the background, and run another program that produces output.Take a screenshot of that big hot terminal mess.

2. Invoke the long-running program, and use a process monitor on the operating system platform to see that program’s threads. How do the different operating systems represent the threads? Note any major similarities and differences, accompanied by screenshot evidence.

**1.**

*Mac OS-X*

    mac-terminal-mess.png

*Ubuntu*

    ubuntu-terminal-mess.png

> JD: OK, so you've got the mess down, but you do realize that `java Sum 100000`
>     *only invokes one additional thread* right?  There is one thread for each
>     summation requested, and here you are only requesting one summation.  This
>     will skew your findings somewhat.

**2.**   

*Mac OS-X*

    mac-process-threads.png


*Ubuntu*

    ubuntu-process-threads-part1.png
    ubuntu-process-threads-part2.png

I used the Sum.java program once with large numbers for input. 

The main difference between Mac and Ubuntu is how the threads are visually represented
differently.

Mac OS-X:

    Mac OS-X displays the threads under the CPU tab in the Activity monitor, where users can sort an order of the threads by selecting the headers to order the threads. Users can also view the number threads being used.  

> JD: Your image does show this, but the actual *java* process is not in the screenshot.
>     You should make sure that the screenshot you include contains information that
>     matches and is relevant to what you say in your commentary.

Ubuntu:

    Ubuntu displays all the threads as separate lines in an ascending ordering, but then still gives them the same process ID and does not show a total number of threads like Mac. 

> JD: What you say above is not consistent with the image you include.  In `ubuntu-process-threads-part2.png1`,
>     I see `java Sum 100000` only once.  Where are the multiple threads?

A similarity between the two operating systems is that the number of threads is updated as the process is run.  That would mean that, as arguments are being added to Sum.java, their individual threads are deleted as necessary.

> JD: Again, this statement would sound credible *if your screenshots matched the text*.
>     Your screenshots do *not* show `Sum` being run with multiple threads, so what you
>     say above cannot be seen in the evidence that you provide.
