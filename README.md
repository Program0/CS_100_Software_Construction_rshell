# rshell
<h1>Description</h1>
<p>Emulates the Bourne Again Shell in Linux systems. </p>

<h1>New Features:</h1>
<ol>
<li>
<p>Added the test command which tests if a passed argument is a file or directory. It depends on flags -e, -f, and -d. If flag is -e it returns true if passed argument is a file or directory, if flag is -d returns true if argument resolves to a directory and false otherwise, if flag is -f returns true if argument resolves to a file and false otherwise. If no flag is passed, the default behavior is with flag -e. 
</p>
</li>
</ol>

<h1>BUGS:</h1> 
<ol>
<li>
<p>The make file compiles the program fine the first time. However, on subsequent calls to make it will not update the object files. The makefile has a circular depency. You need to make clean then make again to build program correctly.</p>
</li>
<li>
<p>The parser ignores semicolons and passes wrong arguments to our build tree.</p>
</li>
<li>
<p>The internal tree does build properly and executes commands as expected, but now it ignores semicolons.</p>
</li>
<li>
<p>The rshell currently does not work well with ( or ) and precedence.</p>
</li>
</ol>

<h1>BUGFIX:</h1>
<ol>
<li>
<p>rshell now runs and is able to use multiple connectors.</p>
<li>
</ol>
