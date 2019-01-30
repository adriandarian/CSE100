# CSE100 Algorithm Design and Analysis

## Lab Policies and Guidelines, Spring 2019

---

In each lab assignment, you will be asked to implement a specific algorithm that you have learned in class (in most cases). _You must follow the input/output formats_ that are specified in each lab assignment description.  We will provide an example in the description, but for more examples, please see $t^{*}$, $o^{*}$ files under `testfiles` directory you can find after upzipping labXX.zip. Each _tx_ file contains an input, and the corresponding output is in file _ox_.

**Submission** Before  the  posted  deadline,  submit  your  source  code  through  the  assignments page of CatCourses. _You must submit only your cpp file (which includes the main function) and the file name must be (your ucm email id).cpp_ -— we apologize for this restriction, but we want to make our grading job as simple as possible.  You will have about two weeks to complete your assignment from the release date.  If your submission is one week overdue, you will lose $10$% ofyour points.  You will get NO points if you submit one week after the deadline.  You’re allowed to resubmit as many times as you want.

**Grading** We will compile your code by standard `c++11` compiler.  You can program your codein your favorite programming environment, but make sure that you compile it by standard `c++11` library and test it before submission; we will give you a testing toolkit.  Here’s a trouble you could run into when you use a different compiler.  Some students preferred to use Visual Studio,so programmed their code using it —- well, it’s a great tool, but you may not be able to use it after graduation unless your company buys it for you.  Don’t expect such luxuries particularly when working for start-ups.  But the problem was that VS used a ‘strengthened’ compiler, which took care of some cumbersome issues such as initialization.  So, even if the students compiled and ran their code successfully using VS, they couldn’t pass any test examples.  When we compiled their  codes  by  standard  `c++11`,  their  code  output  completely  wrong  answers  due  to  a  small initialization mistake.
We will run an _automatic_ grader to test the correctness of your code.  We will test it against10  examples.   Your  score  will  be  proportional  to  the  number  of  test  examples  that  your  code passes.  We will _read_ your code to see if you actually implemented the algorithm you were asked to implement; if you implement a different algorithm, you will get zero points.  Please help us by adding some _comments_ to your code.
We will grade _twice_.  First, right after the deadline, and then, one week after the deadline.Your scores will be updated on catcourses.  Please wait $2$-$3$ days for the update.
Your code should compile by standard `c++11` and run correctly on any machine.  If not, it means your code is not correct.  If you want to avoid any surprise, we strongly recommend that you  test  your  code  on  a  UCM  Linux  machine  (see  below  for  more  details)  before  you  submit your code.  We may test your code on any machine of our choice for convenience.  If you find your score lower than you expected, you can ask us to regrade only on a UCM Linux machine.We will comply.  Note that your code running correctly on your own machine doesn’t give $100$% success guarantees on other machines.

**How to Test your Code by Yourself** We will provide you with the same automatic grading tool for you.  The only difference is that we will disclose only $5$ examples while we will test your code with $5$ additional examples.  By checking your code with the grader before you submit, you will be able to know if your output format is correct.
This is how you can use the grading tool, which is a shell script — so you need to use Linux, Mac  terminal  (if  you’re  a  mac  user),  or  cygwin  (If  you’re  a  window  user).   Or  you  can  use  aUCM  Linux machine,  for  example,  you  can  use `engapps10.ucmerced.edu`.   You  can  access  the machine online.  If you want to do so from out of campus, you will need vpn.  To test your code, unzip `labXX.zip` to your working directory and go inside the labXX folder.  You will see several files.  File `Grade` is the file you will use to test your code.  Your execution file must be named `a.exe`.  Perhaps you may need to use chmod to change the permissions of `Grade`.  Towards this end, you can just type

>“chmod 700 Grade” or “chmod +x Grade”.

Now  if  you  run  `./Grade`  and  your  implementation  is  correct,  you  will  see  the  following messages:

```bash
  Correct for 1 th example.
  Correct for 2 th example.
  Correct for 3 th example.
  Correct for 4 th example.
  Correct for 5 th example.
5/5
```

You can also find a summary of the execution in the file named `result`.  If you want to test your code for just one test file, you can try:  `./a.exe < ./testfiles/t1`

Finally, we also provide a very simple `Makefile` for you, which is very convenient for com-piling your file(s).  If you type `make` it will compile (your ucm email id).cpp; you should editMakefile to rename yourid.cpp by (your ucm email id).cpp.  If you type `make clean`, then `a.exe` will be deleted.  You don’t have to use the provided `Makefile`, but if you don’t know how to use it, this is a good time to learn it.  You can find abundant examples on the web.

**Academic Integrity** Please read file `AcademicHonestyPolicy.pdf` available on CatCourses, and in particular note that the policy says:  “if any violation of the UCM Academic Honesty Policy is suspected in a course, the instructor of record must fill out the Faculty Report for Academic Misconduct.”
You can discuss the lab assignment or your programming approaches with your classmates. However, your code must be your own work.  You can understand what this means by your heart.A good habit is the following.  It is okay to take a look at other implementations for reference.After that, start programming from scratch.  Do not copy and paste and try to modify it to hide plagiarism.
We will occasionally run a tool to catch cheating.  If you get caught even for one lab assignment, you will get $0$ for all labs.  If you cheat in exam, or cheat more than once, you will get $F$. Note that both parties who showed their solutions and copied them will be punished equally.
You can appeal.  If you do, I’ll report your case to the Office of Student Conduct.  You will have to prove that you didn’t cheat in a hearing.  If you fail to defend yourself, you will get $F$ no matter what.