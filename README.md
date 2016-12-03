# rshell
<h1>Description</h1>
<p>Emulates the Bourne Again Shell in Linux systems. </p>

<h1>New Features:</h1>
<ol>
<li>
<p>Added the cd command which behaves similarly to the Bash shell cd command. Added the cd - functionality which returns the user to the previous path. 
</p>
</li>
<li>
<p>Added the test command which tests if a passed argument is a file or directory. It depends on flags -e, -f, and -d. If flag is -e it returns true if passed argument is a file or directory, if flag is -d returns true if argument resolves to a directory and false otherwise, if flag is -f returns true if argument resolves to a file and false otherwise. If no flag is passed, the default behavior is with flag -e. It has also been enhanced to use [] to encapsulate a command.
</p>
</li>

</ol>

<h1>Future Features: </h1>
<ol>
<li>
<p>Revision of the test command to behave more like the BASH test command. 
</p>
</li>
<li>
<p>Access previous commands entered by using the up arrow. 
</p>
</li>

</ol>


<h1>BUGS:</h1> 
<ol>
<li>
<p>The test command works on files or directories if they are in the current program's working directory. Otherwise the user needs to  use .. to check for files in the parent directory or enter the full path.</p>
</li>
<li>
<p>The test command using [] does not currently evaluate expressions as the BASH shell does. Though technically not a bug, future implemenations will include use of the [] to evaluate expressions, but without having to enter spaces between [] and the expressions.</p>
</li>

</ol>

<h1>BUGFIX:</h1>
<ol>
<li>
<p>rshell now runs and is able to use multiple connectors.</p>
</li>
<li>
<p>rshell parser now takes () into account to create precedence among the && and || operators.</p>
</li>
</ol>
