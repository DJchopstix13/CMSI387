# *All of Time and Space*

*Continue our journey through seminal operating systems literature by using library resources (digital or otherwise) to find at least three additional publications (also digital or otherwise) that are related to and/or build upon the work given out in class. For each found publication:*

* *State its connection to the other work in our small collection—the connection must be explicit (i.e., cited). Connections may be to the other work that you find, but at least one must point to something given out in class.*

* *State what it does new or differently from the prior cited works.*

* *Give a brief assessment of the quality of the work. Consider the authors, the publication venue, the level of detail, references cited, etc.*

*You are not expected to fully understand every thing in every piece that you find, but should have some kind of idea.*
*Commit and push this mini-annotated bibliography in any widely-readable format to `homework/os-literature`.*
*Provide full citations for your found work. If you can supply full-text copies of these items, that would be great also.*


##Further comments on Dijkstra's concurrent programming control problem
####Murray A. Eisenberg and Michael R. McGuire

> JD: This one is missing full citation information, unlike the others.

*Connection to Other Work*
***
This article is connected to our small collection because Murray A. Eisenberg and Michael R. McGuire are directly commenting on Djikstra's concurrent programming control problem. Both authors discuss the solution that Djikstra provided and also expand upon the the comments that  Knuth made upon that provided solution.

*Difference from Prior Work*
***
Knuth provided a modification to Dijkstra's algorithm which guaranteed access by an individual contending computer within 2<sup>n-1</sup>-1 turns. This paper expands on that modification and insures that a computer doesn't need to wait more that n-1 turns. They do this by changing the conditions in the `for` loop in the `L2` field to stepping up until 1. They also added this new field into `L3`: `if control [k] ≠ 0 and k ≠ i then goto L0;`. Then they added this to the `L5` field:

	L5: for j := k step 1 until N, 1 step 1 until k do
		if j ≠ k and control [j] ~ 0 then
			begin
				k := j;
				goto L6
			end;

The `L3` field is important and different from Djikstra's initial solution and Knuth's initial comment because th system cannot be blocked because non of the computers contending for access to its critical section has yet passed its statement `L3`.

*Article Quality*
***
This article was written in excellent quality. It came from a non-profit organization that worked for the public interest. As a national resource, the MITRE Corporation applied their expertise in systems engineering, information technology, operational concepts, and enterprise modernization to address their sponsors' critical needs. 

##A simple solution to Lamport's concurrent programming problem with linear wait

####ICS '88 Proceedings of the 2nd international conference on Supercomputing
Pages 621 - 626

####B. K. Szymanski Rensselear Polytechnic Institute, Troy, NY

*Connection to Other Work*
***
This source is connected to source by Lamport beause it references the three
conditions that Lamport believes must be satisfied.

    1. Mutual exclusion: There will be at most one process executing the critical section at a time.
    2. Freedom from deadlock: The critical section will not become inaccessible to all processes. This means that if a number of processes attempts to execute their critical sections, then after finite amount of time some process will be allowed to do so.
    3. Fairness (freedom form starvation): No process will be denied entry to its critical section forever. Thus, a process requesting an entry to its critical section will enter it after waiting for a finite amount of time. The stronger fairness property requires that no process can enter its critical section twice while another process is waiting (linear wait).
    4. Robustness: The solution should be immune to the following two types of failures:
      a. Process failure: a prooess may repeatedly fail and restart. However, process failing in the critical section, prologue or epilogue is assumed to leave the respective section of code and reset all its variables to their initial values.
      b.Read errors during writes (flickering bits): when a process writes a new value to a shared variable, a sequence of reads may return any sequence of the old and new values.

    (Szymanski, 1988, p. 622).

    1. At any time, at most one computer may be in its critical section.
    2. Each computer must eventually be able to enter its critical section (unless it halts)
    3. Any computer may halt in its noncritical section

    (Lamport, 1974, p. 454).

*Difference from prior work*
***
"This algorithm used just five distinct values of shared memory per process.
These values may be stored either in a single variable or in three one-bit
boolean variables per process" (Szymanski, 1988, p. 626).

This is new, in relation to Lamport's paper, because she doesn't deal with the issue
of a process dying in the middle of its critical section. Also, when it came to
the issue of reading and writing from/to a variable at the same time, Szymanski
dealt with these issues. Szymanski proposed a 3 bit system in which more information
can be stored about the state of a certain process than just whether or not it's
in its critical section.

*Article Quality*
***
This was an excellent quality paper because the author took 
the time to set up the background to explain
what Lamport was dealing with, as well as defined confusing
terms before diving into his new element of the algorithm.


##Short-term Scheduling in Multiprogramming Systems

####ACM SIGOPS Operating Systems Review Homepage archive
####Volume 6 Issue 1/2, June 1972
####Pages 101 - 105

*Connection*
***
This source is connected to the paper by Dijkstra because it directly references
that paper.

"At the short-term level of scheduling, a process is either running on a
processor or waiting in a queue. A process can wait for an idle processor or
for a timing signal from another process. In the former case, the process is
said to be ready, in the latter, it is blocked. The synchronizing primitives
for the latter case are the by now familiar P and V operations on semaphores
introduced by E. W. Dijkstra 2" (Hansen, 1972, p. 102).

"It can be done with the aid of a single binary semaphore, say 'free'. The value
of 'free' equals the number of processes allowed to enter their ciritcal setion
now, or:

'free = 1' means: none of the processes is engaged in its critical section

'free = 0' means: one of the proecesses is engaged in its critical section"
(Dijkstra, 1965, p. 30).

*Difference*
***
"Preemption by means of the stop primitive makes it useful to distinguish
between semaphores used to synchronize critical sections and input/output
relationships. When a process enters a critical section, its section depth must
be increased by one to guarantee that it will be able to complete that section,
and, when it leaves it again, the section depth must be decreased by one"
(Hansen, 1972, p. 104).

This is new in relation to the other papers because they mostly talk about how
to determine which process gets to come next, which Hansen does, but they also
describe the addition of some control signals which determine when a process can
enter the processor. These control signals are meant to help determine the exact
context of the process that is occuring and therefore help with the scheduling
of other processes.

*Quality*
***
This Article's is a good quality because the author is associated with Carnegie-Mellon,
a prestigious university in the Computer Science field.This article was that the author not only used snippets of code to get their point across, but they also drew diagrams of things that might be considered
confusing.
