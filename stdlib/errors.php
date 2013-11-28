<?php

/*.
	require_module 'standard';
	pragma 'error_throws_exception' 'ErrorException';
.*/

/**
	Maps errors and warnings into {@link \ErrorException}. This package makes
	aware PHPLint that errors raised by system functions and errors raised by
	user code through <code>trigger_error()</code> are just like if a {@link
	\ErrorException} were thrown, and at runtime that exception is actually
	thrown whenever an error occurs.

	Errors that are detected:
	{@link E_WARNING},
	{@link E_NOTICE},
	{@link E_STRICT},
	{@link E_USER_ERROR},
	{@link E_USER_WARNING},
	{@link E_USER_NOTICE}.
	Note that parse-time errors, compile-time errors and core-errors cannot
	be detected at runtime as always cause an abrupt termination of the
	program.

	Moreover, this package also sets the error level to the maximum allowed
	by calling {@link error_reporting(E_ALL|E_STRICT)}.

	All this provides two important benefits: 1) source code becomes simpler,
	because errors can be handled just like any other exception; 2) higher
	safety level at runtime because exceptions ensure that errors are either
	detected and handled properly or the program terminates.

	If this package is included, then the error silencer <code>@</code> cannot
	be used anymore, but you must use <code>try/catch</code> instead.

	Then, for example, the "classic" error handling pattern

	<pre>
	$f = @fopen("afile.txt", "r");
	if( $f === FALSE )
		die($php_errormsg);
	</pre>

	can be rewritten as

	<pre>
	try {
		$f = fopen("afile.txt", "r");
	} catch(ErrorException $e){
		die($e->getMessage());
	}
	</pre>

	Note that the {@link fopen()} function may raise {@link E_WARNING} and this
	error gets mapped into {@link \ErrorException} both by PHPLint and at
	runtime. Moreover, note that also bare {@link E_NOTICE}s now raises the
	same exception (using undefined variables, using an invalid kay in array,
	etc.), so you must always validate your code with PHPLint and carefully
	check your code to prevent fatal runtime exceptions.

	Note that {@link \ErrorException} is a checked exception (not an unchecked
	one), so you must either catch it or declare that exception to be thrown by
	functions and methods as in this example:

	<pre>
	public function readData($fn)
		/&#42;. throws ErrorException .&#42;/
	{
		$f = fopen($fn, "r");
		$data = fread($f, 1024);
		fclose($f);
		# Here: do something with read data.
	}
	</pre>

	Note that if error remapping into exceptions is enabled by including this
	module, then the whole program and libraries used must follow this same
	error handling schema. PHPLint raises an error if it detects a mixed usage
	of the old error-based schema and the new exception-based schema
	implemented by this package.

	@package errors
	@author Umberto Salsi <salsi@icosaedro.it>
	@version $Date: 2012/02/01 23:34:43 $
*/

error_reporting(E_ALL|E_STRICT);


/*. private void .*/ function phplint_exception_handler(/*. Exception .*/ $e)
{
	error_log( "Uncaught ". $e->__toString() );
}


set_exception_handler("phplint_exception_handler");


/*. private string .*/ function phplint_error_level(/*. int .*/ $errno)
{
	switch( $errno ){
		/* These can't be handled: E_ERROR E_PARSE E_CORE_ERROR
			E_CORE_WARNING E_COMPILE_WARNING E_COMPILE_ERROR */
		case E_WARNING:     return "E_WARNING";
		case E_NOTICE:      return "E_NOTICE";
		case E_STRICT:      return "E_STRICT";
		case E_USER_ERROR:  return "E_USER_ERROR";
		case E_USER_WARNING:return "E_USER_WARNING";
		case E_USER_NOTICE: return "E_USER_NOTICE";
		default:            return "UNKNOWN_ERROR_LEVEL_$errno";
	}
}


/*. private bool .*/ function phplint_error_handler(
	/*. int .*/ $errno,
	/*. string .*/ $message,
	/*. string .*/ $filename,
	/*. int .*/ $lineno
	### , /*. mixed .*/ $context
)
/*. throws ErrorException .*/
{ 
	throw new ErrorException( phplint_error_level($errno)
		. ": $message in $filename:$lineno"); 
}


set_error_handler("phplint_error_handler");
